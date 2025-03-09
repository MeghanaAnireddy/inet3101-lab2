#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

//storing part records
typedef struct {
    int part_number;
    char part_name[50];
    float part_size;
    char part_size_metric[10];
    float part_cost;
}PartRecord;

//global variable for database
PartRecord *database = NULL;
int num_records=0;

// Function to add a record without using realloc()
void add_record() {
    PartRecord *new_database = (PartRecord *)malloc((num_records + 1) * sizeof(PartRecord));
    
    if (new_database == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Copy existing records to new allocation
    for (int i = 0; i < num_records; i++) {
        new_database[i] = database[i];
    }

    // Add new record
    printf("Enter part number: ");
    scanf("%d", &new_database[num_records].part_number);
    getchar();
    
    printf("Enter part name: ");
    fgets(new_database[num_records].part_name, sizeof(new_database[num_records].part_name), stdin);
    new_database[num_records].part_name[strcspn(new_database[num_records].part_name, "\n")] = 0; // Remove newline

    printf("Enter part size: ");
    scanf("%f", &new_database[num_records].part_size);
    getchar();
   
    printf("Enter part size metric: ");
    fgets(new_database[num_records].part_size_metric, sizeof(new_database[num_records].part_size_metric), stdin);
    new_database[num_records].part_size_metric[strcspn(new_database[num_records].part_size_metric, "\n")] = 0;

    printf("Enter part cost: ");
    scanf("%f", &new_database[num_records].part_cost);
    getchar();

    // Free old memory and update database pointer
    free(database);
    database = new_database;
    num_records++;

    printf("Record added successfully.\n");
}

// Function to delete the last record
void delete_record() {
    if (num_records == 0) {
        printf("No records to delete.\n");
        return;
    }

    PartRecord *new_database = (PartRecord *)malloc((num_records - 1) * sizeof(PartRecord));

    if (num_records > 1) {
        for (int i = 0; i < num_records - 1; i++) {
            new_database[i] = database[i];
        }
    }

    free(database);
    database = new_database;
    num_records--;

    printf("Last record deleted successfully.\n");
}

// Function to print all records
void print_records() {
    if (num_records == 0) {
        printf("No records available.\n");
        return;
    }

    printf("\n--- Database Records ---\n");
    for (int i = 0; i < num_records; i++) {
        printf("\nRecord %d:\n", i + 1);
        printf(" Part Number: %d\n", database[i].part_number);
        printf(" Part Name: %s\n", database[i].part_name);
        printf(" Part Size: %.2f %s\n", database[i].part_size, database[i].part_size_metric);
        printf(" Part Cost: $%.2f\n", database[i].part_cost);
    }
}

// Function to print database statistics
void print_database_size() {
    printf("Total database size: %lu bytes\n", num_records * sizeof(PartRecord));
}


int PrintNumChanges (bool print){
    static int changes = 0;

    if (print){
        printf("Database has been modified %d time\n", changes);
    }else{
        changes++;
        printf("%d modificiations so far\n", changes);
    }
    return changes;
    }


int main()
{
    int ch;

    while(1){

    printf("\n MENU");
    printf("\n 1. Print all records");
    printf("\n 2. Add record");
    printf("\n 3. Delete record");
    printf("\n 4. Print number of records");
    printf("\n 5. Print database size");
    printf("\n 6. Print Number of Changes");
    printf("\n 7. Exit");
    printf("\n Please enter you selection numerically: ");
    scanf("%d", &ch);
    getchar();

    switch(ch)
    {
    case 1:
    print_records();
    break;

    case 2:
    add_record();
    PrintNumChanges(false); // Track changes
    print_records();
    break;
    
    case 3:
    delete_record();
    PrintNumChanges(false);
    break;

    case 4:
    printf("Number of recordss: %d\n", num_records);
    break;

    case 5:
    print_database_size();
    break;

    //Uses the bool value initialized at the beginning fo the code
    case 6:
    PrintNumChanges(true);
    break;

    case 7:
    printf("Exiting the program\n");
    free(database);
    return 0;

    default: 
    printf("Invalid section. Please try again.\n");
    break;

    }
    }
    return 0;
}