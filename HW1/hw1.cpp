#include <iostream>
#include <vector>
#include <cmath>       //pow(), sqrt()

class Inputs;
bool getUserInput(int& out_sideA, int& out_sideB, int& out_sideC);
float getArea(const int& sideA, const int& sideB, const int& sideC);
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
        {
            this->_inputIdx = inputIdx;
            this->_sideA = sideA;
            this->_sideB = sideB;
            this->_sideC = sideC;
            this->_area = area;
        }

    Inputs() = delete;
};

int main()
{
    int count = 0;
    std::vector<Inputs*> inputLog;
    int sideA, sideB, sideC;

    while(getUserInput(sideA, sideB, sideC)){
        float area = getArea(sideA, sideB, sideC);
        inputLog.push_back(new Inputs(count, sideA, sideB, sideC, area));
        count ++;
    }
    if(count == 0){
        //Prevent segfault if user terminates the program on the 0th input
        std::cout << "You didn't input any valid values" << std::endl;
        return 0;
    }
    //bubble sort inputLog according to the area of each triangle in ascending order
    int i, j;
    for(i = 0; i<count-1; i++){
        for(j=0; j<count-i-1; j++){
            if(inputLog[j]->_area > inputLog[j+1]->_area){ //this segfaults? WTF?
                Inputs tmp = *inputLog[j];
                *inputLog[j] = *inputLog[j+1];
                *inputLog[j+1] = tmp;
            }
        }
    }

    std::cout << "\tThe triangle with the smallest area is " << inputLog[0]->_area << " with sides " << '(' << inputLog[0]->_sideA << ", " << inputLog[0]->_sideB << ", " << inputLog[0]->_sideC << ")" << std::endl;
    std::cout << "\tAnd the triangle with the largest area is " << inputLog[count-1]->_area << " with sides " << '(' << inputLog[count-1]->_sideA << ", " << inputLog[count -1]->_sideB << ", "  << inputLog[count-1]->_sideC << ')' << std::endl;
    for(auto ptr : inputLog) //delete all heap pointers to prevent memory leak
        delete ptr;
    system("pause"); //press any key to continue
    return 0;
}


float getArea(const int& sideA, const int& sideB, const int& sideC)
{   //takes in the pointer to the first element of array and offset using index
    float halfPerimeter = (sideA + sideB + sideC) / 2.0;
    float area = sqrt(pow(sideA-halfPerimeter, 2) * pow(sideB-halfPerimeter, 2) * pow(sideC-halfPerimeter, 2));
    std::cout << '\t' << "The area of this triangle is " <<  area << std::endl;
    return area;
}

bool getUserInput(int& out_sideA, int& out_sideB, int& out_sideC)
{
    //takes in an int reference to store user inputs
    //returns false and breaks loop when input is (0, 0, 0), receives negative numbers or a triangle cannot be formed
    std::cout << "Please input three values as the length of three sides" <<std::endl;
    std::cout << '\t';
    std::cin >> out_sideA >> out_sideB >> out_sideC;
    if(out_sideA <= 0 || out_sideB <= 0 || out_sideC <= 0){
        std::cout << "At least one side is smaller or equal to 0, terminating program." << std::endl;
        return false;
    }
    if(out_sideA+out_sideB<=out_sideC || out_sideB+out_sideC<=out_sideA || out_sideA+out_sideC<=out_sideB){
        std::cout << "Incorrect side lengths for a triangle, terminating program" << std::endl;
        return false;
    }
    return true;
}
