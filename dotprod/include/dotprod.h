#ifndef DOTPROD_H_
#define DOTPROD_H_

void vector_init(double *x, int n);
double dotprod(double *x, double *y, int n);
double dotprod_parallel(double *x, double *y, int n, int rank, int size);

#endif