#include <iostream>

int main()
{
    int& a;
    int t1, t2, t3;
    t1 = a+1;
    t2 = &a+1;
    t3 = *a+1;
}