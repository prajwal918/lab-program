#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;

int isEmpty() {
    return rear < front;
}

int isFull() {
    return rear == MAX - 1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int val = queue[front];
    front++;
    return val;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
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
                value = dequeue();
                if (value != -1)
                    printf("Dequeued: %d\n", value);
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