/* Q1: Circular queue using a fixed-size array.
 * Fixes the main weakness of a linear queue: space freed by dequeues is reused. */
#include <stdio.h>

#define SIZE 5

typedef struct {
    int items[SIZE];
    int front;  /* index of first element */
    int count;  /* number of elements; distinguishes full from empty */
} CircularQueue;

void init(CircularQueue *q)            { q->front = 0; q->count = 0; }
int  isEmpty(const CircularQueue *q)   { return q->count == 0; }
int  isFull(const CircularQueue *q)    { return q->count == SIZE; }

int enqueue(CircularQueue *q, int value) {
    if (isFull(q)) { printf("Queue overflow: cannot insert %d\n", value); return 0; }
    int rear = (q->front + q->count) % SIZE;   /* wrap around */
    q->items[rear] = value;
    q->count++;
    return 1;
}

int dequeue(CircularQueue *q, int *value) {
    if (isEmpty(q)) { printf("Queue underflow\n"); return 0; }
    *value = q->items[q->front];
    q->front = (q->front + 1) % SIZE;          /* wrap around */
    q->count--;
    return 1;
}

void display(const CircularQueue *q) {
    if (isEmpty(q)) { printf("Queue is empty\n"); return; }
    printf("Queue (front -> rear): ");
    for (int i = 0, idx = q->front; i < q->count; i++, idx = (idx + 1) % SIZE)
        printf("%d ", q->items[idx]);
    printf("\n");
}

int main(void) {
    CircularQueue q;
    int v;
    init(&q);
    for (int i = 1; i <= 5; i++) enqueue(&q, i * 10);
    display(&q);
    enqueue(&q, 60);                       /* full -> overflow */
    dequeue(&q, &v); printf("Dequeued %d\n", v);
    dequeue(&q, &v); printf("Dequeued %d\n", v);
    enqueue(&q, 60);                       /* reuses freed slots (wraps) */
    enqueue(&q, 70);
    display(&q);
    return 0;
}
