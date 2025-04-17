#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


const char Abecedario[] = {'1', '2', '3', 'A', 'E', 'I', 'O', 'U'};
int longitud = 5;
int vocales_max = 2;

bool es_vocal(char valor){
  if(valor == 'A' || valor == 'E' || valor == 'I' || valor == 'O' || valor == 'U'){
    return true;
  }else{ return false;
    }
}


bool es_valida(char valor, int longitud_actual, int cantidad_vocales){
  if((es_vocal(valor) && cantidad_vocales > vocales_max) || longitud < longitud_actual){
    return false;
  }else{ return true;}
}



void abecedario(char palabra_actual[], int longitud_actual, int cantidad_vocales){


  if(longitud ==  longitud_actual){
    if(cantidad_vocales == vocales_max){
      printf("%s", palabra_actual);
    }
    return;
  }


  //Generar extensiones

  for(int i=0;i<longitud<8;i++){
    char nuevo_caracter = Abecedario[i];
    int nueva_cantidad_vocales = cantidad_vocales;


    //Saber si es vocal.

    if(es_vocal(nuevo_caracter)){
      nueva_cantidad_vocales++;
    }

 // Nueva cantidad de vocales no excede el máximo.
   if(nueva_cantidad_vocales <= vocales_max){
     palabra_actual[longitud_actual] = nuevo_caracter;
     palabra_actual[longitud_actual+1] = '\0';

     abecedario(palabra_actual, longitud_actual+1, cantidad_vocales);
   }





  }

}






int main(){


  return 0;
}


