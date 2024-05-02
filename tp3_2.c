#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int main ()
{
    char**cadena; //puntero a: puntero a char 
    char buff[100]; 
    char *nombre; 

    /* usando reserva dinamica de memoria, reservo 5 
    punteros a caracteres. */
    cadena = (char **)malloc(sizeof(char *)*5);   

    for (int i = 0; i < 5; i++)
    {
        printf(" \n Ingrese un nombre: ");
        fgets(buff, MAX, stdin); 
        nombre = (char *)malloc((strlen(buff)+1) ); 
        strcpy(nombre, buff);
        cadena[i] = nombre; 
    }

    printf("\tNombres:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", cadena[i]); // Imprime los nombres
    }

    //libero primero cada uno de los nombres.
    for (int i = 0; i < 5; i++)
    {
        free(cadena[i]);
    }

    //libero los 5 punteros a los que apuntaba 
    for (int i = 0; i < 5; i++)
    {
        free(cadena); 
    }
    return 0; 
}