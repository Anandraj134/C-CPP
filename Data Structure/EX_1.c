#include <stdio.h>
int main()
{
    int i ,j,a[10][10];
    float avg;
    int sum = 0;
    for (i=0;i<5;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("Enter a value : ");
            scanf("%d",&a[i][j]);
        }
    }
     for (i=0;i<5;i++)
    {
        for(j=0;j<2;j++)
        {
            sum += a[i][j];
        }
    }
    avg = sum/10.0;
    printf("%f",avg);
}