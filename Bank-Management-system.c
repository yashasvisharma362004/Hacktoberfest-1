#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* To build a simple but functional banking system that simulates real-world banking tasks while demonstrating core programming skills such as dynamic memory allocation, data structures (linked lists), and user interaction in C. The project showcases how fundamental concepts can be combined to solve practical problems efficiently and clearly.
What functionalities to include:
1.Created a system to manage multiple bank accounts dynamically.
2.Implemented basic banking operations: account creation, deposit, withdrawal.
3.Added complex operations: fund transfer, applying interest rates, deleting accounts.
4.Enabled search by account number or name.
5.Used linked lists to efficiently store and update account data.
6.Provided a menu-driven interface for easy navigation and use.
7.Ensured robustness with input validation and uniqueness checks.*/
typedef struct Account {
    int accountNumber;
    char name[50];
    float balance;
    struct Account *next;
} Account;

Account *head = NULL;


void createAccount() {
    Account *newAcc = (Account*) malloc(sizeof(Account));
    printf("Enter Account Number: ");
    scanf("%d", &newAcc->accountNumber);
    Account *temp = head;
    while (temp != NULL) {
        if (temp->accountNumber == newAcc->accountNumber) {
            printf("Account number already exists!\n");
            free(newAcc);
            return;
        }
        temp = temp->next;
    }

    printf("Enter Account Holder Name: ");
    getchar();
    fgets(newAcc->name, 50, stdin);
    newAcc->name[strcspn(newAcc->name, "\n")] = 0; 
    newAcc->balance = 0.0f;
    newAcc->next = NULL;

    if (head == NULL) {
        head = newAcc;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newAcc;
    }

    printf("Account created successfully!\n");
}


Account* findAccount(int accountNumber) {
    Account *temp = head;
    while (temp != NULL) {
        if (temp->accountNumber == accountNumber)
            return temp;
        temp = temp->next;
    }
    return NULL;
}


void findAccountsByName(char *name) {
    Account *temp = head;
    int found = 0;
    printf("Accounts with name \"%s\":\n", name);
    printf("%-15s %-20s %-10s\n", "Account Number", "Account Holder", "Balance");
    while (temp != NULL) {
        if (strcasecmp(temp->name, name) == 0) {
            printf("%-15d %-20s %-10.2f\n", temp->accountNumber, temp->name, temp->balance);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) printf("No accounts found with this name.\n");
}


void deposit() {
    int accNum;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accNum);
    Account *acc = findAccount(accNum);
    if (!acc) {
        printf("Account not found!\n");
        return;
    }
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }
    acc->balance += amount;
    printf("Amount deposited successfully. New Balance: %.2f\n", acc->balance);
}


void withdraw() {
    int accNum;
    float amount;
    printf("Enter Account Number: ");
    scanf("%d", &accNum);
    Account *acc = findAccount(accNum);
    if (!acc) {
        printf("Account not found!\n");
        return;
    }
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0 || amount > acc->balance) {
        printf("Invalid amount or insufficient balance!\n");
        return;
    }
    acc->balance -= amount;
    printf("Amount withdrawn successfully. Remaining Balance: %.2f\n", acc->balance);
}


void transfer() {
    int fromAccNum, toAccNum;
    float amount;
    printf("Enter Sender Account Number: ");
    scanf("%d", &fromAccNum);
    Account *fromAcc = findAccount(fromAccNum);
    if (!fromAcc) {
        printf("Sender account not found!\n");
        return;
    }
    printf("Enter Receiver Account Number: ");
    scanf("%d", &toAccNum);
    Account *toAcc = findAccount(toAccNum);
    if (!toAcc) {
        printf("Receiver account not found!\n");
        return;
    }
    printf("Enter amount to transfer: ");
    scanf("%f", &amount);
    if (amount <= 0 || amount > fromAcc->balance) {
        printf("Invalid amount or insufficient balance!\n");
        return;
    }
    fromAcc->balance -= amount;
    toAcc->balance += amount;
    printf("Amount transferred successfully.\n");
    printf("Sender New Balance: %.2f\n", fromAcc->balance);
    printf("Receiver New Balance: %.2f\n", toAcc->balance);
}


void applyInterest() {
    float rate;
    printf("Enter interest rate (%%): ");
    scanf("%f", &rate);
    if (rate <= 0) {
        printf("Invalid interest rate!\n");
        return;
    }
    Account *temp = head;
    while (temp != NULL) {
        temp->balance += temp->balance * (rate / 100);
        temp = temp->next;
    }
    printf("Interest applied to all accounts.\n");
}

// Delete account
void deleteAccount() {
    int accNum;
    printf("Enter Account Number to delete: ");
    scanf("%d", &accNum);
    Account *temp = head, *prev = NULL;
    while (temp != NULL && temp->accountNumber != accNum) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Account not found!\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Account deleted successfully.\n");
}

void displayAccounts() {
    Account *temp = head;
    if (!temp) {
        printf("No accounts found.\n");
        return;
    }
    printf("\n--- Bank Accounts List ---\n");
    printf("%-15s %-20s %-10s\n", "Account Number", "Account Holder", "Balance");
    while (temp != NULL) {
        printf("%-15d %-20s %-10.2f\n", temp->accountNumber, temp->name, temp->balance);
        temp = temp->next;
    }
}

void menu() {
    int choice;
    char searchName[50];
    while (1) {
        printf("\nBank Management System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Apply Interest\n");
        printf("6. Delete Account\n");
        printf("7. Display All Accounts\n");
        printf("8. Search Account By Number\n");
        printf("9. Search Accounts By Name\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        Account *acc;
        
        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: transfer(); break;
            case 5: applyInterest(); break;
            case 6: deleteAccount(); break;
            case 7: displayAccounts(); break;
            case 8:
                printf("Enter Account Number to search: ");
                int accNum;
                scanf("%d", &accNum);
                acc = findAccount(accNum);
                if (acc) {
                    printf("Account Found:\nNumber: %d\nName: %s\nBalance: %.2f\n", acc->accountNumber, acc->name, acc->balance);
                } else {
                    printf("Account not found.\n");
                }
                break;
            case 9:
                printf("Enter Account Holder Name to search: ");
                getchar();
                fgets(searchName, 50, stdin);
                searchName[strcspn(searchName, "\n")] = 0;
                findAccountsByName(searchName);
                break;
            case 10:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Enhanced Bank Management System\n");
    menu();
    return 0;
}
