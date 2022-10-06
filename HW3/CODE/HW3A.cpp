int main()
{
    int number = 10831020;
    const int* number_ptr = &number;
    mutable int* another_ptr = number_ptr;
}