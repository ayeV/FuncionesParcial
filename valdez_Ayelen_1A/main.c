#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "input.h"
#define CANT_PROD 100
#define CANT_PROV 5


int main()
{
    int i;
    eProveedor proveedores[CANT_PROV];
    eProducto productos[CANT_PROD];

    int salir = 0;


    inicializarProductos(productos,CANT_PROD);
    hardCode(proveedores);
    for(i=0; i<5; i++)
    {
        printf("%d - %s - %d\n", proveedores[i].idProveedor, proveedores[i].descripcion, proveedores[i].isEmpty);
    }
    system("pause");


    do
    {

        switch(menu())
        {
        case 1:
            printf("Alta del producto\n");
            altaProd(productos,CANT_PROD,proveedores,CANT_PROV);

            system("pause");
            break;
        case 2:
            printf("Modificar\n");
            modificaProd(productos,CANT_PROD,proveedores,CANT_PROV);

            system("pause");
            break;
        case 3:
            printf("Baja del prod\n");
            bajaProd(proveedores,CANT_PROV,productos,CANT_PROD);
            system("pause");
            break;
        case 4:
            informar(productos,CANT_PROD);

            system("pause");
            break;
        case 5:
            listar(productos,CANT_PROD,proveedores,CANT_PROV);
            system("pause");
            break;

        case 6:

            printf("Salir\n");
            salir = 1;
            break;
        default:
            printf("Opcion incorrecta\n");
            system("pause");
        }



    }
    while(salir != 1);







    return 0;
}

