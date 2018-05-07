#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define COL 5


typedef struct{

    int calificacion;



}ePromedio;
typedef struct
{
    int idUsuario;
    char nombre[51];
    char password[11];
    int isEmpty;
    int idProd;
    ePromedio prom;



} eUsuario;
typedef struct
{
    int id;
    char nombre[51];
    float precio;
    int cantVendida;
    int stock;
    int isEmpty;
    int idUsuario;


} eProducto;


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
void inicializarUsers(eUsuario user[], int tam);
void inicializarProductos(eProducto prod[], int tam);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param tam tamanio del array se pasa por parametro
 * @return el primer indice disponible
 */
int buscarLibre(eUsuario user[], int tam);

/**
 * Le pide al usuario los datos y los guarda
 *  \param vec vector de empleados
 * \param tam tamanio del vector empleados se pasa por parametro
 */
void altaUser(eUsuario user[], int tam);

/**
 * Muestra un solo empleado
 * \param emp array se pasa por parametro
 */
void mostrarUsuario(eUsuario user);
/**
 * Obtiene el indice que coincide con el legajo pasado por parametro.
 * @param vec el array se pasa como parametro.
 * @param legajo el legajo a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro legajo
 */
int buscarUsuario(eUsuario user[],int tam, int id);
/**
 * Borra a un empleado del sistema
 * \param vec array se pasa por parametro
 * \param tam tamanio que recibe el array se pasa por parametro
 */
void bajaUsuario(eUsuario user[], int tam);
/** Le permite al usuario modificar datos de algun empleado
 *
 * \param vec el array se pasa como parametro.
 * \param tam tamanio que recibe el array se pasa por parametro
 *
 */

void modificaUsuario(eUsuario user[], int tam);
int menuModificaUsuario();

int buscarProd(eProducto prod[],int tam, int id);
void publicarProducto(eProducto producto[],int tamProd, eUsuario user[],int tamUsuario);
void mostrarUsuarioYProductos(eUsuario users[],eProducto productos[], int tamUser, int tamProd);


int menuModificarUsuario();

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
