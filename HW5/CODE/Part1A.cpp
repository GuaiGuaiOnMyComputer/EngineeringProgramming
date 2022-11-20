#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <array>

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

    float GetSalary() const {return this->Salary;}

    friend std::ostream& operator<< (std::ostream& stream, const PartTimeWorker& worker);

};

std::ostream& operator<< (std::ostream& stream, const PartTimeWorker& worker)
{
    using namespace std;
    stream << "Name" << setw(15) << worker.Name << "\tID" << setw(3) << worker.EmpID << '\n'
        << "\tsalary" << setw(9) << worker.Salary << '\n'
        << "\thour rate" << setw(6) << worker.HourRate << '\n'
        << "\tHours" << setw(10) << worker.Hours;
    return stream;
}

int main()
{
    const int MAX_EMPLOYEE_COUNT = 8;
    std::array<PartTimeWorker, MAX_EMPLOYEE_COUNT> employees;
    employees[0] = {0, "Eric", 100, 0, 0};
    employees[0].SetHours(15); // PartTimeWorker::SetHours() also calculates and sets the salary of each instance
    employees[1] = {1, "NotEric", 110, 0, 0};
    employees[1].SetHours(18);
    employees[2] = {2, "NotNotEric", 120, 0, 0};
    employees[2].SetHours(20);

    float totalSalary = 0;
    for(int i = 0; i < 3; i++){
        std::cout << employees[i] << std::endl;
        totalSalary += employees[i].GetSalary();
        std::cout << "-----------------------------------------" << std::endl;
    }
    std::cout << "Total salary:" << std::setw(8) << std::setprecision(6) << totalSalary << std::endl;
    system("pause");
}

/*
Replit: https://replit.com/@b10831020/Midterm-Paper-Test-1#main.cpp
 ./main
Name           Eric ID  0
    salary     1500
    hour rate   100
    Hours        15
-----------------------------------------
Name        NotEric ID  1
    salary     1980
    hour rate   110
    Hours        18
-----------------------------------------
Name     NotNotEric ID  2
    salary     2400
    hour rate   120
    Hours        20
-----------------------------------------
Total salary:    5880
sh: 1: pause: not found
*/