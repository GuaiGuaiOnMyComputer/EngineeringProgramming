#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <array>

class PartTimeWorker
{
    int mEmpID;
    std::string mName;
    float mHourRate;
    int mHours;
    float mSalary;

public:
    PartTimeWorker(int empID, std::string name, float hourRate)
        :mEmpID(empID), mName(name), mHourRate(hourRate) {}

    PartTimeWorker(){} // dummy constructor
    
    void SetHours(int hours) 
    {
        if(hours <= 50 and hours > 0){
            this->mHours = hours;
            this->mSalary = this->mHourRate * this->mHours;
        }
        else
            std::cout << "Hour error" << std::endl;
    }

    friend std::ostream& operator<< (std::ostream& stream, const PartTimeWorker& worker);
};

std::ostream& operator<< (std::ostream& stream, const PartTimeWorker& worker)
{
    using namespace std;
    stream << "Name:" << setw(15) << right << worker.mName << "\tID" << setw(3) << worker.mEmpID << '\n'
        << '\t' << left << setw(14) << "salary" << worker.mSalary << '\n'
        << '\t' << left << setw(14) << "hour rate" << worker.mHourRate << '\n'
        << '\t' << left << setw(14) << "hours"  << worker.mHours;
    return stream;
}

int main()
{
    const int MAX_EMPLOYEE_COUNT = 8;
    PartTimeWorker employees[MAX_EMPLOYEE_COUNT];
    employees[0] = PartTimeWorker(0, "Eric", 100);
    employees[0].SetHours(15); // PartTimeWorker::SetHours() also calculates and sets the salary of each instance
    employees[1] = PartTimeWorker(1, "NotEric", 110);
    employees[1].SetHours(18);
    employees[2] = PartTimeWorker(2, "NotNotEric", 120);
    employees[2].SetHours(20);
    employees[2] = PartTimeWorker(3, "Erica", 138);
    employees[2].SetHours(34);
    employees[3] = PartTimeWorker(4, "NotErica", 140);
    employees[3].SetHours(47);

    for(int i = 0; i < 4; i++){
        std::cout << employees[i] << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
    }
    system("pause");
}

/*
Replit: https://replit.com/@b10831020/HW5-2#main.cpp
Name:           Eric    ID  0
        salary        1500
        hour rate     100
        hours         15
-----------------------------------------
Name:        NotEric    ID  1
        salary        1980
        hour rate     110
        hours         18
-----------------------------------------
Name:          Erica    ID  3
        salary        4692
        hour rate     138
        hours         34
-----------------------------------------
Name:       NotErica    ID  4
        salary        6580
        hour rate     140
        hours         47
-----------------------------------------
Press any key to continue . . . 
*/