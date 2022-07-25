#include<stdio.h>

int fact(int x)
{
    if (x == 1)
    {
        return 1;
    }
    else
    {
        return x * fact(x-1);
    }
}

int main()
{
    int n;
    printf("Enter a number :- ");
    scanf("%d", &n);
    int factorial = fact(n);
    printf("%d!'s value is :- %d", n, factorial);
}