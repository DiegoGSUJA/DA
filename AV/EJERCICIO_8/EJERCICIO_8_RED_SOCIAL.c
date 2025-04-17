#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Arista {
    int origen;
    int destino;
} Arista;

int encontrar_conjunto(int conjuntos[], int nodo) {
    if (conjuntos[nodo] == nodo) return nodo;
    return conjuntos[nodo] = encontrar_conjunto(conjuntos, conjuntos[nodo]);
}

void unir_conjuntos(int conjuntos[], int origen, int destino) {
    int conjunto_origen = encontrar_conjunto(conjuntos, origen);
    int conjunto_destino = encontrar_conjunto(conjuntos, destino);
    conjuntos[conjunto_origen] = conjunto_destino;
}

float krukal_modificado(Arista aristas[], int num_aristas, int num_usuarios) {
    int conjuntos[num_usuarios];
    for (int i = 0; i < num_usuarios; i++) {
        conjuntos[i] = i;
    }

    for (int i = 0; i < num_aristas; i++) {
        unir_conjuntos(conjuntos, aristas[i].origen, aristas[i].destino);
    }

    // Usar un array auxiliar para rastrear las raíces encontradas
    int raices_encontradas[num_usuarios];
    int num_raices_encontradas = 0;

    for (int i = 0; i < num_usuarios; i++) {
        int raiz = encontrar_conjunto(conjuntos, i);
        bool raiz_ya_encontrada = false;
        for (int j = 0; j < num_raices_encontradas; j++) {
            if (raices_encontradas[j] == raiz) {
                raiz_ya_encontrada = true;
                break;
            }
        }
        if (!raiz_ya_encontrada) {
            raices_encontradas[num_raices_encontradas++] = raiz;
        }
    }

    return (float)num_raices_encontradas / num_usuarios;
}

int main() {
    Arista aristas[] = {{0, 5}, {0, 2}, {1, 6}, {1, 7}, {2, 5}, {2, 3}, {4, 0}, {5, 0}, {6, 1}, {7, 1}, {5, 2}, {3, 2}};
    int num_aristas = sizeof(aristas) / sizeof(aristas[0]);
    int num_usuarios = 8;

    float grado_conexion = krukal_modificado(aristas, num_aristas, num_usuarios);
    printf("Grado de conexión: %.2f\n", grado_conexion);

    return 0;
}