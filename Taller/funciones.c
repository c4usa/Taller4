#include <stdio.h>
#include <string.h>

char nombres[100][30];
float precios[100];
int stocks[100];
int ids[100];
int cantidadProductos = 0;

int validar(int minimo, int maximo)
{
    int valor;
    char c;
    while (1)
    {
        if (scanf("%d%c", &valor, &c) != 2 || c != '\n' || valor < minimo || valor > maximo)
        {
            printf("Entrada inválida. Intente nuevamente: ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            return valor;
        }
    }
}

float comprobar()
{
    float numero;
    char c;
    while (1)
    {
        if (scanf("%f%c", &numero, &c) != 2 || c != '\n' || numero < 0)
        {
            printf("Entrada inválida. Intente nuevamente: ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            return numero;
        }
    }
}

void ingresarProducto()
{
    int cantidad;

    printf("Ingrese la cantidad de productos que desea ingresar: ");
    cantidad = validar(1, 10);
    if (cantidadProductos + cantidad > 100)
    {
        printf("No hay espacio suficiente para %d productos. Puede ingresar hasta %d más.\n", cantidad, 100 - cantidadProductos);
        return;
    }
    for (int i = 0; i < cantidad; i++)
    {
        printf("\nProducto #%d:\n", i + 1);
        printf("Ingrese el nombre del producto: ");
        scanf("%29s", nombres[cantidadProductos]);
        printf("Ingrese el precio del producto: ");
        precios[cantidadProductos] = comprobar();
        cantidadProductos++;
    }
    printf("\nProductos ingresados correctamente.\n");
}

void mostrarProductos()
{
    if (cantidadProductos == 0)
    {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("\n\t\t\t%-30s%-10s\n", "NOMBRE", "PRECIO");
    printf("\t\t\t---------------------------------------------\n");

    for (int i = 0; i < cantidadProductos; i++)
    {
        printf("\t\t\t%-30s$%.2f\n", nombres[i], precios[i]);
    }
}

void mostrarMaxMin()
{
    if (cantidadProductos == 0)
        return;

    int max = 0, min = 0;
    for (int i = 1; i < cantidadProductos; i++)
    {
        if (precios[i] > precios[max])
            max = i;
        if (precios[i] < precios[min])
            min = i;
    }

    printf("Producto más caro: %s ($%.2f)\n", nombres[max], precios[max]);
    printf("Producto más barato: %s ($%.2f)\n", nombres[min], precios[min]);
}

void mostrarPromedio()
{
    if (cantidadProductos == 0)
        return;

    float suma = 0;
    for (int i = 0; i < cantidadProductos; i++)
    {
        suma += precios[i];
    }

    printf("Precio promedio: $%.2f\n", suma / cantidadProductos);
}

void buscarProducto()
{
    char buscado[30];
    int encontrado = 0;

    printf("Ingrese el nombre del producto a buscar: ");
    scanf("%29s", buscado);

    for (int i = 0; i < cantidadProductos; i++)
    {
        if (strcmp(nombres[i], buscado) == 0)
        {
            printf("Producto encontrado: %s - Precio: $%.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Producto no encontrado.\n");
    }
}
