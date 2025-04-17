#include <stdio.h>
#include <stdlib.h>

int encontrar_minimo_local(int A[], int inicio, int fin) {
    if (inicio == fin) {
        return inicio; // Caso base: un solo elemento
    }

    int medio = (inicio + fin) / 2;

    if (medio > inicio && A[medio - 1] < A[medio]) {
        return encontrar_minimo_local(A, inicio, medio - 1);
    } else if (medio < fin && A[medio + 1] < A[medio]) {
        return encontrar_minimo_local(A, medio + 1, fin);
    } else {
        return medio; // A[medio] es un mínimo local
    }
}

int main() {
    int A[] = {9, 6, 3, 14, 5, 7, 12};
    int tam = sizeof(A) / sizeof(A[0]);

    int minimo_local_indice = encontrar_minimo_local(A, 0, tam - 1);

    printf("El mínimo local se encuentra en el índice %i, con valor %i\n", minimo_local_indice, A[minimo_local_indice]);

    return 0;
}