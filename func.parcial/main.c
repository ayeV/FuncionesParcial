#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define CANT 5


int main()
{
    int i;
    eEmpleado gente[CANT];
    eSector sectores[5];
    int salir = 0;

    inicializarEmpleados(gente, CANT);
     hardCode(sectores);
     for(i=0; i<5; i++){
        printf("%d - %s - %d\n", sectores[i].id, sectores[i].descripcion, sectores[i].isEmpty);
    }
    system("pause");
    do
    {

        switch(menu())
        {
        case 1:
            altaEmpleado(gente,CANT);
            system("pause");
            break;
        case 2:

            printf("Baja\n");
             baja(gente,CANT);
            system("pause");
            break;
        case 3:
            printf("Modificar\n");
            modificaEmpleado(gente,CANT);
            system("pause");
            break;
        case 4:
            printf("Listar\n");
            listarEmpPorSector(gente,CANT,sectores);
         //  mostrarEmpleados(gente,CANT,sectores);
            system("pause");
            break;
        case 5:
            printf("Ordenar\n");
            ordenarEmpleados(gente,CANT);
            mostrarEmpleados(gente,CANT,sectores);

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

