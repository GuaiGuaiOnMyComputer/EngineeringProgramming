#include <chrono>
#include <iostream>
#include <vector>
using namespace std::literals::chrono_literals;

void passedByValue(std::vector<double> _largeVtr)
{
    for(int i=0; i<_largeVtr.capacity(); i++)
        _largeVtr[i] = 10831020;
}

void passedByRef(std::vector<double>& _largeVtr)
{
    for(int i=0; i<_largeVtr.capacity(); i++)
        _largeVtr[i] = 10831020;
}

void getResult(double _refTime[], double _valTime[])
{
    double avgRefTime = 0, avgValTime = 0;
    for(int i=0; i<1000; i++){
        avgRefTime = avgRefTime + _refTime[i];
        avgValTime = avgValTime + _valTime[i];
    }
    avgRefTime = avgRefTime / 1000;
    avgValTime = avgValTime / 1000;

    std::cout << "Average pass-by-value time" << avgValTime << std::endl;
    std::cout << "Average pass_by_reference time" << avgRefTime << std::endl;
    std::cout << "Average difference" << avgRefTime - avgValTime;
}

int main()
{
    printf("Student B10831020\n");
    double duration_ref[10000];
    double duration_val[10000];
    for (int i=0; i<1000; i++){
        std::vector<double> largeVtr(1000000);
        auto start = std::chrono::high_resolution_clock::now();
        passedByRef(largeVtr);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        duration_ref[i] = duration.count();
    }
    for (int i=0; i<1000; i++){
        std::vector<double> largeVtr(1000000);
        auto start = std::chrono::high_resolution_clock::now();
        passedByValue(largeVtr);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        duration_val[i] = duration.count();
    }
    getResult(duration_val, duration_ref);
}
/*
Replit: https://replit.com/join/wogevlomwv-b10831020

Output:
./main
Average pass-by-value time0.000555755
Average pass_by_reference time0.00887268

*/