#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "input.h"

int menu()
{
    int opcion;
    system("cls");

    printf("1.Alta producto\n");
    printf("2.Modificar producto\n");
    printf("3.Baja del producto\n");
    printf("4.Informar\n");
    printf("5.Listar\n");

    printf("6.Salir\n");
    scanf("%d", &opcion);

    return opcion;
}
void hardCode(eProveedor proveedores[])
{
    eProveedor nuevoProveedor;

    nuevoProveedor.idProveedor = 1;
    strcpy(nuevoProveedor.descripcion, "ProveedorUno");
    nuevoProveedor.isEmpty = 0;
    proveedores[0] = nuevoProveedor;


    nuevoProveedor.idProveedor = 2;
    strcpy(nuevoProveedor.descripcion, "ProveedorDos");
    nuevoProveedor.isEmpty = 0;
    proveedores[1] = nuevoProveedor;

    nuevoProveedor.idProveedor = 3;
    strcpy(nuevoProveedor.descripcion, "ProveedorTres");
    nuevoProveedor.isEmpty = 0;
    proveedores[2] = nuevoProveedor;

    nuevoProveedor.idProveedor = 4;
    strcpy(nuevoProveedor.descripcion, "ProveedorCuatro");
    nuevoProveedor.isEmpty = 0;
    proveedores[3] = nuevoProveedor;

    nuevoProveedor.idProveedor = 5;
    strcpy(nuevoProveedor.descripcion, "ProveedorCinco");
    nuevoProveedor.isEmpty = 0;

    proveedores[4] = nuevoProveedor;

}

void inicializarProductos(eProducto prod[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        prod[i].isEmpty = 1;

    }
}
int buscarLibreProd(eProducto prod[],int tam)
{

    int i;
    int indice = -1;
    for(i=0; i<tam; i++)
    {
        if(prod[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


void altaProd(eProducto producto[],int tamProd, eProveedor prov[],int tamProv)
{

    eProducto nuevoProducto;
    int idProducto;
    int idProv;
    int indice2;

    system("cls");
    getInt(&idProv,"Ingrese ID de proveedor: ", "Error, ID debe esta entre 1 y 5",1,5);

    indice2 = buscarLibreProd(producto,tamProd);


    if(indice2 == -1)
    {
        printf("El sistema no admite mas productos\n");
    }
    else
    {
        idProducto = indice2 + 1;
        nuevoProducto.isEmpty = 0;
        nuevoProducto.idProd =idProducto;
        nuevoProducto.idProveedor = idProv;
        printf("---Datos del producto---\n");

        getString(nuevoProducto.descripcion,"Descripcion: ","Rango valido [2-50]: ",2,50);
        getFloat(&nuevoProducto.importe,"Precio: ","Rango valido [0-10000]: ",1,10000);
        getInt(&nuevoProducto.stock, "Stock: ","Rango valido [1-100]: ",1,1000);

        producto[indice2] = nuevoProducto;

        printf("Publicacion exitosa\n");
    }
}




void mostrarProveedorYProductos(eProveedor prov[],eProducto prod[], int tamProv, int tamProd)
{
    int i,j;
    system("cls");
    for(i=0; i<tamProv; i++)
    {

        for(j=0; j<tamProd; j++)
        {
            if(prov[i].isEmpty == 0 && prov[i].idProveedor == prod[j].idProveedor && prod[j].isEmpty == 0)
            {
                printf("Publicaciones del proveedor %s\n",prov[i].descripcion);
                printf("ID Prod\t\tNombre\t\tPrecio\t\tStock\n");
                printf("%d\t\t%s\t\t%.2f\t\t%d\n",prod[j].idProd,prod[j].descripcion,prod[j].importe,prod[j].stock);
            }
        }
    }


}
void mostrarProveedorDeterminadoYProductos(eProveedor prov[],eProducto prod[], int tamProv, int tamProd)
{
    int i,j;
    int idProv;
    int esta;

    getInt(&idProv,"Ingrese ID de proveedor: ","ID debe estar  entre 1 y 5: ",1,5);

    esta = buscarProv(prov, tamProv, idProv);

    if(esta == -1)
    {
        printf("\nEl ID %d no se encuentra en el sistema\n\n", idProv);

    }
    else
    {
        system("cls");

        printf("Publicaciones del proveedor %s\n",prov[esta].descripcion);
        printf("ID Prod\t\tNombre\t\tPrecio\t\tStock\n");
        for(i=0; i<tamProd; i++)

        {
            for(j=0; j<tamProv; j++)
            {
                if(prod[i].isEmpty == 0 && prov[j].idProveedor == prod[i].idProveedor && prov[j].isEmpty == 0 && prov[j].idProveedor == idProv)
                {



                    printf("%d\t\t%s\t\t%.2f\t\t%d\n0",prod[i].idProd, prod[i].descripcion, prod[i].importe,prod[i].stock);




                }
            }
        }
    }

}







int buscarProd(eProducto prod[],int tam, int id)
{
    int i;
    int indice = -1;
    for(i=0; i<tam; i++)
    {
        if(prod[i].isEmpty == 0 && prod[i].idProd == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarProv(eProveedor prov[],int tam, int id)
{
    int i;
    int indice = -1;
    for(i=0; i<tam; i++)
    {
        if(prov[i].isEmpty == 0 && prov[i].idProveedor == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void bajaProd(eProveedor prov[], int tamProv, eProducto prod[], int tamProd)
{

    int idProv;
    int idProd;
    char opc;
    int esta1;
    int esta2;

    system("cls");
    getInt(&idProv,"Ingrese ID de Proveedor: ","ID debe estar entre 1 y 5: ",1,5);
    esta1 = buscarProv(prov, tamProv, idProv);
    if(esta1 == -1)
    {
        printf("ID de proveedor inexistente");
    }
    else
    {
        mostrarProveedorYProductos(prov,prod,tamProv,tamProd);
        getInt(&idProd, "Ingrese ID del prod: ","ID debe ser mayor a 0: ",1,100);

        esta2 = buscarProd(prod, tamProd,idProd);
        if(esta2 != -1 )
        {
            mostrarProd(prod[esta2]);


            do
            {
                printf("Confirma la baja? S/N\n");
                fflush(stdin);
                scanf("%c", &opc);
                opc = tolower(opc);
            }
            while(opc != 's' && opc != 'n');
            if(opc == 's')
            {
                prod[esta2].isEmpty = 1;
                printf("Baja exitosa\n");
                mostrarProveedorYProductos(prov,prod,tamProv,tamProd);
            }
            else
            {
                printf("Se ha cancelado la baja\n");

            }
        }
        else
        {
            printf("ID de prod inexistente\n");
        }
    }


}


void mostrarProd(eProducto prod)
{
    printf("%d\t%d\t%s\t\t%.2f\t%d\n",prod.idProd,prod.idProveedor,prod.descripcion,prod.importe,prod.stock);

}
void mostrarProds(eProducto vec[], int tam)
{
    int i;
    printf("ID\tIdProv\tDescripcion\t\tImporte\tStock\n\n");
    for(i=0; i<tam; i++)
    {

        if(vec[i].isEmpty == 0)
        {
            mostrarProd(vec[i]);
        }

    }
}


int menuModificaProd()
{
    int opcion;

    system("cls");
    printf("---Modificar Producto---\n\n");
    printf("1-Descripcion\n");
    printf("2-Importe\n");
    printf("3-Stock\n");
    printf("4-Salir\n");
    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void modificaProd(eProducto prod[], int tamProd, eProveedor prov[],int tamProv)
{

    int idProd;
    eProducto prodModificado;

    int esta2;
    char confirma;
    int salir = 0;


    system("cls");
    printf("---Modificar publicacion---\n\n");

    getInt(&idProd, "Ingrese ID del prod: ","ID debe ser mayor a 0",0,100);

    esta2 = buscarProd(prod, tamProd,idProd);
    if(esta2 != -1 )
    {

        mostrarProd(prod[esta2]);
        do
        {
            printf("\nConfirma la modificacion? [s|n]\n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }
        while(confirma != 's' && confirma != 'n');

        if(confirma == 's')
        {
            prodModificado.isEmpty = 0;
            do
            {
                switch(menuModificaProd())
                {
                case 1:
                    getString(prodModificado.descripcion,"Nueva descripcion: ","Rango valido[2-50]",2,50);
                    strcpy(prod[esta2].descripcion, prodModificado.descripcion);
                    break;
                case 2:
                    getFloat(&prodModificado.importe,"Nuevo precio: ","Rango valido [1-100000]",1,100000);
                    prod[esta2].importe  = prodModificado.importe;

                    break;
                case 3:
                    getInt(&prodModificado.stock,"Nuevo stock: ","Rango valido [1-1000]",1,1000);
                    prod[esta2].stock = prodModificado.stock;
                    break;
                case 4:
                    salir = 1;
                    break;
                default:
                    printf("Ingrese una opcion correcta [1-4]");
                    break;
                }
            }
            while(salir != 1);
            printf("\nSe ha realizado la modificacion\n\n");
            mostrarProveedorYProductos(prov,prod,tamProv,tamProd);
        }
        else
        {
            printf("\nSe ha cancelado la modificacion\n\n");
        }
    }
    else
    {
        printf("El producto no se encuentra en la lista\n");
    }
}

int menuInformar()
{
    int opcion;

    system("cls");
    printf("---INFORMAR---\n\n");
    printf("1-Total y promedio de los importes y cuantos prod superan el promedio\n");
    printf("2-Total y promedio de los importes y cuantos prod no superan el promedio\n");
    printf("3-Cant de prod cuyo stock es menor o igual a 10\n");
    printf("4-Cant de prod cuyo stock es mayor a 10\n");
    printf("5-Salir\n");
    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void informar(eProducto prod[],int tamProd)
{

    int salir = 0;
    float contadorImporte = 0;
    float promedio = 0;
    int cantMax=0;
    int cantMin=0;
    int cant = 0;
    int cant2 = 0;
    int i;
    do
    {
        switch(menuInformar())
        {
        case 1:

            for(i=0; i<tamProd; i++)
            {
                if(prod[i].isEmpty==0)
                {
                    contadorImporte=contadorImporte+prod[i].importe;
                    promedio = contadorImporte/(float)prod[i].stock;
                }

            }

            // promedio = contadorImporte/(float)tamProd;
            for(i=0; i<tamProd; i++)
            {
                if(prod[i].importe>promedio && prod[i].isEmpty==0)
                {
                    cantMax++;
                }
                else if(prod[i].importe<promedio && prod[i].isEmpty==0)
                {
                    cantMin++;
                }
            }

            printf("Total de importes: $ %.2f\n",contadorImporte);
            printf("Promedio: %.2f, cant productos que superan el promedio: %d\n ",promedio,cantMax);
            system("pause");
            break;
        case 2:
            printf("Total de importes: $ %.2f\n",contadorImporte);
            printf("Promedio: %.2f, cant productos que no superan el promedio: %d\n ",promedio,cantMin);
            system("pause");
            break;
        case 3:


            for(i= 0; i<tamProd; i++)
            {
                if( prod[i].stock >0 && prod[i].stock <= 10 && prod[i].isEmpty == 0)
                {
                    cant ++;
                }
            }
            printf("Cantidad de productos cuyo stock es menor o igual a 10: %d\n",cant);
            system("pause");
            break;
        case 4:

            for(i= 0; i<tamProd; i++)
            {
                if( prod[i].stock >10 && prod[i].isEmpty == 0)
                {
                    cant2 ++;
                }
            }
            printf("Cantidad de productos cuyo stock es mayor a 10: %d\n",cant2);
            system("pause");
            break;
        case 5:
            salir = 1;
            break;
        default:
            printf("Ingrese una opcion correcta [1-4]");
            break;
        }
    }
    while(salir != 1);


}
void listarProdCantMenorADiez(eProducto prod[],int tam)
{
    int i;
    printf("ID Prod\t\tNombre\t\tPrecio\t\tStock\n");
    for(i= 0; i<tam; i++)
    {
        if( prod[i].stock >0 && prod[i].stock <= 10 && prod[i].isEmpty == 0)
        {
            printf("%d\t\t%s\t\t%.2f\t\t%d\n",prod[i].idProd,prod[i].descripcion,prod[i].importe,prod[i].stock);
        }
    }


}




void listarProdCantMayorADiez(eProducto prod[],int tam)
{
    int i;
    printf("ID Prod\t\tNombre\t\tPrecio\t\tStock\n");
    for(i= 0; i<tam; i++)
    {
        if( prod[i].stock >10 && prod[i].isEmpty == 0)
        {
            printf("%d\t\t%s\t\t%.2f\t\t%d\n",prod[i].idProd,prod[i].descripcion,prod[i].importe,prod[i].stock);
        }
    }


}

int menuListar()
{

    int opcion;

    system("cls");
    printf("---LISTAR---\n\n");
    printf("1-Lista de prod ordenada por importe y descripcion\n");
    printf("2-Todos los prod que en cant son menor o igual a 10\n");
    printf("3- Todos los prod que en cant son mayor a 10\n");
    printf("4-Todos los prod que superan el promedio de los importes\n");
    printf("5-Todos los prod que no superan el promedio de los importes\n");
    printf("6-Todos los proveedores cuya cant de prod es menor o igual a 10\n");
    printf("7-Todos los prod provistos por cada proveedor\n");
    printf("8-Todos los prod provistos por un proveedor determinado\n");
    printf("9-El proveedor que provee mas prod, mostrando los prod\n");
    printf("10-El proveedor que provee menos prod, mostrando los prod\n");
    printf("11-El proveedor que provee el prod mas caro, mostrando ese prod\n");
    printf("12-El proveedor que provee el prod mas barato, mostrando ese prod\n");
    printf("13-Salir\n");
    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;

}

void listar(eProducto prod[],int tamProd, eProveedor prov[], int tamProv)
{

    int salir = 0;
    int i,j;
    float contadorImporte = 0;
    float promedio = 0;

    do
    {
        switch(menuListar())
        {
        case 1:
            listarProductos(prod, tamProd);
            system("pause");

            break;
        case 2:
            listarProdCantMenorADiez(prod,tamProd);
            system("pause");

            break;
        case 3:
            listarProdCantMayorADiez(prod,tamProd);
            system("pause");
            break;
        case 4:

            for(i=0; i<tamProd; i++)
            {
                if(prod[i].isEmpty==0)
                {
                    contadorImporte=contadorImporte+prod[i].importe;
                }

            }
            promedio = contadorImporte/(float)tamProd;

            system("cls");
            printf("Productos que superan el promedio de importe\n");
            printf("IDProd\tIDProv\tDescripcion\tImporte\tStock\n");
            for(i=0; i<tamProd; i++)
            {
                if(prod[i].isEmpty==0)
                {
                    if(prod[i].importe>promedio)
                    {
                        mostrarProd(prod[i]);
                    }

                }
            }
            system("pause");

            break;
        case 5:
            for(i=0; i<tamProd; i++)
            {
                if(prod[i].isEmpty==0)
                {
                    contadorImporte=contadorImporte+prod[i].importe;
                }

            }
            promedio = contadorImporte/(float)tamProd;

            system("cls");
            printf("Productos que no superan el promedio de importe\n");
            printf("IDProd\tIDProv\tDescripcion\tImporte\tStock\n");
            for(i=0; i<tamProd; i++)
            {
                if(prod[i].isEmpty==0)
                {
                    if(prod[i].importe<promedio)
                    {
                        mostrarProd(prod[i]);
                    }

                }
            }
            system("pause");
            break;
        case 6:
            printf("Proveedores cuya cant de prod es menor o igual a 10:\n");
            printf("Nombre");
            for(i=0; i<tamProv; i++)
            {
                for(j=0; j<tamProd; j++)
                {
                    if(prov[i].isEmpty == 0 && prod[j].isEmpty == 0 && prov[i].idProveedor == prod[j].idProveedor)
                    {
                        if(prod[j].stock <=10)
                        {
                            printf("%s\n",prov[i].descripcion);
                        }
                    }
                }

            }
            system("pause");
            break;
        case 7:
            mostrarProds(prod,tamProd);
            system("pause");
            break;
        case 8:
            mostrarProveedorDeterminadoYProductos(prov,prod,tamProv,tamProd);
            system("pause");
            break;
        case 9:

            listar9(prod,tamProd,prov,tamProv);
            system("pause");
            break;
        case 10:

            listar10(prod,tamProd,prov,tamProv);
            system("pause");
            break;
        case 11:

            listar11(prod,tamProd,prov,tamProv);
            system("pause");
            break;
        case 12:

            listar12(prod,tamProd,prov,tamProv);
            system("pause");
            break;

        case 13:
            salir = 1;
            break;
        default:
            printf("Ingrese una opcion correcta [1-13]");
            break;
        }
    }
    while(salir != 1);



}



void listarProductos(eProducto prod[],int tamProd)
{
    int i,j;
    eProducto aux;
    for(i=0; i<tamProd-1; i++)
    {
        for(j=i+1; j<tamProd; j++ )

        {
            if(prod[i].isEmpty == 0 && prod[j].isEmpty == 0)
            {
                if(prod[i].importe < prod[j].importe)
                {
                    aux.importe = prod[i].importe;
                    prod[i].importe = prod[j].importe;
                    prod[j].importe = aux.importe;
                }
                else
                {
                    if(prod[i].importe == prod[j].importe)
                    {

                        if(strcmp(prod[i].descripcion,prod[j].descripcion)>0)
                        {
                            strcpy(aux.descripcion, prod[i].descripcion);
                            strcpy(prod[i].descripcion,prod[j].descripcion);
                            strcpy(prod[j].descripcion,aux.descripcion);
                        }
                    }
                }
            }
        }
    }
    mostrarProds(prod,tamProd);




}
//Informa el proveedor que tiene mas productos
void listar9(eProducto prod[],int tamProd,eProveedor prov[],int tamProv)
{
    int i,j;
    int flag = 0;
    int mayor=0;
    int idProvMayor;



    if (prod[0].isEmpty == 0)
        mayor = prod[0].stock;
    for(i=0; i<tamProd; i++)
    {

        if(prod[i].isEmpty == 0 && (prod[i].stock > mayor|| flag == 0))
        {
            mayor = prod[i].stock;

            flag =1;


        }
    }


    for(i=0; i<tamProd; i++)
    {

        if(prod[i].stock == mayor )
        {
            idProvMayor= prod[i].idProveedor;

            for(j=0; j<tamProv; j++)
            {

                if( prov[j].idProveedor == idProvMayor && prov[j].isEmpty == 0 && prod[i].isEmpty == 0)
                {
                    printf("El proveedor que provee mas prod es: %s\n",prov[j].descripcion);
                    printf("ID\tIdProv\tDescripcion\tImporte\tStock\n\n");
                    mostrarProd(prod[i]);
                }
            }
        }
    }




}
//informa el proveedor que tiene menos prod
void listar10(eProducto prod[],int tamProd,eProveedor prov[],int tamProv)
{
    int i,j;
    int flag = 0;
    int menor=0;
    int idProvMenor;

    if (prod[0].isEmpty == 0)
        menor = prod[0].stock;

    for(i=0; i<tamProd; i++)
    {

        if(prod[i].isEmpty == 0 && (prod[i].stock < menor || flag == 0))
        {
            menor = prod[i].stock;

            flag =1;


        }
    }


    for(i=0; i<tamProd; i++)
    {

        if(prod[i].stock == menor )
        {
            idProvMenor= prod[i].idProveedor;

            for(j=0; j<tamProv; j++)
            {

                if( prov[j].idProveedor == idProvMenor && prov[j].isEmpty == 0 && prod[i].isEmpty == 0)
                {
                    printf("El proveedor que provee menos prod es: %s\n",prov[j].descripcion);
                    printf("ID\tIdProv\tDescripcion\tImporte\tStock\n\n");
                    mostrarProd(prod[i]);
                }
            }
        }
    }




}

//informa el proveedor que tiene el prod mas caro
void listar11(eProducto prod[],int tamProd, eProveedor prov[],int tamProv)
{
    int i,j;
    int flag = 0;
    float mayor=0;
    int idProvMayor;

    if (prod[0].isEmpty == 0)
        mayor = prod[0].importe;

    for(i=0; i<tamProd; i++)
    {

        if( prod[i].isEmpty == 0 && (prod[i].importe > mayor || flag == 0))
        {
            mayor = prod[i].importe;

            flag =1;


        }
    }


    for(i=0; i<tamProd; i++)
    {

        if(prod[i].importe == mayor )
        {
            idProvMayor= prod[i].idProveedor;

            for(j=0; j<tamProv; j++)
            {

                if( prov[j].idProveedor == idProvMayor && prov[j].isEmpty == 0 && prod[i].isEmpty == 0)
                {
                    printf("El proveedor que tiene el prod mas caro es: %s\n",prov[j].descripcion);
                    printf("ID\tIdProv\tDescripcion\tImporte\tStock\n\n");
                    mostrarProd(prod[i]);
                }
            }
        }
    }

}
//informa el proveedor que tiene el prod mas barato
void listar12(eProducto prod[],int tamProd, eProveedor prov[],int tamProv)
{
    int i,j;
    int flag = 0;
    float menor=0;
    int idProvMenor;

    if (prod[0].isEmpty == 0)
        menor = prod[0].importe;

    for(i=0; i<tamProd; i++)
    {
        menor = prod[0].importe;

        if( prod[i].isEmpty == 0 && (prod[i].importe < menor || flag == 0))
        {
            menor = prod[i].importe;

            flag =1;


        }
    }


    for(i=0; i<tamProd; i++)
    {

        if(prod[i].importe == menor )
        {
            idProvMenor= prod[i].idProveedor;

            for(j=0; j<tamProv; j++)
            {

                if( prov[j].idProveedor == idProvMenor && prov[j].isEmpty == 0 && prod[i].isEmpty == 0)
                {
                    printf("El proveedor que tiene el prod mas barato es: %s\n",prov[j].descripcion);
                    printf("ID\tIdProv\tDescripcion\tImporte\tStock\n\n");
                    mostrarProd(prod[i]);
                }
            }
        }
    }
}



