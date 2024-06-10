#include "dotprod.h"
#include <stdlib.h>
#include <mpi.h>
#include <omp.h>

void vector_init(double *x, u64 n){
    for(u64 i=0; i<n; ++i){
        x[i] = 1.0/(double)(i + 1);
    }
}


double dotprod(double *x, double *y, u64 n) {
    double res = 0.0;
    double *p_x = (double *)__builtin_assume_aligned(x, 32);
    double *p_y = (double *)__builtin_assume_aligned(y, 32);

    #pragma omp simd reduction(+:res)
    for (u64 i = 0; i < n; ++i) {
        res += p_x[i] * p_y[i];
    }

    return res;
}


double dotprod_unroll4(double *x, double *y, u64 n){
    double res = 0.0;
    for(u64 i=0; i< n - (n & 3); i+=4){
        res += x[i]*y[i];
        res += x[i+1]*y[i+1];
        res += x[i+2]*y[i+2];
        res += x[i+3]*y[i+3];
    }
    for (u64 i = (n - (n & 3)); i < n; i++)
	    res +=  x[i]*y[i];
    return res;
}


double dotprod_unroll4_v2(double *x, double *y, u64 n){
    double res = 0.0;
    #pragma GCC unroll 4
    for(u64 i=0; i<n; ++i){
        res += x[i]*y[i]; 
    }
    return res;
}


double dotprod_unroll4_v3(double *x, double *y, u64 n){

    double *res = (double *)malloc(n*sizeof(double));
    double sum = 0.0;

    for(u64 i=0; i< n - (n & 3); i+=4){
        res[i] = x[i]*y[i];
        res[i+1] = x[i+1]*y[i+1];
        res[i+2] = x[i+2]*y[i+2];
        res[i+3] = x[i+3]*y[i+3];
    }

    for (u64 i=(n - (n & 3)); i<n; i++)
	    res[i] =  x[i]*y[i];

    for(u64 i=0; i<n; ++i)
        sum += res[i];
    
    free(res);

    return sum;
}


double dotprod_parallel_mpi(double *x, double *y, u64 n, int rank, int size){

    double res_loc = 0.0;
    double res_glob;

    int deb = (u64)(rank*n/size);
    int fin = (u64)(deb + n/size);

    for(u64 i=deb; i<fin; ++i){
        res_loc += x[i]*y[i];
    }
    MPI_Allreduce(&res_loc, &res_glob, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

    return res_glob;
}


double dotprod_parallel_omp(double *x, double *y, u64 n){
    double res = 0.0;

    #pragma omp parallel for reduction (+:res)
    for(u64 i=0; i<n; ++i){
        res += x[i]*y[i];
    }
    return res;
}