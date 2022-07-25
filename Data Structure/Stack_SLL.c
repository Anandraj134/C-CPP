#include<stdio.h>
#include<stdlib.h>
struct stack_sll
{
    int data;
    struct stack_sll *next;
};
struct stack_sll *start=NULL;
void push() {
    struct stack_sll *newnode;
    int value;
    newnode=(struct stack_sll*)malloc(sizeof(struct stack_sll));
    if(newnode==NULL)
    {
        printf("Stack overflow. Memory NOT available.");
        return;
    }
    printf("Enter a value:");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = start;
    start = newnode;
    printf("Insertion done.");
}

void pop()
{
    struct stack_sll *temp;
    if(start==NULL)
    {
        printf("Stack underflow.");
        return;
    }
    temp = start;
    start = start->next;
    printf("%d is deleted.", temp->data);
    free(temp);
}

void display()
{
    struct stack_sll *ptr;
    if(start==NULL)
        printf("stack is Empty.");
    else{
        printf("stack is:");
        for(ptr=start;ptr!=NULL;ptr=ptr->next)
            printf("%d ", ptr->data);
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n\nStack using Linked List");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0); break;
            default: printf("Invalid choice.");
        }
    }
}
