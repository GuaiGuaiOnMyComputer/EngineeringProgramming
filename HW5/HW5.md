# HW5 期中考重做
 |  班級   | 姓名 |  學號   |   日期   |
 |   :---: | :---:|  :---:  |:---: |
 |四機械四乙|吳宇昕|B10831020|11/20/2022|

## 1. Getter與Setter意義
[sorce code](CODE/Part1A.cpp) and [replit](https://replit.com/@b10831020/HW5-Redomidterm-1A#main.cpp)

a. 在c++情境下，請說明getter與setter之意義，並以下列兩實做項來說明
> class內變數的accessibility預設為private，不可被class外的程式讀寫，達到information hiding的作用。
>
> 然而若有需求，必須在class外（例如main函式裡）讀寫class member的值，與其直接把該class member移至public區域，失去information hiding的設計，我們可以設定一個在class內的public函式，專門讀寫特定class member的值。讀取member值的函式稱為getter，而寫入member值的函式稱為setter。
>
> 如此一來，class member既沒有失去information hiding，又可以在需要的時候被class外的程式讀寫。

b. 若有工讀生之薪資結構，請寫出其適用的struct定義
```c++
struct PartTimeWorker
{
    int EmpID;
    std::string Name;
    float HourRate;
    int Hours;
    float Salary;
}
```
c. 以setter對hours欄位賦值，且檢驗是否介於0到50的正整數
```c++
void PartTimeWorker::SetHours(int hour)
{
  if(hour > 0 and hour < 50) {
  this->Hours = hour
  }else{
      std::cout << "Hour error" << std::endl;
  }
}
```
d. 以getter取得Salary值
```c++
// 假設已經在別處算好某個員工的salary值
void PartTimeWorker::GetSalary()
{
    return this->Salary;
}
```
e. 在主程式裡定義8位工讀生的的陣列，設定其中三個個員工初值，並累計及列印三個人的個人紀錄及薪資和
```c++
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
        std::cout << employees[i] << std::endl; # ostream operator overload defined
        totalSalary += employees[i].GetSalary();
        std::cout << "-----------------------------------------" << std::endl;
    }
    std::cout << "Total salary:" << std::setw(8) << std::setprecision(6) << totalSalary << std::endl;
    system("pause");
}
```

## 2. 參數傳遞概念
a. 說明pass-by-reference與pass-by-value的使用時機與用途
> 函式參數可以選擇傳入引數的值，或傳入引數的reference，即記憶體位置。
> 若函式只需要接收參數的數值進行運算，可以將引數值用pass by value的參數傳入函式。函式內的參數為引數值的副本，因此修改該參數不會影響在函式外被當作引數傳入的變數。pass by value用在函式不希望修改函式外的變數的場合
> 
> pass by reference會傳進某個函式外變數的記憶體位置(reference)，而不是複製其值給函式內的參數產生副本。若函式需要輸出多個計算結果，可以給它pass by reference的參數，將計算結果寫入函式外的某個變數的記憶體位置。
>
> 由於pass by value需要複製變數值，若參數是個龐大的物件，過度使用pass by value會使程式效能較差。此時就可以考慮用pass by reference傳入引數的記憶體位置，避免複製值。若想必免在函式裡修改該參數，則可以使用pass by const reference。

b. 請以"累加總薪資"為目標，寫出以"員工salary陣列"當作輸入參數的函式
```c++
float salarySum(float individualSalary[], int employeeCount)
{
    float sum = 0
    for(int i = 0; i < employeeCount; i++){
        sum += individualSalary[i];
    }
    return sum;
}
```

## 3. 動態向量列印技巧
a. 員工數不固定，改以vector方式代替array(max = 8)
```c++
int main()
{
    std::vector<PartTimeWorker> employees();
    employees.reserve(8);
    employees.push_back({0, "Eric", 100, 0, 0});
    employees.push_back({1, "NotEric", 106, 0, 0});
    employees.push_back({2, "NotNotEric", 158, 0, 0});

    if(employees.size() > 8){
        std::cout << "冗員太多囉" << std::endl;
        return -1;
    }
    return 0;
}
```
b. 有技巧的用for迴圈列印全部員工的姓名、時數與薪資
```c++
for(const auto& worker : employees){
    std::cout << worker << std::endl; // ostream operator defined in problem 1e
}
```

# 第1A階段
用structure的方式重做1e

[sorce code](CODE/Part1A.cpp) and [replit](https://replit.com/@b10831020/HW5-Redomidterm-1A#main.cpp)

