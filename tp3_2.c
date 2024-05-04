#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FILAS 5
#define COLUMNAS 12


void cargarMatriz(int matriz[FILAS][COLUMNAS]);
void mostrarMatriz(int matriz[FILAS][COLUMNAS]);
void calcularPromedioGanancia(int matriz[FILAS][COLUMNAS]);
void encontrarMaximoYMinimo(int matriz[FILAS][COLUMNAS]);

int main() {
    srand(time(NULL));
    int mt[FILAS][COLUMNAS];
    cargarMatriz(mt);
    mostrarMatriz(mt);
    printf("\nPromedio de ganancia por año:");
    calcularPromedioGanancia(mt);
    printf("\nGanancia máxima y mínima:");
    encontrarMaximoYMinimo(mt);
    return 0;
}

void cargarMatriz(int matriz[FILAS][COLUMNAS])
{
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = rand() % (90000 - 10000 + 1) + 10000;
        }
    }
}

void mostrarMatriz(int matriz[FILAS][COLUMNAS]) 
{
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%8d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void calcularPromedioGanancia(int matriz[FILAS][COLUMNAS]) 
{
    for (int i = 0; i < FILAS; i++) {
        int suma = 0;
        for (int j = 0; j < COLUMNAS; j++) {
            suma += matriz[i][j];
        }
        printf("Año %d: %.2f", i + 1, (float)suma /COLUMNAS);
    }
}

void encontrarMaximoYMinimo(int matriz[FILAS][COLUMNAS]) {
    int maximo = 10000 - 1;
    int minimo = 90000+ 1;
    int anioMaximo, mesMaximo, anioMinimo, mesMinimo;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] > maximo) {
                maximo = matriz[i][j];
                anioMaximo = i + 1;
                mesMaximo = j + 1;
            }
            if (matriz[i][j] < minimo) {
                minimo = matriz[i][j];
                anioMinimo = i + 1;
                mesMinimo = j + 1;
            }
        }
    }

    printf("Ganancia máxima: %d (Año %d, Mes %d)", maximo, anioMaximo, mesMaximo);
    printf("Ganancia mínima: %d (Año %d, Mes %d)", minimo, anioMinimo, mesMinimo);
}
