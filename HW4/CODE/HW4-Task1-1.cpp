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
        m1.push_back(HozRow()); //calls HozRow constructor
        m2.push_back(HozRow()); //calls HozRow constructor
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
        // out[i].data.reserve(4);
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

/*
Replit:https://replit.com/join/ivcjhkwpfh-b10831020
Student B10831020
Random composite matrix m1
|17	-60	-84	46|	row average = -20.25
|28	-5	-37	54|	row average = 10
|12	28	-78	11|	row average = -6.75
|39	-47	-23	-72|	row average = -25.75
================================================
Random composite matrix m2
|-19	87	99	89|	row average = 64
|-20	34	51	31|	row average = 24
|-33	-68	10	90|	row average = -0.25
|34	-13	-5	10|	row average = 6.5
================================================
 m1 + m2
|-2	27	15	135|	row average = 43.75
|8	29	14	85|	row average = 34
|-21	-40	-68	101|	row average = -7
|73	-60	-28	-62|	row average = -19.25
================================================
Nondiagonal element sum of m1 and m2
|--	27	15	135|
|8	--	14	85|
|-21	-40	--	101|
|73	-60	-28	--|

*/