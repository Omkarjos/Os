slip 6,19,15,10
#include <stdio.h>
 #include <stdlib.h>
 void sortRequests(int requests[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (requests[i] > requests[j]) {
                temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }
 }
 void cscan(int requests[], int n, int head, int diskSize, char direction) {
    int totalHeadMovements = 0;
    int index = 0;
    int servedRequests[n];
   
    sortRequests(requests, n);
   
    if (direction == 'R') {
        for (int i = 0; i < n; i++) {
            if (requests[i] >= head) {
                index = i;
                break;
            }
        }
       
        for (int i = index; i < n; i++) {
            servedRequests[i - index] = requests[i];
        }
       
        for (int i = 0; i < index; i++) {
            servedRequests[n - index + i] = requests[i];
        }
       
        totalHeadMovements += (diskSize - 1 - head) + (diskSize - 1) - servedRequests[n
1];
       
        printf("Requests in the order they are served:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", servedRequests[i]);
        }
    }
    printf("\nTotal head movements: %d\n", totalHeadMovements);
 }
 int main() {
    int requests[] = {80, 150, 60, 135, 40, 35, 170};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head, diskSize = 200;
    char direction;
    printf("Enter the starting head position: ");
    scanf("%d", &head);
    printf("Enter the direction (R for Right, L for Left): ");
    scanf(" %c", &direction);
    cscan(requests, n, head, diskSize, direction);
    return 0;
 }
