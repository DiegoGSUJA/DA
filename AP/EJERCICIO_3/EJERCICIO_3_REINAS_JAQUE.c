#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Función para verificar si una reina en (fila, col) está segura en el tablero actual
bool es_segura(int tablero[], int fila, int col) {
    // Verificar si hay otra reina en la misma columna
    for (int i = 0; i < fila; i++) {
        if (tablero[i] == col) {
            return false;
        }
    }

    // Verificar diagonales
    for (int i = 0; i < fila; i++) {
        // Diagonal principal (misma diferencia entre filas y columnas)
        if (abs(fila - i) == abs(col - tablero[i])) {
            return false;
        }
    }

    return true;
}

#define N 8

// Función para imprimir una solución (la configuración del tablero)
void imprimir_tablero(int tablero[]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablero[i] == j) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Función recursiva de Vuelta Atrás para encontrar todas las soluciones
void resolver_ocho_reinas(int tablero[], int fila) {
    // Caso base: Si hemos colocado reinas en todas las 8 filas, hemos encontrado una solución
    if (fila == N) {
        imprimir_tablero(tablero);
        return;
    }

    // Intentar colocar una reina en cada columna de la fila actual
    for (int columna = 0; columna < N; columna++) {
        // Verificar si es seguro colocar una reina en esta posición
        if (es_segura(tablero, fila, columna)) {
            // Colocar la reina en esta posición
            tablero[fila] = columna;

            // Llamada recursiva para la siguiente fila
            resolver_ocho_reinas(tablero, fila + 1);

            // No necesitamos "deshacer" la elección aquí explícitamente porque
            // en la siguiente iteración del bucle 'for', sobrescribiremos tablero[fila]
        }
    }
}

int main() {
    int tablero[N];
    resolver_ocho_reinas(tablero, 0); // Empezar desde la primera fila (fila 0)
    return 0;
}