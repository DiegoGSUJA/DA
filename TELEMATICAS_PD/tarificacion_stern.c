#include <stdio.h>
#include <stdlib.h>

int tarificacion_postal(int sellos[], int n, int tarifa) {
    /*
     * Calcula el número de formas de alcanzar una tarifa postal exacta usando diferentes sellos.
     *
     * Args:
     * sellos (int[]): Un array de enteros que representan los valores de los sellos disponibles.
     * n (int): El número de sellos disponibles.
     * tarifa (int): La tarifa postal total que se desea alcanzar.
     *
     * Returns:
     * int: El número de formas diferentes de alcanzar la tarifa postal.
     */

    int i, j;
    // Inicializar la matriz con 0s
    int **matriz = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        matriz[i] = (int *)malloc((tarifa + 1) * sizeof(int));
        for (j = 0; j <= tarifa; j++) {
            matriz[i][j] = 0;
        }
    }

    // Caso base: tarifa 0 se puede alcanzar de 1 forma (sin sellos)
    for (i = 0; i <= n; i++) {
        matriz[i][0] = 1;
    }

    // Llenar la matriz de forma ascendente
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= tarifa; j++) {
            if (sellos[i - 1] > j) {
                matriz[i][j] = matriz[i - 1][j];  // No usar el sello actual
            } else {
                // Usar o no usar el sello actual
                matriz[i][j] = matriz[i - 1][j] + matriz[i][j - sellos[i - 1]];
            }
        }
    }

    int resultado = matriz[n][tarifa];

    // Liberar la memoria asignada a la matriz
    for (i = 0; i <= n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return resultado;
}

int serie_de_stern(int n) {
    /*
     * Calcula el n-ésimo término de la serie de Stern utilizando programación dinámica.
     *
     * Args:
     * n (int): El índice del término a calcular.
     *
     * Returns:
     * int: El n-ésimo término de la serie de Stern.
     */

    // Caso base
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    // Inicializar la tabla para almacenar los valores de la serie
    int *tabla = (int *)malloc((n + 1) * sizeof(int));
    tabla[0] = 0;
    tabla[1] = 1;

    // Calcular los términos de la serie de forma iterativa
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            tabla[i] = tabla[i / 2];
        } else {
            tabla[i] = tabla[i / 2] + tabla[i / 2 + 1];
        }
    }

    int resultado = tabla[n];
    free(tabla); // Liberar la memoria asignada
    return resultado;
}

int main() {
    // Prueba de tarificacion_postal
    int sellos[] = {1, 5, 10, 20};
    int n_sellos = sizeof(sellos) / sizeof(sellos[0]);
    int tarifa = 12;

    int formas = tarificacion_postal(sellos, n_sellos, tarifa);
    printf("Numero de formas de alcanzar la tarifa %d: %d\n", tarifa, formas);  // Output: 4

    // Prueba de serie_de_stern
    int n_stern = 10;
    int resultado_stern = serie_de_stern(n_stern);
    printf("El termino %d de la serie de Stern es: %d\n", n_stern, resultado_stern);  // Output: 4

    return 0;
}