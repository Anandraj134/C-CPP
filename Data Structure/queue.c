#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

int main() {
    //variable of queue
    QUEUE q;
    int val, ch, pos, a;
    // call operations
    qinit(&q);
    while(1) {
        printf("\n<----------------------------------------------->\n");
        printf("Select option from below :\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Change\n");
        printf("5. Display\n");
        printf("6. isEmpty\n");
        printf("7. isFull\n");
        printf("8. Exit\n");
        printf("=================================================\n");
        printf("Choose Your Operation :- ");
        scanf("%d", &ch);
         printf("<----------------------------------------------->\n");

        switch (ch) {
            case 1:
                printf("Enter a value :- ");
                scanf("%d", &val);
                qinsert(&q, val);
                break;
            case 2:
                val = qdelete(&q);
                if(val!= NULL) 
                    printf("Popped value is :- %d", val); 
                break;
            case 3:
                val = qpeek(&q);
                if(val != NULL)
                    printf("Top value is :- %d", val);
                break;
            case 4:
                printf("Please enter a position :- ");
                scanf("%d", &pos);
                printf("Please enter a new value :- ");
                scanf("%d", &val);
                qchange(&q,pos,val);
                if(a)
                {
                    printf("Updated queue is :- ");
                    qcdisplay(&q);
                    printf("\n");
                }
                break;
            case 5:
                qdisplay(&q);
                break;
            case 6:
                if(isEmpty(&q)) {
                    printf("Queue is Empty");
                }
                else
                {
                    printf("Queue is not Empty");
                }
                break;
            case 7:
                 if(isFull(&q)) {
                    printf("Queue is Full");
                }
                else
                {
                    printf("Queue is not Full");
                }
                break;
            case 8:
                return 0;
            default:
                printf("Please select proper option.\n");
        }
    }   
    return 0;
}