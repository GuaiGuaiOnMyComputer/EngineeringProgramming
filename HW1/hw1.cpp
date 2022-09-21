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
    InputLogSort(std::vector<Inputs>* sessionLog)
    {
        _sessionLog = sessionLog;
    }
private:
    std::vector<Inputs>* _sessionLog = nullptr;
};