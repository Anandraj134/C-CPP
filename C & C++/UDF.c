#include <stdio.h>
int add(int a, int b)
{
    return(a+b);
}
int main()
{
    int m,n;
    printf("Enter 2 value : ");
    scanf("%D %d", &m, &n);
    printf("Before \n");
    printf("%d %d", m,n);
    printf("\n\n");

    int temp = m;
    m = n;
    n = temp;

    printf("After \n");
    printf("%d %d", m,n);
    printf("\n");
    
    int v;
    v = add(m,n);
    printf("\nValues : %d", v);
}