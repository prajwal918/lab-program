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

NODE insert_front(NODE last, int item) {
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = NULL;
    if (last == NULL) {
        last = temp;
        last->link = last;
    } else {
        temp->link = last->link;
        last->link = temp;
    }
    return last;
}

NODE insert_rear(NODE last, int item) {
    NODE temp;
    temp = getnode();
    temp->info = item;
    if (last == NULL) {
        last = temp;
        last->link = last;
    } else {
        temp->link = last->link;
        last->link = temp;
        last = temp;
    }
    return last;
}

NODE delete_front(NODE last) {
    NODE first;
    if (last == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (last->link == last) {
        printf("Item deleted is %d\n", last->info);
        freenode(last);
        return NULL;
    }
    first = last->link;
    last->link = first->link;
    printf("Item deleted is %d\n", first->info);
    freenode(first);
    return last;
}

NODE delete_rear(NODE last) {
    NODE prev;
    if (last == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (last->link == last) {
        printf("Item deleted is %d\n", last->info);
        freenode(last);
        return NULL;
    }
    prev = last->link;
    while (prev->link != last) {
        prev = prev->link;
    }
    prev->link = last->link;
    printf("Item deleted is %d\n", last->info);
    freenode(last);
    return prev;
}

void display(NODE last) {
    NODE temp;
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Contents of the Circular Linked list are\n");
    temp = last->link;
    while (temp != last) {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("%d\n", temp->info);
}

int main() {
    int choice, item;
    NODE last = NULL;
    
    for (;;) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                last = insert_front(last, item);
                break;
            case 2:
                printf("Enter the item: ");
                scanf("%d", &item);
                last = insert_rear(last, item);
                break;
            case 3:
                last = delete_front(last);
                break;
            case 4:
                last = delete_rear(last);
                break;
            case 5:
                display(last);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}