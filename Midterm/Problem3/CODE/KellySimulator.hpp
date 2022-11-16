#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>
#include <cmath>   // round()
#include <fstream> // ofstream


struct RoundLog
{
    bool win;
    uint16_t id;
    double cashFlow;
    double remainingBudjet;
    bool goingBroke;
};

class KellySimulator
{
public:
    KellySimulator(const double& p, const double& percentRise, const double& percentFall, const double& budjet)
        :mP(p), mQ(1-p), mPercentRise(percentRise), mPercentFall(percentFall), mBudjet(budjet), mNRounds(30), mWinCount(0), mLooseCount(0)
    {
        sActualEdgeRandGen = std::mt19937(time(0));
        this->mB = mPercentRise/mPercentFall;
        this->mF = mP - (mQ / mB);
        this->mGameRecord.reserve(mNRounds);
    }

    void PlayGame()
    {
        for(int i = 0; i < mNRounds; i++){
            float winOrLoose = mGetRandom();
            double moneyInvested = mBudjet * mF;
            if(winOrLoose > mP){
                mLooseCount ++;
                mBudjet -= moneyInvested * mPercentFall;
                if(mBudjet - moneyInvested * mPercentFall < 100){ // if the budget goes below 100 after another loss, quit game
                    mGameRecord.push_back({false, (uint16_t)i, -moneyInvested * mPercentFall, mBudjet, true});
                    break;
                }else{
                    mGameRecord.push_back({false, (uint16_t)i, -moneyInvested * mPercentFall, mBudjet, false});
                }
            }else{
                mWinCount ++;
                mBudjet += moneyInvested * mPercentRise;
                mGameRecord.push_back({true, (uint16_t)i, moneyInvested * mPercentRise, mBudjet, false});
            }
        }
        mPrintGameResult();
        mWriteGameResultToFile();
    }

    void SetNRounds(uint16_t nRounds) {this->mNRounds = nRounds;}

    double GetFinalBudjet(){return mBudjet;}

private:
    uint16_t mNRounds, mWinCount, mLooseCount;
    std::vector<RoundLog> mGameRecord;
    double mBudjet, mPercentRise, mPercentFall;
    double mP; // historical winning percentage
    double mQ; // historical loosing percentage = 1-p
    double mB; // percent rise / percent fall
    double mF; // Kelly percentage(portion of the total budget to invest)

    static std::mt19937 sActualEdgeRandGen;

    double mGetRandom()
    {
        return (double)(sActualEdgeRandGen() - sActualEdgeRandGen.min()) / (sActualEdgeRandGen.max() - sActualEdgeRandGen.min());
    }

    void mPrintGameResult() const
    {
        using namespace std;
        cout << setw(7) << "Round" << setw(8) << "Win?" << setw(15) << "Cash Flow" << setw(25) << "Remaining Budjet" << endl;
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        for(const RoundLog& roundResult : mGameRecord){
            if(roundResult.goingBroke){
                cout << setw(7) << roundResult.id << setw(8) << roundResult.win << setw(15) << round(roundResult.cashFlow) << setw(25) << round(roundResult.remainingBudjet) << endl; 
                cout << "Sorry mate, you're broke. Let's call it a day" << endl;
            }else{  
                cout << setw(7) << roundResult.id << setw(8) << roundResult.win << setw(15) << round(roundResult.cashFlow) << setw(25) << round(roundResult.remainingBudjet) << endl; 
            }
        }
        cout << setw(45) <<"Final budjet" << setw(10) << mBudjet << endl;
        cout << "Win count: " << mWinCount << '\t' << "Loose count: " << mLooseCount << std::endl;
        cout << endl;
    }

    void mWriteGameResultToFile() const
    {
        using namespace std;
        ofstream file("Log.txt", ofstream::app); // parameter app appends the content of this game to an existing file
        file << left << setw(25) << "Wining probability: " << mP << endl;
        file << left << setw(25) << "Percent increase:" << mPercentRise << endl;
        file << left << setw(25) << "Percent decrease:" << mPercentFall << endl;
        file << left << setw(25) << "Kelly percentage:" << mF << endl;
        file << setw(7) << "Round" << setw(8) << "Win?" << setw(15) <<"Cash Flow" << setw(25) << "Remaining Budjet" << endl;
        file << "-----------------------------------------------------------------------------------------------------" << endl;
        for(const RoundLog& roundResult : mGameRecord){
            if(roundResult.goingBroke){
                file << setw(7) << roundResult.id << setw(8) << roundResult.win << setw(15) << round(roundResult.cashFlow) << setw(25) << round(roundResult.remainingBudjet) << endl; 
                file << "Sorry mate, you're broke. Let's call it a day" << std::endl;
            }else{  
                file << setw(7) << roundResult.id << setw(8) << roundResult.win << setw(15) << round(roundResult.cashFlow) << setw(25) << round(roundResult.remainingBudjet) << endl; 
            }
        }
        file << setw(45) <<"Final budjet" << setw(10) << mBudjet << endl;
        file << "Win count: " << mWinCount << '\t' << "Loose count: " << mLooseCount << std::endl;
        file << endl;
        file.close();
    }
};

std::mt19937 KellySimulator::sActualEdgeRandGen;