#include <iostream>
#include <vector>
#include <cmath>       //pow(), sqrt()

bool getUserInput(float *out_sides);
float getArea(const float* sides);

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
        float area = getArea(&sides[0]);
        inputLog.push_back(Inputs{inputCount, *sides, area});
        inputCount ++;
    }
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

class InputLogSort
{
public:
    InputLogSort(std::vector<Inputs>* sessionLog_ptr)
    {
        _sessionLog_ptr = sessionLog_ptr;  
        _sessionLog = *_sessionLog_ptr;
        _nRecords = sessionLog_ptr->capacity();
        _bubbleSort();
    }
private:
    std::vector<Inputs>* _sessionLog_ptr = nullptr;
    std::vector<Inputs> _sessionLog;
    int _nRecords;
    
    void _swap(int idxA, int idxB)
    {
        Inputs tmp = _sessionLog[idxA];
        _sessionLog[idxA] = _sessionLog[idxB];
        _sessionLog[idxB] = _sessionLog[idxA];
    }

    void _bubbleSort()
    {
        int i = 0, j = 0;
        for(i = 0; i<_nRecords-1; i++){
            while(j<_nRecords-i-1 && _sessionLog[j].area>_sessionLog[j+1].area)
                _swap(i, j);
        }
    }
};