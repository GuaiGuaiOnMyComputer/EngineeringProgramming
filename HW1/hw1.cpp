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
    int _inputIdx ,_sideA ,_sideB ,_sideC;
    float _area;
    Inputs(int inputIdx, int sideA, int sideB, int sideC, float area):
        _inputIdx(inputIdx),
        _sideA(sideA),
        _sideB(sideB),
        _sideC(sideC),
        _area(area)
        {}

    Inputs() = delete;
};

int main()
{
    int count = 0;
    std::vector<Inputs*> inputLog(10);
    int sideA, sideB, sideC;

    while(getUserInput(sideA, sideB, sideC)){
        float area = getArea(sideA, sideB, sideC);
        inputLog.push_back(new Inputs(count, sideA, sideB, sideC, area));
        count ++;
    }

    //bubble sort
    int i = 0, j = 0;
    for(i = 0; i<count-1; i++){
        while(j<count-i-1 && inputLog[j]->_area > inputLog[j+1]->_area){
            Inputs tmp = *inputLog[j];
            *inputLog[j] = *inputLog[i];
            *inputLog[i] = *inputLog[j];
            j++;
        }
    }

    std::cout << "The triangle with the smallest area is " << inputLog[0]->_area << "with sides" << '(' << inputLog[0]->_sideA << ", " << inputLog[0]->_sideB << ", " << inputLog[0]->_sideC << ")" << std::endl;
    std::cout << "And the triangle with the largest area is" << inputLog[count-1]->_area << "with sides" << "( " << inputLog[count-1]->_sideA << ", " << inputLog[count -1]->_sideB << ", "  << inputLog[count-1]->_sideC << ')' << std::endl;
    for(auto ptr : inputLog) //delete all heap pointers to prevent memory leak
        delete ptr;
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
