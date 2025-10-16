#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define input(fmt, var) \
    scanf(fmt, var);

struct Pair{
    struct Pair* branch;
    int apple;
};
struct Pair initPair(struct Pair *f, int s){
    struct Pair root; 
    root.branch = f;
    root.apple = s;
    return root;
}

void viewBranch(struct Pair* root){
    struct Pair * tmp = root;
    printf("view branch\n");
    while(tmp->branch){
        if(tmp == NULL) break;
        printf("%d", tmp->apple);
    }
}

// 1 4 5 1 2
//struct Pair Sequence(int* root, int index){
//    if(root == NULL) return initPair(0, index);
//    return (*root < *(root+index) ? Sequence(root+1, index+1) : initPair(root, index));
//}


int compare_ints_asc(const void*a, const void* b){
    int arg1 = *(const int*) a;
    int arg2 = *(const int*) b;
    return ((arg1>arg2)?1:((arg1<arg2)?-1:0));
}
int main(){
    int interval = -1;
    input("%d", &interval);
    int* rs = malloc(interval*sizeof(int));
    int i = 0;
    while(interval--){
        int size;
        int result=1;
        input("%d", &size);
        int* tree = (int*)malloc(size*sizeof(int));
        for(int i = 0 ; i < size; i++){
            input("%d",(tree+i));
        
        }
        qsort(tree, size, sizeof(int), compare_ints_asc);
        for(int j = 0; j < size-1;j++){
            if(*(tree+j) < *(tree+j+1)){
                result++;
            }
        }
        rs[i++] = result;
        free(tree);
    }
    for(int j = 0; j < i; j++){
        printf("%d\n", rs[j]);
    }
    free(rs);
    return 0;
}
