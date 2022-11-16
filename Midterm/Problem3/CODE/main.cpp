#include <iostream>
#include <iomanip>
#include "KellySimulator.hpp"

#define N_GAMES 3

void getUserInput(double&, double&, double&);

int main()
{
    std::cout << "Student B10831020" << std::endl;
    double p, percentRise, percentFall;
    double budjet = 10000;
    for(int gameCount = 0; gameCount < N_GAMES; gameCount++){
        getUserInput(p, percentRise, percentFall);
        KellySimulator game(p, percentRise, percentFall, budjet);
        game.PlayGame(); // starts simulating 30 investments to a target
        budjet = game.GetFinalBudjet(); // set the budjet for the new game to the final budjet of this game
    }
    system("pause");
}

void getUserInput(double& p, double& percentRise, double& percentFall)
{
  using namespace std;
  int input;
  cout << setw(65) << left << "Please input the winning probability [0, 1] (P)";
  cin >> p;
  if(p > 1 or p < 0){
    cout << "The value of p is incorrect, must be in [0, 1]" << endl;
    getUserInput(p, percentRise, percentFall);
  }
  cout << setw(65) << left << "Please input the percent increase";
  cin >> percentRise;
  cout << setw(65) << left << "Please input the percent decrease";
  cin >> percentFall;
}

