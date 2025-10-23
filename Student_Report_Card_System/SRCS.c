#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
struct Student {
    char name[50];
    int roll;
    float marks[3];
    float average;
    char grade;
};

// Function prototypes
void addRecord();
void displayRecords();
void searchRecord();
char calculateGrade(float avg);

int main() {
    int choice;

    do {
        printf("\n===== STUDENT REPORT CARD SYSTEM =====\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to calculate grade based on average marks
char calculateGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 75) return 'B';
    else if (avg >= 60) return 'C';
    else if (avg >= 45) return 'D';
    else return 'F';
}

// Add new student record
void addRecord() {
    struct Student s;
    FILE *fp = fopen("students.dat", "ab"); // append in binary mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Name: ");
    getchar(); // clear buffer
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Marks in 3 Subjects: ");
    s.average = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%f", &s.marks[i]);
        s.average += s.marks[i];
    }

    s.average /= 3.0;
    s.grade = calculateGrade(s.average);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Record added successfully!\n");
}

// Display all student records
void displayRecords() {
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("No records found! Add a record first.\n");
        return;
    }

    printf("\n%-20s %-10s %-15s %-10s\n", "Name", "Roll No", "Average Marks", "Grade");
    printf("-------------------------------------------------------------\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("%-20s %-10d %-15.2f %-10c\n", s.name, s.roll, s.average, s.grade);
    }

    fclose(fp);
}

// Search for a specific student by roll number
void searchRecord() {
    int roll;
    int found = 0;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("\nRecord Found!\n");
            printf("Name: %s\nRoll No: %d\nAverage: %.2f\nGrade: %c\n",
                   s.name, s.roll, s.average, s.grade);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No record found for Roll No %d.\n", roll);

    fclose(fp);
}
