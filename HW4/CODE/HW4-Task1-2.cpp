#include <iostream>
#include <iomanip>
#include <complex.h>
#include <vector>
#include <random>
#include <time.h>
#include <cmath>

typedef std::vector<std::complex<float>> ComplexVector;
typedef std::complex<float> Complex;

struct CplxRow
{
    ComplexVector data;
    Complex avg;
    CplxRow(){data.reserve(4);}; //struct constructor

    std::complex<float> GetAvg()
    {
        float realAvg = 0, imgAvg = 0;
        for(int i=0 ; i<data.size(); i++){
            realAvg += data[i].real(); //cast std::complex<float> into float
            imgAvg += data[i].imag(); //cast std::complex<float> into float
        }
        realAvg = realAvg / (float)data.size();
        imgAvg = imgAvg / (float)data.size();
        return std::complex<float> (realAvg, imgAvg);
    }
};

using CompositeMatrixCplx = std::vector<CplxRow>;

struct Range
{
    float realMin, realMax, imgMin, imgMax;
    float realInterval, imgInterval;
    Range() {} // struct constructor

    void CheckAndSwapMinMax()
    {
        if(realMin > realMax) {
            float tmp = realMax;
            realMax = realMin;
            realMin = tmp;
        }
        if(imgMin > imgMax) {
            float tmp = imgMax;
            imgMax = imgMin;
            imgMin = tmp;
        }
        imgInterval = imgMax - imgMin;
        realInterval = realMax - realMin;
    }
};

void getRangeInput(Range& out_range);
void assignRandomValues(const Range& rng, CompositeMatrixCplx& m1, CompositeMatrixCplx& m2);
void printCompositeMatrix(const CompositeMatrixCplx& m, const char* msg);

int main()
{
    std::cout << "Student B10831020" << std::endl;
    Range userSetRange;
    CompositeMatrixCplx m1, m2, addResult;
    getRangeInput(userSetRange);
    assignRandomValues(userSetRange, m1, m2);
    printCompositeMatrix(m1, "Complex matrix m1"); 
    system("pause");   
    return 0;
}

void printCompositeMatrix(const CompositeMatrixCplx& m, const char* msg)
{
    std::cout << msg << std::endl;
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[i].data.size(); j++){
            std::cout << std::setprecision(3) << m[i].data[j].real() << '+' << m[i].data[j].imag() << "i\t";
        }
        std::cout << std::endl;
    }
    std::cout << "=============================" << std::endl;
}

void assignRandomValues(const Range& rng, CompositeMatrixCplx& m1, CompositeMatrixCplx& m2)
{
    m1.reserve(4); //reserves 4 ComplexRows in each CompositeMatrixCplx
    m2.reserve(4);
    auto randGenerator = std::mt19937(time(0));    
    for(int i=0; i<4; i++){
        m1.push_back(CplxRow()); // calls the CplxRow constructor and auto reserve 4 complexes in a row
        m2.push_back(CplxRow()); // checkout the CplxRow consturctor
        float randNumbers[4];
        for(int q=0; q<4; q++)
        {
            randNumbers[q] = randGenerator();
            float randOffsetCoeff = 1 + (randGenerator() - randGenerator.min()) / (float)(randGenerator.max() - randGenerator.min()); // the result will be 1.xxx
            float distance;
            // left-shift or right-shift the generated random number into the user input range
            switch (q%2)
            {
                
                case 1:
                    // handling the real part of a complex number if i is an odd number(if this current iteration is an odd iteration)
                    if(randNumbers[q] > rng.realMax){
                        distance = randOffsetCoeff * (randNumbers[q] - rng.realMax);
                        float tmp = randNumbers[q];
                        randNumbers[q] = tmp - distance;
                    }
                    else if(randNumbers[q] < rng.realMin){
                        distance = randOffsetCoeff * (rng.realMin - randNumbers[q]);
                        float tmp = randNumbers[q];
                        randNumbers[q] = tmp + distance;
                    }
                    break;
                case 0:
                    // handling the imaginary part of a complex number if i is an even number(if this current iteration is an even iteration)
                    if(randNumbers[q] > rng.imgMax){
                        distance = randOffsetCoeff * (randNumbers[q] - rng.imgMax);
                        float tmp = randNumbers[q];
                        randNumbers[q] = tmp - distance;
                    }
                    else if(randNumbers[q] < rng.imgMin){
                        distance = randOffsetCoeff * (rng.imgMin - randNumbers[q]);
                        float tmp = randNumbers[q];
                        randNumbers[q] = tmp + distance;
                    }
                    break;
                
            }
        }
        for(int _=0; _<4; _++){ // *2 to handle the real and imginary parts of each element
            m1[i].data.push_back(std::complex<float> (randNumbers[0], randNumbers[1])); // calls the constructor of std::complex<float>
            m2[i].data.push_back(std::complex<float> (randNumbers[2], randNumbers[3])); // push_back a complex number into the matrix
        }
        m1[i].GetAvg();
        m2[i].GetAvg();
    }
}

void getRangeInput(Range& out_range)
{
    std::cout << "Please input the boundaries of the real part" << std::endl;
    std::cin >> out_range.realMin >> out_range.realMax;
    std::cout << "Please input the boundaries of the imaginary part" << std::endl;
    std::cin >> out_range.imgMin >> out_range.imgMax;
    out_range.CheckAndSwapMinMax(); // if the min and max is input oppositely, call this function to revert it and calculate the interval attribute
}