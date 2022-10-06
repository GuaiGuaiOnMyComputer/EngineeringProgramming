#include <cstdlib> //srand(), rand()
#include <stdio.h>
#include <time.h>
#include <vector>

using INT_COL = std::vector<int>; //vector of ints
using INT_MATRIX = std::vector<INT_COL>; //vector of vectors of ints

void AssignRandomValues(INT_MATRIX& _m1, INT_MATRIX& _m2, const int n_rows, const int n_cols);
void PrintMatrix(const INT_MATRIX& _m, const char* _matrixName, const int n_rows, const int n_cols);
void MatrixAdd(const INT_MATRIX& _m1, const INT_MATRIX& _m2, const int n_rows, const int n_cols, INT_MATRIX& out_result);
void MatrixSubtract(const INT_MATRIX& _m1, const INT_MATRIX& _m2, const int n_rows, const int n_cols, INT_MATRIX& out_result);

int main()
{
    INT_MATRIX m1; //create a vector of vectors of ints
    INT_MATRIX m2; //create a vector of vectors of ints
    INT_MATRIX matrixAddtionResult;     //the matrix to store calculation results
    INT_MATRIX matrixSubtractionResult; //the matrix to store calculation results
    AssignRandomValues(m1, m2, 4, 4);   //give random values to the two matrices
    MatrixAdd(m1, m2, 4, 4, matrixAddtionResult);
    MatrixSubtract(m1, m2, 4, 4, matrixAddtionResult);
    system("pause");
    return 0;
}


void MatrixAdd(const INT_MATRIX& _m1, const INT_MATRIX& _m2, const int n_rows, const int n_cols, INT_MATRIX& out_result)
{
    out_result.reserve(n_rows); //allocate 4 vectors of ints
    for(int i=0; i<n_rows; i++){
        out_result[i].reserve(n_cols); //allocate 4 ints within each row vector
        for(int j=0; j<n_cols; j++){
            out_result[i][j] = _m1[i][j] + _m2[i][j];
        }
    }
    PrintMatrix(out_result, "Addition of the two matrice", n_rows, n_cols);
}
void MatrixSubtract(const INT_MATRIX& _m1, const INT_MATRIX& _m2, const int n_rows, const int n_cols, INT_MATRIX& out_result)
{
    out_result.reserve(n_rows); //allocate 4 vectors of ints
    for(int i=0; i<n_rows; i++){
        out_result[i].reserve(n_cols); //allocate 4 ints within each row vector
        for(int j=0; j<n_cols; j++){
            out_result[i][j] = _m1[i][j] - _m2[i][j];
        }
    }
    PrintMatrix(out_result, "Subtraction of the two matrice", n_rows, n_cols);
}

void AssignRandomValues(INT_MATRIX& _m1, INT_MATRIX& _m2, const int n_rows, const int n_cols)
{
    srand(time(0)); //use a time stanp as random seed
    _m1.reserve(n_rows); //allocate 4 vectors of ints
    _m2.reserve(n_rows); //allocate 4 vectors of ints
    for(int i=0; i<n_rows; i++){
        _m1[i].reserve(n_cols); //allocate 4 ints within each row vector
        _m2[i].reserve(n_cols); //allocate 4 ints within each row vector
        for(int j=0; j<n_cols; j++){
            _m1[i].push_back(rand() % 200 - 100);
            _m2[i].push_back(rand() % 200 - 100);
        }
    }
    PrintMatrix(_m1, "m1", n_rows, n_cols);
    PrintMatrix(_m2, "m2", n_rows, n_cols);
}

void PrintMatrix(const INT_MATRIX& _m, const char* _matrixName, const int n_rows, const int n_cols)
{
    printf("%s\n", _matrixName);
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