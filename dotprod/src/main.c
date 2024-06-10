#include "dotprod.h"
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

int main(int argc, char** argv){

    if (argc < 3){
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

    double ref, res_unroll4, res_unroll4_v2, res_unroll4_v3, res_mpi, res_omp;

    clock_t t0, t1;
    double *elapsed = (double *)malloc(7*sizeof(double));

    for(u64 i=0; i<r; ++i){

        t0 = clock();
        vector_init(x, n);
        vector_init(y, n);
        t1 = clock();
        elapsed[0] += (t1-t0);

        t0 = clock();
        ref = dotprod(x, y, n);
        t1 = clock();
        elapsed[1] += (t1-t0);

        t0 = clock();
        res_unroll4 = dotprod_unroll4(x, y, n);
        t1 = clock();
        elapsed[2] += (t1-t0);

        t0 = clock();
        res_unroll4_v2 = dotprod_unroll4_v2(x, y, n);
        t1 = clock();
        elapsed[3] += (t1-t0);

        t0 = clock();
        res_unroll4_v3 = dotprod_unroll4_v3(x, y, n);
        t1 = clock();
        elapsed[4] += (t1-t0);

        t0 = clock();
        res_mpi = dotprod_parallel_mpi(x, y, n, rank, size);
        t1 = clock();
        elapsed[5] += (t1-t0);

        t0 = clock();
        res_omp = dotprod_parallel_omp(x, y, n);
        t1 = clock();
        elapsed[6] += (t1-t0);

    }

    if(rank == 0){
        printf("Temps initialisation : %1.2lf s\n", elapsed[0]/1000000);
        printf("Résultat séquentiel : %lf en %1.2lf s\n", ref, elapsed[1]/1000000);
        printf("Résultat séquentiel avec UNROLL 4 : %lf en %1.2lf s\n", res_unroll4, elapsed[2]/1000000);
        printf("Résultat séquentiel avec UNROLL 4 v2 : %lf en %1.2lf s\n", res_unroll4_v2, elapsed[3]/1000000);
        printf("Résultat séquentiel avec UNROLL 4 v3 : %lf en %1.2lf s\n", res_unroll4_v3, elapsed[4]/1000000);
        printf("Résultat parallèle avec mpi: %lf en %1.2lf s\n", res_mpi, elapsed[5]/1000000);
        printf("Résultat parallèle avec omp: %lf en %1.2lf s\n", res_omp, elapsed[6]/1000000);
    } 

    free(x);
    free(y);
    free(elapsed);

    MPI_Finalize();
    
    return 0;
}