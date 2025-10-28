#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode() {
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Memory not available\n");
        exit(0);
    }
    return x;
}

void freenode(NODE x) {
    free(x);
}

NODE push(NODE top, int item) {
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = top;
    return temp;
}

NODE pop(NODE top) {
    NODE temp;
    if (top == NULL) {
        printf("Stack is empty\n");
        return top;
    }
    temp = top;
    top = top->link;
    printf("Popped element is %d\n", temp->info);
    freenode(temp);
    return top;
}

void display(NODE top) {
    NODE temp;
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents are:\n");
    temp = top;
    while (temp != NULL) {
        printf("%d\n", temp->info);
        temp = temp->link;
    }
}

int main() {
    int choice, item;
    NODE top = NULL;
    
    for (;;) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                top = push(top, item);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}