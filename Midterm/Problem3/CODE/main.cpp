#include <iostream>
#include <iomanip>
#include "KellySimulator.hpp"

#define N_GAMES 3

void getUserInput(double&, double&);

int main()
{
    std::cout << "Student B10831020" << std::endl;
    double b, p;
    double budjet = 10000;
    for(int gameCount = 0; gameCount < N_GAMES; gameCount++){
        getUserInput(b, p);
        KellySimulator game(p, b, budjet);
        game.PlayGame(); // starts simulating 100 investments to a target
        budjet = game.GetFinalBudjet(); // set the budjet for the new game to the final budjet of this game
    }
    system("pause");
}

void getUserInput(double& b, double& p)
{
  int input;
  std::cout << "Here are some investment target you can choose from. Please input the index of the target" << std::endl;
  std::cout << std::setw(7) << "Target|" << std::setw(5) << 'b' << std::setw(5) << 'p' << "|" << std::endl;
  std::cout
       << std::setw(7) << "1|" << std::setw(5) << "1.5"  << std::setw(5) << "75%" << '|' << '\n'
       << std::setw(7) << "2|" << std::setw(5) << "1.4"  << std::setw(5) << "80%" << '|' << "(BEST)" << '\n'
       << std::setw(7) << "3|" << std::setw(5) << "10.0" << std::setw(5) << "51%" << '|' << "(Guess)"<< '\n'
       << std::setw(7) << "4|" << std::setw(5) << "4.6"  << std::setw(5) << "20%" << '|' << '\n'
       << std::setw(7) << "5|" << std::setw(5) << "0.4"  << std::setw(5) << "80%" << '|' << "(Better)" << '\n'
       << std::setw(7) << "0|" << std::setw(5) << "5.0"  << std::setw(5) << "50%" << '|' << std::endl;

  std::cin >> input;
  switch (input) {
    case 1:
      p = 0.75, b = 1.5;
      break;
    case 2:
      p = 0.80, b = 1.4; //(Bese FINAL )
      break;
    case 3:
      p = 0.51, b = 10.0;
      break;
    case 4: 
      p =0.2 , b=4.6; 
      break;
    case 7:
      p = 0.8, b = 0.4;
      break; // FIG1.Demo Data
    default:
      p = 0.50, b = 5.0;
      break;   
  }
  std::cout << "Target\t" << input << "\tis selected" << std::endl;
}

