#include <stdio.h>
#include "./fast-sqrt.c"

int main(){
    float n;
    scanf("%f",&n);
    float answer=fast_inv_sqrt(n);
    printf("%f is the inverse sqrt of %f\n",answer,n);
    return 0;
}