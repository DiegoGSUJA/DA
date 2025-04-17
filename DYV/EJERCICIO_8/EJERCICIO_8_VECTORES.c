#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int existencia_iguales(int M[], int T[], int inicio, int final) {
    int mitad = (inicio+final)/2;

    if(M[mitad] == T[mitad]) {
        return mitad;
    }

    if(M[mitad] > M[mitad]) {
        return existencia_iguales(M,T,mitad+1,final);
    }else if(M[mitad] < M[mitad]) {
        return existencia_iguales(M,T,inicio,mitad-1);
    }
}




int main() {

    int X[] = {1, 3, 5, 7, 9};
    int Y[] = {9, 7, 5, 3, 1};
    int N = sizeof(X) / sizeof(X[0]);

    int indice = existencia_iguales(X, Y, 0, N - 1);

    if (indice != -1) {
        printf("Índice encontrado: %d\n", indice);
    } else {
        printf("No se encontró ningún índice.\n");
    }

    return 0;

}