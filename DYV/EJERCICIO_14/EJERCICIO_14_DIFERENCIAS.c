#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comparar_enteros(const void *a, const void *b) {
 return (*(int *)a - *(int *)b);
}

int diferencia_minima(int V[], int tam) {
 qsort(V, tam, sizeof(int), comparar_enteros);

 int dif_minima = abs(V[1] - V[0]);

 for (int i = 2; i < tam; i++) {
  int dif_actual = abs(V[i] - V[i - 1]);
  if (dif_actual < dif_minima) {
   dif_minima = dif_actual;
  }
 }

 return dif_minima;
}

int main() {
 int V[] = {17, 10, 14, 37, 24, 1, 8, 5};
 int tam = sizeof(V) / sizeof(V[0]);

 int resultado = diferencia_minima(V, tam);

 printf("La diferencia mínima es: %d\n", resultado);

 return 0;
}