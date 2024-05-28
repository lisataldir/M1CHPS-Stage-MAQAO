#include "lu.h"
#include <stdio.h>
#include <stdlib.h>


void print(double **a, int n){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }
}


void init(double **a, int n){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            a[i][j] = (double)(i+j+1);
        }
    }
}


void LU(double **a, int n){
    for(int k=0; k<n-1; ++k){
        for(int i=k+1; i<n; ++i){
            a[i][k] = a[i][k]/a[k][k];
        }
        for(int i=k+1; i<n; ++i){
            for(int j=k+1; j<n; ++j){
                a[i][j] = a[i][j] - a[i][k]*a[k][j];
            }
        }
    }
}


void drop(double **a, int n){
    for(int i=0; i<n; ++i){
        free(a[i]);
    }
    free(a);
}