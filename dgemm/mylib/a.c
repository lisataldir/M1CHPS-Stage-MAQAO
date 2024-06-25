#include "mylib_a.h"
#include <stdio.h>

void my_dgemm_a(int **A, int **B, int **C, int n){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            C[i][j] = 0;
            for(int k=0; k<n; ++k){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}