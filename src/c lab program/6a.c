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

NODE insert_front(NODE first, int item) {
    NODE temp;
    temp = getnode();
    temp->info = item;
    temp->link = first;
    return temp;
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
        printf("List is empty\n");
        return first;
    }
    temp = first;
    first = first->link;
    printf("Deleted data is %d\n", temp->info);
    freenode(temp);
    return first;
}

NODE delete_rear(NODE first) {
    NODE prev, cur;
    if (first == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (first->link == NULL) {
        printf("Deleted data is %d\n", first->info);
        freenode(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while (cur->link != NULL) {
        prev = cur;
        cur = cur->link;
    }
    printf("Deleted data is %d\n", cur->info);
    freenode(cur);
    prev->link = NULL;
    return first;
}

void display(NODE first) {
    NODE temp;
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Contents of the Linked list are\n");
    temp = first;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

void search(int key, NODE first) {
    NODE cur;
    if (first == NULL) {
        printf("List is Empty\n");
        return;
    }
    cur = first;
    while (cur != NULL) {
        if (cur->info == key)
            break;
        else
            cur = cur->link;
    }
    if (cur == NULL) {
        printf("Search unsuccessful\n");
        return;
    }
    printf("Search Successful\n");
}

int main() {
    int choice, item;
    NODE first = NULL;
    
    for (;;) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Search\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                first = insert_front(first, item);
                break;
            case 2:
                printf("Enter the item: ");
                scanf("%d", &item);
                first = insert_rear(first, item);
                break;
            case 3:
                first = delete_front(first);
                break;
            case 4:
                first = delete_rear(first);
                break;
            case 5:
                display(first);
                break;
            case 6:
                printf("Enter the key to search: ");
                scanf("%d", &item);
                search(item, first);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}