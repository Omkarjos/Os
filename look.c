slip 25,27
#include <stdio.h>
 #include <stdlib.h>
 void swap(int *a, int *b) {
 int temp = *a;
 *a = *b;
 *b = temp;
 }
 void sortRequests(int requests[], int n) {
 for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                swap(&requests[j], &requests[j + 1]);
            }
        }
    }
 }
 void look(int requests[], int n, int head, int direction) {
    int total_head_movements = 0;
    int served[n];
    for (int i = 0; i < n; i++) {
        served[i] = 0;
    }
    sortRequests(requests, n);
    int start = (direction == 1) ? 0 : n - 1;
    int end = (direction == 1) ? n - 1 : 0;
    int step = (direction == 1) ? 1 : -1;
    printf("Disk Requests Order: ");
    for (int i = start; (direction == 1 && i <= end) || (direction == 0 && i >= end); i += step) {
        total_head_movements += abs(head - requests[i]);
        head = requests[i];
        printf("%d ", head);
    }
    printf("\nTotal head movements: %d\n", total_head_movements);
 }
 int main() {
    int requests[] = {86, 147, 91, 170, 95, 130, 102, 70};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head, direction;
    printf("Enter the starting head position: ");
    scanf("%d", &head);
    printf("Enter the direction (1 for right, 0 for left): ");
    scanf("%d", &direction);
    look(requests, n, head, direction);
    return 0;
 }
