// Write and Read a Structure

#include <stdio.h>
#include <stdlib.h>

// Define structure
struct person {
    int id;
    char fname[20];
    char lname[20];
};

int main() {
    FILE *outfile, *infile;

    // Create and open file for writing
    outfile = fopen("person.bin", "wb");
    if (outfile == NULL) {
        fprintf(stderr, "\nError opening file for writing\n");
        exit(1);
    }

    // Create struct variable and assign data
    struct person input1 = {1, "Rohan", "Sharma"};

    // Write struct to file
    size_t written = fwrite(&input1, sizeof(struct person), 1, outfile);
    if (written)
        printf("✅ Structure written successfully!\n");
    else
        printf("❌ Error writing structure!\n");

    fclose(outfile);

    // ---------- READ STRUCTURE BACK FROM FILE ----------
    infile = fopen("person.bin", "rb");
    if (infile == NULL) {
        fprintf(stderr, "\nError opening file for reading\n");
        exit(1);
    }

    struct person output1;

    size_t read = fread(&output1, sizeof(struct person), 1, infile);
    if (read)
        printf("✅ Structure read successfully!\n");
    else
        printf("❌ Error reading structure!\n");

    printf("\n--- File Contents ---\n");
    printf("ID: %d\n", output1.id);
    printf("First Name: %s\n", output1.fname);
    printf("Last Name: %s\n", output1.lname);

    fclose(infile);

    return 0;
}
