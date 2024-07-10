#include "init.h"

void init(double *tab, int n){
    for(int i=0; i<n; ++i){
        tab[i] = 1.0/(i+1.0);
    }
}