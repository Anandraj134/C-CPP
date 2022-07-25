#include <stdio.h>
int main()
{
   int*m,*n, a, b;
   
   printf("Enter 2 values : ");
   scanf("%d %d", &a,&b);
   printf("Before \n%d %d\n", a, b);
   int temp = a;
   a = b;
   b = temp; 
   
   m = &a;
   n = &b;

   printf("After \n%d %d\n", *m, *n);
}