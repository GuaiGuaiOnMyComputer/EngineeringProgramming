# Homework 1


| 班級     |    學號   | 姓名    |
| :---:    |   :---:   | :---:  | 
| 四機械四乙| B10831020 | 吳宇昕  |
>日期 9/24/2022

## Task 1：三角形
>[Sorce Code](/HW1/hw1.cpp)以及
>[Replit網址](https://replit.com/join/aemuvrnzpi-b10831020)

>手動輸入三邊長之終端機輸出
>![手動輸入三邊長](/HW1/manual_console_output.png) 
>* 自動判斷三邊長是否合適。若三邊長為0、負數或長度無法組成三角形，程式終止
>* 當三邊長可組成三角形，計算並顯示其面積
>* 可以接收無限多筆輸入
>* 使用```while loop```


## Task２：使用```vector```儲存數據
>* 自動產生亂數作為三邊長
>* 自定義```class Inputs```儲存單筆輸入之三邊長與其三角形面積，並以```vector<Inputs*>```儲存各比輸入
>```c++
>class Inputs
>{
>public:
>    int inputIdx ,sideA ,sideB ,sideC;
>    float area;
>    Inputs(int _inputIdx, int _sideA, int _sideB, int _sideC, float _area):
>        inputIdx(_inputIdx),
>        sideA(_sideA),
>        sideB(_sideB),
>        sideC(_sideC),
>        area(_area)
>        {}
>
>    Inputs() = delete;
>};
>
>```
>* 使用```for loop```與‵```auto```印出所有資料
>```cpp
>for(auto ptr : inputLog){ //print all inputs in this session
>        printf("\tInput #%d: sides(%d, %d, %d) with area %.2f\n", ptr->inputIdx, ptr->sideA, ptr->sideB, ptr->sideC, ptr->area);
>```
