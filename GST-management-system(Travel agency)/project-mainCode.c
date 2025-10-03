#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximums for array sizes and string lengths
#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 100
#define MAX_MOBILE_LENGTH 12
#define MAX_VEHICLE_TYPE_LENGTH 20
#define MAX_DATE_LENGTH 20

// Define the path for the CSV file
#define CSV_FILE_PATH "C:\\Users\\saira\\OneDrive\\Desktop\\c prog\\dts.csv"
// Define the GST rate
#define GST_RATE 0.12

// Structure to store billing records
typedef struct {
    char customer_name[MAX_NAME_LENGTH];
    char mobile_number[MAX_MOBILE_LENGTH];
    float distance;
    char vehicle_type[MAX_VEHICLE_TYPE_LENGTH];
    float driver_charges;
    float base_amount;
    float gst_amount;
    float total_amount;
    char date[MAX_DATE_LENGTH];
} BillingRecord;

// Global variables
BillingRecord records[MAX_RECORDS]; // Array to store all records
int record_count = 0;                // Current number of records

// Function prototypes
void display_header();
void main_menu();
void travel_billing_menu();
void gst_analysis_menu();
void add_billing_record();
void save_to_csv();
void load_from_csv();
void display_all_records();
void find_highest_gst();
void find_lowest_gst();
void calculate_average_gst();
void list_gst_above_threshold();
void compare_gst_entries();
void analyze_quarterly_revenue();
void calculate_profit_analysis();
void filter_high_expense_records();
void clear_screen();
void pause_screen();
void clear_input_buffer(); // Utility to clear stdin
float get_vehicle_rate(char* vehicle_type);

int main() {
    load_from_csv();    // Load existing records from CSV at startup
    main_menu();        // Display the main menu
    return 0;
}

// Clears the standard input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Displays the application header
void display_header() {
    clear_screen();
    printf("          TRAVEL BILLING SYSTEM                                \n");
    printf("             PES University                               \n");
    printf("         Problem Solving with C                             \n");
}

// Displays the main menu and handles user choices
void main_menu() {
    int choice;
    while (1) {
        display_header();
        printf("           MAIN MENU\n");
        printf(" 1. Travel Billing Management\n");
        printf(" 2. GST Analysis & Reports\n");
        printf(" 3. View All Records\n");
        printf(" 4. Exit\n");
        printf("\nEnter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) { // Validate integer input
            clear_input_buffer(); // Clear invalid input
            choice = -1;          // Set to an invalid choice to trigger default case
        } else {
            clear_input_buffer(); // Clear the newline character
        }

        switch (choice) {
            case 1: travel_billing_menu(); break;
            case 2: gst_analysis_menu(); break;
            case 3: display_all_records(); break;
            case 4:
                printf("\nExiting System.\n");
                printf("      Thank you for using our system!     \n");
                exit(0);
            default:
                printf("\nError: Invalid choice! Please try again.\n");
                pause_screen();
        }
    }
}

// Displays the travel billing submenu
void travel_billing_menu() {
    int choice;
    while (1) {
        display_header();
        printf("           TRAVEL BILLING MENU\n");
        printf(" 1. Add New Billing Record\n");
        printf(" 2. View All Billing Records\n");
        printf(" 3. Back to Main Menu\n");
        printf("\nEnter your choice (1-3): ");

        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            choice = -1; // Invalid choice
        } else {
            clear_input_buffer();
        }

        switch (choice) {
            case 1: add_billing_record(); break;
            case 2: display_all_records(); break;
            case 3: return; // Go back to main menu
            default:
                printf("\nError: Invalid choice! Please try again.\n");
                pause_screen();
        }
    }
}

// Displays the GST analysis submenu
void gst_analysis_menu() {
    int choice;
    while (1) {
        display_header();
        printf("   GST ANALYSIS & REPORTS\n");
        printf(" 1. Find Highest GST Transaction\n");
        printf(" 2. Find Lowest GST Transaction\n");
        printf(" 3. Calculate Average GST\n");
        printf(" 4. List GST Entries Above Threshold\n");
        printf(" 5. Compare GST Entries by Vehicle Type\n");
        printf(" 6. Quarterly Revenue Analysis\n");
        printf(" 7. Profit & Loss Analysis\n");
        printf(" 8. Filter High-Value Transactions\n");
        printf(" 9. Back to Main Menu\n");
        printf("\nEnter your choice (1-9): ");

        if (scanf("%d", &choice) != 1) {
            clear_input_buffer();
            choice = -1; // Invalid choice
        } else {
            clear_input_buffer();
        }

        switch (choice) {
            case 1: find_highest_gst(); break;
            case 2: find_lowest_gst(); break;
            case 3: calculate_average_gst(); break;
            case 4: list_gst_above_threshold(); break;
            case 5: compare_gst_entries(); break;
            case 6: analyze_quarterly_revenue(); break;
            case 7: calculate_profit_analysis(); break;
            case 8: filter_high_expense_records(); break;
            case 9: return; // Go back to main menu
            default:
                printf("\nError: Invalid choice! Please try again.\n");
                pause_screen();
        }
    }
}

// Adds a new billing record
void add_billing_record() {
    if (record_count >= MAX_RECORDS) {
        printf("\nError: Maximum records limit reached! Cannot add more.\n");
        pause_screen();
        return;
    }

    display_header();
    printf("           ADD NEW BILLING RECORD\n\n");

    BillingRecord new_record; // Temporary record to fill

    printf("Enter customer name: ");
    scanf(" %99[^\n]", new_record.customer_name); // Read name, limit to 99 chars
    clear_input_buffer();

    printf("Enter mobile number (max %d digits): ", MAX_MOBILE_LENGTH - 1);
    scanf(" %14s", new_record.mobile_number); // Read mobile, limit to 14 chars
    clear_input_buffer();

    printf("Select vehicle type:\n");
    printf("   1. Sedan (Rs.%.2f/km)\n", get_vehicle_rate("Sedan"));
    printf("   2. XUV (Rs.%.2f/km)\n", get_vehicle_rate("XUV"));
    printf("   3. Jumbo (Rs.%.2f/km)\n", get_vehicle_rate("Jumbo"));
    printf("Enter choice (1-3): ");

    int vehicle_choice;
    if (scanf("%d", &vehicle_choice) != 1) {
        clear_input_buffer();
        vehicle_choice = -1; // Trigger default
    } else {
        clear_input_buffer();
    }

    switch (vehicle_choice) {
        case 1: strcpy(new_record.vehicle_type, "Sedan"); break;
        case 2: strcpy(new_record.vehicle_type, "XUV"); break;
        case 3: strcpy(new_record.vehicle_type, "Jumbo"); break;
        default:
            strcpy(new_record.vehicle_type, "Sedan");
            printf("Warning: Invalid choice, defaulting to Sedan.\n");
    }

    printf("Enter distance travelled (km): ");
    while (scanf("%f", &new_record.distance) != 1 || new_record.distance < 0) {
        printf("Error: Invalid input. Please enter a non-negative number for distance: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    printf("Enter driver charges (Rs.): ");
    while (scanf("%f", &new_record.driver_charges) != 1 || new_record.driver_charges < 0) {
        printf("Error: Invalid input. Please enter a non-negative number for driver charges: ");
        clear_input_buffer();
    }
    clear_input_buffer();

    // Calculate billing amounts
    float rate = get_vehicle_rate(new_record.vehicle_type);
    new_record.base_amount = (new_record.distance * rate) + new_record.driver_charges;
    new_record.gst_amount = new_record.base_amount * GST_RATE;
    new_record.total_amount = new_record.base_amount + new_record.gst_amount;

    // Get current date
    time_t t = time(NULL);
    struct tm tm_info = *localtime(&t);
    sprintf(new_record.date, "%02d/%02d/%04d", tm_info.tm_mday, tm_info.tm_mon + 1, tm_info.tm_year + 1900);

    // Display the generated bill
    printf("                          TRAVEL BILL                           \n");
    printf("--------------------------------------------------------------------------------------------\n");
    printf(" Customer: %-46s \n", new_record.customer_name);
    printf(" Mobile: %-48s \n", new_record.mobile_number);
    printf(" Vehicle: %-15s  Distance: %-7.2f km          \n", new_record.vehicle_type, new_record.distance);
    printf(" Rate: Rs.%-9.2f/km         Date: %-18s \n", rate, new_record.date);
    printf("-----------------------------------------------------------------------------------------------\n");
    printf(" Distance Charges: Rs.%-37.2f \n", new_record.distance * rate);
    printf(" Driver Charges:   Rs.%-37.2f \n", new_record.driver_charges);
    printf(" Subtotal:         Rs.%-37.2f \n", new_record.base_amount);
    printf(" GST (%.0f%%):       Rs.%-37.2f \n", GST_RATE * 100, new_record.gst_amount);
    printf(" TOTAL AMOUNT:     Rs.%-37.2f \n", new_record.total_amount);
    printf("------------------------------------------------------------------------------------------------\n");

    records[record_count] = new_record; // Add to global records array
    record_count++;

    printf("\nSuccess: Record added successfully!\n");
    save_to_csv(); // Auto-save after adding a record
    pause_screen();
}

// Returns the rate per km based on vehicle type
float get_vehicle_rate(char* vehicle_type) {
    if (strcmp(vehicle_type, "Sedan") == 0) return 12.0;
    if (strcmp(vehicle_type, "XUV") == 0) return 14.0;
    if (strcmp(vehicle_type, "Jumbo") == 0) return 19.0;
    return 12.0; // Default rate if type is unknown
}

// Saves all current records to a CSV file
void save_to_csv() {
    FILE *file = fopen(CSV_FILE_PATH, "w"); // Open in write mode (overwrites existing)
    if (file == NULL) {
        printf("\nError: Could not open file for writing!\n");
        printf("Attempted to save at: %s\n", CSV_FILE_PATH);
        perror("File system error"); // Display system error message
        pause_screen();
        return;
    }

    // Write CSV header
    fprintf(file, "Customer Name,Mobile Number,Vehicle Type,Distance,Driver Charges,Base Amount,GST Amount,Total Amount,Date\n");
    // Write each record to the file
    for (int i = 0; i < record_count; i++) {
        fprintf(file, "\"%s\",\"%s\",\"%s\",%.2f,%.2f,%.2f,%.2f,%.2f,%s\n", // Quote string fields
                records[i].customer_name, records[i].mobile_number,
                records[i].vehicle_type, records[i].distance,
                records[i].driver_charges, records[i].base_amount,
                records[i].gst_amount, records[i].total_amount,
                records[i].date);
    }
    fclose(file);
    printf("Info: Records saved to %s\n", CSV_FILE_PATH);
    // pause_screen(); // Pause might be excessive if called frequently
}

// Loads records from a CSV file into memory
void load_from_csv() {
    FILE *file = fopen(CSV_FILE_PATH, "r"); // Open in read mode
    if (file == NULL) {
        // This is normal if the program is run for the first time or file deleted
        // printf("Info: No existing data file found at %s. Starting fresh.\n", CSV_FILE_PATH);
        return;
    }

    char line[1024]; // Buffer to read each line

    // Skip header line
    if (fgets(line, sizeof(line), file) == NULL) {
        fclose(file);
        return; // Empty or only header
    }

    record_count = 0; // Reset record count before loading
    // Read each line and parse data
    while (fgets(line, sizeof(line), file) && record_count < MAX_RECORDS) {
        // sscanf format for parsing CSV lines. Assumes strings are quoted.
        // Width specifiers (%99[^"]) prevent buffer overflows.
        int items_read = sscanf(line, "\"%99[^\"]\",\"%14[^\"]\",\"%19[^\"]\",%f,%f,%f,%f,%f,%19s",
               records[record_count].customer_name,
               records[record_count].mobile_number,
               records[record_count].vehicle_type,
               &records[record_count].distance,
               &records[record_count].driver_charges,
               &records[record_count].base_amount,
               &records[record_count].gst_amount,
               &records[record_count].total_amount,
               records[record_count].date);

        if (items_read == 9) { // Successfully parsed 9 fields
            record_count++;
        } else {
             // Fallback for unquoted simple CSV or if the above fails
            items_read = sscanf(line, "%99[^,],%14[^,],%19[^,],%f,%f,%f,%f,%f,%19s",
                records[record_count].customer_name,
                records[record_count].mobile_number,
                records[record_count].vehicle_type,
                &records[record_count].distance,
                &records[record_count].driver_charges,
                &records[record_count].base_amount,
                &records[record_count].gst_amount,
                &records[record_count].total_amount,
                records[record_count].date);
            if (items_read == 9) {
                record_count++;
            }
            // else {
            //    fprintf(stderr, "Warning: Malformed or unreadable line in CSV: %s", line);
            // }
        }
    }
    fclose(file);
}

// Displays all stored billing records
void display_all_records() {
    display_header();
    printf("           ALL BILLING RECORDS\n\n");

    if (record_count == 0) {
        printf("Info: No records found!\n");
        pause_screen();
        return;
    }
    // Print table header for records
    printf("%-20.20s %-15s %-10s %-10s %-10s %-10s %-10s %-12s %-10s\n",
           "Customer", "Mobile", "Vehicle", "Distance", "DriverCh", "Base", "GST", "Total", "Date");
    printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");

    // Print each record
    for (int i = 0; i < record_count; i++) {
        printf("%-20.20s %-15s %-10s %-10.2f %-10.2f %-10.2f %-10.2f %-12.2f %-10s\n",
               records[i].customer_name, records[i].mobile_number,
               records[i].vehicle_type, records[i].distance,
               records[i].driver_charges, records[i].base_amount,
               records[i].gst_amount, records[i].total_amount,
               records[i].date);
    }
    printf("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────\n");
    printf("\nSummary: Total Records: %d\n", record_count);
    pause_screen();
}

// Finds and displays the record with the highest GST amount
void find_highest_gst() {
    display_header();
    printf("           HIGHEST GST TRANSACTION\n\n");

    if (record_count == 0) {
        printf("Info: No records found!\n");
        pause_screen();
        return;
    }

    int max_index = 0; // Index of the record with highest GST
    for (int i = 1; i < record_count; i++) {
        if (records[i].gst_amount > records[max_index].gst_amount) {
            max_index = i;
        }
    }

    printf("Highest GST Transaction Details:\n");
    printf("   Customer:     %s\n", records[max_index].customer_name);
    printf("   Mobile:       %s\n", records[max_index].mobile_number);
    printf("   Vehicle:      %s\n", records[max_index].vehicle_type);
    printf("   Distance:     %.2f km\n", records[max_index].distance);
    printf("   Driver Charges: Rs.%.2f\n", records[max_index].driver_charges);
    printf("   Base Amount:  Rs.%.2f\n", records[max_index].base_amount);
    printf("   GST Amount:   Rs.%.2f\n", records[max_index].gst_amount);
    printf("   Total Amount: Rs.%.2f\n", records[max_index].total_amount);
    printf("   Date:         %s\n", records[max_index].date);
    pause_screen();
}

// Finds and displays the record with the lowest GST amount
void find_lowest_gst() {
    display_header();
    printf("           LOWEST GST TRANSACTION\n\n");

    if (record_count == 0) {
        printf("Info: No records found!\n");
        pause_screen();
        return;
    }

    int min_index = 0; // Index of the record with lowest GST
    for (int i = 1; i < record_count; i++) {
        if (records[i].gst_amount < records[min_index].gst_amount) {
            min_index = i;
        }
    }

    printf("Lowest GST Transaction Details:\n");
    printf("   Customer:     %s\n", records[min_index].customer_name);
    printf("   Mobile:       %s\n", records[min_index].mobile_number);
    printf("   Vehicle:      %s\n", records[min_index].vehicle_type);
    printf("   Distance:     %.2f km\n", records[min_index].distance);
    printf("   Driver Charges: Rs.%.2f\n", records[min_index].driver_charges);
    printf("   Base Amount:  Rs.%.2f\n", records[min_index].base_amount);
    printf("   GST Amount:   Rs.%.2f\n", records[min_index].gst_amount);
    printf("   Total Amount: Rs.%.2f\n", records[min_index].total_amount);
    printf("   Date:         %s\n", records[min_index].date);
    pause_screen();
}

// Calculates and displays average GST and transaction values
void calculate_average_gst() {
    display_header();
    printf("           AVERAGE GST ANALYSIS\n\n");

    if (record_count == 0) {
        printf("Info: No records found!\n");
        pause_screen();
        return;
    }

    float total_gst = 0;
    float total_revenue_val = 0;
    for (int i = 0; i < record_count; i++) {
        total_gst += records[i].gst_amount;
        total_revenue_val += records[i].total_amount;
    }

    printf("GST Statistics:\n");
    printf("   Total Records:              %d\n", record_count);
    printf("   Total GST Collected:        Rs.%.2f\n", total_gst);
    printf("   Total Revenue (incl. GST):  Rs.%.2f\n", total_revenue_val);
    printf("   Average GST per Transaction: Rs.%.2f\n", total_gst / record_count);
    printf("   Average Transaction Value:  Rs.%.2f\n", total_revenue_val / record_count);
    pause_screen();
}

// Lists records where GST amount is above a user-defined threshold
void list_gst_above_threshold() {
    display_header();
    printf("           GST ENTRIES ABOVE THRESHOLD\n\n");

    if (record_count == 0) {
        printf("Info: No records found!\n");
        pause_screen();
        return;
    }

    float threshold;
    printf("Enter GST threshold amount (Rs.): ");
    if (scanf("%f", &threshold) != 1 || threshold < 0) {
        clear_input_buffer();
        printf("Error: Invalid threshold amount.\n");
        pause_screen();
        return;
    }
    clear_input_buffer();

    printf("\nTransactions with GST above Rs.%.2f:\n\n", threshold);
    printf("%-4s %-20.20s %-10s %-10s %-12s\n", "No.", "Customer", "Vehicle", "GST Amt", "Total Amt");
    printf("──── ──────────────────── ────────── ────────── ────────────\n");

    int count = 0; // Count of records meeting criteria
    for (int i = 0; i < record_count; i++) {
        if (records[i].gst_amount > threshold) {
            printf("%-4d %-20.20s %-10s Rs.%-8.2f Rs.%-10.2f\n",
                   ++count, records[i].customer_name, records[i].vehicle_type,
                   records[i].gst_amount, records[i].total_amount);
        }
    }

    if (count == 0) {
        printf("\nNo transactions found above the threshold of Rs.%.2f.\n", threshold);
    } else {
        printf("\nFound %d transaction(s) above the threshold.\n", count);
    }
    pause_screen();
}

// Compares GST collected by vehicle type
void compare_gst_entries() {
    display_header();
    printf("           GST COMPARISON BY VEHICLE TYPE\n\n");

    if (record_count == 0) {
        printf("Info: No records found!\n");
        pause_screen();
        return;
    }

    float sedan_gst = 0, xuv_gst = 0, jumbo_gst = 0;
    int sedan_count = 0, xuv_count = 0, jumbo_count = 0;

    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].vehicle_type, "Sedan") == 0) {
            sedan_gst += records[i].gst_amount; sedan_count++;
        } else if (strcmp(records[i].vehicle_type, "XUV") == 0) {
            xuv_gst += records[i].gst_amount; xuv_count++;
        } else if (strcmp(records[i].vehicle_type, "Jumbo") == 0) {
            jumbo_gst += records[i].gst_amount; jumbo_count++;
        }
    }

    printf("GST Analysis by Vehicle Type:\n\n");
    printf("Sedan Vehicle:\n");
    printf("   Transactions: %d\n", sedan_count);
    printf("   Total GST:    Rs.%.2f\n", sedan_gst);
    if (sedan_count > 0) printf("   Average GST:  Rs.%.2f\n", sedan_gst / sedan_count);
    else printf("   Average GST:  N/A\n");

    printf("\nXUV Vehicle:\n");
    printf("   Transactions: %d\n", xuv_count);
    printf("   Total GST:    Rs.%.2f\n", xuv_gst);
    if (xuv_count > 0) printf("   Average GST:  Rs.%.2f\n", xuv_gst / xuv_count);
    else printf("   Average GST:  N/A\n");

    printf("\nJumbo Vehicle:\n");
    printf("   Transactions: %d\n", jumbo_count);
    printf("   Total GST:    Rs.%.2f\n", jumbo_gst);
    if (jumbo_count > 0) printf("   Average GST:  Rs.%.2f\n", jumbo_gst / jumbo_count);
    else printf("   Average GST:  N/A\n");

    pause_screen();
}

// Analyzes and displays revenue by quarter
void analyze_quarterly_revenue() {
    display_header();
    printf("           QUARTERLY REVENUE ANALYSIS\n\n");

    if (record_count == 0) {
        printf("Info: No records found!\n");
        pause_screen();
        return;
    }

    float q_revenue[4] = {0}; // Revenue for Q1, Q2, Q3, Q4
    int q_counts[4] = {0};    // Transaction counts for Q1, Q2, Q3, Q4
    int month;

    for (int i = 0; i < record_count; i++) {
        // Parse month from date string (dd/mm/yyyy)
        if (sscanf(records[i].date, "%*d/%d/%*d", &month) == 1) {
            if (month >= 1 && month <= 3)      { q_revenue[0] += records[i].total_amount; q_counts[0]++; } // Q1
            else if (month >= 4 && month <= 6)  { q_revenue[1] += records[i].total_amount; q_counts[1]++; } // Q2
            else if (month >= 7 && month <= 9)  { q_revenue[2] += records[i].total_amount; q_counts[2]++; } // Q3
            else if (month >= 10 && month <= 12){ q_revenue[3] += records[i].total_amount; q_counts[3]++; } // Q4
        }
    }

    printf("Quarterly Revenue Report:\n\n");
    printf("   Q1 (Jan-Mar): Rs.%-10.2f (%d transactions)\n", q_revenue[0], q_counts[0]);
    printf("   Q2 (Apr-Jun): Rs.%-10.2f (%d transactions)\n", q_revenue[1], q_counts[1]);
    printf("   Q3 (Jul-Sep): Rs.%-10.2f (%d transactions)\n", q_revenue[2], q_counts[2]);
    printf("   Q4 (Oct-Dec): Rs.%-10.2f (%d transactions)\n", q_revenue[3], q_counts[3]);

    float total_annual_revenue = q_revenue[0] + q_revenue[1] + q_revenue[2] + q_revenue[3];
    printf("\n   Total Annual Revenue:        Rs.%.2f\n", total_annual_revenue);

    int active_quarters = 0;
    for(int i=0; i<4; ++i) if(q_counts[i] > 0) active_quarters++;

    if (active_quarters > 0) {
        printf("   Average Quarterly Revenue (based on active quarters): Rs.%.2f\n", total_annual_revenue / active_quarters);
    } else {
        printf("   Average Quarterly Revenue: N/A\n");
    }
    pause_screen();
}

// Calculates and displays a simple profit/loss analysis
void calculate_profit_analysis() {
    display_header();
    printf("           PROFIT & LOSS ANALYSIS\n\n");

    if (record_count == 0) {
        printf("Info: No records found!\n");
        pause_screen();
        return;
    }

    float total_revenue_val = 0;
    float total_expenses = 0;    // Assuming driver charges are the main expense
    float total_gst_collected = 0;

    for (int i = 0; i < record_count; i++) {
        total_revenue_val += records[i].total_amount;
        total_expenses += records[i].driver_charges;
        total_gst_collected += records[i].gst_amount;
    }

    float net_revenue_before_gst_calc = total_revenue_val - total_gst_collected;
    float gross_profit = net_revenue_before_gst_calc - total_expenses;
    float profit_margin = 0;
    if (net_revenue_before_gst_calc != 0) { // Avoid division by zero
        profit_margin = (gross_profit / net_revenue_before_gst_calc) * 100;
    }

    printf("Financial Analysis Report:\n\n");
    printf("   Total Gross Revenue (incl. GST):   Rs.%.2f\n", total_revenue_val);
    printf("   Total GST Collected (remitted):    Rs.%.2f\n", total_gst_collected);
    printf("   Net Revenue (after GST remittance):Rs.%.2f\n", net_revenue_before_gst_calc);
    printf("   Total Direct Expenses (Driver):    Rs.%.2f\n", total_expenses);
    printf("   ----------------------------------------------------\n");
    printf("   Gross Profit (Net Revenue - Expenses): Rs.%.2f\n", gross_profit);
    if (net_revenue_before_gst_calc != 0) {
        printf("   Profit Margin:                     %.2f%%\n", profit_margin);
    } else {
        printf("   Profit Margin:                     N/A (Net Revenue is zero)\n");
    }

    if (gross_profit > 0) {
        printf("\nStatus: Business is showing a gross profit.\n");
    } else if (gross_profit < 0) {
        printf("\nStatus: Business is showing a gross loss.\n");
    } else {
        printf("\nStatus: Business is breaking even (gross profit is zero).\n");
    }
    printf("   (Note: This analysis assumes driver charges as the only direct expense.)\n");
    pause_screen();
}

// Filters and displays records with total amount above a threshold
void filter_high_expense_records() { // Renamed for clarity (high-value transactions)
    display_header();
    printf("           HIGH-VALUE TRANSACTION FILTER\n\n");

    if (record_count == 0) {
        printf("Info: No records found!\n");
        pause_screen();
        return;
    }

    float threshold;
    printf("Enter minimum transaction total amount (Rs.) to filter: ");
    if (scanf("%f", &threshold) != 1 || threshold < 0) {
        clear_input_buffer();
        printf("Error: Invalid threshold amount.\n");
        pause_screen();
        return;
    }
    clear_input_buffer();

    printf("\nHigh-value transactions (Total Amount > Rs.%.2f):\n\n", threshold);
    printf("%-4s %-20.20s %-10s %-10s %-12s %-10s\n", "No.", "Customer", "Vehicle", "Distance", "Total Amt", "Date");
    printf("──── ──────────────────── ────────── ────────── ──────────── ──────────\n");

    int count = 0; // Count of high-value transactions
    float high_value_sum = 0; // Sum of amounts for these transactions
    for (int i = 0; i < record_count; i++) {
        if (records[i].total_amount > threshold) {
            printf("%-4d %-20.20s %-10s %-10.2f Rs.%-10.2f %-10s\n",
                   ++count, records[i].customer_name, records[i].vehicle_type,
                   records[i].distance, records[i].total_amount, records[i].date);
            high_value_sum += records[i].total_amount;
        }
    }

    if (count == 0) {
        printf("\nNo transactions found with total amount above Rs.%.2f.\n", threshold);
    } else {
        printf("\nSummary for High-Value Transactions:\n");
        printf("   Count: %d\n", count);
        printf("   Total Value: Rs.%.2f\n", high_value_sum);
        printf("   Average Value: Rs.%.2f\n", high_value_sum / count);
        printf("   Percentage of Total Records: %.2f%%\n", ((float)count / record_count) * 100);
    }
    pause_screen();
}

// Clears the console screen
void clear_screen() {
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For UNIX-like systems (Linux, macOS)
    #endif
}

// Pauses execution and waits for user to press Enter
void pause_screen() {
    printf("\nPress Enter to continue...");
    // getchar(); // Consume any leftover newline from previous input
    getchar(); // Wait for Enter key
}