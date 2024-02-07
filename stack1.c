#include <stdio.h>
#define MAXSTK 100

typedef struct stack{
    int top;
    int arr[MAXSTK];
} stack;

void initialize(stack *s){
    s->top = -1;
}

int isempty(stack *s){
    return (s->top == -1);
}
int isfull(stack *s){
    return (s->top == MAXSTK - 1);
}
int push(stack *s){
    int data;
    if(isfull(s)){
        printf("\nStack is full\n");
        return -1;
    }
    printf("\nEnter the element to be pushed: ");
    scanf("%d", &data);
    s->top++;
    s->arr[s->top] = data;
    
    printf("\nPushed element: %d", data);
}
int pop(stack *s){
    int deleted;
    if(isempty(s)){
        printf("\nStack is empty\n");
        return -1;
    }
    deleted = s->arr[s->top];
    s->top--;
    printf("\nDeleted element: %d\n", deleted);
}
int display(stack *s){
    if(isempty(s)){
        printf("\nStack is empty\n");
        return -1;
    }
    for (int i = 0; i <= s->top;i++){
        printf(" %d ", s->arr[i]);
    }
}

int main(){
    stack s;

    initialize(&s);
    push(&s);
    push(&s);
    push(&s);
    pop(&s);
    display(&s);
    return 0;
}
