#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int i, length, hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';  // remove newline

    length = strlen(password);

    for (i = 0; i < length; i++) {
        if (isupper(password[i]))
            hasUpper = 1;
        else if (islower(password[i]))
            hasLower = 1;
        else if (isdigit(password[i]))
            hasDigit = 1;
        else if (ispunct(password[i]))
            hasSpecial = 1;
    }

    printf("\nPassword Analysis:\n");
    printf("-------------------\n");
    printf("Length: %d\n", length);
    printf("Contains Uppercase: %s\n", hasUpper ? "Yes" : "No");
    printf("Contains Lowercase: %s\n", hasLower ? "Yes" : "No");
    printf("Contains Digit: %s\n", hasDigit ? "Yes" : "No");
    printf("Contains Special Character: %s\n", hasSpecial ? "Yes" : "No");

    if (length >= 8 && hasUpper && hasLower && hasDigit && hasSpecial)
        printf("\n✅ Password Strength: STRONG\n");
    else if (length >= 6 && ((hasUpper && hasLower) || hasDigit))
        printf("\n⚠️ Password Strength: MODERATE\n");
    else
        printf("\n❌ Password Strength: WEAK\n");

    return 0;
}
