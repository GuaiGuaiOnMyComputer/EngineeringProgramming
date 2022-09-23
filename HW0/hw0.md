# Homework 0

| 班級     |    學號   | 姓名    |
| :---:    |   :---:   | :---:  | 
| 四機械四乙| B10831020 | 吳宇昕  |
>日期 9/24/2022
## Task3：外送員
>[Sorce Code](/hw0/hw0A.cpp)以及[Replit網址]()
>
>* 手動輸入座標終端機輸出
>![外送員終端機輸出](/HW0/delivery_person_console_output.png)
> * 自定義```struct Stats```存放每筆輸入資料
> ```c++
>struct Stats
>{
>    int count;
>    double in_x, in_y, distance;
>};
>```
> * 用```vector<Stats>```儲存每筆輸入與距離，可以容納無數筆輸入
> * 當輸入為```0 0```結束程式並顯示最短距離與出發座標
> * 利用pass by reference從函式輸出變數值
> ```c++
> bool getUserInput(double &out_x, double &out_y)
>{
>    //get user input and store into out_x and out_y by reference
>    //returns false when user input is 0 0
>    //otherwise returns true
>    std::cout << "Input the coordinates of the destination" << std::endl;
>    std::cout << '\t';
>    std::cin >> out_x >> out_y;
>    return !(out_x == 0 && out_y==0);
>}
> ```