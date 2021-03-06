#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define CANT_USUARIOS 100
#define CANT_PROD 1000


int main()
{
    int i;
    eUsuario users[CANT_USUARIOS];
    eProducto productos[CANT_PROD];
    float promedio =0;
    int salir = 0;

    inicializarUsers(users, CANT_USUARIOS);
    inicializarProductos(productos,CANT_PROD);

    //system("pause");
    do
    {

        switch(menu())
        {
        case 1:
            altaUser(users,CANT_USUARIOS);
            system("pause");
            break;
        case 2:

            printf("Modificar datos del usuario\n");
             modificaUsuario(users,CANT_USUARIOS);
            system("pause");
            break;
        case 3:
            printf("Baja del usuario\n");
            bajaUsuario(users,CANT_USUARIOS);
            system("pause");
            break;
        case 4:
            printf("Publicar producto\n");
            publicarProducto(productos,CANT_PROD,users,CANT_USUARIOS);
            system("pause");
            break;
        case 5:
            printf("Modificar publicacion\n");
            modificaPublicacion(productos,CANT_PROD,users,CANT_USUARIOS);

            system("pause");
            break;
            case 6:
                printf("Cancelar publicacion\n");
                cancelarPublic(users,CANT_USUARIOS,productos,CANT_PROD);
                system("pause");
                break;
            case 7:
                printf("Comprar producto\n");
                comprar(users,CANT_USUARIOS,productos,CANT_PROD);
                system("pause");
                break;
            case 8:
                printf("Listar publicaciones del usuario\n");
                mostrarUsuarioDeterminadoYProductos(users,productos,CANT_USUARIOS,CANT_PROD);
                system("pause");
                break;
            case 9:
                printf("Listar publicaciones\n");
                listarProd(productos,CANT_PROD,users,CANT_USUARIOS);
                break;
            case 10:
                printf("Listar usuarios\n");
                mostrarUsuarios(users,CANT_USUARIOS);
                system("pause");
                break;
        case 11:

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

