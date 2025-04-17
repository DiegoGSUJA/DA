#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct Arista {
    int origen;
    int destino;
    int costo;
}Arista;


int calcular_costo(int origen, int destino) {
    return (origen + destino) % 8;
}

int comparar_aristas(const void *a, const void *b) {
    Arista *arista_a = (Arista *)a;
    Arista *arista_b = (Arista *)b;
    return arista_a->costo - arista_b->costo;
}

int encontrar_conjunto(int conjuntos[], int nodo) {
    if(conjuntos[nodo] == nodo) {
        return nodo;
    }
    return  conjuntos[nodo] = encontrar_conjunto(conjuntos, conjuntos[nodo]);
}

void unir_conjuntos(int conjuntos[], int origen, int destino) {
    int conjunto_origen = encontrar_conjunto(conjuntos, origen);
    int conjunto_destino = encontrar_conjunto(conjuntos, destino);
    conjuntos[conjunto_origen] = conjunto_destino;
}


int main() {
    int num_nodos = 10;
    int num_aristas = num_nodos * (num_nodos-1) / 2 ;
    Arista aristas[num_aristas];
    int conjuntos[num_nodos];

    int indice_arista = 0;
    for(int i=0;i<num_nodos;i++) {
        for(int j = i+1;j<num_nodos;j++) {
            aristas[indice_arista].origen = i;
            aristas[indice_arista].destino = j;
            aristas[indice_arista].costo = calcular_costo(i+1, j+1);
            indice_arista++;
        }
    }

    qsort(aristas, num_aristas, sizeof(Arista), comparar_aristas);

    for(int i=0;i<num_nodos;i++) {
        conjuntos[i] = i;
    }

    int costo_total = 0;
    int num_aristas_seleccionadas = 0;
    Arista aristas_seleccionadas[num_nodos-1];

    for(int i=0;i<num_aristas;i++) {
        int origen = aristas[i].origen;
        int destino = aristas[i].destino;

        if(encontrar_conjunto(conjuntos, origen) != encontrar_conjunto(conjuntos, destino)) {
            unir_conjuntos(conjuntos, origen, destino);
            aristas_seleccionadas[num_aristas_seleccionadas] = aristas[i];
            costo_total += aristas[i].costo;
            num_aristas_seleccionadas++;
        }

        if(num_aristas_seleccionadas == num_nodos-1) {
            break;
        }
    }

    // Imprimir el resultado
    printf("Aristas seleccionadas:\n");
    for (int i = 0; i < num_aristas_seleccionadas; i++) {
        printf("(%d, %d) - Costo: %d\n", aristas_seleccionadas[i].origen + 1, aristas_seleccionadas[i].destino + 1, aristas_seleccionadas[i].costo);
    }
    printf("Costo total: %d\n", costo_total);

    return 0;
}

