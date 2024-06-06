#include <stdio.h>
#include <stdlib.h>
#include <mylib_a.h>
#include <mylib_b.h>

typedef long long unsigned u64;

int main(int argc, char** argv){

    if(argc < 2){
        printf("usage: %s [r]\n", argv[0]);
        return 1;
    }

    u64 r = atoll(argv[1]);

    int n = 2;
    double s;

    for(u64 k=0; k<r; ++k){
        for(int i=0; i<9; ++i){
            s = my_sqrt_a(n);
        }
        s = my_sqrt_b(n);
    }

    return 0;
}