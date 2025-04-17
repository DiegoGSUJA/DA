#include <stdio.h>
#include <stdlib.h> // Para poder usar malloc y free si la longitud de A es dinámica
#include <stdbool.h>

#define MAX_N 100 // Un tamaño máximo por defecto, pero podríamos hacerlo dinámico

int *A; // Puntero al conjunto de números enteros (para tamaño dinámico)
int n; // Número de elementos en A
int m; // Tamaño exacto del subconjunto buscado
int C; // Suma objetivo
int solucion_parcial[MAX_N]; // Almacena el subconjunto parcial actual
int contador_elementos = 0; // Cuenta los elementos en el subconjunto parcial
int suma_actual = 0; // Suma de los elementos en el subconjunto parcial

// Función para imprimir una solución encontrada
void imprimir_solucion() {
  printf("{ ");
  for (int i = 0; i < m; i++) {
    printf("%d ", solucion_parcial[i]);
  }
  printf("}\n");
}

// Función para verificar si la inclusión de un valor es prometedora
bool es_valida(int suma_parcial_actual, int valor_a_añadir, int C) {
  if (suma_parcial_actual + valor_a_añadir > C) {
    return false;
  }
  return true;
}

// Función recursiva de Vuelta Atrás
void encontrar_subconjuntos(int indice_actual) {
  if (contador_elementos == m) {
    if (suma_actual == C) {
      imprimir_solucion();
    }
    return;
  }

  if (contador_elementos > m || suma_actual > C) {
    return;
  }

  for (int i = indice_actual; i < n; i++) {
    if (es_valida(suma_actual, A[i], C)) {
      solucion_parcial[contador_elementos] = A[i];
      contador_elementos++;
      suma_actual += A[i];

      encontrar_subconjuntos(i + 1);

      suma_actual -= A[i];
      contador_elementos--;
    }
  }
}

// Función para inicializar el proceso
void inicializar_busqueda(int conjunto[], int tam_conjunto, int tam_subconjunto, int suma_objetivo) {
  A = conjunto;
  n = tam_conjunto;
  m = tam_subconjunto;
  C = suma_objetivo;
  contador_elementos = 0;
  suma_actual = 0;
  encontrar_subconjuntos(0);
}

int main() {
  printf("Introduce el número de elementos del conjunto A (n): ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Error: Por favor, introduce un número válido de elementos.\n");
    return 1;
  }

  // Si quieres manejar un tamaño dinámico para A:
  A = (int *) malloc(n * sizeof(int));
  if (A == NULL) {
    printf("Error: No se pudo asignar memoria para el conjunto A.\n");
    return 1;
  }

  printf("Introduce los %d elementos del conjunto A separados por espacios:\n", n);
  for (int i = 0; i < n; i++) {
    if (scanf("%d", &A[i]) != 1) {
      printf("Error: Por favor, introduce números enteros válidos.\n");
      free(A);
      return 1;
    }
  }

  printf("Introduce el tamaño exacto del subconjunto a buscar (m): ");
  if (scanf("%d", &m) != 1 || m < 0 || m > n) {
    printf("Error: Por favor, introduce un tamaño de subconjunto válido (0 <= m <= n).\n");
    free(A);
    return 1;
  }

  printf("Introduce la suma objetivo (C): ");
  if (scanf("%d", &C) != 1) {
    printf("Error: Por favor, introduce un valor entero para la suma objetivo.\n");
    free(A);
    return 1;
  }

  inicializar_busqueda(A, n, m, C);

  if (A != NULL) {
    free(A); // Liberar la memoria si se asignó dinámicamente
  }

  return 0;
}
