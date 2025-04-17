#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>



//PARA CIRCULO, radio L/2
bool dentro_figura(double x, double y, double lado_cuadrado){

  double centro_x = lado_cuadrado/2.0;
  double centro_y = lado_cuadrado/2.0;
  double radio = lado_cuadrado/2.0;
  return (x-centro_x)*(x-centro_x) + (y-centro_y)*(y-centro_y) <= radio * radio;
}



int main(){
  double lado_cuadrado;
  int num_puntos;
  int exitos = 0;


  printf("Introduce longitud lado cuadrado:");
  scanf("%lf", &lado_cuadrado);

  printf("Introduce numero de puntos:");
  scanf("%d", &num_puntos);

  srand(time(NULL));


  for(int i = 0; i < num_puntos; i++){
    double x = (double)rand()/RAND_MAX*lado_cuadrado;
    double y = (double)rand()/RAND_MAX*lado_cuadrado;

    if(dentro_figura(x,y,lado_cuadrado)){exitos++;}
  }

  double proporcion = (double)exitos/(double)num_puntos;


  double area_estimada = proporcion * lado_cuadrado * lado_cuadrado;

  printf("Número de puntos simulados: %d\n", num_puntos);
  printf("Número de puntos dentro de la figura (éxitos): %d\n", exitos);
  printf("Proporción de éxitos: %.6f\n", proporcion);
  printf("Área estimada de la figura: %.6f\n", area_estimada);


  return 0;
  }










