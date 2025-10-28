#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

int top = -1;

void push(int a[], int item)
{
    top = top + 1;
    a[top] = item;
}

int pop(int a[])
{
    int item;
    item = a[top];
    top = top - 1;
    return item;
}

void display(int a[])
{
    int i;
    if (top == -1)
    {
        printf("the stack is empty");
    }
    else
    {
        printf("the stack elements are ");
    }
    for (i = top; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[10], choice, item;
    while (1)
    {
        printf("Enter the choice \n");
        printf("\n 1.push \n 2.pop \n 3.Display \n 4.Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (top == MAXSIZE - 1)
            {
                printf("the stack is full\n");
            }
            else
            {
                printf("enter the element to be pushed: ");
                scanf("%d", &item);
                push(a, item);
            }
            break;

        case 2:
            if (top == -1)
            {
                printf("the stack is empty\n");
            }
            else
            {
                item = pop(a);
                printf("Popped element: %d\n", item);
            }
            break;

        case 3:
            display(a);
            break;

        case 4:
            exit(0);
        }
    }
    return 0;
}
