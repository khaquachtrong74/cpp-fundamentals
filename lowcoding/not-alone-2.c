#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef long long i64;

static inline i64 llabsll(i64 x){ return x >= 0 ? x : -x; }

/* giữ tên hàm theo ý tưởng bạn: cộng/trừ -> thực chất là |a-b| cho chuẩn L1 */
static inline i64 addOrMinus(i64 a, i64 b, bool /*unused*/) {
    return llabsll(a - b);
}

static i64 run_one_rotation(const i64 *a, int n, int start){
    // copy mảng theo phép xoay start, để làm "vòng tròn -> tuyến tính"
    i64 *b = (i64*)malloc(sizeof(i64) * n);
    for(int i=0;i<n;i++) b[i] = a[(start + i) % n];

    const i64 INF = (i64)4e18;
    i64 *dp = (i64*)malloc(sizeof(i64) * (n+1));
    for(int i=0;i<=n;i++) dp[i] = INF;
    dp[0] = 0;

    for(int j = 2; j <= n; ++j){
        // ---- Phương án ghép 2 phần tử: (j-2, j-1)
        i64 tmp_01 = addOrMinus(b[j-2], b[j-1], true); // |x-y|
        if (dp[j-2] + tmp_01 < dp[j]) dp[j] = dp[j-2] + tmp_01;

        // ---- Phương án ghép 3 phần tử: (j-3, j-2, j-1)
        if (j >= 3) {
            i64 x = b[j-3], y = b[j-2], z = b[j-1];
            i64 mx = x; if (y > mx) mx = y; if (z > mx) mx = z;
            i64 mn = x; if (y > mn) mn = y; if (z > mn) mn = z;

            i64 tmp_02 = addOrMinus(mx, mn, false);  // mx - mn
            i64 tmp_03 = tmp_02;                     // giữ tên biến của bạn

            if (dp[j-3] + tmp_03 < dp[j]) dp[j] = dp[j-3] + tmp_03;
        }
    }

    i64 ans = dp[n];
    free(b); free(dp);
    return ans;
}

static i64 solve_one_case(i64 *a, int n){
    if (n == 2) return llabsll(a[0]-a[1]); // trường hợp đơn giản

    // thử 3 điểm cắt: 0, n-1, n-2 — giữ tinh thần “quét vòng” của bạn
    i64 best = (i64)4e18;
    i64 t;

    t = run_one_rotation(a, n, 0);        if (t < best) best = t;
    t = run_one_rotation(a, n, (n-1+n)%n);if (t < best) best = t;
    t = run_one_rotation(a, n, (n-2+n)%n);if (t < best) best = t;

    return best;
}

int main(void){
    int T = 1;                 // bạn đang để mặc định 1 test -> giữ nguyên
    if (scanf("%d", &T) != 1) T = 1; // nếu không nhập thì coi như 1 test

    while (T--){
        int size_of_arr;
        if (scanf("%d", &size_of_arr) != 1) return 0;

        i64 *dynamic_arr = (i64*)malloc(sizeof(i64) * size_of_arr);
        for (int i = 0; i < size_of_arr; ++i) scanf("%lld", &dynamic_arr[i]);

        i64 cost = solve_one_case(dynamic_arr, size_of_arr);
        printf("%lld\n", cost);

        free(dynamic_arr);
    }
    return 0;
}
