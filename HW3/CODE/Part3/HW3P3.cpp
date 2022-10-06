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
    printf("Student B10831020\n");
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
            //get the beginning memory location of _m1 and cast the pointer to int* to operate on each value
            int* m1_ptr = (int*)(&_m1) + (N_COL*i + j); 
            int* m2_ptr = (int*)(&_m2) + (N_COL*i + j);
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

/*
Replit: https://replit.com/join/ixeibzasth-b10831020
Student B10831020Matrix M1:
        |-150   -107    -106    -162|
        |-167   -177    -115    -193|
        |-115   -123    -116    -188|
        |-158   -151    -140    -166|
==========================================
Matrix M2:
        |-116   -162    -112    -148|
        |-195   -129    -198    -198|
        |-186   -139    -136    -180|
        |-163   -139    -110    -140|
==========================================
M1+M2:
        |-266   -269    -218    -310|
        |-362   -306    -313    -391|
        |-301   -262    -252    -368|
        |-321   -290    -250    -306|
==========================================
M1-M2:
        |-34    55      6       -14|
        |28     -48     83      5|
        |71     16      20      -8|
        |5      -12     -30     -26|
==========================================
Press any key to continue . . .
*/