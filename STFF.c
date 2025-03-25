slip 8,14,23,
 #include <stdio.h>
 #include <stdlib.h>
 void sortRequests(int requests[], int n, int head) {
    int temp;
    int minDist, minIndex;
    for (int i = 0; i < n - 1; i++) {
        minDist = abs(requests[i] - head);
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(requests[j] - head) < minDist) {
                minDist = abs(requests[j] - head);
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = requests[i];
            requests[i] = requests[minIndex];
            requests[minIndex] = temp;
        }
    }
 }
 void sstf(int requests[], int n, int head) {
    int totalHeadMovements = 0;
    int served[n];
    for (int i = 0; i < n; i++) {
        served[i] = 0;
    }
    printf("Request order: ");
    for (int i = 0; i < n; i++) {
        int minDist = -1;
        int index = -1;
        for (int j = 0; j < n; j++) {
            if (!served[j]) {
                int dist = abs(requests[j] - head);
                if (minDist == -1 || dist < minDist) {
                    minDist = dist;
                    index = j;
                }
            }
        }
        served[index] = 1;
        totalHeadMovements += minDist;
        head = requests[index];
        printf("%d ", requests[index]);
    }
    printf("\nTotal head movements: %d\n", totalHeadMovements);
 }
 int main() {
    int requests[] = {186, 89, 44, 70, 102, 22, 51, 124};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head;
    printf("Enter the starting head position: ");
    scanf("%d", &head);
    sstf(requests, n, head);
    return 0;
 }
 