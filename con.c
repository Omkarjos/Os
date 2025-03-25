slip 8,14,16,22
#include <stdio.h>
 #include <stdlib.h>
 #define MAX_BLOCKS 100
 int n;
 int bitVector[MAX_BLOCKS];
 int directory[MAX_BLOCKS];
 void showBitVector() {
    printf("Bit Vector: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", bitVector[i]);
    }
    printf("\n");
 }
 void createNewFile(int fileSize) {
    int start = -1;
    for (int i = 0; i <= n - fileSize; i++) {
        int found = 1;
        for (int j = i; j < i + fileSize; j++) {
            if (bitVector[j] == 1) {
                found = 0;
                break;
            }
        }
        if (found) {
            start = i;
            break;
        }
    }
    if (start == -1) {
        printf("Not enough space to allocate the file.\n");
        return;
    }
    for (int i = start; i < start + fileSize; i++) {
        bitVector[i] = 1;
        directory[i] = 1;
    }
    printf("File allocated starting from block %d.\n", start);
 }
 void showDirectory() {
    printf("Directory: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", directory[i]);
    }
    printf("\n");
 }
 int main() {
    int choice, fileSize;
   
    printf("Enter the number of blocks in the disk: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        bitVector[i] = 0;
        directory[i] = 0;
    }
    while (1) {
        printf("\nMenu:\n");
        printf("1. Show Bit Vector\n");
        printf("2. Create New File\n");
        printf("3. Show Directory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                showBitVector();
                break;
            case 2:
                printf("Enter the size of the file to create: ");
                scanf("%d", &fileSize);
                createNewFile(fileSize);
                break;
            case 3:
                showDirectory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
 }