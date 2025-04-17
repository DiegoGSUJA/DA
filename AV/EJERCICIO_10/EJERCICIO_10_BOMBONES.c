#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    CHOCOLATE,
    CARAMELO,
    FRUTAS,
    MENTA,
    NUEZ,
    COCO
} TipoBombon;

typedef struct Bombon {
    TipoBombon tipo;
} Bombon;

typedef struct Caja {
    Bombon* bombones;
    int numBombones;
    int numTiposDistintos;
    int id; // Identificador de la caja
} Caja;

int comparar_cajas(const void* a, const void* b) {
    Caja* caja_a = (Caja*)a;
    Caja* caja_b = (Caja*)b;

    // Priorizar cajas con más tipos distintos y, en caso de empate, cajas con menos bombones en total
    if (caja_a->numTiposDistintos != caja_b->numTiposDistintos) {
        return caja_b->numTiposDistintos - caja_a->numTiposDistintos;
    } else {
        return caja_a->numBombones - caja_b->numBombones;
    }
}

void comprar_cajas(Caja cajas[], int num_cajas, int num_tipos_totales) {
    qsort(cajas, num_cajas, sizeof(Caja), comparar_cajas);

    bool tipos_recolectados[num_tipos_totales];
    for (int i = 0; i < num_tipos_totales; i++) {
        tipos_recolectados[i] = false;
    }

    int num_cajas_compradas = 0;
    int num_tipos_recolectados = 0;

    for (int i = 0; i < num_cajas && num_tipos_recolectados < num_tipos_totales; i++) {
        bool caja_util = false;
        for (int j = 0; j < cajas[i].numTiposDistintos; j++) {
            if (!tipos_recolectados[cajas[i].bombones[j].tipo]) {
                tipos_recolectados[cajas[i].bombones[j].tipo] = true;
                num_tipos_recolectados++;
                caja_util = true;
            }
        }
        if (caja_util) {
            printf("Comprar caja %d\n", cajas[i].id);
            num_cajas_compradas++;
        }
    }

    printf("Total de cajas compradas: %d\n", num_cajas_compradas);
}

int main() {
    Caja cajas[] = {
        {{(Bombon[]){{CHOCOLATE}, {CARAMELO}, {FRUTAS}}}, 3, 3, 1},
        {{(Bombon[]){{MENTA}, {NUEZ}}}, 2, 2, 2},
        {{(Bombon[]){{COCO}, {CHOCOLATE}}}, 2, 2, 3},
        {{(Bombon[]){{FRUTAS}, {NUEZ}, {COCO}}}, 3, 3, 4}
    };
    int num_cajas = sizeof(cajas) / sizeof(cajas[0]);
    int num_tipos_totales = 6;

    comprar_cajas(cajas, num_cajas, num_tipos_totales);

    return 0;
}