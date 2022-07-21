#define MAX 5

typedef struct stack{
    int data[MAX];
    int top;
}STACK;

void init(STACK *s) {
    s->top = -1;
}

void push(STACK *s, int val) {
    s->top++;
    s->data[s->top] = val;
}
//pop
int pop(STACK *s) {
    int val= NULL;
    val = s->data[s->top];
    s->top--;
    return val;
}
// peep
int peep(STACK *s) {
    int val = NULL;
    val = s->data[s->top];
}
// change
void change(STACK *s, int pos, int val) {
    int idx = pos;
    if(idx == 0 && idx <= s-> top){
        s->data[idx] = val;
    }
}
// display
void display(STACK *s) {
    int i;
    for(i=0;i <= s->top;i++){
        printf("%c",s->data[i]);
    }
}
// isEmpty
int isEmpty(STACK *s) {
    if(s->top == -1)
        return 1;
    else
        return 0;
}
// isFull
int isFull(STACK *s) {
    if(s->top == MAX-1)
        return 1;
    else
        return 0;
}