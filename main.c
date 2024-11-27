#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prints out the contents of a text file
// Returns 0 or 1 depending on the execution status
int printFile(char fileName[]){
    FILE *fileToPrint;
    char dir[] = "/res/";
    strcat(dir, fileName); // Adding resource directory to file

    fileToPrint = fopen(dir, "r");

    if (fileToPrint == NULL) {
        char error[] = "Error opening ";
        strcat(error, fileName);
        printf(strcat(error, "\n"));
        return 1;
    }

    fseek(fileToPrint, 0, SEEK_END); // Move file pointer to end of file
    long fileSize = ftell(fileToPrint); // We get the position of the file pointer which should now be equal to the length of the file
    rewind(fileToPrint); // Move pointer back to start

    char *fileContents = (char *)malloc(fileSize + 1); // We add an extra character for the String terminator

    if (fileContents == NULL){
        printf("Memory allocation failed");
        fclose(fileToPrint);
        return 1;
    }

    fread(fileContents, 1, fileSize, fileToPrint);
    
    fileContents[fileSize] = '\0'; // Adding terminator

    printf("%s\n", fileContents); // Print file yipee!   

    fclose(fileToPrint);

    return 0;
}

int titleScreen() {
    if (printFile("titleScreen.txt") == 0){
        return 0;
    }
    else{
        return 1;
    }
}

int main() {
    int status; // Execution status of the application (1: Error, 0: Success)

    status = titleScreen();

    if (status == 1){
        return 1; 
    } 

    return 0;  // Return 0 to indicate successful execution
}