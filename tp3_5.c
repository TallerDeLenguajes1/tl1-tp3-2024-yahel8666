#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int main ()
{
    char**cadena; //puntero a: puntero a char 
    char *buff; //puntero a char  
    char *nombre; 
    int cantNombres; 

    printf("\n Ingrese la cantidad de nombres que desea escribir: "); 
    scanf("%d", &cantNombres); 
    cadena = (char **)malloc(sizeof(char *) *cantNombres);  

    for (int i = 0; i < cantNombres; i++)
    {
        buff = (char*)malloc(sizeof(char)*MAX);
        printf(" \n Ingrese un nombre: ");
        nombre = (char*)malloc( (strlen(buff)+1) * sizeof(char)); 
        strcpy(nombre, buff); //copio lo que estaba en buff a nombre. 
        cadena[i] = nombre; 
    }

    printf("\tNombres:\n");
    for (int i = 0; i < cantNombres; i++) {
        printf("%s\n", cadena[i]); // Imprime los nombres
    }

    
    //libero primero cada uno de los nombres.
    for (int i = 0; i < cantNombres; i++)
    {
        free(cadena[i]);
    }
 
    for (int i = 0; i < cantNombres; i++)
    {
        free(cadena); 
    }
    return 0; 
}