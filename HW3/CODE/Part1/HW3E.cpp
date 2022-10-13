void DoSomething(int& a, int& b)
{
    a = a+b;
}

int DoSomething(int a, int b)
{
    return a+b;
}

void DoSomething(int* a, int* b)
{
    *a = *a+*b;
}


int main()
{
    int a = 10831020;
    int b = 2;
    int result = DoSomething(a, b); //attempt to call version 1
    DoSomething(a, b);              //attempt to call version 2
    DoSomething(&a, &b);
    return 0;
}