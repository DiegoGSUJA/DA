#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool incluido(int mi, int ma, int valor) {
    return valor >= mi && valor <= ma;
}

int contar_incluidos(int minimo, int maximo, int valores[], int inicio, int fin) {
    if (inicio > fin) {
        return 0; // Caso base: no hay elementos en el rango
    }

    if (inicio == fin) {
        return incluido(minimo, maximo, valores[inicio]) ? 1 : 0;
    }

    int medio = (inicio + fin) / 2;
    int contador = 0;

    // Contar elementos en la mitad izquierda
    contador += contar_incluidos(minimo, maximo, valores, inicio, medio);

    // Contar elementos en la mitad derecha
    contador += contar_incluidos(minimo, maximo, valores, medio + 1, fin);

    return contador;
}

int main() {
    int valores[] = {1, 3, 5, 7, 9, 11, 12, 13, 15};
    int minimo = 4;
    int maximo = 12;
    int tam = sizeof(valores) / sizeof(valores[0]);

    int resultado = contar_incluidos(minimo, maximo, valores, 0, tam - 1);
    printf("Número de elementos en el rango [%d, %d]: %d\n", minimo, maximo, resultado);

    return 0;
}