**INET 3101 Lab2

**This code uses an in-memory database in C that allows users to store and manage records dynamically using memory allocation (`malloc()` and `free()`). The program does not use arrays or linked lists.

- Add a new record: Stores a new part record in dynamically allocated memory.
- Delete the last record: Removes the most recently added record and re-allocates memory.
- Print all records: Displays all stored part records.
- Print number of records: Shows the current number of stored records.
- Print database size: Displays the total memory usage of the database.
- Track modifications: Keeps count of how many times the database has been modified.
- Memory Management: Dynamically manages memory without using `realloc()`.
