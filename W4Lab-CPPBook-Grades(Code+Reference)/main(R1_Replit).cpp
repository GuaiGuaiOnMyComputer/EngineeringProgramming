// ==========================================================================
// ME5015 StuID:NNNNNN     NAME::______________ 
// Software written by Boguslaw Cyganek (C) to be used with the book:
// INTRODUCTION TO PROGRAMMING WITH C++ FOR ENGINEERS
// ==========================================================================
// Revised ME5015-HW1ref:: for testing replit.com  (Date:2022-Sep-23)
// listing 3.2 in book (page. 53~ 56)
//
#include <vector>			// A header to use std::vector
#include <iostream>			// Headers for input and output
#include <iomanip>			// and output formatting
#include <cmath>			// For math functions

// Introduce these, to write vector instead of std::vector
using std::cout, std::cin, std::endl, std::vector; 

int main()
{

  cout << "(ME5015-CPPbook::R0)Enter your GPA grades:(1.0 ~5.0 max):" << endl;
  cout << "\n\tNote: If GPA grade < 2.0, DOWN. Not be counted !!" << endl;
  vector< double > studentGradeVec;	// An empty vector of doubles
  int stuCount =0;
	// Collect student's grades
	for( ;; )
	{
		double grade {};

		cin >> grade;

		// If ok, push new grade at the end of the vector
		if( grade >= 2.0 && grade <= 5.0 ){
      stuCount++;
			studentGradeVec.push_back( grade );
      } 
	  
		cout << "OK count="<< stuCount <<  "\tEnter more? [y/n] "; 
		char ans {};
		cin >> ans;

		if( ans == 'n' || ans == 'N' )
			break;		// the way to exit the loop
	}

	// Ok, if there are any grades compute the average
	if( studentGradeVec.size() > 0 )
	{
		double sum { 0.0 };
		// Add all the grades
		for( auto g : studentGradeVec )
			sum += g;
  
		double av = sum / studentGradeVec.size();

		double finalGrade {};

		// Let it adjust
		if( av < 3.0 )
		{
			finalGrade = 2.0;
		}
		else
		{
			double near_int = std::floor( av );	// get integer part
			double frac		= av - near_int;	// get only the fraction

			double adjust { 0.5 };	// new adjustment value

			if( frac < 0.25 )
				adjust = 0.0;
			else if( frac > 0.75 )
				adjust = 1.0;

			finalGrade = near_int + adjust;
		}
		cout << "\n\tNote: Lucky formula::: finalGrade = near_int + adjust\n ";
		cout	<< "Final grade: " 
			// 	<< std::fixed << std::setw( 3 ) << std::setprecision( 1 ) //ORG.mode
      	<< std::fixed << std::setw( 6 ) << std::setprecision( 2 ) 
				<< finalGrade << " Students Count="<< stuCount <<endl;
	}

	return 0;
}
/* --output 
(ME5015-CPPbook::R0)Enter your GPA grades:(1.0 ~5.0 max):

    Note: If GPA grade < 2.0, DOWN. Not be counted !!
4.67
OK count=1  Enter more? [y/n] y
5.999
OK count=1  Enter more? [y/n] y
4.95
OK count=2  Enter more? [y/n] y
1.5
OK count=2  Enter more? [y/n] y
3.99
OK count=3  Enter more? [y/n] y
4.6789
OK count=4  Enter more? [y/n] y
4.9
OK count=5  Enter more? [y/n] n

    Note: Lucky formula::: finalGrade = near_int + adjust
 Final grade:   4.50 Students Count=5
*/
