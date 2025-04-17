#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Arista {
    int origen;
    int destino;
}Arista;

int encontrar_conjunto(int conjuntos[], int nodo) {
    if(conjuntos[nodo] == nodo) return nodo;
    return conjuntos[nodo] = encontrar_conjunto(conjuntos, conjuntos[nodo]);
}

void unir_conjuntos(int conjuntos[], int origen, int destino) {
    int conjunto_origen = encontrar_conjunto(conjuntos, origen);
    int conjuntos_destino = encontrar_conjunto(conjuntos, destino);
    conjuntos[conjunto_origen] = conjuntos_destino;
}

bool kruskal_conexo(Arista aristas[], int num_aristas, int num_elementos) {
    int conjuntos[num_elementos];
    for(int i = 0; i < num_elementos; i++) {
        conjuntos[i] = i;
    }

    for(int i=0;i<num_aristas;i++) {
        unir_conjuntos(conjuntos,aristas[i].origen, aristas[i].destino);
    }

    int raiz = encontrar_conjunto(conjuntos,0);
    for(int i=1;i<num_elementos;i++) {
        if(encontrar_conjunto(conjuntos,i) != raiz) return false;
    }
    return true;


}
















int main(){}