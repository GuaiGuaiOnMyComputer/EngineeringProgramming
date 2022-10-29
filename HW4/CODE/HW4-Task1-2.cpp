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

    Complex GetAvg()
    {
        Complex avg;
        for(int i=0 ; i<data.size(); i++){
            avg += data[i];
        }
        avg = Complex(avg.real() / data.size(), avg.imag()/ data.size());
        return avg;
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
void matrixAdd(const CompositeMatrixCplx& m1, const CompositeMatrixCplx& m2, CompositeMatrixCplx& out_result);
void matrixSubtract(const CompositeMatrixCplx& m1, const CompositeMatrixCplx& m2, CompositeMatrixCplx& out_result);
void printNonDiaSum(const CompositeMatrixCplx& m);

int main()
{
    std::cout << "Student B10831020" << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << "NOTICE: Currently there is a bug"<< std::endl;
    std::cout << "The generated random values repeats and their values are not within the user-designated interval. Maybe I can fix it later, maybe not" << std::endl;
    std::cout << "==================================================" << std::endl;
    Range userSetRange;
    CompositeMatrixCplx m1, m2, addResult, subtractResult;
    getRangeInput(userSetRange);
    assignRandomValues(userSetRange, m1, m2);
    printCompositeMatrix(m1, "Complex matrix m1"); 
    printCompositeMatrix(m2, "Complex matrix m2");
    matrixAdd(m1, m2, addResult);
    printCompositeMatrix(addResult, "m1 + m2");
    matrixSubtract(m1, m2, subtractResult);
    printCompositeMatrix(subtractResult, "m1 - m2");
    printNonDiaSum(addResult);
    system("pause");   
    return 0;
}

void printNonDiaSum(const CompositeMatrixCplx& m)
{
    std::cout << "Non diagonal sum of m1 and m2" << std::endl;
    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[i].data.size(); j++){
            if(i==j){
                if(i == 3){
                    std::cout << "----------" << '\t';
                }
                else{
                    std::cout << "----------" << '\t';
                }
            }
            else{
                if(i==3){
                    std::cout << m[i].data[j].real() << "+" << m[i].data[j].imag() << 'i' << '\t';
                }
                else{
                    std::cout << m[i].data[j].real() << '+' << m[i].data[j].imag() << 'i' << '\t';
                }
            }
        }
        std::cout << std::endl;
    }
}

void matrixAdd(const CompositeMatrixCplx& m1, const CompositeMatrixCplx& m2, CompositeMatrixCplx& out_result)
{
    out_result.reserve(4);
    for(int i=0; i<m1.size(); i++){
        out_result.push_back(CplxRow());
        for(int j=0; j<m1.size(); j++){
            out_result[i].data.push_back(m1[i].data[j] + m2[i].data[j]);
        }
    }
}
void matrixSubtract(const CompositeMatrixCplx& m1, const CompositeMatrixCplx& m2, CompositeMatrixCplx& out_result)
{
    out_result.reserve(4);
    for(int i=0; i<m1.size(); i++){
        out_result.push_back(CplxRow());
        for(int j=0; j<m1.size(); j++){
            out_result[i].data.push_back(m1[i].data[j] - m2[i].data[j]);
        }
    }
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
    std::cout << std::endl;
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
        for(int j=0; j<4; j++)
        {
            // randNumbers[j] = (float)randGenerator(); this line seems necessary but it creates weird bug
            float randOffsetCoeff = 1 + (float)(randGenerator() - randGenerator.min()) / (float)(randGenerator.max() - randGenerator.min()); // the result will be 1.xxx
            // left-shift or right-shift the generated random number into the user input range
            switch (j%2)
            {
                case 1:
                    // handling the real part of a complex number if i is an odd number(if this current iteration is an odd iteration)
                    if(randNumbers[j] > rng.realMax){
                        randNumbers[j] = randNumbers[j] - randOffsetCoeff * (randNumbers[j] - rng.realMax);
                    }
                    else if(randNumbers[j] < rng.realMin){
                        randNumbers[j] = randNumbers[j] + randOffsetCoeff * (rng.realMin - randNumbers[j]);
                    }
                    break;
                case 0:
                    // handling the imaginary part of a complex number if i is an even number(if this current iteration is an even iteration)
                    if(randNumbers[j] > rng.imgMax){
                        randNumbers[j] = randNumbers[j] - randOffsetCoeff * (randNumbers[j] - rng.imgMax);
                    }
                    else if(randNumbers[j] < rng.imgMin){
                        randNumbers[j] = randNumbers[j] + randOffsetCoeff * (rng.imgMin - randNumbers[j]);
                    }
                    break;
            }
            m1[i].data.push_back(Complex(randNumbers[0], randNumbers[1])); // calls the constructor of std::complex<float>
            m2[i].data.push_back(Complex(randNumbers[2], randNumbers[3])); // push_back a complex number into the matrix
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

/*
Replit:https://replit.com/join/zulanzrtsi-b10831020

Student B10831020
==================================================
NOTICE: Currently there is a bug
The generated random values repeats and their values are not within the user-designated interval. Maybe I can fix it later, maybe not
==================================================
Please input the boundaries of the real part
89.66
11
Please input the boundaries of the imaginary part
-78
23
Complex matrix m1
7.74e-38+0i 7.74e-38+14.7i  7.74e-38+14.7i  7.74e-38+14.7i
7.74e-38+0i 7.74e-38+17.5i  7.74e-38+17.5i  7.74e-38+17.5i
7.74e-38+0i 7.74e-38+18.1i  7.74e-38+18.1i  7.74e-38+18.1i
7.74e-38+0i 7.74e-38+21.3i  7.74e-38+21.3i  7.74e-38+21.3i
=============================

Complex matrix m2
7.74e-38+0i 7.74e-38+0i 7.74e-38+0i 7.74e-38+17.7i
7.74e-38+0i 7.74e-38+0i 7.74e-38+0i 7.74e-38+20.9i
7.74e-38+0i 7.74e-38+0i 7.74e-38+0i 7.74e-38+12.1i
7.74e-38+0i 7.74e-38+0i 7.74e-38+0i 7.74e-38+21.6i
=============================

m1 + m2
1.55e-37+0i 1.55e-37+14.7i  1.55e-37+14.7i  1.55e-37+32.5i
1.55e-37+0i 1.55e-37+17.5i  1.55e-37+17.5i  1.55e-37+38.4i
1.55e-37+0i 1.55e-37+18.1i  1.55e-37+18.1i  1.55e-37+30.2i
1.55e-37+0i 1.55e-37+21.3i  1.55e-37+21.3i  1.55e-37+43i
=============================

m1 - m2
0+0i    0+14.7i 0+14.7i 0+-3.03i
0+0i    0+17.5i 0+17.5i 0+-3.38i
0+0i    0+18.1i 0+18.1i 0+6.05i
0+0i    0+21.3i 0+21.3i 0+-0.271i
=============================

Non diagonal sum of m1 and m2
----------  1.55e-37+14.7i  1.55e-37+14.7i  1.55e-37+32.5i
1.55e-37+0i ----------  1.55e-37+17.5i  1.55e-37+38.4i
1.55e-37+0i 1.55e-37+18.1i  ----------  1.55e-37+30.2i
1.55e-37+0i 1.55e-37+21.3i  1.55e-37+21.3i  ----------
*/