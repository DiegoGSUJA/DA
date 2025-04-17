#include <stdio.h>
#include <stdlib.h>

int contar_frecuencia(int V[], int inicio, int fin, int elemento) {
    int frecuencia = 0;
    for (int i = inicio; i < fin; i++) {
        if (V[i] == elemento) {
            frecuencia++;
        }
    }
    return frecuencia;
}

int mayoritario(int T[], int inicio, int fin) {
    int n = fin - inicio;
    if (n == 0) {
        return -1;
    }
    if (n == 1) {
        return T[inicio];
    }

    int mitad = inicio + n / 2;

    int mayoritario_izq = mayoritario(T, inicio, mitad);
    int mayoritario_derech = mayoritario(T, mitad, fin);

    if (mayoritario_izq == mayoritario_derech) {
        return mayoritario_izq;
    } else {
        if (contar_frecuencia(T, inicio, fin, mayoritario_derech) > n / 2) {
            return mayoritario_derech;
        } else if (contar_frecuencia(T, inicio, fin, mayoritario_izq) > n / 2) {
            return mayoritario_izq;
        } else {
            return -1;
        }
    }
}

int main() {
    int prueba[] = {1, 2, 2, 2, 1};
    int resultado_esperado = 2;
    int n = sizeof(prueba) / sizeof(prueba[0]);

    int resultado = mayoritario(prueba, 0, n);

    if (resultado == resultado_esperado) {
        printf("Prueba: PASADA (resultado=%d, esperado=%d)\n", resultado, resultado_esperado);
    } else {
        printf("Prueba: FALLIDA (resultado=%d, esperado=%d)\n", resultado, resultado_esperado);
    }

    return 0;
}