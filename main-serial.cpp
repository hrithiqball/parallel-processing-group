#include <cstdio>
#include <cmath>
#include <ctime>

int main() {
    double A, B, C, D, E, Y, Z;
    double term1, term2, term3, result;

    // Input
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

    clock_t start = clock();

    // Compute terms
    term1 = A;
    term2 = (B / C) * (D + E * E);
    term3 = Y * Z;
    result = term1 + term2 + term3;

    clock_t end = clock();
    double duration_ms = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;

    // Output
    printf("Result: %.2lf + (%.2lf/%.2lf)*(%.2lf + %.2lf^2) + %.2lf*%.2lf\n", A, B, C, D, E, Y, Z);
    printf("= %.2lf + (%.2lf)*(%.2lf) + %.2lf\n", term1, B / C, D + E * E, term3);
    printf("= %.2lf + %.2lf + %.2lf = %.2lf\n", term1, term2, term3, result);
    printf("Final Result: %.2lf\n", result);
    printf("Execution Time: %.3f ms\n", duration_ms);

    return 0;
}
