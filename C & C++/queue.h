#define MAX 5

typedef struct queue{
    int data[MAX];
    int f, r;
}QUEUE;
//operation on QUEUE
//initialization
void qinit(QUEUE *q) 
{
    q->f = -1;
    q->r = -1;

    printf("Queue Initialised.\n");
}
//insert
void qinsert(QUEUE *q, int val)
{
    if(q->r == MAX-1)
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        if(q->f == -1 && q->r == -1)
        {
            q->r = 0;
            q->f = 0;
        }
        else
        {
            q->r++;
        }
        q->data[q->r] = val;
        printf("Value Inserted.\n");
    }
}
//Delete
int qdelete(QUEUE *q)
{
    int val = NULL;
    if(q->f == -1 || q->f > q->r)
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        val = q->data[q->f];
        q->f++;
    }
    return val;    
}

//Peek
int qpeek(QUEUE *q)
{
    int val = NULL;
    if(q->f == -1 || q->f > q->r)
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        val = q->data[q->f];
    }
    return val;    
}

//Change
int qchange(QUEUE *q, int pos, int val)
{
    int a = 1;
    int idx = q->f + pos - 1;
    if(q->f == -1 || q->f > q->r)
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        if(q->f <= idx && idx <= q->r)
        {
            q->data[idx] = val;
            printf("Value Updated.\n");
            return a;
        }
        else
        {
            printf("Invalid Position");
        } 
    }
}
void qcdisplay(QUEUE *q)
{
    for(int i=q->f; i<=q->r; i++)
    {
        printf("%d ", q->data[i]);
    }
}

//Display
void qdisplay(QUEUE *q)
{
    if(q->f == -1 || q->f > q->r)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue Contains :- ");
        for(int i=q->f; i<=q->r; i++)
        {
            printf("%d ", q->data[i]);
        }
    }
}

//Is Empty
int isEmpty(QUEUE *q)
{
    if(q->f == -1 || q->f > q->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Is Full
int isFull(QUEUE *q)
{
    if(q->r == MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}