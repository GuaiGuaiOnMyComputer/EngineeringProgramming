#include <iostream>
#include <vector>

using namespace std;

void printPtrArray(int* ptr, string msg, bool checkFlag)
{
    cout << msg << endl;
    for (int i=0; i<10; i++){
        cout << *(ptr + i) << ',';
    }
    cout << endl;
}

int main() 
{
    int arr[10];
    int *ptr = new int[10];
    cout << "ME5015 Week2 Demo-VECTOR: Pointer" << endl;
    for (int i=0; i<10; i++){
        ptr[i] = i*10;
    }
    printPtrArray(ptr, "Print Out ::Original Array", false);
    printPtrArray(ptr, "Print Out ::Modified Array", true);

    vector<int> data{1, 2, 3};
    cout << "\n\tDemo-VECTOR :Accessing AUTO" << endl;
    for (auto x : data) {
        cout << x << ' ';
    }
    auto it = data.begin();
    //cout << *it;
    ++it;

    --it;
    it = it + 5;
    //Delete
    it = data.begin();
    data.erase(it);
    cout << endl;
    for (auto x : data){
        cout << x << ' ';
    }
    return 0;
}