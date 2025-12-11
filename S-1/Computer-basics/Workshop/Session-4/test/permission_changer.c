
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>


int main() {
    const char filename[] = "notes.txt";
    struct stat file_stat;


    // Get current file info
    if (stat(filename, &file_stat) == -1) {
        printf("Error getting file info");
        return 1;
    }

    printf("=== File Permission Modifier ===\n");
    printf("File: %s\n\n", filename);

    // Get current permissions
    mode_t current_mode = file_stat.st_mode;
    // Remove user read permission using bitwise AND
    mode_t mask = ~(0400);  // Bitwise NOT of user read bit (0400)
    mode_t new_mode = current_mode & mask;

    // Apply new permissions
    if (chmod(filename, new_mode) == -1) {
        printf("Error changing file permissions");
        return 1;
    }

    // TO DO: Verify the change

    printf("Operation completed successfully!\n");
    printf("User read permission has been removed.\n");

    return 0;
}
