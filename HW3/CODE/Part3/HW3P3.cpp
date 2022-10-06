#include <stdio.h> //printf()
#include <time.h>  //time()
#include <cstdlib> //rand(), srand()

#define N_COL 4
#define N_ROW 4

struct hozRow
{
    int w, x, y, z;
};
struct struct_mat
{
    hozRow row0, row1, row2, row3;
};

void AssignRandomValue(struct_mat&, struct_mat&);
void PrintStructMatrix(const struct_mat& m, const char* matrixName);
void StructMatrixAdd(const struct_mat& _m1, const struct_mat& _m2, struct_mat& out_result);
void StructMatrixSubtract(const struct_mat& _m1, const struct_mat& _m2, struct_mat& out_result);

int main()
{
    struct_mat M1;
    struct_mat M2;
    struct_mat addResult;
    struct_mat subtractResult;
    AssignRandomValue(M1, M2);
    PrintStructMatrix(M1, "Matrix M1:");
    PrintStructMatrix(M2, "Matrix M2:");
    StructMatrixAdd(M1, M2, addResult);
    PrintStructMatrix(addResult, "M1+M2:");
    StructMatrixSubtract(M1, M2, subtractResult);
    PrintStructMatrix(subtractResult, "M1-M2:");
    system("pause");
    return 0;
}

void AssignRandomValue(struct_mat& _m1, struct_mat& _m2)
{
    srand(time(0));
    for(int i=0; i<N_ROW; i++){
        for(int j=0; j<N_COL; j++){
            int* m1_ptr = (int*)(&_m1) + (N_COL*i + j); //get the beginning memory location of _m1 and cast the pointer to int* to operate on each value
            int* m2_ptr = (int*)(&_m2) + (N_COL*i + j); //get the beginning memory location of _m2 and cast the pointer to int* to operate on each value
            *(m1_ptr) = rand() % 100 - 200;
            *(m2_ptr) = rand() % 100 - 200;
        }
    }
}
void StructMatrixAdd(const struct_mat& _m1, const struct_mat& _m2, struct_mat& out_result)
{
    int* write_ptr = (int*)(&out_result);
    for(int i=0; i<N_ROW; i++){
        for(int j=0; j<N_COL; j++){
            *(write_ptr + j + i*N_COL) = *((int*)(&_m1) + j + i*N_COL) + *((int*)(&_m2) + j + i*N_COL);
        }
    }
}
void StructMatrixSubtract(const struct_mat& _m1, const struct_mat& _m2, struct_mat& out_result)
{
    int* write_ptr = (int*)(&out_result);
    for(int i=0; i<N_ROW; i++){
        for(int j=0; j<N_COL; j++){
            *(write_ptr + j + i*N_COL) = *((int*)(&_m1) + j + i*N_COL) - *((int*)(&_m2) + j + i*N_COL);
        }
    }
}


void PrintStructMatrix(const struct_mat& m, const char* matrixName)
{
    const int* read_ptr = (int*)(&m);
    printf("%s\n", matrixName);
    for(int i=0; i<N_ROW; i++){
        for(int j=0; j<N_COL; j++){
            switch (j)
            {
            case 0:
                printf("\t|%d\t", *(read_ptr + N_COL*i +j));
                break;
            case N_COL - 1:
                printf("%d|\n", *(read_ptr + N_COL*i + j));
                break;
            default:
                printf("%d\t", *(read_ptr + N_COL*i +j));
                break;
            }
        }
    }
    printf("==========================================\n");
}