#include <iostream>
#include <vector>
#include <cmath>       //pow(), sqrt()

bool getUserInput(float *out_sides);
float getArea(const float* sides);
class InputLogSort;

struct Inputs
{
    int inputIdx;
    float sides[3];
    float area;
};

int main()
{
    int inputCount = 0;
    std::vector<Inputs> inputLog(10);
    float sides[3];

    while(getUserInput(&sides[0])){
        if(inputCount == 0 && sides[0] == 0 && sides[1] == 0 && sides[2] == 0){
            //prevent the user from breaking the program by entering 0, 0, 0 at the 0th input, segfaultting the program
            std::cout << "You didn't input any valid values before terminating the program" << std::endl;
            return 0;
        }
        float area = getArea(&sides[0]);
        inputLog.push_back(Inputs{inputCount, *sides, area});
        inputCount ++;
    }

    InputLogSort sortSessionLog = InputLogSort(&inputLog);
    sortSessionLog.bubbleSort();

    printSortedResult(&inputLog);    
    return 0;
}


float getArea(const float* sides)
{   //takes in the pointer to the first element of array and offset using index
    float halfPerimeter = (sides[0] + sides[1] + sides[2]) / 2;
    return sqrt(pow(sides[0]-halfPerimeter, 2) * pow(sides[1]-halfPerimeter, 2) * pow(sides[2]-halfPerimeter, 2));
}

bool getUserInput(float* out_sides)
{
    //takes in a pointer to an float array to store user inputs
    //returns false and breaks loop when input is 0, 0, 0
    std::cout << "Please input three values as the length of three sides" <<std::endl;
    std::cin >> out_sides[0] >> out_sides[1] >> out_sides[2];
    return !(out_sides == 0 && out_sides[1] == 0 && out_sides[2] == 0);
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