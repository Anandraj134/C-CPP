#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

int main() {
    //variable of stack
    STACK s;
    int val, ch, pos, a;
    // call operations
    init(&s);
    while(1) {
        printf("\n<----------------------------------------------->\n");
        printf("Select option from below :\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
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
                push(&s, val);
                break;
            case 2:
                val = pop(&s);
                if(val!= NULL) 
                    printf("Popped value is :- %d", val); 
                break;
            case 3:
                val = peep(&s);
                if(val != NULL)
                    printf("Top value is :- %d", val);
                break;
            case 4:
                printf("Please enter a position :- ");
                scanf("%d", &pos);
                printf("Please enter a new value :- ");
                scanf("%d", &val);
                change(&s,pos,val);
                break;
            case 5:
                display(&s);
                break;
            case 6:
                if(isEmpty(&s)) {
                    printf("Stack is Empty");
                }
                else
                {
                    printf("Stack is not Empty");
                }
                
                break;
            case 7:
                 if(isFull(&s)) {
                    printf("Stack is Full");
                }
                else
                {
                    printf("Stack is not Full");
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