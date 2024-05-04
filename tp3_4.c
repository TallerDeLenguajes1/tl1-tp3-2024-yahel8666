#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

/* Aquí *TiposProductos es un arreglo de punteros a caracteres, 
donde cada puntero apunta a la primera letra de una cadena de
caracteres (string) */

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct {
    int ProductoID; //nerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct {
    int ClienteID; // nerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos //El tamaño de este arreglo depende de la variable CantidadProductosAPedir". 
} typedef Cliente;

void cargarDatos(Cliente*cliente, int n);
float costoTotal(Producto producto);
void mostrarDatos(Cliente*cliente, int n);
void liberarMemoria(Cliente*cliente, int n);

int main ()
{
    float precioTotal;
    int n; 
    do
    {
        printf("\n Ingrese la cantidad de clientes: "); 
        scanf("%d", &n);
        if (n > 5 || n <= 0)
        {
            printf("\n Cantidad invalida. "); 
        }
    } while (n > 5);

    Cliente *clientes = malloc(sizeof(Cliente)*n);
    cargarDatos(clientes, n); 
    mostrarDatos(clientes, n);
    liberarMemoria(clientes, n);

    return 0; 
}

void cargarDatos(Cliente *cliente, int n)
{
    char aux[MAX]; 
    for (int i = 0; i < n; i++)
    {
        //quiero que empiece en 1. 
        cliente->ClienteID=1+i; 
        printf("\n ---Datos del cliente %d---", i+1);
        printf("\n Ingrese el nombre del cliente:");
        gets(aux);
        cliente->NombreCliente = (char *)malloc(strlen(aux)+1); 
        strcpy(cliente->NombreCliente, aux);
        getchar();
        getchar();

        printf("\n cantidad de productos a pedir: "); 
        fgets(aux, sizeof(aux), stdin);
        sscanf(aux, "%d", &cliente->CantidadProductosAPedir); 
        //limpia el buffer 
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}


        //arreglo dinamico de tipo Producto
        cliente->Productos = (Producto *) malloc(sizeof(Producto)*cliente->CantidadProductosAPedir);
        //cargo este arreglo.
            for (int j = 0; j < cliente->CantidadProductosAPedir; j++)
            {
                cliente->Productos[j].ProductoID=j+1;
                cliente->Productos[j].Cantidad = rand () % 10 + 1; 
                cliente->Productos[j].TipoProducto = TiposProductos[rand()%5];
                cliente->Productos[j].PrecioUnitario = (100+ rand()%900)/10;   
            }
        cliente++;
    } 
}

float costoTotal(Producto producto)
{
    return producto.Cantidad * producto.PrecioUnitario;
}

void mostrarDatos(Cliente*cliente, int n)
{
    float totalPagar;
    for (int i = 0; i < n; i++)
    {
        printf("\n ---Datos del cliente %d---", i+1);
        printf(" \n Nombre: %s ", cliente->NombreCliente);

        printf("\n ID: %d", cliente->ClienteID);
        printf("\n Cantidad de productos a pedir: %d", cliente->CantidadProductosAPedir);

        for (int j = 0; j < cliente->CantidadProductosAPedir; j++)
        {
            printf("\n Producto numero: %d", j+1);    
            printf("\n ID del producto: %d", cliente->Productos[j].ProductoID);
            printf("\n Tipo de producto: %s", cliente->Productos[j].TipoProducto);
            printf("\n Cantidad: %d", cliente->Productos[j].Cantidad);
            printf("\n Precio por unidad: %f", cliente->Productos[j].PrecioUnitario);
            
            totalPagar+=costoTotal(cliente[i].Productos[j]);
        }
        printf("\n Precio a pagar en total: %f", totalPagar);
        cliente++;
    }   
}

void liberarMemoria(Cliente*cliente, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            free(cliente[i].NombreCliente);
            free(cliente[i].Productos);
        }
        free(cliente);
    }
}