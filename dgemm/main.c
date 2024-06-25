#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mylib_a.h>
#include <mylib_b.h>

// typedef long long unsigned u64;

void matrix_init(int **M, int n){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            M[i][j] = i+j;
        }
    }
}

int main(int argc, char** argv){

    if(argc < 3){
        printf("usage: %s [n] [r]\n", argv[0]);
        return 1;
    }

    int n = atoll(argv[1]);
    int r = atoll(argv[2]);

    /* Initialisation */
    int** restrict A = malloc(sizeof(int*)*n);
    int** restrict B = malloc(sizeof(int*)*n);
    int** restrict C = malloc(sizeof(int*)*n);

    for(int i=0; i<n; ++i){
        A[i] = malloc(sizeof(int)*n);
        B[i] = malloc(sizeof(int)*n);
        C[i] = malloc(sizeof(int)*n);
    }

    matrix_init(A, n);
    matrix_init(B, n);

    for(int rep=0; rep<r; ++rep){
        for(int p=0; p<9; ++p){
            my_dgemm_a(A, B, C, n);
        }
        my_dgemm_b(A, B, C, n);
    }

    /* Libération */
    for(int i=0; i<n; ++i){
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}