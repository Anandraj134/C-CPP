#define MAX 5

typedef struct queue{
    int data[MAX];
    int f, r;
}CQUEUE;

//initialization
void cqinit(CQUEUE *q) 
{
    q->f = -1;
    q->r = -1;

    printf("Queue Initialised.\n");
}
//insert
void cqinsert(CQUEUE *q, int val)
{
    if((q->r == MAX-1 && q->f == 0)||(q->f == q->r+1))
    {
        printf("Queue Overflow.\n");
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
            q->r = (q->r+1) % MAX;
        }
        q->data[q->r] = val;
        printf("Value Inserted.\n");
    }
}
//Delete
int cqdelete(CQUEUE *q)
{
    int val = NULL;
    if(q->f == -1 && q->r == -1)
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        val = q->data[q->f];
        if (q->f == q->r)
        {
            q->f = -1;
            q->r = -1;
        }
        else
        {
            q->f = (q->f+1)%MAX;
        }
    }
    return val;    
}

//Peek
int cqpeek(CQUEUE *q)
{
    int val = NULL;
    if(q->f == -1 && q->r == -1)
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
int cqchange(CQUEUE *q, int pos, int val)
{
    int a = 1;
    int idx = (q->f + pos - 1)%MAX;
    if(pos > MAX)
    {
        printf("Invalid position.\nMax size is %d\n", MAX);
    }
    else if(q->f == -1 && q->r == -1)
    {
        printf("Queue is empty. There is nothing to update.\n");
    }
    else
    {
        if((q->f <= q->r) && (q->f <= idx && idx <= q->r))
        {
            q->data[idx] = val;
            printf("Value Updated.\n");
            return a;
        }
        else if((q->f > q->r) && ((q->f <= idx && idx < MAX) || (0 <= idx && idx <= q->r)))
        {
            q->data[idx] = val;
            printf("Value Updated.\n");
            return a;
        }
        else
        {
            printf("Invalid position.\n");
        }
    }
}

void ccqchange(CQUEUE *q)
{
if(q->f <= q->r)
    {
        for(int i=q->f; i<=q->r; i++)
        {
            //Print f---------r
            printf("%d ", q->data[i]);
        }
    }
    else
    {
        for(int i=q->f; i<MAX; i++)
        {
            // Print f-------MAX
            printf("%d ", q->data[i]);
        }
        for(int i=0; i<=q->r; i++)
        {
            //Print 0---------r
            printf("%d ", q->data[i]);
        }
    }
}

//Display
void cqdisplay(CQUEUE *q)
{
    if(q->f == -1 && q->r == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue Contains :- ");
        if(q->f <= q->r)
        {
            for(int i=q->f; i<=q->r; i++)
            {
                //Print f---------r
                printf("%d ", q->data[i]);
            }
        }
        else
        {
            for(int i=q->f; i<MAX; i++)
            {
                // Print f-------MAX
                printf("%d ", q->data[i]);
            }
            for(int i=0; i<=q->r; i++)
            {
                //Print 0---------r
                printf("%d ", q->data[i]);
            }
        }
    }
}

//Is Empty
int isEmpty(CQUEUE *q)
{
    if(q->f == -1 && q->r == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Is Full
int isFull(CQUEUE *q)
{
    if((q->r == MAX-1 && q->f == 0)||(q->f == q->r+1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}