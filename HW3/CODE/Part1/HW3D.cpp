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