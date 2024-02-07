#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
};

struct CircularQueue *createQueue() {
    struct CircularQueue *queue = (struct CircularQueue *)malloc(sizeof(struct CircularQueue));
    queue->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    queue->front = queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isEmpty(struct CircularQueue *queue) {
    return (queue->size == 0);
}

int isFull(struct CircularQueue *queue) {
    return (queue->size == MAX_SIZE);
}

void enqueue(struct CircularQueue *queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", data);
        return;
    }
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->arr[queue->rear] = data;
    queue->size++;
    printf("%d enqueued to the queue.\n", data);
}

int dequeue(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return data;
}

void display(struct CircularQueue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the circular queue are: ");
    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE)
        printf("%d ", queue->arr[i]);
    printf("%d\n", queue->arr[i]);
}

int main() {
    struct CircularQueue *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    display(queue);

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    enqueue(queue, 6);
    enqueue(queue, 7);

    display(queue);

    return 0;
}
