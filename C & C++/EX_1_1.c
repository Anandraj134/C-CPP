#include <stdio.h>
//Sort By Value
void SBV(int x, int y){
    printf("\tBefore swap : A = %d & B = %d\n", x,y); 
    int temp = x;
    x = y;
    y = temp;
    printf("\tAfter swap : A = %d & B = %d\n", x,y);
}
//Sort By Referance
void SBR(int *x, int *y) {
    printf("\tBefore swap : A = %d & B = %d\n", *x, *y); 
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("\tAfter swap : A = %d & B = %d\n", *x,*y);
}
int main() {
    int m,n;
    printf("Please enter 1st number :- ");
    scanf("%d", &m);
    printf("Please enter 2nd number :- ");
    scanf("%d", &n);
    printf("Call by Val : \n");
    printf("\tBefore Call : A = %d  & B = %d\n", m,n);
    SBV(m,n);
    printf("\tAfter Call : A = %d  & B = %d\n", m,n);
    printf("Call By Ref : \n");
    printf("\tBefore call : A = %d & B = %d\n", m ,n);
    SBR(&m,&n);
    printf("\tAfter Call : A = %d & B = %d\n", m ,n);
}