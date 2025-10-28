#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Defines the structure for the stack
struct stack {
    int top;
    int items[MAX];
};

// Function prototypes
void push(int, struct stack *);
void pop(struct stack *);
void display(struct stack *);

int main() {
    struct stack s;
    s.top = -1; // Initialize the top of the stack
    int choice, item;

    // Infinite loop for the menu
    for (;;) {
        printf("\nEnter your choice:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(item, &s);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// Function to add an item to the stack
void push(int item, struct stack *s) {
    if (s->top == MAX - 1) {
        printf("Stack is full. Cannot push item.\n");
    } else {
        s->top++;
        s->items[s->top] = item;
    }
}

// Function to remove an item from the stack
void pop(struct stack *s) {
    int item;
    if (s->top == -1) {
        printf("Stack is empty. Cannot pop item.\n");
    } else {
        item = s->items[s->top];
        s->top--;
        printf("%d deleted from the stack.\n", item);
    }
}

// Function to display the elements of the stack
void display(struct stack *s) {
    int t = s->top;
    if (s->top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Elements in the stack are: ");
        while (t > -1) {
            printf("%d ", s->items[t--]);
        }
        printf("\n");
    }
}
