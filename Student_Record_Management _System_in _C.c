#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

// Function to add a student
void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.dat", "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &s.roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student added successfully!\n");
}

// Function to view all students
void viewStudents() {
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Roll No: %d\nName: %s\nMarks: %.2f\n\n", s.roll, s.name, s.marks);
    }
    fclose(fp);
}

// Function to search student by roll number
void searchStudent() {
    int roll;
    struct Student s;
    int found = 0;
    FILE *fp = fopen("students.dat", "rb");
    if (!fp) {
        printf("No records found.\n");
        return;
    }

    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("Record Found:\nRoll No: %d\nName: %s\nMarks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No student found with Roll No %d\n", roll);
    }
    fclose(fp);
}

// Function to delete a student record
void deleteStudent() {
    int roll;
    struct Student s;
    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    int found = 0;

    if (!fp || !temp) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll != roll) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);
    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("Record deleted successfully.\n");
    else
        printf("No student found with Roll No %d\n", roll);
}

int main() {
    int choice;
    do {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n2. View Students\n3. Search Student\n4. Delete Student\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}