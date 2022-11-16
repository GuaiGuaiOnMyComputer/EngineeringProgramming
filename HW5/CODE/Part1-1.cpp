#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>

struct PartTimeWorker
{
    int EmpID;
    std::string Name;
    float HourRate;
    int Hours;
    float Salary;

    void SetHOurs(int hours) 
    {
        if(hours <= 50 and hours > 0)
            this->Hours = hours;
        else
            std::cout << "Hour error" << std::endl;
        this->Salary = this->HourRate * this->Hours;
    }

    friend std::ostream& operator<< (std::ostream& stream, const PartTimeWorker& worker);

};

std::ostream& operator<< (std::ostream& stream, const PartTimeWorker& worker)
{
    using namespace std;
    stream << "Name" << setw(15) << worker.Name << "\tID" << setw(3) << worker.EmpID << '\n'
        << "\tsalary" << setw(9) << worker.Salary << '\n'
        << "\thour rate" << setw(6) << worker.HourRate << '\n'
        << "\tHours" << setw(10) << worker.Hours;
}

int main()
{
    int maxEmployee = 8;
    PartTimeWorker* employees = new PartTimeWorker[maxEmployee];
    employees[0] = {0, "Eric", 100, 0, 0};
    employees[0].SetHOurs(15); // PartTimeWorker::SetHours() also calculates and sets the salary of each instance
    employees[1] = {1, "NotEric", 110, 0, 0};
    employees[1].SetHOurs(18);
    employees[2] = {2, "NotNotEric", 120, 0, 0};
    employees[2].SetHOurs(20);

    for(int i=0; i<3; i++){
        std::cout << employees[i] << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
    }
    delete[] employees;
    system("pause");
}