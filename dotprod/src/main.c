#include "dotprod.h"
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv){

    if (argc < 2){
        printf("usage: %s [n]\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    MPI_Init(&argc, &argv);

    int size, rank;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    double *x = (double *)malloc(n*sizeof(double));
    double *y = (double *)malloc(n*sizeof(double));

    vector_init(x, n);
    vector_init(y, n);

    double res_sequentiel, res_parallel_mpi, res_parallel_omp;

    res_parallel_mpi = dotprod_parallel_mpi(x, y, n, rank, size);

    if(rank == 0){

        res_sequentiel = dotprod(x, y, n);
        res_parallel_omp = dotprod_parallel_omp(x, y, n);

        printf("Résultat séquentiel : %lf\n", res_sequentiel);
        printf("Résultat parallèle avec mpi: %lf\n", res_parallel_mpi);
        printf("Résultat parallèle avec omp: %lf\n", res_parallel_omp);
    } 

    MPI_Finalize();
    
    return 0;
}