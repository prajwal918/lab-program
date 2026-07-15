#include <stdio.h>

#define MAX 100

struct Queue {
    int queue[MAX];
    int front;
    int rear;
};

struct Queue q = { .front = 0, .rear = -1 };

void enqueue(int value) {
    if (q.rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    q.rear++;
    q.queue[q.rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (q.front > q.rear) {
        printf("Queue is empty\n");
        return;
    }
    int val = q.queue[q.front];
    q.front++;
    printf("Deleted item is: %d\n", val);
}

void display() {
    if (q.front > q.rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}