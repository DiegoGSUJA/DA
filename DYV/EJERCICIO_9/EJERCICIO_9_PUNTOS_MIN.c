#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Posicion {
    double x;
    double y;
} Posicion;

double distancia_euclidea(Posicion p1, Posicion p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int comparar_posiciones_x(const void* a, const void* b) {
    Posicion* p1 = (Posicion*)a;
    Posicion* p2 = (Posicion*)b;
    return (p1->x > p2->x) - (p1->x < p2->x);
}

int comparar_posiciones_y(const void* a, const void* b) {
    Posicion* p1 = (Posicion*)a;
    Posicion* p2 = (Posicion*)b;
    return (p1->y > p2->y) - (p1->y < p2->y);
}

double distancia_min_recursiva(Posicion puntos[], int inicio, int fin) {
    if (fin - inicio <= 3) {
        double min_distancia = DBL_MAX;
        for (int i = inicio; i < fin; i++) {
            for (int j = i + 1; j <= fin; j++) {
                double dist = distancia_euclidea(puntos[i], puntos[j]);
                if (dist < min_distancia) {
                    min_distancia = dist;
                }
            }
        }
        return min_distancia;
    }

    int medio = (inicio + fin) / 2;
    double distancia_izquierda = distancia_min_recursiva(puntos, inicio, medio);
    double distancia_derecha = distancia_min_recursiva(puntos, medio + 1, fin);
    double distancia_minima = fmin(distancia_izquierda, distancia_derecha);

    Posicion franja[fin - inicio + 1];
    int franja_tam = 0;

    for (int i = inicio; i <= fin; i++) {
        if (fabs(puntos[i].x - puntos[medio].x) < distancia_minima) { // Corrección aquí
            franja[franja_tam++] = puntos[i];
        }
    }

    qsort(franja, franja_tam, sizeof(Posicion), comparar_posiciones_y);

    for (int i = 0; i < franja_tam; i++) {
        for (int j = i + 1; j < franja_tam && franja[j].y - franja[i].y < distancia_minima; j++) {
            double dist = distancia_euclidea(franja[i], franja[j]);
            if (dist < distancia_minima) {
                distancia_minima = dist;
            }
        }
    }

    return distancia_minima;
}

double encontrar_par_mas_cercano(Posicion puntos[], int tam) {
    qsort(puntos, tam, sizeof(Posicion), comparar_posiciones_x);
    return distancia_min_recursiva(puntos, 0, tam - 1);
}

int main() {
    Posicion puntos[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int tam = sizeof(puntos) / sizeof(puntos[0]);

    double distancia_minima = encontrar_par_mas_cercano(puntos, tam);
    printf("La distancia mínima entre el par de puntos es: %lf\n", distancia_minima);

    return 0;
}