#include <stdio.h>
#include <string.h>

char nombres[100][30];
float precios[100];
int stocks[100];
int ids[100];
int cantidadProductos = 0;

int validar(int minimo, int maximo)
{
    char linea[100];
    int valor;
    char extra;
    while (1)
    {
        if (fgets(linea, 100 , stdin) == NULL)
        {
            printf("Error de entrada. Intente nuevamente: ");
            continue;
        }
        if (sscanf(linea, "%d %c", &valor, &extra) != 1 || valor < minimo || valor > maximo)
        {
            printf("Entrada invalida. Intente nuevamente: ");
        }
        else
        {
            return valor;
        }
    }
}

float comprobar()
{
    char linea[100];
    float numero;
    char extra;
    while (1)
    {
        if (fgets(linea,100, stdin) ==NULL)
        {
            printf("Error de entrada. Intente nuevamente: ");
            continue;
        }
        if (sscanf(linea, "%f %c", &numero, &extra) != 1 || numero < 0)
        {
            printf("Entrada invalida. Intente nuevamente: ");
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
        printf("No hay espacio suficiente para %d productos. Puede ingresar hasta %d mas.\n", cantidad, 100 - cantidadProductos);
        return;
    }
    for (int i = 0; i < cantidad; i++)
    {
        char nombreTemporal[30];
        int nombreRepetido;
        do {
            nombreRepetido = 0;
            printf("\nProducto #%d:\n", i + 1);
            printf("Ingrese el nombre del producto: ");
            fgets(nombreTemporal, 30, stdin);
            for (int j = 0; nombreTemporal[j] != '\0'; j++)
            {
                if (nombreTemporal[j] == '\n')
                {
                    nombreTemporal[j] = '\0';
                    break;
                }
            }
            for (int k = 0; k < cantidadProductos; k++)
            {
                if (strcmp(nombreTemporal, nombres[k]) == 0)
                {
                    printf("Ese nombre ya existe. Ingrese un nombre diferente.\n");
                    nombreRepetido = 1;
                    break;
                }
            }
        } while (nombreRepetido);
        strcpy(nombres[cantidadProductos], nombreTemporal);
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
    printf("\nNOMBRE\t\t\tPRECIO\n");
    printf("---------------------------------------------\n");
    for (int i = 0; i < cantidadProductos; i++)
    {
        printf("%s\t\t\t%.2f\n", nombres[i], precios[i]);
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
    printf("Producto mas caro: %s ($%.2f)\n", nombres[max], precios[max]);
    printf("Producto mas barato: %s ($%.2f)\n", nombres[min], precios[min]);
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
    scanf("%s", buscado);
    for (int i = 0; i < cantidadProductos; i++)
    {
        if (strcmp(nombres[i], buscado) == 0)
        {
            printf("Producto encontrado: %s ---Precio: $%.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
    {
        printf("Producto no encontrado.\n");
    }
}
