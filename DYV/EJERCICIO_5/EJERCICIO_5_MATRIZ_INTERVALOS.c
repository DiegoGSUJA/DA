#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool incluido(int a, int b, int valor) {
    return valor >= a && valor <= b;
}

// Implementación de Divide y Vencerás
int contarDentroIntervaloEnMAtriz(int **matrizP, int inicioFila, int inicioColumna, int n, int a, int b) {
    if (n == 1) {
        return incluido(a, b, matrizP[inicioFila][inicioColumna]) ? 1 : 0;
    }

    int mitad = n / 2;

    int contador1 = contarDentroIntervaloEnMAtriz(matrizP, inicioFila, inicioColumna, mitad, a, b);
    int contador2 = contarDentroIntervaloEnMAtriz(matrizP, inicioFila, inicioColumna + mitad, mitad, a, b);
    int contador3 = contarDentroIntervaloEnMAtriz(matrizP, inicioFila + mitad, inicioColumna, mitad, a, b);
    int contador4 = contarDentroIntervaloEnMAtriz(matrizP, inicioFila + mitad, inicioColumna + mitad, mitad, a, b);

    return contador1 + contador2 + contador3 + contador4;
}

// Implementación Clásica (iterativa)
int contarDentroIntervaloClasico(int **matriz, int n, int a, int b) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (incluido(a, b, matriz[i][j])) {
                contador++;
            }
        }
    }
    return contador;
}

int main() {
    int n = 1024; // Matriz grande para medir tiempos
    int **matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    // Inicializar la matriz con valores aleatorios
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100; // Valores entre 0 y 99
        }
    }

    int a = 30, b = 70;

    // Medir tiempo de Divide y Vencerás
    clock_t inicio_dyv = clock();
    int resultado_dyv = contarDentroIntervaloEnMAtriz(matriz, 0, 0, n, a, b);
    clock_t fin_dyv = clock();
    double tiempo_dyv = (double)(fin_dyv - inicio_dyv) / CLOCKS_PER_SEC;

    // Medir tiempo del algoritmo clásico
    clock_t inicio_clasico = clock();
    int resultado_clasico = contarDentroIntervaloClasico(matriz, n, a, b);
    clock_t fin_clasico = clock();
    double tiempo_clasico = (double)(fin_clasico - inicio_clasico) / CLOCKS_PER_SEC;

    // Imprimir resultados y tiempos
    printf("Divide y Vencerás: Cantidad de números en el intervalo [%d, %d]: %d\n", a, b, resultado_dyv);
    printf("Tiempo de ejecución (Divide y Vencerás): %f segundos\n", tiempo_dyv);

    printf("Clásico: Cantidad de números en el intervalo [%d, %d]: %d\n", a, b, resultado_clasico);
    printf("Tiempo de ejecución (Clásico): %f segundos\n", tiempo_clasico);

    // Liberar la memoria
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}