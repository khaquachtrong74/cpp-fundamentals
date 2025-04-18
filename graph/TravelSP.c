#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int mat[30][30];
int ans[30];
int n = 0;
/*** INITIALIZE ***/

void initMat(int matrix[][30], int a[], int s) {
    FILE * file_ptr;

    file_ptr = fopen("Doc/inMat2.txt", "r");

    if (file_ptr == NULL) {
        printf("Can not find file!!!");
        exit(1);
    }

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (fscanf(file_ptr, "%d ", &n) == EOF) {
                break;
            }
            matrix[i][j] = n;
        }
        a[i] = -1;
    }

    fclose(file_ptr);
}

void printMatrix(int matrix[][30], int s) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

/*** PROCESSING ***/

void output(int a[], int s) {
    for (int i = 0; i < s; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

bool isValid(int a[], int idx, int i) {
    return a[idx] == -1 && a[i] == -1;
}

int findSmallest(int a[], int idx) {
    int sm = INT_MAX;
    int id = 0;
    for (int i = 0; i < 20; i++) {
        if (mat[idx][i] < sm && idx != i && isValid(a, idx, i)) {
            sm = mat[idx][i];
            id = i;
        }
    }
    return id;
}

void process(int a[], int idx, int count) {
    if (count == 20) {
        output(a, count);
    }
    else {
        int sm = findSmallest(a, idx);
        a[idx] = sm;
        process(a, sm, count + 1);
    }
}

int main() {

    initMat(mat, ans, 20);

    printf("Here is the Matrix from file:\n");
    printMatrix(mat, 20);

    process(ans, 0, 0);

    return 0;
}
