#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main()
{
    int opcion;
    do
    {
        printf("\nMenú de Opciones:\n");
        printf("\t1. Ingresar producto\n");
        printf("\t2. Calcular precio total del inventario\n");
        printf("\t3. Mostrar producto más caro y más barato\n");
        printf("\t4. Mostrar precio promedio\n");
        printf("\t5. Buscar producto por nombre\n");
        printf("\t6. Salir\n");
        printf("Seleccione una opción: ");

        opcion = validar(1, 6);

        switch (opcion)
        {
        case 1:
            ingresarProducto();
            break;
        case 2:
            mostrarPrecioTotal();
            break;
        case 3:
            mostrarMaxMin();
            break;
        case 4:
            mostrarPromedio();
            break;
        case 5:
            buscarProducto();
            break;
        case 6:
            printf("Saliendo del programa...\n");
            break;
        }
    } while (opcion != 6);

    return 0;
}
