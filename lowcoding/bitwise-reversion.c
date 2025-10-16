#include<stdio.h>
#include<stdlib.h>
#define input(fmt, elm) \
    scanf(fmt, elm);
#define i64 long long

int main(){
    int interval = -1;
    i64* d_arr;
    input("%d", &interval);
    if(interval == -1) return 0;
    d_arr  = (i64*)malloc(interval*sizeof(i64));
    int i = 0;
    while(interval--){
        i64 x, y, z;
        input("%lld", &x);
        input("%lld", &y);
        input("%lld", &z);
        i64 invalid = (x & y & ~z) | (x & z & ~y) | (y & z & ~x);
        d_arr[i++] = invalid;
    }
    for(i64* ptr = d_arr; ptr < d_arr+i; ptr++){
        printf("%s\n",(*ptr == 0)?"YES":"NO");
    }
    free(d_arr);
}
