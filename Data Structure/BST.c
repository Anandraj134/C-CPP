//Binary Search Tree

#include<stdio.h>
#include "BST.h"

int main()
{
    NODE *tree = NULL;
    int val, ch;

    while(1)
    {
        printf("============================================\n");
        printf("Binary tree contains \n");
        Display(tree);
        printf("\n============================================\n");
        printf("Operation on BST :- \n");
        printf("1. Insert\n");
        printf("2. Delete.\n");
        printf("3. Exit");
         printf("============================================\n");
        printf("Please Enter your choice :- ");
        scanf("%d",&ch);
        printf("============================================\n");

        switch (ch)
        {
        case 1:
            printf("Please enter value :- ");
            scanf("%d", &val);
            tree = insert(tree, val);
            break;
        case 3:
            return 1;
            break;
        
        default:
        printf("Please select proper option.\n");
            break;
        }
    }
}