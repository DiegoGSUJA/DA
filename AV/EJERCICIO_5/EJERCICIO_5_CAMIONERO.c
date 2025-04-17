#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Vamos
 *
 */

int camionero(int distancias[], int num_distancias, int rango) {
 int paradas = 0;
 int gasolina_actual = rango;

 for(int i = 0; i < num_distancias; i++) {
  if(gasolina_actual - distancias[i] < 0 ) {
   paradas = paradas + 1;
   gasolina_actual = rango;
  }
  gasolina_actual = gasolina_actual - distancias[i];

 }
 return paradas;
}





int main() {
 int distancias[] = {100, 150, 120, 80, 250, 130};
 int num_distancias = sizeof(distancias) / sizeof(distancias[0]);
 int rango = 200;

 int paradas = camionero(distancias, num_distancias, rango);
 printf("El camionero reposta %d veces.\n", paradas);

 return 0;
}