#include <cstdlib> //srand(), rand()
#include <stdio.h>
#include <time.h>
#include <vector>

using rowVtr = std::vector<int>; //vector of ints
using matrixVtr = std::vector<rowVtr>; //vector of vectors of ints

void AssignRandomValues(matrixVtr& _m1, matrixVtr& _m2, const int n_rows, const int n_cols);
void PrintMatrix(const matrixVtr& _m, const char* _matrixName, const int n_rows, const int n_cols);
void MatrixAdd(const matrixVtr& _m1, const matrixVtr& _m2, const int n_rows, const int n_cols, matrixVtr& out_result);
void MatrixSubtract(const matrixVtr& _m1, const matrixVtr& _m2, const int n_rows, const int n_cols, matrixVtr& out_result);

int main()
{
    printf("Student B10831020\n");
    matrixVtr m1; //create a vector of vectors of ints
    matrixVtr m2; //create a vector of vectors of ints
    matrixVtr matrixAddtionResult;     //the matrix to store calculation results
    matrixVtr matrixSubtractionResult; //the matrix to store calculation results
    AssignRandomValues(m1, m2, 4, 4);   //give random values to the two matrices
    PrintMatrix(m1,"Matrix m1", 4, 4);
    PrintMatrix(m2,"Matrix m2", 4, 4);
    MatrixAdd(m1, m2, 4, 4, matrixAddtionResult);
    PrintMatrix(matrixAddtionResult, "Addition of the two matrices", 4, 4);
    MatrixSubtract(m1, m2, 4, 4, matrixSubtractionResult);
    PrintMatrix(matrixSubtractionResult, "Subtracetion of the two matrices", 4, 4);
    return 0;
}


void MatrixAdd(const matrixVtr& _m1, const matrixVtr& _m2, const int n_rows, const int n_cols, matrixVtr& out_result)
{
    out_result.reserve(n_rows); //allocate 4 vectors of ints
    for(int i=0; i<n_rows; i++){
        out_result.push_back(rowVtr());
        out_result[i].reserve(n_cols); //allocate 4 ints within each row vector
        for(int j=0; j<n_cols; j++){
            out_result[i].push_back(_m1[i][j] + _m2[i][j]);
        }
    }
}
void MatrixSubtract(const matrixVtr& _m1, const matrixVtr& _m2, const int n_rows, const int n_cols, matrixVtr& out_result)
{
    out_result.reserve(n_rows); //allocate 4 vectors of ints
    for(int i=0; i<n_rows; i++){
        out_result.push_back(rowVtr());
        out_result[i].reserve(n_cols); //allocate 4 ints within each row vector
        for(int j=0; j<n_cols; j++){
            out_result[i].push_back(_m1[i][j] - _m2[i][j]);
        }
    }
}

void AssignRandomValues(matrixVtr& _m1, matrixVtr& _m2, const int n_rows, const int n_cols)
{
    srand(time(0)); //use a time stanp as random seed
    _m1.reserve(n_rows); //allocate 4 vectors of ints
    _m2.reserve(n_rows); //allocate 4 vectors of ints
    for(int i=0; i<n_rows; i++){
        _m1.push_back(rowVtr());
        _m2.push_back(rowVtr());
        _m1[i].reserve(n_cols); //allocate 4 ints within each row vector
        _m2[i].reserve(n_cols); //allocate 4 ints within each row vector
        for(int j=0; j<n_cols; j++){
            _m1[i].push_back(rand() % 200 - 100);
            _m2[i].push_back(rand() % 200 - 100);
        }
    }
}

void PrintMatrix(const matrixVtr& _m, const char* _matrixName, const int n_rows, const int n_cols)
{
    printf("%s size %d capacity %d\n", _matrixName, _m.size(), _m.capacity());
    for(int i=0; i<n_rows; i++){
        for(int j=0; j<n_cols; j++){
            if(j==0){
                printf("%d\t", _m[i][j]);
            }
            else if (j==n_cols-1){
                printf("%d\n", _m[i][j]);
            }
            else{
                printf("%d\t", _m[i][j]);
            }
        }
    }
    printf("========================\n\n");
}

/*
Replit: https://replit.com/join/aqehxsqagg-b10831020

m1
-49     69      19      -81
-27     -55     -46     -88
-92     -97     37      -3
45      -49     -6      -7
========================

m2
-4      -72     95      -44
28      11      9       -3
88      -67     -72     -85
-17     8       -17     98
========================

Addition of the two matrice
-53     -3      114     -125
1       -44     -37     -91
-4      -164    -35     -88
28      -41     -23     91
========================

Subtraction of the two matrice
-45     141     -76     -37
-55     -66     -55     -85
-180    -30     109     82
62      -57     11      -105
========================

Press any key to continue . . .
*/