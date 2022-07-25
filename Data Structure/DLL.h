#include<stdlib.h>

typedef struct nnode
{
    struct nnode *prev;
    int data;
    struct nnode *next;
} NODE;

display(NODE *start)
{
    NODE *tr = start;
    if(start == NULL)
    {
        printf("LinkedList is empty.");
    }
    else
    {
        while (tr != NULL)
        {
            printf("%d", tr->data);
            if (tr->next != NULL)
            {
                printf(" -> ");
            }
            tr = tr->next;
        }
    }
}

NODE* createNode()
{
    NODE *n = (NODE *) malloc(sizeof(NODE));
    n->data = NULL;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

NODE* insertFirst(NODE *start, int val)
{
    NODE *n= createNode();
    n->data = val;
    if(start == NULL)
    {
        n->prev = NULL;
        n->next = NULL;
        start = n;
    }
    else
    {
        // n->data = val;
        n->prev = NULL;
        n->next = start;
        start->prev = n;
        start = n;
    }
    return start;
}

NODE* insertLast(NODE *start, int val)
{
    NODE *tr = start;
    NODE *n = createNode();
    n->data = val;
    n->next = NULL;

    if(start == NULL)
    {
        n->prev = NULL;
        start = n;
    }
    else
    {
        while (tr->next != NULL)
        {
            tr = tr->next;
        }
        tr->next = n;
        n->prev = tr;
    }
    return start;
}

NODE* InsertAtPos(NODE *start, int val, int pos)
{
    NODE *tr = start;
    int count = 1;
    NODE *n = createNode();
    n->data = val;
    if(pos == 1)
    {
        n->prev = NULL;
        n->next = NULL;
        start = n;
    }
    else
    {
        while (tr != NULL && count != pos-1)
        {
            tr = tr->next;
            count+=1;
        }
        if (tr != NULL)
        {
            n->prev = tr;
            n->next = tr->next;
            if(tr->next != NULL)
            {
                (tr->next)->prev = n;
            }
            tr->next = n;                
        }
        else
        {
            printf("Invalid position.\n");
            free(n);
        }
    }
    return start;
}

NODE* InsertBefore(NODE *start, int eval, int nval)
{
    NODE *tr = start;
    NODE *pretr = NULL;
    NODE *n = createNode();
    n->data = nval;
    if(start == NULL)
    {
        printf("Linked list Underflow.\n");
        free(n);
    }
    else if (tr->data == eval)
    {
        n->prev = NULL;
        n->next = start;
        start->prev = n;
        start = n;
    }
    else
    {
        while (tr != NULL && tr->data != eval)
        {
            pretr = tr;
            tr = tr->next;
        }
        if (tr != NULL)
        {
            n->prev = pretr;
            n->next = tr;
            tr->prev = n;
            pretr->next = n;
        }
        else
        {
            printf("Value not found.\n");
            free(n);
        }
    }
    return start;
}

NODE* InsertAfter(NODE *start, int eval, int nval)
{
    NODE *n = createNode();
    NODE *tr = start;
    n->data = nval;
    if(start == NULL)
    {
        printf("Linked list Underflow.\n");
    }
    else
    {    
        while (tr != NULL && tr->data != eval)
        {
            tr = tr->next;
        }
        if (tr != NULL)
        {
            n->prev = tr;
            n->next = tr->next;
            tr->next = n;
            tr->next->prev = n;
        }
        else
        {
            printf("Value not found.\n");
            free(n);
        }
    }
    return start;
}

NODE* DeleteFirst(NODE *start)
{
    NODE *tr = start;
    if (start == NULL)
    {
        printf("Linked List Underflow.\n");
    }
    else
    {
        if(start->next != NULL)
        {
            start = tr->next;
            tr->next->prev = start;
            printf("Deleted value is %d.\n", tr->data);
        }
        else
        {
            printf("Deleted value is %d.\n", tr->data);
            start = NULL;
        }
        free(tr);
    }
    return start;
}

NODE* DeleteLast(NODE *start)
{
    NODE *tr = start;
    NODE *pretr = NULL;
    if(start == NULL)
    {
        printf("Linked List Underflow.\n");
    }
    else if(start->next == NULL)
    {
        printf("Deleted value is %d.\n",tr->data);
        free(start);
        start = NULL;
    }
    else
    {
        while (tr->next != NULL)
        {
            pretr = tr;
            tr = tr->next;
        }
        printf("Deleted value is %d.\n",tr->data);
        pretr->next = NULL;
        free(tr);
    }
    return start;
}

NODE* DeleteAtPos(NODE *start, int pos)
{
    NODE* tr = start;
    NODE* pretr = NULL;
    int count = 1;
    if(start == NULL)
    {
        printf("Linked List Underflow.\n");
    }
    else if(pos == 1)
    {
        if(start->next != NULL)
        {
            start = tr->next;
            tr->next->prev = start;
            printf("Deleted value is %d.\n", tr->data);
        }
        else
        {
            printf("Deleted value is %d.\n", tr->data);
            start = NULL;
        }
    }
    else
    {
        while (count < pos && tr != NULL)
        {
            pretr = tr;
            tr = tr->next;
            count+=1;
        }
        if(tr == NULL)
        {
            printf("Invalid Position.\n");
        }
        else
        {
            if(tr->next != NULL)
            {
                printf("Deleted value is %d.\n", tr->data);
                pretr->next = tr->next;
                tr->next->prev = pretr;
            }
            else
            {
                printf("Deleted value is %d.\n",tr->data);
                pretr->next = NULL;
            }
            free(tr);
        }
    }
    return start;
}

NODE* DeleteBefore(NODE *start, int eval)
{
    NODE *tr = start;
    NODE *pretr = NULL;
    if(start->data == eval || start == NULL)
    {
        printf("Linked List Underflow.\n");
    }
    else if((start->next)->data == eval)
    {
        start = start->next;
        start->next->prev = NULL;
        free(tr);
    }
    else
    {
        while (tr->next != NULL && (tr->next)->data != eval)
        {
            pretr = tr;
            tr = tr->next;
        }
    }
    if (tr->next == NULL)
    {
        printf("Value not found.\n");
    }
    else
    {
        pretr->next = tr->next;
        tr->next->prev = pretr;
        free(tr);
    }
    return start;
}

NODE* DeleteAfter(NODE *start, int eval)
{
    NODE* tr = start;
    NODE *pretr = NULL;
    if(start == NULL)
    {
        printf("Linked List Underslow.\n");
    }
    else
    {
        while (tr != NULL && tr->data != eval)
        {
            tr = tr->next;
        }
        if (tr == NULL)
        {
            printf("Value not found.\n");
        }
        else if (tr->next == NULL)
        {
            printf("Nothing to Delete.\n");
        } 
        else
        {
            pretr = tr->next;
            tr->next = pretr->next;
            if(pretr->next != NULL)
            {
                pretr->next->prev = tr;
            }
            printf("Deleted value is %d.\n", pretr->data);
            free(pretr);
        }
    }
    return start;
}

NODE* DeleteFirstOcc(NODE *start, int eval)
{
    NODE* tr = start;
    NODE* pretr = NULL;
    int c = 1;
    if(start == NULL)
    {
        printf("Linked List Underflow.\n");
    }
    else if(start->data == eval)
    {
        printf("Deleted value is %d.", start->data);
        start = start->next;
        free(tr);
    }
    else
    {
        while (tr != NULL && tr->data != eval)
        {
            pretr = tr;
            tr = tr->next;
            // printf("%d\n",c);
            // c++;
        }
        if (tr->data == eval)
        {
           printf("Value not found.\n");
        }
        else
        {
            if(tr->next != NULL)
            {
                printf("Deleted value is %d.\n", tr->data);
                pretr->next = tr->next;
                tr->next->prev = pretr;
            }
            else
            {
                printf("Deleted value is %d.\n",tr->data);
                pretr->next = NULL;
            }
            free(tr);
        }
    }
    return start;
}

NODE* DeleteAllOcc(NODE *start, int eval)
{
    NODE *tr;
    NODE *pretr;
    int count = 0;
    if (start == NULL)
    {
        printf("Linked List Underflow.\n");
    }
    while (start->data == eval && start != NULL)
    {
        tr = start;
        start = start->next;
        start->next->prev = start;
        free(tr);
        count++;
    }
    tr = start->next;
    pretr = start;
    while (tr != NULL)
    {
        if(tr->data == eval)
        {
            if(tr->next != NULL)
            {
                pretr->next = tr->next;
                tr->next->prev = pretr;
            }
            else
            {
                pretr->next = NULL;
            }
            free(tr);
            tr = pretr;
            count++;
        }
        pretr = tr;
        tr = tr->next;
    }
    if (count == 0)
    {
        printf("Value not found.\n");
    }
    else
    {
        printf("Entered value '%d' deleted %d times.\n", eval, count);
    }
    return start;
}