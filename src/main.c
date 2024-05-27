#include "lu.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

    if(argc < 2){
        printf("usage: %s [n]\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    double **a = malloc(n*sizeof(double));
    for(int i=0; i<n; ++i){
        a[i] = malloc(n*sizeof(double));
    }

    init(a, n);
    LU(a, n);
    
    // print(a, n);

    drop(a, n);
    
    return 0;
}