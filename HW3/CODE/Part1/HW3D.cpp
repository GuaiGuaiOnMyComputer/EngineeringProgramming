#include <iostream>

using namespace std;

int main() {
  cout << "Student B10831020" << endl;
  int number = 10831020;
  int* number_ptr = &number;
  int* number_ptr2 = number_ptr;
  
  cout << "Printing all 3 symbols of number: " <<endl;
  cout << '\t' << "&number\t\t\t" << "*number\t\t\t" << "number" << endl;
  cout << '\t' << &number << "\t\t" << "N/A" << "\t\t\t" << number << endl;
  
  cout << "Printing all 3 symbols of number_ptr: " << endl;
  cout << '\t' << "&number_ptr\t\t" << "*number_ptr\t\t" << "number_ptr" << endl;
  cout << '\t' << &number_ptr << "\t\t" << *number_ptr << "\t\t" << number_ptr << endl;
  
  return 0;
}

 /*
 Replit: https://replit.com/join/rbiugzgkui-b10831020
 Student B10831020
Printing all 3 symbols of number:
        &number                 *number                 number
        0x61fef8                N/A                     10831020
Printing all 3 symbols of number_ptr:
        &number_ptr             *number_ptr             number_ptr
        0x61fef4                10831020                0x61fef8
 */