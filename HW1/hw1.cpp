#include <iostream>
#include <vector>
#include <cmath>       //pow(), sqrt()

class Inputs;
bool getUserInput(int& out_sideA, int& out_sideB, int& out_sideC);
float getArea(const int& sideA, const int& sideB, const int sideC);
void printSortedResult(const std::vector<Inputs>& sessionLog);


class Inputs
{
public:
    Inputs(int inputIdx, int sideA, int sideB, int sideC, float area):
        _inputIdx(inputIdx),
        _sideA(sideA),
        _sideB(sideB),
        _sideC(sideC),
        _area(area)
    {
        this->_inputIdx = inputIdx;
        this->_sideA = sideA;
        this->_sideB = sideB;
        this->_sideC = sideC;
        this->_area = area;
    }

    int _inputIdx;
    int _sideA;
    int _sideB;
    int _sideC;
    float _area;

    Inputs() = delete;
};

int main()
{
    int inputCount = 0;
    std::vector<Inputs> inputLog(10);
    int sideA, sideB, sideC;

    while(getUserInput(sideA, sideB, sideC)){
        float area = getArea(sideA, sideB, sideC);
        // inputLog.push_back();
        inputCount ++;
    }

    //bubble sort
    int i = 0, j = 0;
    for(i = 0; i<inputCount-1; i++){
        while(j<inputCount-i-1 && inputLog[j]._area>inputLog[j+1]._area){
            auto tmp = inputLog[j];
            inputLog[j] = inputLog[i];
            inputLog[i] = inputLog[j];
            j++;
        }
    }
    printSortedResult(inputLog);    
    return 0;
}


float getArea(const int& sideA, const int& sideB, const int sideC)
{   //takes in the pointer to the first element of array and offset using index
    float halfPerimeter = (sideA + sideB + sideC) / 2;
    float area = sqrt(pow(sideA-halfPerimeter, 2) * pow(sideB-halfPerimeter, 2) * pow(sideC-halfPerimeter, 2));
    std::cout << '\t' << "The area of this triangle is " <<  area << std::endl;
    return area;
}

bool getUserInput(int& out_sideA, int& out_sideB, int& out_sideC)
{
    //takes in a pointer to an float array to store user inputs
    //returns false and breaks loop when input is 0, 0, 0
    std::cout << "Please input three values as the length of three sides" <<std::endl;
    std::cin >> out_sideA >> out_sideB >> out_sideC;
    if(out_sideA <= 0 || out_sideB <= 0 || out_sideC <= 0){
        std::cout << "At least one side is smaller or equal to 0, terminating program." << std::endl;
        return false;
    }
    return true;
}

void printSortedResult(const std::vector<Inputs>& sessionLog)
{
    const int count = sessionLog.capacity();
    std::cout << "The triangle with the smallest area is " << sessionLog[0]._area << "with sides" << '(' << sessionLog[0]._sideA << ", " << sessionLog[0]._sideB << ", " << sessionLog[0]._sideC << ")" << std::endl;
    std::cout << "And the triangle with the largest area is" << sessionLog[count-1]._area << "with sides" << "( " << sessionLog[count-1]._sideA << ", " << sessionLog[count -1]._sideB << ", "  << sessionLog[count-1]._sideC << ')' << std::endl;
}

