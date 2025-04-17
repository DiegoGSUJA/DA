#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



int laberinto[6][6] = {{3,0,0,0,0,0},
                       {0,0,1,1,0,0},
                       {0,0,1,1,0,0},
                       {0,0,1,0,0,0},
                       {0,1,1,0,1,0},
                       {0,0,0,4,0,0}};


bool es_valida(int f, int c, int laberinto[][6], int num_filas=6, int num_columnas=6, int pasos_actuales, int pasos_minimos) {

    //limites

    if (f < 0 || f >= num_filas || c < 0 || c >= num_columnas) {
        return false;
    }

    //Obstaculo

    if (laberinto[f][c] == 1) return false;

    //Visitada

    if (laberinto[f][c] == 2) return false;

    if (pasos_minimos != -1 && pasos_actuales>= pasos_minimos) {
        return false;
    }

    return true;
}



bool encontrar_camino(int fila, int columna, int laberinto[][6], int num_filas, int num_columnas, int pasos_actuales, int *pasos_minimos) {
    if (laberinto[fila][columna] == 4) {
        if (*pasos_minimos == -1 || pasos_actuales < *pasos_minimos) {
            *pasos_minimos = pasos_actuales;
        }
        return true;
    }


    laberinto[fila][columna] = 2;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};


    for (int i=0;i<4;i++) {
        int nueva_fila = fila + dr[i];
        int nuevac_columna = columna + dc[i];

        if (es_valida(nueva_fila,nuevac_columna,laberinto,num_filas,num_columnas,pasos_actuales+1,*pasos_minimos)) {
            if (encontrar_camino(nueva_fila,nuevac_columna,laberinto,num_filas,nuevac_columna,pasos_actuales+1,pasos_minimos)) {

            }
        }
    }

    laberinto[fila][columna] = 0;


    return false;

}

int main() {
    int laberinto[6][6] = {
        {3, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0},
        {0, 0, 0, 4, 0, 0}
    };
    int num_filas = 6;
    int num_columnas = 6;
    int inicio_fila, inicio_columna;
    int pasos_minimos = -1;

    // Encontrar la posición de inicio
    for (int i = 0; i < num_filas; i++) {
        for (int j = 0; j < num_columnas; j++) {
            if (laberinto[i][j] == 3) {
                inicio_fila = i;
                inicio_columna = j;
                break;
            }
        }
    }

    encontrar_camino(inicio_fila, inicio_columna, laberinto, num_filas, num_columnas, 0, &pasos_minimos);

    if (pasos_minimos != -1) {
        printf("La longitud del camino más corto es: %d\n", pasos_minimos);
    } else {
        printf("No se encontró un camino a la salida.\n");
    }

    return 0;
}
