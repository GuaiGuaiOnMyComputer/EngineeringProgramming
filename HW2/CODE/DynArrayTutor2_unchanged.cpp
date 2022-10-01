// Creating a dynamic array of integers and inserting values dynamically
// Test this at C++ tutor: https://pythontutor.com/visualize.html#mode=edit
// StuID:110xxxx   Name: 
// dynArrayTutor2.cpp 
#include <iostream>
#include <vector>
using namespace std; 
using std::vector;
  
void printPTR( int* passInVar, std::string msg1, std::string msg2, 
    int nCount=3 ){
  cout << msg1 << endl;
  for ( int ix=0 ; ix < nCount ; ++ ix) {
    cout <<  " index=" << ix << " -address "<< passInVar 
     << "\t dptr POINTED Value= " << *passInVar << endl;
    passInVar++;
 }
  cout << msg2 << endl;
}
 
int main()
{
  
  vector<int> dynArray (3); // dynamic array of int
  int n5Array[5] ={1111,2222,3333}; // add your StuID as Num#4
  dynArray[0] = 365;
  dynArray[1] = 254;
  dynArray[2] = 143;
 
  cout << "Number of integers in array: " << dynArray.size() << endl; 
  // set1 
  int* dptr = &dynArray[0];
  printPTR( dptr, "start 0", "set1", 3 );
  cout << "Enter another element to insert: " << endl;
  int newValue = 2220; // TODO: your stuID
  for ( int i=0; i<5; ++i){
    newValue = 1000+ i*10;
    dynArray.push_back(newValue);
  }
 dptr = &dynArray[3];
 cout << "pointered value = " << *dptr; 
 
 printPTR( dptr, "start 3", "New Added 5  elements?", 5 );  
  

  cout << "Number of integers in array: " << dynArray.size() << endl;
  cout << "Last element in array: ";
  cout << dynArray[dynArray.size() - 1] << endl;

  return 0;
}