#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Pedido {
    int pedido;
    int limite;
    int cobro;
} Pedido;

int comprar_pedidos(const void *a, const void *b) {
    Pedido *A = (Pedido*)a;
    Pedido *B = (Pedido*)b;
    return B->cobro - A->cobro; // Corregido el orden para ordenar de mayor a menor cobro
}

int planificar_pedidos(Pedido pedidos[], int num_pedidos, int planificacion[]) {
    qsort(pedidos, num_pedidos, sizeof(Pedido), comprar_pedidos);

    int beneficio_total = 0;
    int tiempos_ocupados[num_pedidos];
    for(int i = 0; i < num_pedidos; i++) {
        tiempos_ocupados[i] = 0;
        planificacion[i] = 0; // Inicializar planificacion con 0
    }

    for(int i=0;i<num_pedidos;i++) {
        int pedido_actual = pedidos[i].pedido;
        int limite_actual = pedidos[i].limite;
        int cobro_actual = pedidos[i].cobro;

        for(int j=limite_actual-1;j>=0;j--) {
            if(tiempos_ocupados[j] == 0) {
                tiempos_ocupados[j] = 1;
                planificacion[j] = pedido_actual; // Corregido: asignar el número del pedido
                beneficio_total += cobro_actual;
                break;
            }
        }
    }
    return beneficio_total;
}

int main() {
    Pedido pedidos[] = {
        {1, 1, 60}, {2, 5, 70}, {3, 5, 80}, {4, 6, 20},
        {5, 6, 30}, {6, 4, 50}, {7, 4, 50}, {8, 2, 90}, {9, 2, 40}
    };
    int num_pedidos = sizeof(pedidos) / sizeof(pedidos[0]);
    int planificacion[num_pedidos];

    int beneficio_total = planificar_pedidos(pedidos, num_pedidos, planificacion);

    printf("Planificación de pedidos:\n");
    for (int i = 0; i < num_pedidos; i++) {
        if (planificacion[i] != 0) {
            printf("Tiempo %d: Pedido %d\n", i + 1, planificacion[i]);
        }
    }

    printf("Beneficio total: %d\n", beneficio_total);

    return 0;
}