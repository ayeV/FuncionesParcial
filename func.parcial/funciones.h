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
typedef struct
{
    int id;
    char descripcion[51];
    int isEmpty;


} eSector;

/**
 *  Obtiene la opcion del menu elegida por el usuario
 * \return la opcion elegida por el usuario
 *
 */
int menu();

/** Inicializa el vector vec en 0 para poder hacer una carga aleatoria
 *
 * \param vec vector de empleados
 * \param tam tamanio del vector empleados se pasa por parametro
 */
void inicializarEmpleados(eEmpleado vec[], int tam);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param tam tamanio del array se pasa por parametro
 * @return el primer indice disponible
 */
int buscarLibre(eEmpleado vec[], int tam);

/**
 * Le pide al usuario los datos y los guarda
 *  \param vec vector de empleados
 * \param tam tamanio del vector empleados se pasa por parametro
 */
void altaEmpleado(eEmpleado vec[], int tam);

/**
 * Muestra un solo empleado
 * \param emp array se pasa por parametro
 */
void mostrarEmpleado(eEmpleado emp);
/**
 * Obtiene el indice que coincide con el legajo pasado por parametro.
 * @param vec el array se pasa como parametro.
 * @param legajo el legajo a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro legajo
 */
int buscarEmpleado(eEmpleado vec[],int tam, int legajo);
/**
 * Borra a un empleado del sistema
 * \param vec array se pasa por parametro
 * \param tam tamanio que recibe el array se pasa por parametro
 */
void baja(eEmpleado vec[], int tam);
/** Le permite al usuario modificar datos de algun empleado
 *
 * \param vec el array se pasa como parametro.
 * \param tam tamanio que recibe el array se pasa por parametro
 *
 */

void modificaEmpleado(eEmpleado vec[], int tam);
/** Hardcodeo de sectores
 *
 * \param sectores array se pasa por parametro
 */
void hardCode(eSector sectores[]);
/**
 * Ordena los empleados por sueldo en forma descendente
 *\param vec array se pasa por parametro
 * \param tam tamanio que recibe el array se pasa por parametro
 */
void ordenarEmpleados(eEmpleado vec[],int tam);
/**
 * Muestra una Lista de todos los empleados y sus sectores correspondientes
 * \param vec array se pasa por parametro
 * \param tam tamanio que recibe el array se pasa por parametro
 * \param sec array se pasa por parametro
 * \return
 */
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sec[]);
/** Menu para la funcion modificarEmpleado
 *
 * \return la opcion elegida por el usuario
 *
 */

int menuModifica();
/** Funcion que grafica barras en forma vertical
 *
 * \param parametro 1 se pasa por parametro
 * \param parametro 2 se pasa por parametro
 * \param parametro 3 se pasa por parametro
 */
void graficar(int parametro1, int parametro2, int parametro3);

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);

/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/** \brief
 * Lista los sectores por empleado
 * \param emp array se pasa por parametro
 * \param tam tamanio del array se pasa por parametro
 * \param sec array se pasa por parametro
 */
void listarEmpPorSector(eEmpleado emp[],int tam, eSector sec[]);



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
