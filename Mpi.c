slip 30,29,28,27,24,22,21,20,16,11,5,3,2
#include <mpi.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #define ARRAY_SIZE 1000
 int main(int argc, char *argv[]) {
    int rank, size, i, sum = 0, total_sum = 0;
    int numbers[ARRAY_SIZE], local_sum = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0) {
        srand(time(NULL));
        for (i = 0; i < ARRAY_SIZE; i++) {
            numbers[i] = rand() % 100;
        }
    }
    int chunk_size = ARRAY_SIZE / size;
    int local_numbers[chunk_size];
    MPI_Scatter(numbers, chunk_size, MPI_INT, local_numbers, chunk_size, MPI_INT, 
0, MPI_COMM_WORLD);
    for (i = 0; i < chunk_size; i++) {
        local_sum += local_numbers[i];
    }
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, 
MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Total sum of 1000 numbers: %d\n", total_sum);
    }
    MPI_Finalize();
    return 0;
 }
