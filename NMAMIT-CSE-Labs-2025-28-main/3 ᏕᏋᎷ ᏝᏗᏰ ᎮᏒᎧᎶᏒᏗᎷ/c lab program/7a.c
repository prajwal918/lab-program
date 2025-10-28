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

NODE insert_rear(NODE first, int item) {
    NODE temp, cur;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if (first == NULL) {
        return temp;
    }
    cur = first;
    while (cur->link != NULL) {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

NODE delete_front(NODE first) {
    NODE temp;
    if (first == NULL) {
        printf("Queue is empty\n");
        return first;
    }
    temp = first;
    first = first->link;
    printf("Deleted element is %d\n", temp->info);
    freenode(temp);
    return first;
}

void display(NODE first) {
    NODE temp;
    if (first == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents are:\n");
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int choice, item;
    NODE first = NULL;
    
    for (;;) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                first = insert_rear(first, item);
                break;
            case 2:
                first = delete_front(first);
                break;
            case 3:
                display(first);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}