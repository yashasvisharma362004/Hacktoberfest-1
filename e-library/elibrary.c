//E-Library Management System in C


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct books{
    int id;
    char bookName[50];
    char authorName[50];
    char date[12];
}book;

struct student{
    int id;
    char sName[50];
    char sClass[50];
    int sRoll;
    char bookName[50];
    char date[12];
}student;

FILE *fp;
int main(){
    int ch;
    while(1){
        system("cls");
        printf("<== Library Management System ==>\n");
        printf("1.Add Book\n");
        printf("2.Books List\n");
        printf("3.Remove Book\n");
        printf("4.Issue Book\n");
        printf("5.Issued Book List\n");
        printf("0.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
        case 0:
            exit(0);
        case 1:
            addBook();
            break;
        case 2:
            booksList();
            break;
        case 3:
            del();
            break;
        case 4:
            issueBook();
            break;
        case 5:
            issueList();
            break;
        default:
            printf("Invalid Choice...\n\n");
        }
        printf("Press Any Key To Continue...");
        getch();
    }
    return 0;
}
//ADDING BOOKS
void addBook(){
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(book.date, myDate);
    fp = fopen("books.txt", "ab");
    printf("Enter book id: ");
    scanf("%d", &book.id);
    printf("Enter book name: ");
    fflush(stdin);
    gets(book.bookName);
    printf("Enter author name: ");
    fflush(stdin);
    gets(book.authorName);
    printf("Book Added Successfully");
    fwrite(&book, sizeof(book), 1, fp);
    fclose(fp);
}

//VIEWING BOOKS LIST
void booksList(){
    system("cls");
    printf("<== Available Books ==>\n\n");
    printf("%-10s %-30s %-20s %s\n\n", "Book id", "Book Name", "Author", "Date");
    fp = fopen("books.txt", "rb");
    while(fread(&book, sizeof(book), 1, fp) == 1){
        printf("%-10d %-30s %-20s %s\n", book.id, book.bookName, book.authorName, book.date);
    }
    fclose(fp);
}

//DELETING BOOKS FROM LIST
void del(){
    int id, f=0;
    system("cls");
    printf("<== Remove Books ==>\n\n");
    printf("Enter Book id to remove: ");
    scanf("%d", &id);
    FILE *ft;
    fp = fopen("books.txt", "rb");
    ft = fopen("temp.txt", "wb");
    while(fread(&book, sizeof(book), 1, fp) == 1){
        if(id == book.id){
            f=1;
        }else{
            fwrite(&book, sizeof(book), 1, ft);
        }
    }
    if(f==1){
        printf("\n\nDeleted Successfully.");
    }else{
        printf("\n\nRecord Not Found !");
    }
    fclose(fp);
    fclose(ft);
    remove("books.txt");
    rename("temp.txt", "books.txt");
}

//ISSUING BOOKS
void issueBook(){
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(student.date, myDate);
    int f=0;
    system("cls");
    printf("<== Issue Books ==>\n\n");
    printf("Enter Book id to issue: ");
    scanf("%d", &student.id);

//CHECKING IF WE HAVE BOOK OF GIVEN ID
    fp = fopen("books.txt", "rb");
    while(fread(&book, sizeof(book), 1, fp) == 1){
        if(book.id == student.id){
            strcpy(student.bookName, book.bookName);
            f=1;
            break;
        }
    }
    if(f==0){
        printf("No book found with this id\n");
        printf("Please try again...\n\n");
        return;
    }
    fp = fopen("issue.txt", "ab");
    printf("Enter Student Name: ");
    fflush(stdin);
    gets(student.sName);
    printf("Enter Student Email id: ");
    fflush(stdin);
    gets(student.sClass);
    printf("Enter Student Roll: ");
    scanf("%d", &student.sRoll);
    printf("Book Issued Successfully\n\n");
    fwrite(&student, sizeof(student), 1, fp);
    fclose(fp);
}

//VIEWING ISSUED BOOK LIST
void issueList(){
    system("cls");
    printf("<== Book Issue List ==>\n\n");
    printf("%-10s %-30s %-20s %-10s %-30s %s\n\n", "S.id", "Name", "Class", "Roll", "Book Name", "Date");
    fp = fopen("issue.txt", "rb");
    while(fread(&student, sizeof(student), 1, fp) == 1){
        printf("%-10d %-30s %-20s %-10d %-30s %s\n", student.id, student.sName, student.sClass, student.sRoll, student.bookName, student.date);
    }
    fclose(fp);
}