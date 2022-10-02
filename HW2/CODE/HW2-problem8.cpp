#include <iostream>

void modifyArr(int _arr[], int count)
{
    for(int i=0; i<count; i++){
        _arr[i] = 0;
    }
}

void displayArr(int _arr[], int count)
{
    for(int i=0; i<count; i++)
        std::cout << _arr[i] << std::endl;
}

int main()
{
    int myInts[] = {32, 35, 67, 99, 3, 66};
    modifyArr(myInts, 6);
    displayArr(myInts, 6);
    system("Pause");
    return 0;
}