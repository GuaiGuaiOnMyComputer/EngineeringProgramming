#include <iostream>  //std::cout, std::cin
#include <cmath>     //pow(), sqrt()
#include <vector>    //std::vector

bool getUserInput(double &out_x, double &out_y)
{
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
    int count = 0;
    double input_x, input_y;
    double shortestDist;
    int shortestRound;
    const int x0 = 0, y0 = 0;
    std::vector<Stats> record(5);
    std::cout << "Delivery person takes unlimited orders until input 0 0" << std::endl;

    while (getUserInput(input_x, input_y)) {
        double distance = sqrt(pow(input_x - x0, 2) + pow(input_y - y0, 2));
        std::cout << "\tThe distance from origin (0, 0) to (" << input_x << ", " << input_y << ") is " << distance << std::endl;
        Stats userInput = {count, input_x, input_y, distance};
        record.push_back(userInput);
        if(count == 0){
            shortestDist = distance;
            shortestRound = count;
        }else{
            if(distance < shortestDist){
                shortestDist = distance;
                shortestRound = count;
            }
        }
        count ++;
    }

    std::cout << "The shortest distance is " << shortestDist << " from (" << record[shortestRound].in_x << ", " << record[shortestRound].in_y << ")" << std::endl;
    return 0;
}