#include <stdio.h>

struct student {
    int rollno;
    char name[50];
    int sem;
    float mark1, mark2, mark3;
};

int main() {
    struct student s[5], *ptr;
    int i;
    float total, s1total = 0, s2total = 0, s3total = 0;

    ptr = s;

    // Input student details
    for (i = 0; i < 5; i++) {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", ptr->name);
        printf("Enter roll number: ");
        scanf("%d", &ptr->rollno);
        printf("Enter semester: ");
        scanf("%d", &ptr->sem);
        printf("Enter marks of subject 1: ");
        scanf("%f", &ptr->mark1);
        printf("Enter marks of subject 2: ");
        scanf("%f", &ptr->mark2);
        printf("Enter marks of subject 3: ");
        scanf("%f", &ptr->mark3);
        ptr++;
    }

    // Reset pointer
    ptr = s;

    // Display student details + total
    printf("\n--- Student Details and Totals ---\n");
    for (i = 0; i < 5; i++) {
        total = ptr->mark1 + ptr->mark2 + ptr->mark3;
        printf("\nName: %s, Roll No: %d, Semester: %d", ptr->name, ptr->rollno, ptr->sem);
        printf("\nMarks: %.2f, %.2f, %.2f", ptr->mark1, ptr->mark2, ptr->mark3);
        printf("\nTotal marks of student %d = %.2f\n", i + 1, total);
        ptr++;
    }

    // Reset pointer
    ptr = s;

    // Calculate subject-wise totals
    for (i = 0; i < 5; i++) {
        s1total += ptr->mark1;
        s2total += ptr->mark2;
        s3total += ptr->mark3;
        ptr++;
    }

    printf("\n--- Subject-wise Totals ---\n");
    printf("Subject 1 total = %.2f\n", s1total);
    printf("Subject 2 total = %.2f\n", s2total);
    printf("Subject 3 total = %.2f\n", s3total);

    return 0;
} 