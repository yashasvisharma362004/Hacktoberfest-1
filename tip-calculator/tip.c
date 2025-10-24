#include <stdio.h>

int main(void) {
    double bill_amount;
    int tip_percentage;

    // ANSI escape sequences for color
    const char *CYAN = "\033[1;36m";
    const char *YELLOW = "\033[1;33m";
    const char *GREEN = "\033[1;32m";
    const char *RESET = "\033[0m";
    const char *BOLD = "\033[1m";

    printf("%s\n✨==============================================================✨%s\n", CYAN, RESET);
    printf("%s💰 Tip Calculator — Indian Rupees Edition 🇮🇳%s\n", BOLD, RESET);
    printf("--------------------------------------------------------------\n");

    printf("%sEnter bill amount (₹): %s", YELLOW, RESET);
    scanf("%lf", &bill_amount);

    printf("%sEnter tip percentage (%%): %s", YELLOW, RESET);
    scanf("%d", &tip_percentage);

    double tip_amount = bill_amount * (tip_percentage / 100.0);
    double total_amount = bill_amount + tip_amount;

    printf("\n%s──────────────────────────────────────────────%s\n", CYAN, RESET);
    printf("%sBill Amount      :%s ₹ %.2f\n", BOLD, RESET, bill_amount);
    printf("%sTip Percentage   :%s %d%%\n", BOLD, RESET, tip_percentage);
    printf("%sTip Amount       :%s ₹ %.2f\n", BOLD, RESET, tip_amount);
    printf("%sTotal to Pay 💸  :%s ₹ %.2f\n", GREEN, RESET, total_amount);
    printf("%s──────────────────────────────────────────────%s\n", CYAN, RESET);

    printf("%s✅ Thank you for using the Tip Calculator!%s\n", GREEN, RESET);
    printf("%s✨==============================================================✨%s\n", CYAN, RESET);

    return 0;
}
