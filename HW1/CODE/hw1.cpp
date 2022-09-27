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

class Inputs
{
public:
    int inputIdx ,sideA ,sideB ,sideC;
    float area;
    Inputs(int _inputIdx, int _sideA, int _sideB, int _sideC, float _area):
        inputIdx(_inputIdx),
        sideA(_sideA),
        sideB(_sideB),
        sideC(_sideC),
        area(_area)
        {}

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
        inputLog.push_back(new Inputs(count, sideA, sideB, sideC, area));
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
            if(inputLog[j]->area > inputLog[j+1]->area){
                Inputs tmp = *inputLog[j];
                *inputLog[j] = *inputLog[j+1];
                *inputLog[j+1] = tmp;
            }
        }
    }

    printf("\tThe smallest triangle's area is %.2f with sides (%d, %d, %d)\n", inputLog[0]->area, inputLog[0]->sideA, inputLog[0]->sideB, inputLog[0]->sideC);
    printf("\tThe largest triangle's area is %.2f with sides (%d, %d, %d)\n", inputLog[count-1]->area, inputLog[count-1]->sideA, inputLog[count-1]->sideB, inputLog[count-1]->sideC);
    

    printf("Printing all inputs in this session\n=======================================================\n");
    for(auto ptr : inputLog){ //print all inputs in this session
        printf("\tInput #%d: sides(%d, %d, %d) with area %.2f\n", ptr->inputIdx, ptr->sideA, ptr->sideB, ptr->sideC, ptr->area);
        delete ptr; //deleting all heap-allocated pointers to prevent memory leak
    }
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

/*Replit https://replit.com/join/aemuvrnzpi-b10831020
Output MANUAL mode:
Student B10831020
Please choose whether to use automatically generated numbers as input?(1:Yes, 0:No)    0
Please input three values as the length of three sides
    23 64 76
    The area of this triangle is 5630.62
Please input three values as the length of three sides
    87 42 67
    The area of this triangle is 19096
Please input three values as the length of three sides
    87 34 69
    The area of this triangle is 12688
Please input three values as the length of three sides
    343 454 767
    The area of this triangle is 2.15988e+06
Please input three values as the length of three sides
    23 54 77
Incorrect side lengths for a triangle, terminating program
    The largest triangle's area is 5630.62 with sides (23, 64, 76)
    The smallest triangle's area is 2159880.00 with sides (343, 454, 767)
Printing all inputs in this session
=======================================================
    Input #0: sides(23, 64, 76) with area 5630.62
    Input #2: sides(87, 34, 69) with area 12688.00
    Input #1: sides(87, 42, 67) with area 19096.00
    Input #3: sides(343, 454, 767) with area 2159880.00

AUTOMODE:
Student B10831020
Please choose whether to use automatically generated numbers as input?(1:Yes,
0:No)   1 Generating side lengths from random numbers The sides are (5, 5, 2)
The area of this triangle is 4 Generating side lengths from random numbers The
sides are (2, 2, 3) The area of this triangle is 1.125 Generating side lengths
from random numbers The sides are (7, 7, 8) The area of this triangle is 48
Generating side lengths from random numbers
    The sides are (6, 6, 9) The area of this triangle is 30.375
Generating side lengths from random numbers
    The sides are (1, 1, 8)Incorrect side lengths for a triangle, terminating
program The largest triangle's area is 1.12 with sides (2, 2, 3) The smallest
triangle's area is 48.00 with sides (7, 7, 8) Printing all inputs in this
session
=======================================================
    Input #1: sides(2, 2, 3) with area 1.12
    Input #0: sides(5, 5, 2) with area 4.00
    Input #3: sides(6, 6, 9) with area 30.38
    Input #2: sides(7, 7, 8) with area 48.00
sh: 1: pause: not found
*/
