#include <stdio.h>
#include <stdlib.h>


int suma_filtrada_calculo(int M[],int n, int mayor, int menor) {
    int acumulador = 0;
    for(int i=0;i<n;i++) {
        if(M[i]!=mayor && M[i]!= menor) {
            acumulador += M[i];
        }
    }
    return acumulador;
}

void busquedad_menor_mayor(int M[],int n, int *mayor, int *menor) {
    if(n==0) {
        return;
    }
    *mayor = M[0];
    *menor = M[0];
    for(int i=1;i<n;i++) {
        if(M[i]>*mayor) {
            *mayor=M[i];
        }
        if(M[i]<*menor) {
            *menor=M[i];
        }
    }
}

int suma_filtrada(int T[], int n) {
    if (n <= 2) {
        return 0; // Caso base: no hay elementos para sumar
    }

    int mitad = n / 2;
    int *U = (int *)malloc(mitad * sizeof(int));
    int *V = (int *)malloc((n - mitad) * sizeof(int));

    for (int i = 0; i < mitad; i++) {
        U[i] = T[i];
    }

    for (int i = mitad; i < n; i++) {
        V[i - mitad] = T[i];
    }

    // Llamadas recursivas para calcular la suma filtrada de los sub-arrays
    int resultado_izq = suma_filtrada(U, mitad);
    int resultado_der = suma_filtrada(V, n - mitad);

    int mayor_izq, menor_izq, mayor_der, menor_der;
    busquedad_menor_mayor(U, mitad, &mayor_izq, &menor_izq);
    busquedad_menor_mayor(V, n - mitad, &mayor_der, &menor_der);

    free(U);
    free(V);

    // Lógica para combinar resultados (esto es complejo y podría no ser eficiente)
    int mayor, menor;
    mayor = (mayor_izq > mayor_der) ? mayor_izq : mayor_der;
    menor = (menor_izq < menor_der) ? menor_izq : menor_der;

    // Calcular la suma filtrada del array original usando el mayor y el menor global
    return suma_filtrada_calculo(T, n, mayor, menor);
}









int main() {
    int T[] = {4, 1, 8, 7, 2, 6, 9, 3};
    int resultado = suma_filtrada(T, sizeof(T) / sizeof(T[0]));
    printf("Suma filtrada: %d\n", resultado);
    return 0;
}