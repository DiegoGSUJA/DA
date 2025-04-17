#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int suma_optima(int A[], int B[], int tam) {
    qsort(B, tam, sizeof(int), comparar); // Ordenar B de forma ascendente
    int suma = 0;
    int j = 0;
    for (int i = 0; i < tam; i++) {
        while (j < tam && B[j] < A[i]) {
            j++;
        }
        if (j < tam && B[j] >= A[i]) {
            suma += A[i];
            j++;
        }
    }
    return suma;
}

int main() {
    int A[] = {1, 4, 6, 7, 9};
    int B[] = {3, 2, 4, 6, 5};
    int tam = sizeof(A) / sizeof(A[0]);

    int resultado = suma_optima(A, B, tam);
    printf("La suma óptima es: %d\n", resultado);

    return 0;
}