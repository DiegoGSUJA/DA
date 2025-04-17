#include <stdio.h>
#include <stdlib.h>

int buscar_min(int U[], int inicio, int final) {
    if(inicio == final || inicio>final) return U[inicio];

    int mitad = (inicio + final) / 2;

    if(U[mitad]>U[mitad+1]) {
        return buscar_min(U, mitad+1, final);
    }else {
        return buscar_min(U, inicio, mitad);
    }
}

int main() {
    int U[] = {6,4,3,1,9,10,13};
    int tam = sizeof(U) / sizeof(int);

    int resultado = buscar_min(U, 0, tam-1);

    printf("%d\n", resultado);
}