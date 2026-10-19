
#include <stdio.h>

#define MAX 100

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void addStudent(struct Student students[], int *count) {
    if (*count >= MAX) {
        printf("Student record limit reached!\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &students[*count].rollNo);

    printf("Enter name (without spaces): ");
    scanf("%49s", students[*count].name);

    printf("Enter marks (0-100): ");
    scanf("%f", &students[*count].marks);

    if (students[*count].marks < 0 ||
        students[*count].marks > 100) {
        printf("Invalid marks! Record not added.\n");
        return;
    }

    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(struct Student students[], int count) {
    int i;

    if (count == 0) {
        printf("No student records available.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    printf("%-10s %-20s %-10s\n",
           "Roll No", "Name", "Marks");

    for (i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].marks);
    }
}

void searchStudent(struct Student students[], int count) {
    int roll, i;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("\nStudent found!\n");
            printf("Roll No: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }

    printf("Student not found.\n");
}

int main(void) {
    struct Student students[MAX];
    int count = 0, choice;

    do {
        printf("\n===== Student Management =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
