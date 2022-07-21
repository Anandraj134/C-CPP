#define MAX 5

typedef struct stack{
    int data[MAX];
    int top;
}STACK;
//operation on stack
//initialization
void init(STACK *s) {
    s->top = -1;
    printf("Stack Initialised.\n");
}
//push
void push(STACK *s, int val) {
    if(s->top == MAX-1) {
        printf("Stack Overflow.\n");
    }
    else {
        s->top++;
        s->data[s->top] = val;
        printf("Value Inserted.\n");
    }
}
//pop
int pop(STACK *s) {
    int val= NULL;
    if(s->top == -1) {
        printf("Stack Underflow.\n");
    }
    else {
        val = s->data[s->top];
        s->top--;
    }
    return val;
}
// peep
int peep(STACK *s) {
    int val = NULL;
    if(s->top == -1) {
        printf("Stack Underflow.\n");
    }
    else {
        val = s->data[s->top];
    }
}
// change
void change(STACK *s, int pos, int val) {
    int idx = pos;
    if(s -> top == -1) {
        printf("Stack Underflow.\n");
    }else{
        if(idx == 0 && idx <= s-> top){
            s->data[idx] = val;
            printf("Value Changed.\n");
        } else {
            printf("Invalid position.\n");
        }
    }
}
// display
void display(STACK *s) {
    int i;
    if(s->top == -1){
        printf("Stack Underflow.\n");
    }else{
        printf("Stack contains:\n");
        for(i = s->top;i>=0;i--){
            printf("%d\n",s->data[i]);
        }
    }
}
// isEmpty
int isEmpty(STACK *s) {
    if(s->top == -1)
        return 1;
    else
    {
        return 0;
    }
}

// isFull
int isFull(STACK *s) {
    if(s->top == MAX-1)
        return 1;
    else
    {
        return 0;
    }
}