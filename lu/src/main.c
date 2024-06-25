#include "lu.h"
#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>
#include <time.h>

int main(int argc, char** argv){

    if(argc < 2){
        printf("usage: %s [n]\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    double *A = (double*)malloc(n*n*sizeof(double));

    clock_t t0, t1;
    double elapsed;

    printf("\033[1m ________________________________________________\n");
    printf(" \033[1m| \033[1m%-30s | \033[1m%s\033[1m|\n", "Function", "Time (in s)");
    printf("\033[1m ________________________________________________\n");

    t0 = clock();
    init(A, n);
    t1 = clock();
    printf(" \033[1m| \033[1m%-30s | \033[104m%-10.2lf \033[0m \033[1m|\n", "init()", (double)(t1-t0)/1000000);

    t0 = clock();
    LU_v0(A, n);
    t1 = clock();
    printf(" \033[1m| \033[1m%-30s | \033[104m%-10.2lf \033[0m \033[1m|\n", "lu_v0()", (double)(t1-t0)/1000000);

    t0 = clock();
    LU_v1(A, n);
    t1 = clock();
    printf(" \033[1m| \033[1m%-30s | \033[104m%-10.2lf \033[0m \033[1m|\n", "lu_v1()", (double)(t1-t0)/1000000);

    int *ipiv = (int*)malloc(n*sizeof(int));
    t0 = clock();
    int info = LAPACKE_dgetrf(LAPACK_ROW_MAJOR, n, n, A, n, ipiv);
    t1 = clock();
    printf(" \033[1m| \033[1m%-30s | \033[104m%-10.2lf \033[0m \033[1m|\n", "LAPACKE_dgetrf()", (double)(t1-t0)/1000000);
    printf("\033[1m ________________________________________________\n");

    free(A);
    free(ipiv);
    
    return 0;
}