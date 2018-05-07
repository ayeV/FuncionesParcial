#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define CANT 5
#define COL 5
#define FILAS 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int indice = 0;
    printf("%s",message);
    scanf("%d",input);

    while( *input < lowLimit || *input >hiLimit)
    {
        printf("%s", eMessage);
        scanf("%d",input);
    }

    if(*input >lowLimit || *input <hiLimit){
        return indice;
    }
    else{
        indice = -1;
        return indice;
    }



}


int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int indice=0;

    printf("%s",message);
    scanf("%f",input);

    while( *input < lowLimit || *input >hiLimit)
    {
        printf("%s", eMessage);
        scanf("%f",input);
    }
    if(*input >lowLimit || *input <hiLimit){
        return indice;
    }
    else{
        indice = -1;
        return indice;
    }



}



int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    int indice=0;

     printf("%s",message);
     fflush(stdin);
    scanf("%c",input);

    while( *input != lowLimit && *input != hiLimit)
    {
        printf("%s", eMessage);
        fflush(stdin);
        scanf("%c",input);
    }

   if(*input == lowLimit || *input == hiLimit){
        return indice;
    }
    else{
        indice = -1;
        return indice;
    }

}



int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int indice = 0;

    printf("%s",message);
    fflush(stdin);
    scanf("%[^\n]",input);

    while( strlen(input) < lowLimit || strlen(input) >hiLimit)
    {
        printf("%s", eMessage);
        fflush(stdin);
        scanf("%[^\n]",input);
    }
    if(*input >lowLimit || *input <hiLimit){
        return indice;
    }
    else{
        indice = -1;
        return indice;
    }



}
int validarCadena(char cadena[])
{
    int i;

    for(i=0; i<strlen(cadena); i++)
    {
        if(!(isalpha(cadena[i])))
        {
            printf("Ingrese solo letras\n");
            getch();
            return 0;

        }
    }
    return 1;
}



void cargarVector(int vec[]){
    int i;

    for(i=0;i<CANT;i++){
        printf("Ingrese valor a cargar en el vector: ");
        scanf("%d", &vec[i]);
    }


}
void mostrarVector(int vec[]){
    int i;
    for(i=0;i<CANT;i++){
        printf("%d", vec[i]);
    }


}




float sumar(float a, float b){

    float resultado;
        resultado = a + b;

    return resultado;
}


float restar(float c, float d){
    float resultado;
        resultado = c-d;
    return resultado;

}


float division (float e, float f){
    float resultado;
    if(f != 0){
        resultado = e/f;
    }
    else{
        printf("No se puede dividir por 0");
    }
    return resultado;
  }


float multiplicacion(float g, float h){
    float resultado;

    resultado = g*h;
    return resultado;
}



void ordenar(int vec[], int tam, int criterio){
    int i,j,aux;

    for(i=0; i<tam-1; i++){
        for(j=i+1;j<tam; j++ ){
            if(vec[i]>vec[j] && criterio == 0){
                aux = vec[i];
                vec[i]= vec[j];
                vec[j]=aux;
                }
            }
            if(vec[i]<vec[j] && criterio == 1){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
                }
            }
}

int menu()
{
    int opcion;
    system("cls");

    printf("1.Alta de usuario\n");
    printf("2.Modificar datos del usuario\n");
    printf("3.Baja del usuario\n");

    printf("4.Publicar producto\n");
    printf("5.Modificar publicacion\n");
    printf("6.Cancelar publicacion\n");
    printf("7.Comprar producto\n");
    printf("8.Listar publicaciones del usuario\n");
    printf("9.Listar publicaciones\n");
    printf("10.Listar usuarios");
    printf("11.Salir\n");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarUsers(eUsuario user[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        user[i].isEmpty = 1;

    }
}

int buscarLibre(eUsuario user[], int tam)
{
    int i;
    int indice = -1;

    for(i=0; i<tam; i++)
    {
        if(user[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void inicializarProductos(eProducto prod[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        prod[i].isEmpty = 1;

    }
}
int buscarLibreProd(eProducto prod[],int tam){

    int i;
    int indice = -1;
    for(i=0;i<tam;i++){
        if(prod[i].isEmpty == 1){
            indice = i;
            break;
        }
    }

    return indice;
}

void altaUser(eUsuario user[], int tam)
{
    int r;
    eUsuario nuevoUser;
    int esta;
    int idUsuario;
    int indice;

    system("cls");
    indice = buscarLibre(user,tam);


    if(indice == -1)
    {
        printf("El sistema no admite mas usuarios\n");
    }
    else
    {
        r = getInt(&idUsuario,"Ingrese ID: ","ID debe ser mayor a 0: ",0,9999999);

        esta = buscarUsuario(user,tam,idUsuario);
        if(esta != -1 )
        {   if(r==0){
            printf("\nEl ID %d ya esta dado de alta\n", idUsuario);
            mostrarUsuario(user[esta]);
            }
        }
        else
        {
            nuevoUser.isEmpty = 0;
            nuevoUser.idUsuario =idUsuario;
            r = getString(nuevoUser.nombre,"Nombre: ","Rango valido [2-50]",2,50);

           r = getString(nuevoUser.password,"Password: ","Rango valido [2-10]",2,50);


            user[indice] = nuevoUser;
          //  user[indice].idUsuario = esta;
           //  user[indice] = nuevoUser;
            printf("Alta exitosa\n");
        }
    }
}
void mostrarProd(eProducto prod){

    printf("Nombre\t\tID\t\tPrecio\tStock\n");
    printf("%s\t\t%d\t\t%.2f\t%d",prod.nombre,prod.id,prod.precio,prod.stock);


}

void publicarProducto(eProducto producto[],int tamProd, eUsuario user[],int tamUsuario)
{
    int r;
    eProducto nuevoProducto;
    int esta1;
    int esta2;
    int idProducto;
    int idUsuario;

    int indice2;

    system("cls");
    getInt(&idUsuario,"Ingrese su ID: ", "Error, ID debe ser mayor a 0",0,999999);
    esta1 = buscarUsuario(user,tamUsuario,idUsuario);
    if(esta1 != -1)
    {
        indice2 = buscarLibreProd(producto,tamProd);


        if(indice2 == -1)
        {
            printf("El sistema no admite mas productos\n");
        }
        else
        {
            r = getInt(&idProducto,"Ingrese ID de producto: ","ID debe ser mayor a 0: ",0,9999999);

            esta2 = buscarProd(producto,tamProd,idProducto);
            if(esta2 != -1 )
            {
                if(r==0)
                {
                    printf("\nEl ID del producto %d ya esta publicado\n", idProducto);

                    mostrarProd(producto[esta2]);
                }
            }
            else
            {
                nuevoProducto.isEmpty = 0;
                nuevoProducto.id =idProducto;
                nuevoProducto.idUsuario = idUsuario;
                r = getString(nuevoProducto.nombre,"Nombre: ","Rango valido [2-50]",2,50);
                r = getFloat(&nuevoProducto.precio,"Precio: ","Rango valido [0-10000]",0,10000);
                r = getInt(&nuevoProducto.stock, "Stock: ","Rango valido [1-100]",0,100);




                producto[indice2] = nuevoProducto;
               // producto[indice2].id = esta2;
              //  producto[indice2] = nuevoProducto;
                printf("Publicacion exitosa\n");
            }
    }



    }
    else{
        printf("Usuario inexistente\n");
    }

}
void hardCode(eProducto productos[])
{
    eProducto nuevoProducto;

    nuevoProducto.id = 1;
    strcpy(nuevoProducto.nombre, "Lamparas");
    nuevoProducto.isEmpty = 0;
    productos[0] = nuevoProducto;


    nuevoProducto.id = 2;
    strcpy(nuevoProducto.nombre, "Canillas");
    nuevoProducto.isEmpty = 0;
    productos[1] = nuevoProducto;

    nuevoProducto.id = 3;
    strcpy(nuevoProducto.nombre, "Tornillos");
    nuevoProducto.isEmpty = 0;
    productos[2] = nuevoProducto;

    nuevoProducto.id = 4;
    strcpy(nuevoProducto.nombre, "Clavos");
    nuevoProducto.isEmpty = 0;
    productos[3] = nuevoProducto;

    nuevoProducto.id = 5;
    strcpy(nuevoProducto.nombre, "Pinturas");
    nuevoProducto.isEmpty = 0;
    productos[4] = nuevoProducto;

}


//lista de todos los usuarios
void mostrarUsuarios(eUsuario users[], int tam)
{
    int i;
    printf("ID\tNombre\n\n");
    for(i=0; i<tam; i++)
    {
        if(users[i].isEmpty == 0)
        {
            printf("%d\t%s\t\n", users[i].idUsuario,users[i].nombre);



        }
    }
}






void mostrarUsuario(eUsuario user){
    printf("Nombre\t\tID\t\tPassword\n");
    printf("%s\t\t%d\t\t%s",user.nombre, user.idUsuario,user.password);
}


void mostrarUsuarioYProductos(eUsuario user[],eProducto prod[], int tamUser, int tamProd)
{
    int i,j;
    system("cls");
    for(i=0; i<tamUser; i++)
    {
        for(j=0; j<tamProd; j++)
        {
            if(user[i].isEmpty == 0 && user[i].idUsuario == prod[j].idUsuario && prod[j].isEmpty == 0)
            {
                 printf("Publicaciones del usuario %s\n",user[i].nombre);

                printf("ID Prod\t\tNombre\t\tPrecio\t\tStock\n");
                printf("%d\t\t%s\t\t%.2f\t\t%d\n",prod[j].id,prod[j].nombre,prod[j].precio,prod[j].stock);
            }
        }
    }



}






int buscarUsuario(eUsuario user[],int tam, int id)
{
    int i;
    int indice = -1;
    for(i=0; i<tam; i++)
    {
        if(user[i].isEmpty == 0 && user[i].idUsuario == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int buscarProd(eProducto prod[],int tam, int id)
{
    int i;
    int indice = -1;
    for(i=0; i<tam; i++)
    {
        if(prod[i].isEmpty == 0 && prod[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void bajaUsuario(eUsuario user[], int tam)
{

    int id;
    char opc;
    int esta;

    system("cls");
    getInt(&id,"Ingrese ID: ","ID debe ser mayor a 0: ",0,9999999);

    esta = buscarUsuario(user, tam, id);
    if(esta == -1)
    {
        printf("ID inexistente");
    }
    else
    {
        mostrarUsuario(user[esta]);
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
            user[esta].isEmpty = 1;
            printf("Baja exitosa\n");
        }
        else
        {
            printf("Se ha cancelado la baja\n");

        }
    }

}
void modificaUsuario(eUsuario user[], int tam)
{
    int id;
    eUsuario usuarioModificado;
    int esta;
    char confirma;
    int salir = 0;

    system("cls");
    printf("---Modifica Usuario---\n\n");

     getInt(&id,"Ingrese ID: ","ID debe ser mayor a 0: ",0,9999999);

    esta = buscarUsuario(user, tam, id);

    if(esta == -1)
    {
        printf("\nEl ID %d no se encuentra en el sistema\n\n", id);

    }
    else
    {

        mostrarUsuario(user[esta]);

        do
        {
            printf("\nConfirma la modificacion? [s|n]: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
        }
        while(confirma != 's' && confirma != 'n');

        if(confirma == 's')
        {
            usuarioModificado.isEmpty = 0;
            do
            {
                switch(menuModificaUsuario())
                {
                case 1:
                    getString(usuarioModificado.password,"Nuevo password: ","Rango valido [2-10]",2,10);


                    strcpy(user[esta].password, usuarioModificado.password);



                    break;
                case 2:
                    getString(usuarioModificado.nombre,"Nuevo nombre: ","Rango valido [2-50]",2,50);

                    strcpy(user[esta].nombre, usuarioModificado.nombre);

                    break;


                case 3:
                    salir = 1;
                    break;
                }
            }
            while(salir != 1);
            printf("\nSe ha realizado la modificacion\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la modificacion\n\n");
        }

    }
}

int menuModificaUsuario()
{
    int opcion;

    system("cls");
    printf("---Modificar Usuario---\n\n");
    printf("1-Password\n");
    printf("2-Nombre\n");
    printf("3-Salir\n");
    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuModificaPublicacion()
{
    int opcion;

    system("cls");
    printf("---Modificar Publicacion---\n\n");
    printf("1-Precio\n");
    printf("2-Stock\n");
    printf("3-Salir\n");
    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void modificaPublicacion(eProducto prod[], int tamProd, eUsuario user[],int tamUser)
{
    int idUser;
    int idProd;
    eProducto prodModificado;
    int esta1;
    int esta2;
    char confirma;
    int salir = 0;
   // int indice;

    system("cls");
    printf("---Modificar publicacion---\n\n");

     getInt(&idUser,"Ingrese ID: ","ID debe ser mayor a 0: ",0,9999999);

    esta1 = buscarUsuario(user, tamUser, idUser);

    if(esta1 == -1)
    {
        printf("\nEl ID %d no se encuentra en el sistema\n\n", idUser);

    }
    else
    {   mostrarUsuarioYProductos(user,prod,tamUser,tamProd);
        getInt(&idProd, "Ingrese ID del prod: ","ID debe ser mayor a 0",0,9999999);

        esta2 = buscarProd(prod, tamProd,idProd);
        if(esta2 != -1 ){
                mostrarProd(prod[esta2]);
        do
        {
            printf("\nConfirma la modificacion? [s|n]: ");
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
                switch(menuModificaPublicacion())
                {
                case 1:
                    getString(&prodModificado.precio,"Nuevo precio: ","Rango valido [1-100000]",1,100000);


                    prod[esta2].precio  = prodModificado.precio;



                    break;
                case 2:
                    getInt(&prodModificado.stock,"Nuevo stock: ","Rango valido [1-1000]",1,1000);
                    prod[esta2].stock = prodModificado.stock;
                    break;
                case 3:
                    salir = 1;
                    break;
                default:
                    printf("Ingrese una opcion correcta [1-6]");
                    break;
                }
            }
            while(salir != 1);
            printf("\nSe ha realizado la modificacion\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la modificacion\n\n");
        }
        }
        else{
            printf("El producto no se encuentra en la lista\n");
        }
    }
}




/*void mostrarPersonas(eEmpleado persona[],int cantidad){
    int i;
    printf("Nombre\t\tSexo\tSueldo\t\t\n\n");
    for(i=0;i<cantidad;i++){
        printf("%s\t\t\t%c\t%.2f\t\t\n\n", persona[i].nombre, persona[i].sexo,persona[i].sueldo);
    }


}*/




int esNumeroInt(char msj[], char eMsj[]){
     int i, flag, cant;
     char cadena[10];
     int nro;

     int contador=0;


    do{
        if(contador >=1){
            printf("%s",eMsj);
            fflush(stdin);
            scanf("%s",cadena);
        }
        else if(contador == 0){
            printf("%s",msj);
            fflush(stdin);
            scanf("%s",cadena);
        }


        flag = 0;
        cant = strlen(cadena);

    for(i=0; i<cant; i++){
        if(!isdigit(cadena[i])){
            flag = 1;

            break;
        }
    }
    contador++;
    }while(flag == 1);
    if(flag == 0){
        nro = atoi(cadena);
    }
    return nro;
}



float esNumFloat(char msj[],char eMsj[]){
    int i, flag, cant;
     char cadena[10];
     float nro;

     int contador=0;


    do{
        if(contador >=1){
            printf("%s",eMsj);
            fflush(stdin);
            scanf("%s",cadena);
        }
        else if(contador == 0){
            printf("%s",msj);
            fflush(stdin);
            scanf("%s",cadena);
        }
        flag = 0;
        cant = strlen(cadena);

    for(i=0; i<cant; i++){
        if(!isdigit(cadena[i]) && cadena[i] != '.' ){
            flag = 1;

            break;
        }
    }
    contador++;
    }while(flag == 1);
    if(flag == 0){
        nro = atof(cadena);
    }
    return nro;


}




