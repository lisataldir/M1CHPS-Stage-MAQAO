#ifndef DOTPROD_H_
#define DOTPROD_H_

void vector_init(double *x, int n);
double dotprod(double *x, double *y, int n);
double dotprod_parallel_mpi(double *x, double *y, int n, int rank, int size);
double dotprod_parallel_omp(double *x, double *y, int n);

#endif