#include<stdio.h>
#include<stdlib.h>
int main() {
    int n, i, min, max, sum = 0, avg;
    printf("Enter total number of elements :- ");
    scanf("%d", &n);
    int *p = (int *) malloc (n * sizeof(int));

    for(i=0;i<n;i++) {
        printf("Enter %d element :- ", i);
        scanf("%d", (p+i));        
    }
    for(i=0;i<n;i++) 
    {
        printf("You enter %d element is :- %d",i, *(p+i));
        printf("\n");
    }
    min = *p;
    for (i=0;i<n;i++)
    {
        if (*(p+i)<min ) 
        {
            min = (*(p+i));
        }
    }
    max = *p;
    for (i=0;i<n;i++) 
    {
        if (*(p+i)>max ) 
        {
            max = (*(p+i));   
        }
    }
    for(i=0;i<n;i++) 
    {
        sum += *(p+i);
    }
    avg = (sum/n);
    printf("min = %d\nmax = %d\navg = %d\n", min, max, avg);
    free(p);
}