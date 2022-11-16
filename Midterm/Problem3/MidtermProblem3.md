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

## 結果討論

### 1. 即使避開所有Kelly percentage低於0的標的，投資仍然可能賠錢
> 下圖的Kelly percentage為0.11%，數值相當小，可能代表這並不是個很吸引人的投資標的。經過30次模擬，總資金少了40元。其實也不是很大的損失，但是實在沒有很值得投資人忙碌奔波。
> 
> ![loosing money although kelly percent > 0](IMG/loosing%20slightly.png)

### 2. 依凱力公式買台股很難買到破產
> 程式有破產停止模擬的設計，但是經過很多次模擬都沒有觸發。台股有每天漲跌幅10%的限制，若遵守凱利公式分配預算，很難因為突然暴跌讓投資人破產。