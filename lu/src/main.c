#include "lu.h"
#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>

int main(int argc, char** argv){

    if(argc < 2){
        printf("usage: %s [n]\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    double *A = (double*)malloc(n*n*sizeof(double));
    int *ipiv = (int*)malloc(n*sizeof(int));
    int info;

    /* Décomposition LU avec la fonction v0 */
    init(A, n);
    LU_v0(A, n);

    /* Décomposition LU avec la fonction v0 */
    init(A, n);
    LU_v1(A, n);

    /* Décomposition LU avec LAPACKE */
    init(A, n);
    info = LAPACKE_dgetrf(LAPACK_ROW_MAJOR, n, n, A, n, ipiv);

    free(A);
    free(ipiv);
    
    return 0;
}