#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define N 1000

void bubble_sort(int arr[], int n)
{
    int tmp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

int main()
{
    int data[N];
    srand(time(0));

    for (int i = 0; i < N; i++)
    {
        data[i] = rand() % 1000;
    }

    clock_t start = clock();

    bubble_sort(data, N);

    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    printf("First 10 elements of sorted array:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\nExecution time: %.2f ms\n", duration);

    return 0;
}
