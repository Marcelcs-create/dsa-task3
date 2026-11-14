/* Q7: Double-ended queue (circular array) with front/rear insertion and deletion. */
#include <stdio.h>

#define SIZE 5

int dq[SIZE];
int front = 0, count = 0;

int isFull(void)  { return count == SIZE; }
int isEmpty(void) { return count == 0; }

void insertFront(int x) {
    if (isFull()) { printf("Deque overflow\n"); return; }
    front = (front - 1 + SIZE) % SIZE;
    dq[front] = x;
    count++;
}

void insertRear(int x) {
    if (isFull()) { printf("Deque overflow\n"); return; }
    dq[(front + count) % SIZE] = x;
    count++;
}

int deleteFront(void) {
    if (isEmpty()) { printf("Deque underflow\n"); return -1; }
    int x = dq[front];
    front = (front + 1) % SIZE;
    count--;
    return x;
}

int deleteRear(void) {
    if (isEmpty()) { printf("Deque underflow\n"); return -1; }
    int x = dq[(front + count - 1) % SIZE];
    count--;
    return x;
}

void display(void) {
    if (isEmpty()) { printf("Deque is empty\n"); return; }
    printf("Deque (front -> rear): ");
    for (int i = 0; i < count; i++) printf("%d ", dq[(front + i) % SIZE]);
    printf("\n");
}

int main(void) {
    int choice, x;
    do {
        printf("\n1.Insert front 2.Insert rear 3.Delete front 4.Delete rear 5.Display 6.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1: printf("Value: "); if (scanf("%d", &x) == 1) insertFront(x); break;
            case 2: printf("Value: "); if (scanf("%d", &x) == 1) insertRear(x); break;
            case 3: x = deleteFront(); if (x != -1) printf("Deleted %d from front\n", x); break;
            case 4: x = deleteRear();  if (x != -1) printf("Deleted %d from rear\n", x); break;
            case 5: display(); break;
            case 6: break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}
