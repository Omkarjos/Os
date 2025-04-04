slip 2,6,15,25
#include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #define MAX_FILES 10
 #define MAX_BLOCKS 100
 int bitVector[MAX_BLOCKS];
 int directory[MAX_FILES][MAX_BLOCKS];
 int fileStart[MAX_FILES];
 int fileCount = 0;
 void initializeDisk(int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        bitVector[i] = rand() % 2;
    }
 }
 void showBitVector(int n) {
    printf("Bit Vector: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", bitVector[i]);
    }
    printf("\n");
 }
 void createNewFile(int n) {
    if (fileCount >= MAX_FILES) {
        printf("Directory full! Cannot create more files.\n");
        return;
    }
    int fileSize, block, currentBlock = -1, previousBlock = -1;
    printf("Enter file size: ");
    scanf("%d", &fileSize);
    if (fileSize > n) {
        printf("File size too large.\n");
        return;
    }
    fileStart[fileCount] = -1;
    for (int i = 0; i < fileSize; i++) {
        do {
            block = rand() % n;
        } while (bitVector[block] != 0);
        bitVector[block] = 1;
        if (previousBlock == -1) {
            fileStart[fileCount] = block;
        } else {
            directory[fileCount][previousBlock] = block;
        }
        previousBlock = block;
        directory[fileCount][block] = -1;
    }
    printf("File created with starting block %d\n", fileStart[fileCount]);
    fileCount++;
 }
 void showDirectory() {
    printf("Directory:\n");
    for (int i = 0; i < fileCount; i++) {
        printf("File %d: ", i + 1);
        int block = fileStart[i];
        while (block != -1) {
            printf("%d -> ", block);
            block = directory[i][block];
        }
        printf("NULL\n");
    }
}
 int main() {
    int n, choice;
    printf("Enter total number of blocks: ");
    scanf("%d", &n);
    initializeDisk(n);
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
                showBitVector(n);
                break;
            case 2:
                createNewFile(n);
                break;
            case 3:
                showDirectory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
 }
