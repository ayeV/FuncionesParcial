#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define COL 5

typedef struct
{
    int dia;
    int mes;
    int anio;



} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int isEmpty;
    int idSector;



} eEmpleado;
typedef struct{
    int id;
    char descripcion[51];
    int isEmpty;


}eSector;


int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
void altaEmpleado(eEmpleado vec[], int tam);
void mostrarEmpleado(eEmpleado emp);

int buscarEmpleado(eEmpleado vec[],int tam, int legajo);
void baja(eEmpleado vec[], int tam);
void modificaEmpleado(eEmpleado vec[], int tam);
void hardCode(eSector sectores[]);
void ordenarEmpleados(eEmpleado vec[],int tam);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sec[]);

int menuModifica();

void cargarMatriz(int mat[][COL]);
void mostrarMatriz(int mat[][COL]);
void cargarVector(int vec[]);
void mostrarVector(int vec[]);
float sumar(float, float);
float restar (float, float);
float division (float, float);
float multiplicacion(float, float);
int factorial(int);




#endif // FUNCIONES_H_INCLUDED
