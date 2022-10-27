#include <iostream>
#include <complex.h>
#include <vector>
#include <random>
#include <time.h>

typedef std::vector<std::complex<float>> ComplexVector;
typedef std::complex<float> Complex;

struct CplxRow
{
    ComplexVector data;
    Complex avg;
    CplxRow(){data.reserve(4);}; //struct constructor
};

using CompositeMatrixCplx = std::vector<CplxRow>;

struct Range
{
    float min, max;
};

void getRangeInput(Range& out_range);

int main()
{
    std::cout << "Student B10831020" << std::endl;
    Range userSetRange;
    CompositeMatrixCplx m1(), m2(), addResult();
    getRangeInput(userSetRange);
    return 0;
}

void assignRandomValues(const Range& rng, CompositeMatrixCplx& m1, CompositeMatrixCplx& m2)
{
    auto randGenerator = std::mt19937(time(0));    
    for(int i=0; i<m1.size(); i++){
        for(int j=0; j<m1[i].data.size(); j++){
        }
    }
}

void getRangeInput(Range& out_range)
{
    std::cout << "Please input the minimum and maximum value of the real part" << std::endl;
    std::cin >> out_range.min >> out_range.max;
    if(out_range.min > out_range.max){
        std::cout << "Minimum input is larger than maximum, please try again" << std::endl;
        getRangeInput(out_range);
    }
}