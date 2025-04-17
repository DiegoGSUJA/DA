#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h> // Añadimos la librería para medir el tiempo

#define MAX_CIFRAS 10 // Límite máximo de cifras

// Función para verificar si la suma de pares e impares es igual al final
bool verificar_suma_final(int digitos[], int n) {
    int suma_pares = 0;
    int suma_impares = 0;
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0) {
            suma_pares += digitos[i];
        } else {
            suma_impares += digitos[i];
        }
    }
    return suma_pares == suma_impares;
}

// Función de Vuelta Atrás para encontrar los números
void encontrar_numeros_va(int n, int posicion, int digitos_actuales[], int* resultados, int* contador_resultados, int suma_parcial_pares, int suma_parcial_impares) {
    if (posicion == n) {
        if (verificar_suma_final(digitos_actuales, n)) {
            int numero = 0;
            int potencia = 1;
            for (int i = n - 1; i >= 0; i--) {
                numero += digitos_actuales[i] * potencia;
                potencia *= 10;
            }
            resultados[*contador_resultados] = numero;
            (*contador_resultados)++;
        }
        return;
    }

    for (int digito = 1; digito <= 5; digito++) {
        digitos_actuales[posicion] = digito;
        int nueva_suma_pares = suma_parcial_pares;
        int nueva_suma_impares = suma_parcial_impares;

        if ((posicion + 1) % 2 == 0) {
            nueva_suma_pares += digito;
        } else {
            nueva_suma_impares += digito;
        }

        // Función de factibilidad (podría ser más elaborada)
        // Aquí, simplemente continuamos si todavía podemos construir un número válido
        // Una mejora sería verificar si la diferencia entre las sumas parciales
        // es demasiado grande para ser compensada por los dígitos restantes.
        encontrar_numeros_va(n, posicion + 1, digitos_actuales, resultados, contador_resultados, nueva_suma_pares, nueva_suma_impares);
    }
}

int main() {
    int n;
    clock_t inicio, fin; // Variables para almacenar los tiempos
    double tiempo_ejecucion;

    printf("Introduce el número de cifras (n): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_CIFRAS) {
        printf("Por favor, introduce un valor de n entre 1 y %d.\n", MAX_CIFRAS);
        return 1;
    }

    int max_resultados = (int)pow(5, n);
    int resultados[max_resultados];
    int contador_resultados = 0;
    int digitos[MAX_CIFRAS];

    printf("Números de %d cifras que cumplen la condición (Vuelta Atrás):\n", n);

    inicio = clock(); // Marca el tiempo de inicio
    encontrar_numeros_va(n, 0, digitos, resultados, &contador_resultados, 0, 0);
    fin = clock(); // Marca el tiempo de finalización

    tiempo_ejecucion = (double)(fin - inicio) / CLOCKS_PER_SEC; // Calcula el tiempo en segundos

    if (contador_resultados > 0) {
        for (int i = 0; i < contador_resultados; i++) {
            printf("%d\n", resultados[i]);
        }
    } else {
        printf("No se encontraron números que cumplan la condición para n = %d.\n", n);
    }

    printf("Tiempo de ejecución: %.4f segundos\n", tiempo_ejecucion); // Muestra el tiempo de ejecución

    return 0;
}