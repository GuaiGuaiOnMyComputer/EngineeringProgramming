#include <iostream>
#include <complex> // std::complex<float>
#include <vector>  // std::vector<std::vector<std::float>>>
#include <random>  // std::mt19937
#include <time.h>  // time(0)
#include <iomanip> // std::setprecision()

using Complex = std::complex<float>;
using HozRow = std::vector<Complex>;


struct realImgMinMax
{
    float realMin, realMax, imgMin, imgMax;
};

class CplxMatrix
{
public:

    CplxMatrix(int nRows, int nCols, const realImgMinMax& rng, const char* matrixName)
        :mNRows(nRows), mNCols(nCols), mRealMax(rng.realMax), mRealMin(rng.realMin), mImgMax(rng.imgMax), mImgMin(rng.imgMin), mMatrixName(matrixName)
    {
        this->mConstructShape();
        this->mAssignRandValusAndGetNonDiaSum();
        this->mGetRowAvg();
    }

    CplxMatrix(int nRows, int nCols, const char* matrixName) // this constructor is used for + and - operator
        : mNRows(nRows), mNCols(nCols), mMatrixName(matrixName)
    {
        this->mConstructShape();
    }

    friend std::ostream& operator<< (std::ostream& stream, const CplxMatrix& mat);

    CplxMatrix operator+ (const CplxMatrix& another)
    {
        CplxMatrix tmp(this->mNRows, this->mNCols, "Addition of the two matrices");
        for(int i=0; i<this->mNRows; i++){
            tmp.mData[i].reserve(this->mNCols);
            for(int j=0; j<this->mNCols; j++){
                tmp.mData[i].push_back(this->mData[i][j] + another.mData[i][j]);
            }
        }
        tmp.mGetNonDiagonalSum();
        tmp.mGetRowAvg();
        return tmp;
    }

    CplxMatrix operator- (const CplxMatrix& another)
    {
        CplxMatrix tmp(this->mNRows, this->mNCols, "subtraction of the two matrices");
        for(int i=0; i<this->mNRows; i++){
            tmp.mData[i].reserve(this->mNCols);
            for(int j=0; j<this->mNCols; j++){
                tmp.mData[i].push_back(this->mData[i][j] - another.mData[i][j]);
            }
        }
        tmp.mGetNonDiagonalSum();
        tmp.mGetRowAvg();
        return tmp;
    }

private:
    std::vector<HozRow> mData = std::vector<HozRow>();
    int mNRows, mNCols;
    float mRealMin, mRealMax, mImgMin, mImgMax;
    const char* mMatrixName;
    Complex mNonDiaSum;
    std::vector<Complex> mRowAvg = std::vector<Complex> ();

    void mConstructShape()
    {
        this->mData.reserve(this->mNRows);
        for(int i=0; i<this->mNRows; i++){
            this->mData.push_back(HozRow());
        }
    }

    void mGetNonDiagonalSum()
    {
        this->mNonDiaSum = Complex(0, 0);
        for(int i=0; i < this->mNRows; i++){
            for(int j=0; j < this->mNCols; j++){
                if(i != j){this->mNonDiaSum += this->mData[i][j];}
            }
        }
    }

    void mAssignRandValusAndGetNonDiaSum()
    {
        static auto sRandGen = std::mt19937(time(0));
        float realRandTmp, imagRandTmp;
        for(int i=0; i<this->mNRows; i++){
            this->mData[i].reserve(this->mNCols);
            for(int j=0; j<this->mNCols * 2; j++){ // *2 since each complex has its real and imaginary part
                //generate a random number, rescale it into [0, 1] and remaps the value into user-set range
                realRandTmp = ((float)(sRandGen() - sRandGen.min()) / (float)(sRandGen.max() - sRandGen.min())) * (this->mRealMax - this->mRealMin) + this->mRealMin; 
                //generate a random number, rescale it into [0, 1] and remaps the value into user-set range
                imagRandTmp = ((float)(sRandGen() - sRandGen.min()) / (float)(sRandGen.max() - sRandGen.min())) * (this->mImgMax - this->mImgMin) + this->mImgMin;
                Complex element = Complex(realRandTmp, imagRandTmp);
                if(i != j){this->mNonDiaSum += element;} // calculate the nondiagonal sum
                this->mData[i].push_back(element);
            }
        }
    }

    void mGetRowAvg()
    {
        this->mRowAvg.reserve(this->mData.size());
        for(const HozRow& row : this->mData){
            Complex tmp = Complex(0, 0);
            for(const Complex& cplx : row){
                tmp += cplx;
            }
            Complex avg = Complex(tmp.real() / (int)row.size(), tmp.imag() / (int)row.size());
            this->mRowAvg.push_back(avg);
        }
    }
};

std::ostream& operator<< (std::ostream& stream, const CplxMatrix& mat)
{
    stream << '\n';
    stream << mat.mMatrixName << '\n';
    stream << std::setw(7) << "Row ID" << std::setw(1) << '|' << std::setw(40) << "Content" 
        << std::setw(40) << ' ' << std::setw(1) << '|' << std::setw(15) << "Row avg" << std::endl;
    for(int i=0; i<mat.mNRows; i++){\
        stream << std::setw(7) << i << std::setw(1) << '|';
        for(int j=0; j<mat.mNCols; j++){
            if(j==mat.mNCols - 1){
                stream << std::setw(20) << std::setprecision(3) << mat.mData[i][j] << std::setw(1) << '|' << std::setw(15) << mat.mRowAvg[i] << '\n';
            }
            else{
                stream << std::setw(20) << std::setprecision(3) << mat.mData[i][j];
            }
        }
    }
    stream <<  "Sum of the matrix excluding the diagonal = " << std::setprecision(2) << mat.mNonDiaSum << '\n';
    return stream;
}

void sortUserInput(realImgMinMax& rng)
{
    if(rng.realMax < rng.realMin){ // if the user inputs the minimum and maximum boundaries backwards, reverse it
        float tmp = rng.realMin;
        rng.realMin = rng.realMax;
        rng.realMax = tmp;
    }
    if(rng.imgMax < rng.imgMin){ // if the user inputs the minimum and maximum boundaries backwards, reverse it
        float tmp = rng.imgMin;
        rng.imgMin = rng.imgMax;
        rng.imgMax = tmp;
    }
}

void getUserInput(realImgMinMax& rng)
{
    std::cout << "Please input the boundaries of the real parts as floats seperated by a space" << std::endl;
    std::cin >> rng.realMin >> rng.realMax;
    std::cout << "Please input the boundaries of the imaginary parts as floats seperated by a space" << std::endl;
    std::cin >> rng.imgMin >> rng.imgMax;
    sortUserInput(rng);
}

int main(int argc, char* argv[])
{
    std::cout << "Student ID: B10831020" << std::endl;
    realImgMinMax range;
    // check if the user have provided command-line argument when starting the program
    if(argc != 5){
        // if the user didn't provide command-line argument, prompt the user to do so
        std::cout << "You didn't provide enough command-line arguments" << std::endl;
        std::cout << "Setting the real and imaginary boundaries in program" << std::endl;
        getUserInput(range);
    }
    else{
        // use struct member initializer list {memb1, memb2, memb3, memb4}
        // atof() takes in a char pointer, cast the content at the char pointer to double
        // cast the double returned by atof() to float and initialize range's member value
        // argv[0] is the program name, not one of the floats
        range = {(float)atof(argv[1]), (float)atof(argv[2]), (float)atof(argv[3]), (float)atof(argv[4])};
        sortUserInput(range);
        std::cout << std::setw(5) << " " << std::setw(5) << "real" << std::setw(10) << "imaginary" << std::endl;
        std::cout << std::setw(5) << "min" << std::setw(5) << range.realMin << std::setw(5) << range.imgMin << std::endl;
        std::cout << std::setw(5) << "max" << std::setw(5) << range.realMax << std::setw(5) << range.imgMax << std::endl;
    }

    CplxMatrix m1 = CplxMatrix(4, 4, range, "Complex matrix m1");
    CplxMatrix m2 = CplxMatrix(4, 4, range, "Complex matrix m2");
    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;
    std::cout << m1 + m2 << std::endl;
    std::cout << m1 - m2 << std::endl;
    system("pause");
    return 0;
}

/*
Replit: https://replit.com/join/cgebjnbftu-b10831020
Student ID: B10831020
You didn't provide enough command-line arguments
Setting the real and imaginary boundaries in program
Please input the boundaries of the real parts as floats seperated by a space
5 6
Please input the boundaries of the imaginary parts as floats seperated by a space
2 3

Complex matrix m1
 Row ID|                                 Content                                        |        Row avg
      0|         (5.31,2.68)          (5.1,2.06)         (5.25,2.48)          (5.49,2.3)|    (5.34,2.37)
      1|          (5.8,2.35)         (5.71,2.48)          (5.82,2.8)          (5.8,2.18)|    (5.65,2.44)
      2|          (5.3,2.01)         (5.78,2.08)         (5.75,2.64)          (5.4,2.11)|    (5.46,2.27)
      3|          (5.8,2.23)          (5.87,2.5)         (5.66,2.42)         (5.89,2.07)|    (5.62,2.38)
Sum of the matrix excluding the diagonal = (1.5e+02,66)


Complex matrix m2
 Row ID|                                 Content                                        |        Row avg
      0|         (5.69,2.71)         (5.33,2.35)         (5.76,2.98)         (5.31,2.25)|     (5.52,2.6)
      1|         (5.54,2.68)          (5.5,2.88)         (5.03,2.89)         (5.95,2.75)|    (5.55,2.59)
      2|         (5.52,2.87)         (5.38,2.19)         (5.62,2.01)         (5.57,2.17)|    (5.43,2.41)
      3|         (5.24,2.02)         (5.26,2.03)         (5.31,2.31)          (5.73,2.6)|     (5.4,2.26)
Sum of the matrix excluding the diagonal = (1.5e+02,69)


Addition of the two matrices
 Row ID|                                 Content                                        |        Row avg
      0|           (11,5.38)         (10.4,4.41)           (11,5.45)         (10.8,4.55)|    (10.8,4.95)
      1|         (11.3,5.03)         (11.2,5.37)         (10.9,5.69)         (11.8,4.93)|    (11.3,5.25)
      2|         (10.8,4.88)         (11.2,4.27)         (11.4,4.65)           (11,4.28)|    (11.1,4.52)
      3|           (11,4.25)         (11.1,4.53)           (11,4.72)         (11.6,4.67)|    (11.2,4.54)
Sum of the matrix excluding the diagonal = (1.3e+02,57)


subtraction of the two matrices
 Row ID|                                 Content                                        |        Row avg
      0|      (-0.38,-0.034)      (-0.23,-0.286)       (-0.507,-0.5)      (0.178,0.0507)|(-0.235,-0.192)
      1|       (0.26,-0.332)       (0.21,-0.399)     (0.788,-0.0897)       (-0.15,-0.57)| (0.277,-0.348)
      2|     (-0.224,-0.869)      (0.401,-0.106)       (0.131,0.636)    (-0.174,-0.0647)|(0.0334,-0.101)
      3|       (0.553,0.211)       (0.606,0.465)       (0.353,0.109)      (0.162,-0.525)| (0.419,0.0651)
Sum of the matrix excluding the diagonal = (1.9,-2)
*/