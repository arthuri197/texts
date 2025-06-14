#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *filePtr;
    char buffer[100]; // Buffer to store each line of text
    char *token;

    filePtr = fopen("C:\\Users\\20241en20047\\Desktop\\pratica8\\test_file_2.txt", "r"); // Open for reading
    if (filePtr == NULL) {
        perror("Error opening file");
        return 1; // Exit program if file opening fails
    }

    // Read and parse each line of the file
    while (fgets(buffer, sizeof(buffer), filePtr) != NULL) {
        // Assuming each line in the file is CSV (Comma-Separated Values) format
        token = strtok(buffer, ",");
        while (token != NULL) {
            // Process each token (field) in the line
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }
    }

    fclose(filePtr); // Close the file
    return 0;
}