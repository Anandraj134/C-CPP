#include<stdio.h>
int main()
{
    int i, j, n, min, a[50];
    printf("Enter Number of Elements :- ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    for(i=0;i<n;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
}