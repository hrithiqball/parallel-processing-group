#include <mpi.h>
#include <cstdio>
#include <cmath>
#include <ctime>

// run with 3 processes
int main(int argc, char** argv) {
    int rank, size;
    double A, B, C, D, E, Y, Z;
    double part = 0.0, result = 0.0;
    double parts[3];
    double start_time, end_time;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Only rank 0 reads input
    if (rank == 0) {
        setbuf(stdout, NULL);
        printf("Enter values for the following:\n");

        printf("A: "); fflush(stdout);
        scanf("%lf", &A);

        printf("B: "); fflush(stdout);
        scanf("%lf", &B);

        printf("C: "); fflush(stdout);
        scanf("%lf", &C);

        printf("D: "); fflush(stdout);
        scanf("%lf", &D);

        printf("E: "); fflush(stdout);
        scanf("%lf", &E);

        printf("Y: "); fflush(stdout);
        scanf("%lf", &Y);

        printf("Z: "); fflush(stdout);
        scanf("%lf", &Z);
    }

    // Broadcast all values to all processes
    MPI_Bcast(&A, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(&B, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(&C, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(&D, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(&E, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(&Y, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Bcast(&Z, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);
    start_time = MPI_Wtime();

    // Start computation
    if (rank == 0) {
        part = A;
    } else if (rank == 1) {
        part = (B / C) * (D + E * E);
    } else if (rank == 2) {
        part = Y * Z;
    }

    // Gather parts into rank 0
    MPI_Gather(&part, 1, MPI_DOUBLE, parts, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        end_time = MPI_Wtime();

        double term1 = parts[0];
        double term2 = parts[1];
        double term3 = parts[2];
        result = term1 + term2 + term3;

        printf("Result: %.2lf + (%.2lf/%.2lf)*(%.2lf + %.2lf^2) + %.2lf*%.2lf\n", A, B, C, D, E, Y, Z);
        printf("= %.2lf + (%.2lf)*(%.2lf) + %.2lf\n", term1, B / C, D + E * E, term3);
        printf("= %.2lf + %.2lf + %.2lf = %.2lf\n", term1, term2, term3, result);
        printf("Final Result: %.2lf\n", result);
        printf("Execution Time: %.3f ms\n", (end_time - start_time) * 1000);
    }

    MPI_Finalize();
    return 0;
}
