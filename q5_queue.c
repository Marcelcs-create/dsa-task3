/* Q5: Enqueue and dequeue operations on a (linear) queue using an array. */
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) { printf("Queue overflow\n"); return; }
    queue[++rear] = x;
    printf("Enqueued %d\n", x);
}

void dequeue(void) {
    if (front > rear) { printf("Queue underflow\n"); return; }
    printf("Dequeued %d\n", queue[front++]);
    if (front > rear) { front = 0; rear = -1; }   /* reset when empty */
}

void display(void) {
    if (front > rear) { printf("Queue is empty\n"); return; }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
    printf("\n");
}

int main(void) {
    int choice, x;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1: printf("Value: "); if (scanf("%d", &x) == 1) enqueue(x); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
