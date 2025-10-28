#include <stdio.h>
#include <stdlib.h>

// Function prototype for the tower function
void tower(int n, char sp, char ap, char dp);

int main()
{
    int n;
    printf("enter the number of discs: ");
    scanf("%d", &n);
    printf("The discs movements are:\n");
    tower(n, 'A', 'C', 'B');
    return 0;
}

void tower(int n, char sp, char ap, char dp)
{
    if (n == 1)
    {
        printf("\nMoving disc %d from %c to %c", n, sp, dp);
        return;
    }

    // Move n-1 discs from source (sp) to auxiliary (ap) using destination (dp) as auxiliary.
    tower(n - 1, sp, dp, ap);

    printf("\nMove disc %d from %c to %c", n, sp, dp);

    // Move n-1 discs from auxiliary (ap) to destination (dp) using source (sp) as auxiliary.
    tower(n - 1, ap, sp, dp);
}