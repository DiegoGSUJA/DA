#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_TRANSPORTISTAS 6 // Según la matriz proporcionada

int costes[MAX_TRANSPORTISTAS][MAX_TRANSPORTISTAS] = {
    {40, 73, 77, 83, 29, 11},
    {56, 14, 86, 22, 75, 37},
    {24, 67, 49, 19, 91, 12},
    {26, 56, 33, 67, 32, 62},
    {38, 53, 73, 83, 21, 43},
    {76, 44, 10, 42, 31, 12}
};

int mejor_coste = INT_MAX;
int solucion_actual[MAX_TRANSPORTISTAS];
int mejor_solucion[MAX_TRANSPORTISTAS];
bool destino_asignado[MAX_TRANSPORTISTAS];

// Función de Vuelta Atrás para asignar transportistas
void asignar_transportistas(int transportista_actual, int coste_actual) {
    if (transportista_actual == MAX_TRANSPORTISTAS) {
        // Se han asignado todos los transportistas
        if (coste_actual < mejor_coste) {
            mejor_coste = coste_actual;
            for (int i = 0; i < MAX_TRANSPORTISTAS; i++) {
                mejor_solucion[i] = solucion_actual[i];
            }
        }
        return;
    }

    // Probar asignar el transportista actual a cada destino no asignado
    for (int destino = 0; destino < MAX_TRANSPORTISTAS; destino++) {
        if (!destino_asignado[destino]) {
            solucion_actual[transportista_actual] = destino;
            destino_asignado[destino] = true;
            int nuevo_coste = coste_actual + costes[transportista_actual][destino];

            // Poda: Si el coste actual ya es mayor que la mejor solución encontrada, no explorar más
            if (nuevo_coste < mejor_coste) {
                asignar_transportistas(transportista_actual + 1, nuevo_coste);
            }

            // Deshacer la asignación para la siguiente prueba (Vuelta Atrás)
            destino_asignado[destino] = false;
        }
    }
}

int main() {
    // Inicializar el array de destinos asignados
    for (int i = 0; i < MAX_TRANSPORTISTAS; i++) {
        destino_asignado[i] = false;
    }

    printf("Resolviendo la Huelga de Transportistas con Vuelta Atrás y Poda:\n");
    asignar_transportistas(0, 0);

    printf("Mejor coste encontrado: %d\n", mejor_coste);
    printf("Asignación de transportistas (Transportista -> Destino):\n");
    for (int i = 0; i < MAX_TRANSPORTISTAS; i++) {
        printf("Transportista %d -> Destino %d\n", i + 1, mejor_solucion[i] + 1);
    }

    return 0;
}
