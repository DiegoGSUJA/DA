#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dorsal;
    int cantidadLiquido;
} Participante;

// Función para intercambiar dos elementos
void intercambiar(Participante *a, Participante *b) {
    Participante temp = *a;
    *a = *b;
    *b = temp;
}

// Función de partición
int particionar(Participante participantes[], int inicio, int fin) {
    int pivote = participantes[fin].cantidadLiquido;
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        if (participantes[j].cantidadLiquido >= pivote) {
            i++;
            intercambiar(&participantes[i], &participantes[j]);
        }
    }

    intercambiar(&participantes[i + 1], &participantes[fin]);
    return i + 1;
}

// Función principal de Divide y Vencerás
int encontrar_k_esimo(Participante participantes[], int inicio, int fin, int k) {
    if (inicio == fin) {
        return participantes[inicio].dorsal;
    }

    int posicion_pivote = particionar(participantes, inicio, fin);

    if (posicion_pivote == k - 1) {
        return participantes[posicion_pivote].dorsal;
    } else if (posicion_pivote > k - 1) {
        return encontrar_k_esimo(participantes, inicio, posicion_pivote - 1, k);
    } else {
        return encontrar_k_esimo(participantes, posicion_pivote + 1, fin, k);
    }
}

int main() {
    Participante participantes[] = {
        {7, 575}, {3, 842}, {10, 27}, {1, 135},
        {4, 970}, {6, 10}, {8, 1000}, {2, 624},
        {5, 468}, {9, 580}
    };
    int n = sizeof(participantes) / sizeof(participantes[0]);

    int k = 3; // Ejemplo: encontrar el 3er corredor con más líquido
    int dorsal_k_esimo = encontrar_k_esimo(participantes, 0, n - 1, k);

    printf("El dorsal del corredor en la posición %d es: %d\n", k, dorsal_k_esimo);

    return 0;
}