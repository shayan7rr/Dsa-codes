#include <stdio.h>
#define MAXQ 100
typedef struct queue{
    int f;
    int r;
    int arr[MAXQ];
} queue;

void initialize(queue *q){
    q->f = -1;
    q->r = -1;
}

int isfull(queue *q){
    return (q->r > MAXQ - 1);
}
int isempty(queue *q){
    return (q->f == -1 && q->r == -1);
}

int enqueue(queue *q,int data){
    if(isfull(q)){
        return -1;
    }
    else if(isempty(q)){
        q->f = q->r = 0;
    }
    else{
        q->r++;
    }
    q->arr[q->r] = data;
}

int dequeue(queue *q){
    int deleted;
    if(isempty(q)){
        return -1;
    }
    else if(q->f==q->r){
        deleted=q->arr[q->f];
        q->f = q->r = -1;
        }
    else{
        deleted=q->arr[q->f];
        q->f++;
    }
    return deleted;
}

void display(queue *q){
    if(isempty(q)){
        printf("\nQueue is empty\n");

    }
    else{
        for (int i = q->f; i <= q->r;i++){
            printf(" %d ", q->arr[i]);
        }
    }
}

int main(){
    queue q;
    initialize(&q);
    enqueue(&q, 100);
    enqueue(&q, 200);
    enqueue(&q, 300);
    dequeue(&q);
    display(&q);

    return 0;
}