#ifndef DOTPROD_H_
#define DOTPROD_H_

#include <unistd.h>

typedef long long int u64;

void vector_init(double *x, u64 n);
double dotprod(double *x, double *y, u64 n);
double dotprod_unroll4(double *x, double *y, u64 n);
double dotprod_unroll4_v2(double *x, double *y, u64 n);
double dotprod_unroll4_v3(double *x, double *y, u64 n);
double dotprod_parallel_mpi(double *x, double *y, u64 n, int rank, int size);
double dotprod_parallel_omp(double *x, double *y, u64 n);

#endif