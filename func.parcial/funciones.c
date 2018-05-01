#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define CANT 5
#define COL 5
#define FILAS 5
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


void cargarMatriz(int mat[][COL]){
    int i,j;

    for(i=0; i<FILAS; i++){
        for(j=0;j<COL; j++){
            printf("Ingrese valor a cargar en la posicion (%d,%d): ",i,j);
            scanf("%d", &mat[i][j]);
        }
    }



}

void mostrarMatriz(int mat[][COL])
{
    int i, j;
 for(i=0; i<FILAS; i++)
    {
        for(j=0; j<COL; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
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


int factorial(int i){
    int resultado;
        if(i == 1){
            return 1;
        }
        resultado = i*factorial(i-1);

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

    printf("1.Agregar empleado\n");
    printf("2.Dar de baja empleado\n");
    printf("3.Modificar empleado\n");

    printf("4.Listar\n");
    printf("5.Ordenar\n");
    printf("6.Salir\n");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarEmpleados(eEmpleado vec[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;

    }
}

int buscarLibre(eEmpleado vec[], int tam)
{
    int i;
    int indice = -1;

    for(i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam)
{
    eEmpleado nuevoEmpleado;
    int esta;
    int legajo;
    int indice;

    system("cls");
    indice = buscarLibre(vec,tam);


    if(indice == -1)
    {
        printf("El sistema no admite mas empleados\n");
    }
    else
    {
        printf("Legajo: ");
        scanf("%d",&legajo);

        esta = buscarEmpleado(vec,tam,legajo);
        if(esta != -1 )
        {
            printf("\nEl legajo %d ya esta dado de alta\n", legajo);
            mostrarEmpleado(vec[esta]);
        }
        else
        {
            nuevoEmpleado.isEmpty = 0;
            nuevoEmpleado.legajo =legajo;
            printf("Nombre: ");
            fflush(stdin);
            scanf("%[^\n]",nuevoEmpleado.nombre);
            printf("\n\nFecha de Ingreso");
            printf("\nDia: ");
            scanf("%d", &nuevoEmpleado.fechaIngreso.dia);

            printf("\nMes: ");
            scanf("%d", &nuevoEmpleado.fechaIngreso.mes);

            printf("\nAño: ");
            scanf("%d", &nuevoEmpleado.fechaIngreso.anio);

            printf("Sexo: ");
            fflush(stdin);
            scanf("%c",&nuevoEmpleado.sexo);
            printf("Sueldo: ");
            scanf("%f",&nuevoEmpleado.sueldo);
            vec[indice] = nuevoEmpleado;
            printf("Sector: ");
            scanf("%d",&nuevoEmpleado.idSector);
             vec[indice] = nuevoEmpleado;
            printf("Alta exitosa\n");
        }
    }
}


void hardCode(eSector sectores[])
{
    eSector nuevoSector;

    nuevoSector.id = 1;
    strcpy(nuevoSector.descripcion, "RRHH");
    nuevoSector.isEmpty = 0;
    sectores[0] = nuevoSector;


    nuevoSector.id = 2;
    strcpy(nuevoSector.descripcion, "Sistemas");
    nuevoSector.isEmpty = 0;
    sectores[1] = nuevoSector;

    nuevoSector.id = 3;
    strcpy(nuevoSector.descripcion, "Administracion");
    nuevoSector.isEmpty = 0;
    sectores[2] = nuevoSector;

    nuevoSector.id = 4;
    strcpy(nuevoSector.descripcion, "Compras");
    nuevoSector.isEmpty = 0;
    sectores[3] = nuevoSector;

    nuevoSector.id = 5;
    strcpy(nuevoSector.descripcion, "Deposito");
    nuevoSector.isEmpty = 0;
    sectores[4] = nuevoSector;

}







void mostrarEmpleados(eEmpleado vec[], int tam, eSector sec[])
{
    int i,j;
    printf("Legajo\tNombre\tFecha Ingreso\tSueldo\tSexo\tSector\n\n");
    for(i=0; i<tam; i++)
    {
        for(j=0; j<5; j++)
        {
            if(vec[i].idSector == sec[j].id)
            {
                printf("%d\t%s\t%d/%d/%d\t%.2f\t%c\t%s\n", vec[i].legajo,vec[i].nombre,vec[i].fechaIngreso.dia,vec[i].fechaIngreso.mes,vec[i].fechaIngreso.anio,vec[i].sueldo,vec[i].sexo,sec[j].descripcion);
               /* printf("%s\t",vec[i].nombre);
                printf("%d/%d/%d\t", vec[i].fechaIngreso.dia,vec[i].fechaIngreso.mes,vec[i].fechaIngreso.anio);
                printf("%.2f\t",vec[i].sueldo);
                printf("%c\t",vec[i].sexo);
                printf("%s",sec[j].descripcion);*/
            }

        }
    }
}


void mostrarEmpleado(eEmpleado emp)
{

    printf("%d\t%s\t\t\t%d/%d/%d\t%.2f\t\t%c\n", emp.legajo, emp.nombre, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anio, emp.sueldo, emp.sexo);

}

int buscarEmpleado(eEmpleado vec[],int tam, int legajo)
{
    int i;
    int indice = -1;
    for(i=0; i<tam; i++)
    {
        if(legajo == vec[i].legajo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void baja(eEmpleado vec[], int tam)
{
    int legajo;
    char opc;
    int esta;

    system("cls");

    printf("Legajo: ");
    scanf("%d", &legajo);
    esta = buscarEmpleado(vec, tam, legajo);
    if(esta == -1)
    {
        printf("Legajo inexistente");
    }
    else
    {
        mostrarEmpleado(vec[esta]);
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
            vec[esta].isEmpty = 1;
            printf("Baja exitosa\n");
        }
        else
        {
            printf("Se ha cancelado la baja\n");

        }
    }

}
void modificaEmpleado(eEmpleado vec[], int tam)
{
    int legajo;
    eEmpleado empleadoModificado;
    int esta;
    char confirma;
    int salir = 0;

    system("cls");
    printf("---Modifica Empleado---\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if(esta == -1)
    {
        printf("\nEl legajo %d no se encuentra en el sistema\n\n", legajo);

    }
    else
    {

        mostrarEmpleado(vec[esta]);

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
            empleadoModificado.isEmpty = 0;
            do
            {
                switch(menuModifica())
                {
                case 1:
                    printf("Ingrese nuevo legajo: ");
                    scanf("%d",&empleadoModificado.legajo);
                    vec[esta].legajo = empleadoModificado.legajo;

                    break;
                case 2:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    scanf("%[^\n]",empleadoModificado.nombre);
                    strcpy(vec[esta].nombre, empleadoModificado.nombre);

                    break;
                case 3:
                    do
                    {
                        printf("Ingrese nuevo sexo: ");
                        fflush(stdin);
                        scanf("%c",&empleadoModificado.sexo);
                        empleadoModificado.sexo = tolower(empleadoModificado.sexo);
                    }
                    while(empleadoModificado.sexo != 'm' && empleadoModificado.sexo != 'f');
                    vec[esta].sexo = empleadoModificado.sexo;

                    break;
                case 4:
                    printf("Ingrese nuevo sueldo: ");
                    scanf("%f",&empleadoModificado.sueldo);
                    vec[esta].sueldo = empleadoModificado.sueldo;

                    break;
                case 5:
                    printf("Ingrese nueva fecha de ingreso DD/MM/AA: ");
                    scanf("%d %d %d ", &empleadoModificado.fechaIngreso.dia,&empleadoModificado.fechaIngreso.mes,&empleadoModificado.fechaIngreso.anio);
                    vec[esta].fechaIngreso.dia = empleadoModificado.fechaIngreso.dia;
                    vec[esta].fechaIngreso.mes = empleadoModificado.fechaIngreso.mes;
                    vec[esta].fechaIngreso.anio = empleadoModificado.fechaIngreso.anio;
                    break;
                case 6:
                    printf("Ingrese nuevo sector: ");
                    scanf("%d",&empleadoModificado.idSector);
                    vec[esta].idSector = empleadoModificado.idSector;

                    break;

                case 7:
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

int menuModifica()
{
    int opcion;

    system("cls");
    printf("---Modificar Empleados---\n\n");
    printf("1-Legajo\n");
    printf("2-Nombre\n");
    printf("3-Sexo\n");
    printf("4-Sueldo\n");
    printf("5-Fecha de Ingreso\n");
    printf("6-Sector\n");
    printf("7-Salir\n");
    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

//ordenado en forma descendente
void ordenarEmpleados(eEmpleado vec[],int tam)
{
    int i,j;
    eEmpleado aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(vec[i].sueldo < vec[j].sueldo)
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }


}

void mostrarPersonas(eEmpleado persona[],int cantidad){
    int i;
    printf("Nombre\t\tSexo\tSueldo\t\t\n\n");
    for(i=0;i<cantidad;i++){
        printf("%s\t\t\t%c\t%.2f\t\t\n\n", persona[i].nombre, persona[i].sexo,persona[i].sueldo);
    }


}


