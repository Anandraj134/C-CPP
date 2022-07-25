#include<stdio.h>
#include "DLL.h"

int main()
{
    NODE *start = NULL;
    int val, ch, pos, eval, nval;

    while(1)
    {
        printf("============================================\n");
        printf("\n");
        printf("DLL contains :- ");
        display(start);
        printf("\n");
        printf("\n============================================\n");
        printf("Operations on DLL :- \n");
        printf("1. InsertFirst\t\t2. InsertLast\n");
        printf("3. InsertAtPos\t\t4. InsertBefore\n");
        printf("5. InsertAfter\n");
        printf("6. DeleteFirst\t\t7. DeleteLast\n");
        printf("8. DeleteAtPos\t\t9. DeleteBefore\n");
        printf("10.DeleteAfter\t\t11.DeleteFirstOcc\n");
        printf("12.DeleteAllOcc\n");
        printf("13.Exit\n");
        printf("============================================\n");
        printf("Please Enter your choice :- ");
        scanf("%d",&ch);
        printf("============================================\n");
        
        switch (ch)
        {
        case 1:
            printf("Please enter value :- ");
            scanf("%d", &val);
            start = insertFirst(start, val);
            break;
        case 2:
            printf("Please enter value :- ");
            scanf("%d", &val);
            start = insertLast(start, val);
            break;
        case 3:
            printf("Please enter position :- ");
            scanf("%d", &pos);
            printf("Please enter value :- ");
            scanf("%d", &val);
            start = InsertAtPos(start, val, pos);
            break;
        case 4:
            printf("Please enter previous value:- ");
            scanf("%d", &eval);
            printf("Please enter new value:- ");
            scanf("%d", &nval);
            start = InsertBefore(start, eval, nval);
            break;
        case 5:
            printf("Please enter previous value:- ");
            scanf("%d", &eval);
            printf("Please enter new value:- ");
            scanf("%d", &nval);
            start = InsertAfter(start, eval, nval);
            break;
        case 6:
            start = DeleteFirst(start);
            break;
        case 7:
            start = DeleteLast(start);
            break;
        case 8:
            printf("Please enter position :- ");
            scanf("%d",&pos);
            start = DeleteAtPos(start, pos);
            break;
        case 9:
            printf("Please enter value :- ");
            scanf("%d",&eval);
            start = DeleteBefore(start, eval);
            break;
        case 10:
            printf("Please enter value :- ");
            scanf("%d",&eval);
            start = DeleteAfter(start, eval);
            break;
        case 11:
            printf("Please enter value :- ");
            scanf("%d",&eval);
            start = DeleteFirstOcc(start, eval);
            break;
        case 12:
            printf("Please enter value :- ");
            scanf("%d",&eval);
            start = DeleteAllOcc(start, eval);
            break;
        case 13:
            return 1;
        default:
            printf("Please select proper option.\n");
            break;
        }
    }
}