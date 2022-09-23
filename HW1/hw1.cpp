#include <stdio.h>     //prinf()
#include <cmath>       //pow(), sqrt()
#include <iostream>    //system("pause")
#include <chrono>      //time.now()
#include <cstdlib>     //rand() srand()
#include <vector>

class Inputs;
bool getInput(int& out_sideA, int& out_sideB, int& out_sideC, bool autoRandom);
bool checkInput(const int& sideA, const int& sideB, const int& sideC);
float getArea(const int& sideA, const int& sideB, const int& sideC);
void printSortedResult(const std::vector<Inputs>& sessionLog);


class Inputs
{
public:
    int inputIdx ,sideA ,sideB ,sideC;
    float area;
    Inputs(int _sideA, int _sideB, int _sideC, float _area):
        sideA(_sideA),
        sideB(_sideB),
        sideC(_sideC),
        area(_area)
        {
            this->sideA = _sideA;
            this->sideB = _sideB;
            this->sideC = _sideC;
            this->area = _area;
        }

    Inputs() = delete;
};

int main()
{
    int count = 0;
    std::vector<Inputs*> inputLog;
    int sideA, sideB, sideC;
    int autoRandom;

    std::cout << "Student B10831020" << std::endl;
    std::cout << "Please choose whether to use automatically generated numbers as input?(1:Yes, 0:No)\t";
    std::cin >> autoRandom;

    while(getInput(sideA, sideB, sideC, autoRandom)){
        float area = getArea(sideA, sideB, sideC);
        inputLog.push_back(new Inputs(sideA, sideB, sideC, area));
        count ++;
    }
    if(count == 0){
        //Prevent segfault if user terminates the program on the 0th input
        std::cout << "You didn't input any valid values" << std::endl;
        system("pause");
        return 0;
    }
    //bubble sort inputLog according to the area of each triangle in ascending order
    int i, j;
    for(i = 0; i<count-1; i++){
        for(j=0; j<count-i-1; j++){
            if(inputLog[j]->area > inputLog[j+1]->area){ //this segfaults? WTF?
                Inputs tmp = *inputLog[j];
                *inputLog[j] = *inputLog[j+1];
                *inputLog[j+1] = tmp;
            }
        }
    }

    printf("\tThe largest triangle's area is %.2f with sides (%d, %d, %d)\n", inputLog[0]->area, inputLog[0]->sideA, inputLog[0]->sideB, inputLog[0]->sideC);
    printf("\tThe smallest triangle's area is %.2f with sides (%d, %d, %d)\n", inputLog[count-1]->area, inputLog[count-1]->sideA, inputLog[count-1]->sideB, inputLog[count-1]->sideC);
    
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

bool getInput(int& out_sideA, int& out_sideB, int& out_sideC, bool autoRandom)
{
    //returns false and breaks lop when input is (0, 0, 0), program receives negative numbers or a triangle cannot be formed
    if(!autoRandom){
        std::cout << "Please input three values as the length of three sides" <<std::endl;
        std::cout << '\t';
        std::cin >> out_sideA >> out_sideB >> out_sideC;
    }else{
        std::cout << "Generating side lengths from random numbers" << std::endl;
        std::cout << '\t';
        auto currentTimeStamp = std::chrono::steady_clock::now().time_since_epoch().count();
        srand((uint64_t)currentTimeStamp);
        out_sideA = abs(rand() % 10);
        out_sideB = abs(rand() % 10);
        out_sideC = abs(rand() % 10);
        printf("The sides are (%d, %d, %d)", out_sideA, out_sideB, out_sideC);
    }
    return checkInput(out_sideA, out_sideB, out_sideC);
}

bool checkInput(const int& sideA, const int& sideB, const int& sideC)
{
    if(sideA <= 0 || sideB <= 0 || sideC <= 0){
        std::cout << "At least one side is smaller or equal to 0, terminating program." << std::endl;
        return false;
    }
    if(sideA+sideB<=sideC || sideB+sideC<=sideA || sideA+sideC<=sideB){
        std::cout << "Incorrect side lengths for a triangle, terminating program" << std::endl;
        return false;
    }
    return true;
}
