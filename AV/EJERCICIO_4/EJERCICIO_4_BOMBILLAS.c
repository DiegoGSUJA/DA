#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Bombilla {
    int id;
    int duracion;
} Bombilla;

int comparar_bombillas_duracion(const void *a, const void *b) {
    Bombilla *b1 = (Bombilla *)a;
    Bombilla *b2 = (Bombilla *)b;
    return b2->duracion - b1->duracion;
}

bool bombilla_disponible(Bombilla bombillas[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (bombillas[i].duracion > 0) {
            return true;
        }
    }
    return false;
}

void suplir_bombilla_encendida(Bombilla bombillas[], int tam, Bombilla *bombillas_encendidas[], int encendidas_indices[]) {
    for (int i = 0; i < 3; i++) {
        if (bombillas_encendidas[i]->duracion <= 0) {
            for (int j = 0; j < tam; j++) {
                bool usada = false;
                for (int k = 0; k < 3; k++) {
                    if (encendidas_indices[k] == j) {
                        usada = true;
                        break;
                    }
                }
                if (!usada && bombillas[j].duracion > 0) {
                    *bombillas_encendidas[i] = bombillas[j];
                    bombillas[j].duracion = 0; // Actualizar la bombilla en el arreglo original
                    encendidas_indices[i] = j;
                    break;
                }
            }
        }
    }
}

void pasar_dia(Bombilla bombillas[], int tam, Bombilla *bombillas_encendidas[], int encendidas_indices[], int *dias_superados) {
    for (int i = 0; i < 3; i++) {
        bombillas_encendidas[i]->duracion--;
    }
    suplir_bombilla_encendida(bombillas, tam, bombillas_encendidas, encendidas_indices);
    (*dias_superados)++;
}

void funcion_heuristica_def(Bombilla bombillas[], int tam, int *resultado) {
    qsort(bombillas, tam, sizeof(Bombilla), comparar_bombillas_duracion);

    Bombilla *bombillas_encendidas[3];
    int encendidas_indices[3];
    for (int i = 0; i < 3; i++) {
        bombillas_encendidas[i] = &bombillas[i];
        encendidas_indices[i] = i;
    }

    int dias_pasados = 0;

    while (bombilla_disponible(bombillas, tam)) {
        pasar_dia(bombillas, tam, bombillas_encendidas, encendidas_indices, &dias_pasados);
    }

    *resultado = dias_pasados;
}

int main() {
    Bombilla bombillas[] = {{1, 1}, {2, 4}, {3, 2}, {4, 3}, {5, 1}, {6, 1}, {7, 3}, {8, 1}, {9, 5}, {10, 2}};
    int tam_bombillas = sizeof(bombillas) / sizeof(bombillas[0]);
    int dias_superados = 0;

    funcion_heuristica_def(bombillas, tam_bombillas, &dias_superados);
    printf("El resultado fue: %d\n", dias_superados);

    return 0;
}