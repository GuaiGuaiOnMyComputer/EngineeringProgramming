#include <iostream>
#include <vector>
#include <cmath>       //pow(), sqrt()

bool getUserInput(int& out_sideA, int& out_sideB, int& out_sideC);
float getArea(const int& sideA, const int& sideB, const int sideC);
class InputLogSort;

class Inputs
{
public:
    int inputIdx;
    int sideA;
    int sideB;
    int sideC;
    float area;
};

int main()
{
    int inputCount = 0;
    std::vector<Inputs> inputLog(10);
    int sideA, sideB, sideC;

    while(getUserInput(sideA, sideB, sideC){
        float area = getArea(sideA, sideB, sideC);
        Inputs currentInput;
        currentInput.inputIdx = inputCount;
        currentInput.sides = *sides;

        inputLog.push_back(currentInput);
        inputCount ++;
    }

    InputLogSort sortSessionLog = InputLogSort(&inputLog);
    sortSessionLog.bubbleSort();

    printSortedResult(&inputLog);    
    return 0;
}


float getArea(const int& sideA, const int& sideB, const int sideC)
{   //takes in the pointer to the first element of array and offset using index
    float halfPerimeter = (sideA + sideB + sideC) / 2;
    return sqrt(pow(sideA-halfPerimeter, 2) * pow(sideB-halfPerimeter, 2) * pow(sideC-halfPerimeter, 2));
}

bool getUserInput(int& out_sideA, int& out_sideB, int& out_sideC)
{
    //takes in a pointer to an float array to store user inputs
    //returns false and breaks loop when input is 0, 0, 0
    std::cout << "Please input three values as the length of three sides" <<std::endl;
    std::cin >> out_sideA >> out_sideB >> out_sideC;
    return !(out_sideA == 0 && out_sideB == 0 && out_sideC == 0);
}

void printSortedResult(const std::vector<Inputs>* sessionLog)
{
    const std::vector<Inputs> __sessionLog = *sessionLog;
    const int count = sessionLog->capacity();
    std::cout << "The triangle with the smallest area is " << __sessionLog[0].area << "with sides" << '(' << __sessionLog[0].sides[0] << ", " << __sessionLog[0].sides[1] << ", " << __sessionLog[0].sides[2] << ")" << std::endl;
    std::cout << "And the triangle with the largest area is" << __sessionLog[count-1].area << "with sides" << "( " << __sessionLog[count-1].sides[0] << ", " << __sessionLog[count -1].sides[1] << ", "  << __sessionLog[count-1].sides[2] << ')' << std::endl;
}


class InputLogSort
{
public:
    InputLogSort(std::vector<Inputs>* sessionLog_ptr)
    { 
        __sessionLog = *sessionLog_ptr;
        __nRecords = __sessionLog_ptr->capacity();
        bubbleSort();
    }

    void bubbleSort()
    {
        int i = 0, j = 0;
        for(i = 0; i<__nRecords-1; i++){
            while(j<__nRecords-i-1 && __sessionLog[j].area>__sessionLog[j+1].area){
                __swap(i, j);
                j++;
            }
        }
    }

private:
    std::vector<Inputs>* __sessionLog_ptr = nullptr;
    std::vector<Inputs> __sessionLog;
    int __nRecords;
    
    void __swap(int idxA, int idxB)
    {
        Inputs tmp = __sessionLog[idxA];
        __sessionLog[idxA] = __sessionLog[idxB];
        __sessionLog[idxB] = __sessionLog[idxA];
    }
};