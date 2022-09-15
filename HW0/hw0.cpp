#include <iostream>  //std::cout, std::cin
#include <cmath>     //pow(), sqrt()
#include <vector>    //std::vector

bool getUserInput(double &out_x, double &out_y)
{
    //get user input and store into out_x and out_y by reference
    //returns false when user input is 0 0
    //otherwise returns true
    std::cout << "Input the coordinates of the destination" << std::endl;
    std::cin >> out_x >> out_y;
    return !(out_x == 0 && out_y==0);
}

struct Stats
{
    int count;
    double in_x, in_y, distance;
};



int main()
{
    int count = 0; //number of user inputs
    double input_x, input_y;
    double shortestDist;
    int shortestRound; //index of the user input resulting the shortest distance
    const int x0 = 0, y0 = 0; //coordinance of the origin
    std::vector<Stats> record;
    std::cout << "Delivery person takes unlimited orders until input 0 0" << std::endl;

    while (getUserInput(input_x, input_y)) { //condition is false when user input is 0 0 and loop stops
        double distance = sqrt(pow(input_x - x0, 2) + pow(input_y - y0, 2));
        std::cout << "\tThe distance from origin (0, 0) to (" << input_x << ", " << input_y << ") is " << distance << std::endl;
        Stats userInput; //store the user inputs, its index and the resulting distance in a custom struce
        userInput.count = count;
        userInput.distance = distance;
        userInput.in_x = input_x;
        userInput.in_y = input_y;
        record.push_back(userInput); //put the struct into an growing array
        if(count == 0){ //put the zeroth user input into comparison for the later ones
            shortestDist = distance;
            shortestRound = count;
        }
        else{ 
            if(distance < shortestDist){ //comparint the latest user input to the one with currently the shortest distance
                shortestDist = distance;
                shortestRound = count;
            }
        }
        count ++;
    }

    std::cout << "The shortest distance is " << shortestDist << " from (" << record[shortestRound].in_x << ", " << record[shortestRound].in_y << ")" << std::endl;
    return 0;
}