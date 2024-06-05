#include "dotprod.h"
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv){

    if (argc < 2){
        printf("usage: %s [n] [r]\n", argv[0]);
        return 1;
    }

    u64 n = atoll(argv[1]);
    u64 r = atoll(argv[2]);

    MPI_Init(&argc, &argv);

    int size, rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    double* restrict x;
    double* restrict y;
    posix_memalign((void **)&x, 32, n * sizeof(double));
    posix_memalign((void **)&y, 32, n * sizeof(double)); 

    double ref, res_unroll4, res_mpi, res_omp;

    for(u64 i=0; i<r; ++i){

        vector_init(x, n);
        vector_init(y, n);

        ref = dotprod(x, y, n);
        res_unroll4 = dotprod_unroll4(x, y, n);
        res_mpi = dotprod_parallel_mpi(x, y, n, rank, size);
        res_omp = dotprod_parallel_omp(x, y, n);

    }

    if(rank == 0){
        printf("Résultat séquentiel : %lf\n", ref);
        printf("Résultat séquentiel avec UNROLL 4: %lf\n", res_unroll4);
        printf("Résultat parallèle avec mpi: %lf\n", res_mpi);
        printf("Résultat parallèle avec omp: %lf\n", res_omp);
    } 

    MPI_Finalize();
    
    return 0;
}