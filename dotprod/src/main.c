#include "dotprod.h"
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv){

    if (argc < 2){
        printf("usage: %s [n]\n", argv[0]);
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

    double res_sequentiel, res_parallel;

    res_parallel = dotprod_parallel(x, y, n, rank, size);

    if(rank == 0){

        res_sequentiel = dotprod(x, y, n);

        printf("Résultat séquentiel : %lf\n", res_sequentiel);
        printf("Résultat parallèle : %lf\n", res_parallel);

    } 

    MPI_Finalize();
    
    return 0;
}