#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define INF 4e18
typedef long long i64;

#define input(var, fmt)\
    scanf(fmt, var);

#define DECLARE_MATH_FUNCS(T)\
    static inline T Abs_##T(T x) {\
        return x >= 0 ? x : -x;\
    }\
    static inline T addOrMinus_##T(T a, T b) {\
        return Abs_##T(a - b);\
    }

DECLARE_MATH_FUNCS(i64);
i64 circleTracking(i64* a, int size, int start){
    i64* circleArr = (i64*)malloc(size*sizeof(i64));
    i64* dp = (i64*) malloc((size+1)*sizeof(i64));
    for(int i = 0; i < size; i++) {
        circleArr[i] = a[(i+start)%size];
        dp[i] = (i64) INF;
        if(i == size - 1){
            dp[i+1] = (i64)INF;
            break;
        }
    }
    dp[0] = 0;
    for(int j = 2; j <= size; ++j)
    {
        i64 tmp1 = addOrMinus_i64(circleArr[j-2], circleArr[j-1]);
        if(dp[j-2] + tmp1 < dp[j]) dp[j] = dp[j-2] + tmp1;

        if(j >= 3){
            i64 x = circleArr[j-3], y = circleArr[j-2], z = circleArr[j-1];
            i64 mx = x;
            if(mx < y) mx = y;
            if(mx < z) mx = z;
            i64 mn = x;
            if(mn > y) mn = y;
            if(mn > z) mn = z;

            i64 tmp2 = addOrMinus_i64(mx, mn);
            if(dp[j-3] + tmp2 < dp[j]) dp[j] = dp[j-3] + tmp2;
        }
    }
    i64 cost = dp[size];
    free(circleArr);
    free(dp);
    return cost; 
}
i64 solve(i64* a, int size){
    if(size == 2) return Abs_i64(a[0] - a[1]);

    i64 best = (i64) INF;
    i64 t;
    t = circleTracking(a, size, 0);
    if(t < best) best = t;

    t = circleTracking(a, size, (size-1+size)%size);
    if(t < best) best = t;
    
    t = circleTracking(a, size, (size-2+size)%size);
    if(t < best) best = t;

    return best; 
}
int main(){
    int interval=-1;
    int size_of_arr;
    i64 *dynamic_arr;
    input(&interval, "%d");
    while(interval--){
        input(&size_of_arr, "%d");
        dynamic_arr = (i64*) malloc(size_of_arr*sizeof(i64));
        if(dynamic_arr == NULL) printf("ALLOCATION FAILED");
        for(int i = 0; i < size_of_arr; i++) input((dynamic_arr+i), "%lld");
        printf("%lld\n", solve(dynamic_arr, size_of_arr));
        free(dynamic_arr);
    }
    return 0;
}
