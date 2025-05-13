#include <stdio.h>
int main(void){
    printf("Hello, World!\n");
    char c;
    printf("Enter one character ");
    scanf("%s",&c);
    printf("%s", &c);
    return 0;
}
