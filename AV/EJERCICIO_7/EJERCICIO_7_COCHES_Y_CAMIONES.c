#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Coche {
    int longitud;
    int peso;
} Coche;

typedef struct Trailer {
    int longitud;
    int peso;
    Coche coches_metidos[4];
    int num_coches_metidos; // Para rastrear la cantidad de coches en el trailer
} Trailer;

int comparar_coche_desc(const void *a, const void *b) {
    Coche *a1 = (Coche *)a;
    Coche *b1 = (Coche *)b;
    if (b1->peso != a1->peso) {
        return b1->peso - a1->peso; // Ordenar por peso descendente
    } else {
        return b1->longitud - a1->longitud; // Ordenar por longitud descendente
    }
}

int comparar_trailer_desc(const void *a, const void *b) {
    Trailer *a1 = (Trailer *)a;
    Trailer *b1 = (Trailer *)b;
    if (b1->peso != a1->peso) {
        return b1->peso - a1->peso; // Ordenar por capacidad de peso descendente
    } else {
        return b1->longitud - a1->longitud; // Ordenar por capacidad de longitud descendente
    }
}

void heuristica_coches_trailers(Coche coches[], int tam_coches, Trailer trailers[], int tam_trailers) {
    int trailer_index = 0;
    for (int i = 0; i < tam_coches; i++) {
        bool coche_asignado = false;
        for (int j = 0; j < tam_trailers; j++) {
            if (trailers[j].peso >= coches[i].peso && trailers[j].longitud >= coches[i].longitud && trailers[j].num_coches_metidos < 4) {
                trailers[j].coches_metidos[trailers[j].num_coches_metidos] = coches[i];
                trailers[j].num_coches_metidos++;
                trailers[j].peso -= coches[i].peso;
                trailers[j].longitud -= coches[i].longitud;
                coche_asignado = true;
                break;
            }
        }
        if (!coche_asignado) {
            printf("No se pudo asignar el coche %d (peso=%d, longitud=%d)\n", i, coches[i].peso, coches[i].longitud);
        }
    }
}

int main() {
    Coche coches[] = {{3, 1000}, {2, 800}, {4, 1200}, {2, 900}, {3, 1100}};
    Trailer trailers[20];
    for (int i = 0; i < 20; i++) {
        trailers[i].peso = 5000;
        trailers[i].longitud = 10;
        trailers[i].num_coches_metidos = 0;
    }
    int tam_coches = sizeof(coches) / sizeof(coches[0]);
    int tam_trailers = 20;

    qsort(coches, tam_coches, sizeof(Coche), comparar_coche_desc);
    qsort(trailers, tam_trailers, sizeof(Trailer), comparar_trailer_desc);

    heuristica_coches_trailers(coches, tam_coches, trailers, tam_trailers);

    // Imprimir resultados
    for (int i = 0; i < tam_trailers; i++) {
        if (trailers[i].num_coches_metidos > 0) {
            printf("Trailer %d: %d coches\n", i, trailers[i].num_coches_metidos);
        }
    }

    return 0;
}