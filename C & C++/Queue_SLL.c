#include<stdio.h>
#include<stdlib.h>
struct sll_queue
{
    int data;
    struct sll_queue *next;
};
struct sll_queue *front=NULL, *rear=NULL;
int value;
void insert()
{
    struct sll_queue *newnode;
     newnode = (struct sll_queue*)malloc(sizeof(struct sll_queue));
    if(newnode==NULL)
    {
        printf("Memory NOT available.");
        return;
    }
    printf("Enter a value:");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;
    if(front==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Insertion done.");
}

void del()
{
    struct sll_queue *temp;
    if(front==NULL)
    {
        printf("List is Empty.");
        return;
    }
    temp = front;
    printf("%d is deleted.",front->data);
    if(front==rear)
        front=rear=NULL;
    else
        front=front->next;
    free(temp);
}

void display()
{
    struct sll_queue *ptr;
    if(front==NULL)
        printf("List is Empty.");
    else{
        printf("List is:");
        for(ptr=front;ptr!=NULL;ptr=ptr->next)
            printf("%d ", ptr->data);
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n\nQueue using Link list:");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: insert();  break;
            case 2: del();     break;
            case 3: display(); break;
            case 4: exit(0);    break;
            default: printf("Invalid choice.");
        }
    }
}
