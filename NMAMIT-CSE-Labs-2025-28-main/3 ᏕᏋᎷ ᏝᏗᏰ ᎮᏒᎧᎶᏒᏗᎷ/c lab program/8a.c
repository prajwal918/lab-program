#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *llink;
    struct node *rlink;
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

NODE insert_front(NODE head, int item) {
    NODE temp, cur;
    temp = getnode();
    temp->info = item;
    if (head->rlink == NULL) {
        head->rlink = temp;
        temp->llink = head;
        temp->rlink = NULL;
        return head;
    } else {
        cur = head->rlink;
        temp->llink = head;
        temp->rlink = cur;
        head->rlink = temp;
        cur->llink = temp;
        return head;
    }
}

NODE insert_rear(NODE head, int item) {
    NODE temp, cur;
    temp = getnode();
    temp->info = item;
    if (head->rlink == NULL) {
        head->rlink = temp;
        temp->llink = head;
        temp->rlink = NULL;
        return head;
    }
    cur = head->rlink;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    temp->llink = cur;
    temp->rlink = NULL;
    cur->rlink = temp;
    return head;
}

NODE delete_front(NODE head) {
    NODE cur, temp;
    cur = head->rlink;
    if (head->rlink == NULL) {
        printf("List is empty\n");
    } else if (cur->rlink == NULL) {
        head->rlink = NULL;
        printf("%d deleted\n", cur->info);
        freenode(cur);
    } else {
        temp = cur->rlink;
        printf("%d deleted\n", cur->info);
        freenode(cur);
        head->rlink = temp;
        temp->llink = head;
    }
    return head;
}

NODE delete_rear(NODE head) {
    NODE cur, prev;
    if (head->rlink == NULL) {
        printf("List is Empty\n");
        return head;
    }
    cur = head->rlink;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    prev = cur->llink;
    prev->rlink = NULL;
    printf("Deleted is %d\n", cur->info);
    freenode(cur);
    return head;
}

void display(NODE head) {
    NODE temp;
    if (head->rlink == NULL) {
        printf("List is empty\n");
    } else {
        temp = head->rlink;
        printf("Contents of the Doubly Linked list are\n");
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->rlink;
        }
        printf("\n");
    }
}

int main() {
    int choice, item;
    NODE head;
    head = getnode();
    head->info = 0;
    head->llink = NULL;
    head->rlink = NULL;
    
    for (;;) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the item: ");
                scanf("%d", &item);
                head = insert_front(head, item);
                break;
            case 2:
                printf("Enter the item: ");
                scanf("%d", &item);
                head = insert_rear(head, item);
                break;
            case 3:
                head = delete_front(head);
                break;
            case 4:
                head = delete_rear(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}