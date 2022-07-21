#include <stdio.h>
int main() {
    int a[4],i,j;
    int *p;
    p = &a[0];
    for(i=1;i<=4;i++,p++) {
        printf("Enter %d value : ", i);
        scanf("%d", p);
        // printf("\n");
    }
    p = &a[0];
    for(i=0;i<4;i++) {
        printf("%d  ", *p);
        p++;
    }
}