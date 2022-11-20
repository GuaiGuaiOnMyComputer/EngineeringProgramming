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

    void SetHours(int hours) 
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
    const int MAX_EMPLOYEE_COUNT = 8;
    PartTimeWorker employees[MAX_EMPLOYEE_COUNT];
    employees[0] = {0, "Eric", 100, 0, 0};
    employees[0].SetHours(15); // PartTimeWorker::SetHours() also calculates and sets the salary of each instance
    employees[1] = {1, "NotEric", 110, 0, 0};
    employees[1].SetHours(18);
    employees[2] = {2, "NotNotEric", 120, 0, 0};
    employees[2].SetHours(20);

    // Overwrites employees[2]
    employees[2] = {3, "Erica", 138, 0, 0};
    employees[2].SetHours(34);

    // New employees[3]
    employees[3] = {4, "NotErica", 128, 0, 0};
    employees[3].SetHours(47);

    for(int i = 0; i < 4; i++){
        std::cout << employees[i] << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
    }
    system("pause");
}