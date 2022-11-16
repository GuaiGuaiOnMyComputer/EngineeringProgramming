# Kelly Simulator
 |  班級   | 姓名 |  學號   |   日期   |
 |   :---: | :---:|  :---:  |:---: |
 |四機械四乙|吳宇昕|B10831020|11/16/2022|

## 原始碼與Replit
兩個原始碼檔案須放在同個資料夾內才能運作

[main.cpp](CODE/main.cpp) and [KellySimulator.hpp](CODE/KellySimulator.hpp)

[replit](https://replit.com/join/shgkerdwie-b10831020)

## 檔案紀錄輸出
使用者須手動輸入投資標的之預期漲跌幅(percent increase/decrease)，以及賭贏的機率(P)。程式會模擬投資三個標的，每個標的投資30次。初始資金為10000元，每次投資將會把賺得或賠掉的金額更新至下次的投資資金。下圖僅包含投資第一個標的的結果，數值金額皆四捨五入至整數位。

![normal terminal output](IMG/terminal%20output%20normal.png)

若投資標的的Kelly percentage低於0，表示不應該投資該標的。程式會跳過該標的，直接開始模擬投資下一個標的。

## Bug
程式目前設計若Kelly percentage小於0，就不會模擬該標的。若更改程式允許模擬Kelly percentage小於0的情形，會在模擬投資Kelly percentage < 0的標的時發生執行其錯誤。即使投資人賭錯了，該輪模擬仍然會讓投資人的資金增加，而不是反應賠錢虧損。

## 結果討論

### 1. 即使避開所有Kelly percentage低於0的標的，投資仍然可能賠錢
> 下圖的Kelly percentage為0.11%，數值相當小，可能代表這並不是個很吸引人的投資標的。經過30次模擬，總資金少了40元。其實也不是很大的損失，但是實在沒有很值得投資人忙碌奔波。
> 
> ![loosing money although kelly percent > 0](IMG/loosing%20slightly.png)

### 2. 依凱力公式買台股很難買到破產
> 程式有破產停止模擬的設計，但是在不投資Kelly percentage < 0的標的前提下，經過很多次模擬都沒有破產。台股有每天漲跌幅10%的限制，若遵守凱利公式分配預算，很難讓投資人破產。

### 3. 投資人需主觀決定凱利公式中的參數
> 公式裡的預期漲跌幅，以及猜對的機率，都需要主觀決定。散戶往往缺乏經驗，對標的的消息也不如大戶靈通，很難正確判斷三個參數的數值。模擬得到的結果也不準確。

## 心得
這份作業很適合用OOP的風格完成。將計算Kelly percentage到輸出模擬結果的過程都包覆在class之內，避免class外的程式干預。

對於寫程式的技巧，我還在想辦法讓終端機輸出與檔案輸出的程式碼更簡潔。以這個函式為例，我想要在Kelly percentage 小於0時在終端機輸出Kelly percentage及相關參數值，告訴投資人不要投資這個標的，同時把上述所有內容完整寫入紀錄檔案。整個函式明顯有兩段一模一樣的程式碼，相當冗長。不知道有沒有更好的做法。
```c++
    void KellySimulator::mQuitGameBecauseThisSucks()
    {
        using namespace std;
        ofstream file("Log.txt", ofstream::app); // parameter app appends the content of this game to an existing file
        file << left << setw(25) << "Wining probability: " << mP << endl;
        file << left << setw(25) << "Percent increase:" << mPercentRise << endl;
        file << left << setw(25) << "Percent decrease:" << mPercentFall << endl;
        file << left << setw(25) << "Kelly percentage:" << mF << endl;
        file << "This investment target sucks! Don't put any money into it. Terminating simulaton\n" << endl;
        cout << left << setw(25) << "Wining probability: " << mP << endl;
        cout << left << setw(25) << "Percent increase:" << mPercentRise << endl;
        cout << left << setw(25) << "Percent decrease:" << mPercentFall << endl;
        cout << left << setw(25) << "Kelly percentage:" << mF << endl;
        cout << "This investment target sucks! Don't put any money into it. Terminating simulaton\n" << endl;
        file.close();
    }
```

至於報告Bug章節提到的問題，仍然不清楚解決方式為何。看不太出來為什麼會這樣子。