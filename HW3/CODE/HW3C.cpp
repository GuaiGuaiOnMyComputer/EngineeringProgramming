#include <iostream>
int main()
{
    int arr[10];
    int* arr_ptr[10];

    arr[0] = 100;
    *arr_ptr[2] = 100;
    *arr_ptr[4] = 100;
    *arr_ptr[6] = 100;

    int* h_arr_ptr = new int[10];
    h_arr_ptr[3] = 10831020;
    h_arr_ptr[2] = 10831020;
    h_arr_ptr[8] = 10831020;
    delete[] h_arr_ptr;

    system("pause");
}