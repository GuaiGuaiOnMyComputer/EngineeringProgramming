#include <iostream>

uint64_t getFibNumber(int);

int main()
{
    int index;
    std::cout << "Enter a 0-based index of a Fib number\t";
    std::cin >> index;
    std::cout << "The Fib number is " << getFibNumber(index) << std::endl;
    system("pause");
}

uint64_t getFibNumber(int _index)
{
    if(_index < 2)
        return _index;
    else
        return getFibNumber(_index-1) + getFibNumber(_index-2);
}