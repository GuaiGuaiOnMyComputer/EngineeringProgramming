# Problem 4

|姓名|學號|日期|
|:---:|:---:|:---:|
|吳宇昕|B10831020|2022/11/8|

> OOP挑戰題，將過去作業四的complex struct matrix改以class方式呈現

[sorce code](CODE/Problem4.cpp) and [replit](https://replit.com/join/cgebjnbftu-b10831020)

## 終端機輸出
程式可以在終端機執行時輸入四個command line argument浮點數作為隨機複數實部與虛部的上下限，也可以執行程式後依提示設定。下圖以輸入command line argument為例。

![terminal output wihth command line arguments](IMG/terminal%20output%20comand%20line%20arg.png)

照老師的建議，用```std::setw()```為輸出數值預留版面，讓終端機輸出看起來更順眼整齊。

## Operator Overload
二維複數陣列class名稱為```CplxMatrix```，為此class自行定義+、-與ostream operator的<<三種operator overload。

+與-定義如下，為```class CplxMatrix```的public method

![+-operator overload](IMG/%2B-operator%20overload.png)

ostream << 定義如下

位於```class CplxMatrix```的public區域

![friend operator](IMG/friend%20ostream%20operaotr.png)

位於```class CplxMatrix```之外

![ostream operator body](IMG/ostream%20operator%20body.png)

這次自行定義ostream operator才知道C++還有個關鍵字叫做```friend```，修飾一個class之外的function或operator，讓非class內的函式讀寫class的private member。

## 心得
這份題目需整合第三方的Complex API，且練習以OOP語法定義虛數陣列。有感覺到自定義簡單算數運算子帶來的方便性，讓兩個虛數陣列相加減的程式碼看起來更直觀易懂。

同時有學到一個vector的新函式。過去我們使用```push_back()```將原始資料型別的元素加進一個vector讓它增長。但是若要把一個class instance加入一條vector，用另一個函式```emplace_back()```更為理想。

過去我們的做法是這樣：
```c++
#include <complex>
#include <vector>
int main(){
    std::vector<std::complex<int>> vtr; // create a vector contain float complexes
    vtr.push_back(std::complex<int>(1, 2)) // push 1+j2 into the vector
}
```
這種寫法，會在main()的stack frame裡創建一個complex instance，並複製此instance到vector裡，捨棄原本創進的complex instance。

比較好的做法應該是
```c++
    vtr.emplace_back(1, 2) // push 1+j2 into the vector
```

```emplace_back()```函式會自動把傳入的參數導引至complex的constructor，呼叫constructor並直接把得到的instance存入vector的記憶體中，不須複製。同時也會讓vector增長，幾乎與```push_back()```有同樣的效果，但是處理class instance時效能更好。