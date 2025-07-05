#include <mpi.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define N 1000

// Use Bubble Sort
void bubble_sort(int arr[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main(int argc, char** argv)
{
    int rank, size;
    int data[N];
    int local_data[N];
    int chunk, i;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    chunk = N / size;

    double start_time = 0.0, end_time = 0.0;

    if (rank == 0)
    {
        srand(time(0));
        for (i = 0; i < N; i++)
        {
            data[i] = rand() % 1000;
        }

        start_time = MPI_Wtime();
    }

    MPI_Scatter(data, chunk, MPI_INT, local_data, chunk, MPI_INT, 0, MPI_COMM_WORLD);

    bubble_sort(local_data, chunk);

    MPI_Gather(local_data, chunk, MPI_INT, data, chunk, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        end_time = MPI_Wtime();


        printf("First 10 elements of partially sorted array:\n");
        for (i = 0; i < 10; i++)
        {
            printf("%d ", data[i]);
        }
        printf("\n");
        printf("Execution time: %f ms\n", (end_time - start_time) * 1000);
    }

    MPI_Finalize();
    return 0;
}
