#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int balda_mejor_candidata(int baldas[], int num_baldas) {
    int indice_balda_minima = 0;
    for (int i = 1; i < num_baldas; i++) {
        if (baldas[i] < baldas[indice_balda_minima]) {
            indice_balda_minima = i;
        }
    }
    return indice_balda_minima;
}

void heuristica_libros_baldas(int pesos_libros[], int num_libros, int baldas[], int num_baldas, int cantidad_libros_balda[]) {
    // Inicializar baldas con los primeros libros y cantidad de libros a 1
    for (int i = 0; i < num_baldas; i++) {
        baldas[i] = pesos_libros[i];
        cantidad_libros_balda[i] = 1;
    }

    // Asignar los libros restantes a las baldas
    for (int i = num_baldas; i < num_libros; i++) {
        int indice_balda_minima = balda_mejor_candidata(baldas, num_baldas);
        baldas[indice_balda_minima] += pesos_libros[i];
        cantidad_libros_balda[indice_balda_minima]++;
    }
}

int main() {
    int baldas[] = {20, 20, 20};
    int libros[] = {2, 6, 2, 9, 1, 4, 7, 1, 1, 4, 2};
    int num_baldas = 3;
    int num_libros = sizeof(libros) / sizeof(libros[0]);
    int cantidad_libros_balda[num_baldas];

    heuristica_libros_baldas(libros, num_libros, baldas, num_baldas, cantidad_libros_balda);

    printf("Resultados:\n");
    for (int i = 0; i < num_baldas; i++) {
        printf("Balda %d: Peso total = %d, Cantidad de libros = %d\n", i + 1, baldas[i], cantidad_libros_balda[i]);
    }

    return 0;
}