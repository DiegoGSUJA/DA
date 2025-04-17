#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void merge(int T[], int U[], int V[], int n) {
    int mitad = n / 2;
    int tam_u = mitad;
    int tam_v = n - mitad;

    int i = 0, j = 0, k = 0;

    printf("merge: n=%d, mitad=%d, tam_u=%d, tam_v=%d\n", n, mitad, tam_u, tam_v); // Depuración

    for (; i < tam_u && j < tam_v; k++) {
        printf("merge: i=%d, j=%d, k=%d\n", i, j, k); // Depuración
        if (U[i] <= V[j]) {
            T[k] = U[i++];
        } else {
            T[k] = V[j++];
        }
    }

    if (i < tam_u) {
        for (; i < tam_u; k++) {
            T[k] = U[i];
        }
    } else if (j < tam_v) {
        for (; j < tam_v; k++) {
            T[k] = V[j];
        }
    }
}

void mergesort(int T[], int n) {
    if (n < 2) {
        return;
    }

    int mitad = n / 2;
    int *U = (int *)malloc(mitad * sizeof(int));
    int *V = (int *)malloc((n - mitad) * sizeof(int));

    printf("mergesort: n=%d, mitad=%d\n", n, mitad); // Depuración

    if (U == NULL || V == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < mitad; i++) {
        U[i] = T[i];
    }

    for (int i = mitad; i < n; i++) {
        V[i - mitad] = T[i];
    }

    mergesort(U, mitad);
    mergesort(V, n - mitad);

    merge(T, U, V, n);

    free(U);
    free(V);
}

int main(void) {
    int T[] = {18, 11, 14, 2, 5};
    int n = sizeof(T) / sizeof(T[0]);

    mergesort(T, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }

    return 0;
}