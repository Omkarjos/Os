slip 5,23 
#include <stdio.h>
 int main() {
    int m, n;
    printf("Enter number of processes (m): ");
    scanf("%d", &m);
    printf("Enter number of resource types (n): ");
    scanf("%d", &n);
    int allocation[m][n], max[m][n], need[m][n], available[n];
    int request[n], process;
    // Input Available resources for each resource type
    printf("Enter the number of available instances for each resource type: \n");
    for (int i = 0; i < n; i++) {
        printf("Resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }
    // Input Allocation matrix
    printf("Enter the Allocation matrix:\n");
    for (int i = 0; i < m; i++) {
        printf("Process %d Allocation: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    // Input Maximum requirement matrix
    printf("Enter the Maximum requirement matrix:\n");
    for (int i = 0; i < m; i++) {
        printf("Process %d Maximum: ", i);
        for (int j = 0; j < n; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    // Calculate the Need matrix (Need = Max - Allocation)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    // Display the Need matrix
    printf("\nNeed Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    // Accept a request from a process
    printf("\nEnter the process number making the request (0 to %d): ", m - 1);
    scanf("%d", &process);
    printf("Enter the resource request for process %d:\n", process);
    for (int i = 0; i < n; i++) {
        printf("Resource %d: ", i + 1);
        scanf("%d", &request[i]);
    }
    // Check if the request can be granted immediately
    int can_be_granted = 1;
    // Check if the request is less than the available resources
    for (int i = 0; i < n; i++) {
        if (request[i] > available[i]) {
            can_be_granted = 0;
            break;
        }
    }
    // Check if the request is less than the need for the process
    for (int i = 0; i < n; i++) {
        if (request[i] > need[process][i]) {
            can_be_granted = 0;
            break;
        }
    }
    if (can_be_granted) {
        printf("\nThe request can be granted immediately.\n");
    } else {
        printf("\nThe request cannot be granted immediately.\n");
    }
    return 0;
 }
