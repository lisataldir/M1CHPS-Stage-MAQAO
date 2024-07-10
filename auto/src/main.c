#include "init.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv){

    if(argc < 3){
        printf("usage: %s [n] [r]\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int r = atoi(argv[2]);

    double *tab = (double *)malloc(sizeof(double)*n);

    for(int rep=0; rep<r; ++rep){
        init(tab, n);
    }

    if(n<10){
        for(int i=0; i<n; ++i){
            printf("%lf ", tab[i]);
        }
        printf("\n");
    }

    return 0;
}