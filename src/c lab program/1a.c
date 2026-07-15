#include <stdio.h>
#include <stdlib.h>

int a[100];
int pos, elem;
int n = 0;

void create();
void display();
void insert();
void del();

int main() {
    int choice;
    while (1) {
        printf("\n\n~~~~~MENU~~~~~");
        printf("\n->1: Create an array of n integers");
        printf("\n->2: Display the array elements");
        printf("\n->3: Insert an element at a given position");
        printf("\n->4: Delete an element at a given position");
        printf("\n->5: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                del();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid choice. Please enter a valid option.");
        }
    }
    return 0;
}

void create() {
    int i;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    if (n > 100) {
        printf("Error: Array size cannot exceed 100.\n");
        n = 0;
        return;
    }
    printf("Enter the %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void display() {
    int i;
    if (n == 0) {
        printf("\nThe array is empty.");
        return;
    }
    printf("\nThe array elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

void insert() {
    int i;
    if (n == 100) {
        printf("\nArray is full. Insertion not possible.");
        return;
    }

    do {
        printf("\nEnter a valid position to insert the element (0 to %d): ", n);
        scanf("%d", &pos);
    } while (pos > n || pos < 0);

    printf("\nEnter the value to be inserted: ");
    scanf("%d", &elem);

    for (i = n - 1; i >= pos; i--) {
        a[i + 1] = a[i];
    }

    a[pos] = elem;
    n = n + 1;

    printf("\nElement inserted successfully.");
    display();
}

void del() {
    int i;
    if (n == 0) {
        printf("\nArray is empty. Deletion not possible.");
        return;
    }

    do {
        printf("\nEnter a valid position to delete the element (0 to %d): ", n - 1);
        scanf("%d", &pos);
    } while (pos >= n || pos < 0);

    elem = a[pos];
    printf("\nDeleted element is: %d", elem);

    for (i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    n = n - 1;

    display();
}
