#include<stdio.h>
int main()
{
    int i, j, count=1, n, a[50];
    printf("Enter Number of Elements :- ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(count == 0)
        {
            break;
        }
        count = 0;
        for(j=0;j<n-i;j++)
        {
            if(a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                count++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
}