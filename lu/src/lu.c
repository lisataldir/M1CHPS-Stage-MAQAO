#include "lu.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void print(double *A, int n){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            printf("%lf ", A[i*n + j]);
        }
        printf("\n");
    }
}


void init(double *A, int n){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            A[i*n + j] = (double)(i+j+1);
        }
    }
}


void LU_v0(double *A, int n){
    for(int k=0; k<n-1; ++k){
        for(int i=k+1; i<n; ++i){
            A[i*n + k] /= A[k*n + k];
        }
        for(int i=k+1; i<n; ++i){
            for(int j=k+1; j<n; ++j){
                A[i*n + j] -= A[i*n + k]*A[k*n + j];
            }
        }
    }
}

void LU_v1(double *A, int n){
    double max, tmp;
    int imax;
    double d = 1.0;

    double ipiv[n];

    for(int i=0; i<n; ++i){
        max = 0.0;
        for(int j=0; j<n; ++j){
            if ( (tmp=abs(A[i*n + j])) > max ) max = tmp;
        }
        ipiv[i] = 1.0/max;
    }
    for(int k=0; k<n; ++k){
        max = 0.0;
        for(int i=k; i<n; ++i){
            tmp = ipiv[i]*abs(A[i*n + k]);
            if(tmp > max){
                max = tmp;
                imax = i;
            }
        }
        if (k != imax){
            for (int j=0; j<n; ++j){
                tmp = A[imax*n + j];
                A[imax*n + j] = A[k*n + j];
                A[k*n + j] = tmp;
            }
            d = -d;
            ipiv[imax] = ipiv[k];
        }
        for (int i=k+1;i<n;++i) {
            tmp=A[i*n + k] /= A[k*n + k]; 
            for (int j=k+1;j<n;++j){
                A[i*n + j] -= tmp*A[k*n + j];
            }
        }
    }
}