#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const int Monedas[] = {200, 100, 50, 20, 10, 5, 2, 1}; // Ordenar para intentar usar monedas grandes primero
int n_monedas = 8;
int min_monedas = -1; // Inicializar el mínimo a -1 (o un valor grande)

void encontrar_cambio(int cantidad_restante, int indice_moneda, int num_monedas_usadas) {
  if (cantidad_restante == 0) {
    if (min_monedas == -1 || num_monedas_usadas < min_monedas) {
      min_monedas = num_monedas_usadas;
    }
    return;
  }

  if (min_monedas != -1 && num_monedas_usadas >= min_monedas) {
    return; // Poda: ya usamos demasiadas monedas
  }

  for (int i = indice_moneda; i < n_monedas; i++) {
    int valor_moneda = Monedas[i];
    if (cantidad_restante >= valor_moneda) {
      encontrar_cambio(cantidad_restante - valor_moneda, i, num_monedas_usadas + 1);
    }
  }
}

int main() {
  int cantidad_a_devolver;
  printf("Introduce la cantidad a devolver: ");
  scanf("%d", &cantidad_a_devolver);

  encontrar_cambio(cantidad_a_devolver, 0, 0);

  if (min_monedas != -1) {
    printf("El número mínimo de monedas es: %d\n", min_monedas);
  } else {
    printf("No se encontró cambio.\n");
  }

  return 0;
}