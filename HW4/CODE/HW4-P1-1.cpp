#include <iostream>
#include <vector>
#include <random>
#include <time.h>

struct HozRow
{
    uint8_t ID;
    std::vector<int> data;
    double avg;

    HozRow(){data.reserve(4);} //struct constructor
};

using CompositeArr = std::vector<HozRow>;

void getPrintNonDiaSum(const CompositeArr&);
void assignRandomValue(CompositeArr&, CompositeArr&);
void printCompositeArr(const CompositeArr& , const char*);
void matrixAdd(const CompositeArr&, const CompositeArr&, CompositeArr&);

int main()
{
    std::cout << "Student B10831020" << std::endl;
    CompositeArr m1, m2, addResult;
    assignRandomValue(m1, m2);
    printCompositeArr(m1, "Random composite matrix m1");
    printCompositeArr(m2, "Random composite matrix m2");
    matrixAdd(m1, m2, addResult);
    printCompositeArr(addResult, " m1 + m2");
    getPrintNonDiaSum(addResult); 
    return 0;
}

void getRowAvg(CompositeArr & m)
{
    for(HozRow& row : m){
        double rowSum = 0.0;
        for(const int& element : row.data){
            rowSum += element;
        }
        row.avg = rowSum / row.data.size();
    }
}

void assignRandomValue(CompositeArr& m1, CompositeArr& m2)
{
    auto randGenerator = std::mt19937(time(0));
    m1.reserve(4);
    m2.reserve(4);
    for(int i = 0; i < 4; i++){
        m1.push_back(HozRow());
        m2.push_back(HozRow());
        for(int j = 0; j < 4; j++){
            m1[i].data.push_back(randGenerator() % 200 - 100);
            m2[i].data.push_back(randGenerator() % 200 - 100);
        }
    }
    getRowAvg(m1);
    getRowAvg(m2);
}

void printCompositeArr(const CompositeArr& m, const char* message)
{
    std::cout << message << std::endl;
    for(const HozRow& row : m){
        for(int j = 0; j < row.data.size(); j++){
            switch (j)
            {
            case 0:
                std::cout << '|' << row.data[j] << '\t';
                break;
            case 3:
                std::cout << row.data[j] << "|\trow average = " << row.avg << std::endl;
                break;
            default:
                std::cout << row.data[j] << '\t';
                break;
            }
        }
    }
    std::cout << "================================================" << std::endl;
}

void matrixAdd(const CompositeArr& m1, const CompositeArr& m2, CompositeArr& out)
{
    out.reserve(4);
    for(int i = 0; i < m1.size(); i++){
        out.push_back(HozRow());
        out[i].data.reserve(4);
        for(int j = 0; j < m1[i].data.size(); j++){
            out[i].data.push_back(m1[i].data[j] + m2[i].data[j]);
        }
    }
    getRowAvg(out);
}

void getPrintNonDiaSum(const CompositeArr& addResult)
{
    std::cout << "Nondiagonal element sum of m1 and m2" << std::endl;
    for(int i = 0; i < addResult.size(); i++){
        for(int j = 0; j < addResult[i].data.size(); j++){
            switch (j)
            {
            case 0:
                if(i == j){std::cout << "|--\t";break;}
                else{std::cout << '|' << addResult[i].data[j] << '\t';break;}
            case 3:
                if(i == j){std::cout << "--|" << std::endl;break;}
                else{std::cout << addResult[i].data[j] << '|' << std::endl;break;}
            default:
                if(i == j){std::cout << "--\t";break;}
                else{std::cout << addResult[i].data[j] << '\t'; break;}
            }
        }
    }
}