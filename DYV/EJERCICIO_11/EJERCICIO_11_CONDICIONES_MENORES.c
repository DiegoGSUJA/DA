#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool son_iguales(int n1, int n2) {
    return n1 == n2;
}

int encontrar_diferencia(int inicio, int fin, int V[], int U[]) {
    if (inicio > fin) {
        return -1; // Caso base: no hay elementos en el rango
    }

    if (inicio == fin) {
        return son_iguales(V[inicio], U[inicio]) ? -1 : inicio;
    }

    int medio = (inicio + fin) / 2;

    int izquierda = encontrar_diferencia(inicio, medio, V, U);
    int derecha = encontrar_diferencia(medio + 1, fin, V, U);

    if (izquierda != -1) {
        return izquierda;
    } else {
        return derecha;
    }
}

int main() {
    int V[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int U[] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 10};

    int tam = sizeof(V) / sizeof(V[0]);

    int resultado = encontrar_diferencia(0, tam - 1, V, U);

    printf("%d\n", resultado);

    return 0;
}