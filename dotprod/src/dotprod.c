#include "dotprod.h"
#include <stdlib.h>
#include <mpi.h>

void vector_init(double *x, int n){
    srand(0);
    for(int i=0; i<n; ++i){
        x[i] = (double)RAND_MAX / (double)rand();
    }
}


double dotprod(double *x, double *y, int n){
    double res = 0.0;
    for(int i=0; i<n; ++i){
        res += x[i]*y[i];
    }
    return res;
}


double dotprod_parallel(double *x, double *y, int n, int rank, int size){

    double res_loc = 0.0;
    double res_glob;

    int deb = (int)(rank*n/size);
    int fin = (int)(deb + n/size);

    for(int i=deb; i<fin; ++i){
        res_loc += x[i]*y[i];
    }
    MPI_Allreduce(&res_loc, &res_glob, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

    return res_glob;
}