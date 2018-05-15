#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "input.h"
#include "funciones.h"


typedef struct
{
    int idProveedor;
    char descripcion[51];
    int isEmpty;


} eProveedor;
typedef struct
{
    int idProd;
    char descripcion[51];
    float importe;
    int idProveedor;
    int stock;
    int isEmpty;


} eProducto;


/**
 *  Obtiene la opcion del menu elegida por el usuario
 * \return la opcion elegida por el usuario
 *
 */
int menu();
/**
 *  Obtiene la opcion del menu elegida por el usuario
 * \return la opcion elegida por el usuario
 *
 */
int menuModificarProd();

/**
 *  Obtiene la opcion del menu elegida por el usuario
 * \return la opcion elegida por el usuario
 *
 */

int menuInformar();


/** Inicializa el vector prod en 0 para poder hacer una carga aleatoria
 *
 * \param prod vector de productos
 * \param tam tamanio del vector productos se pasa por parametro
 */

void inicializarProductos(eProducto prod[], int tam);
/**
 *  Harcodeo de proveedores
 * \param recibe el vector de proveedores
 */

void hardCode(eProveedor proveedores[]);
/**
 * Obtiene el primer indice libre del array.
 * \param lista el array se pasa como parametro.
 * \param tam tamanio del array
 * @return el primer indice disponible
 */
int buscarLibreProd(eProducto prod[],int tam);
/** Lista los productos segun descripcion (ascendente)  e importe (descendente)
 *
 * \param prod el array se pasa por parametro
 * \param tam tamanio del array
 */

void listarProductos(eProducto prod[],int tamProd);
/**
 * Obtiene el indice que coincide con el ID pasado por parametro.
 * @param prov el array se pasa como parametro.
* \param tam tamanio del array
 * @param ID el ID a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro id
 */
int buscarProv(eProveedor prov[],int tam, int id);
/** Muestra la cantidad de productos con stock mayor a 10
 *
 * \param prod el array se pasa por parametro
 * \param tam tamanio del array
*/

void cantProdConStockMayorADiez(eProducto prod[], int tam);
/** Muestra la cantidad de productos con stock menor a 10
 *
 * \param prod el array se pasa por parametro
 * \param tam tamanio del array
*/
void cantProdConStockMenorADiez(eProducto prod[], int tam);

/** Muestra los productos con stock mayor a 10
 *
 * \param prod el array se pasa por parametro
 * \param tam tamanio del array
*/

void listarProdCantMayorADiez(eProducto prod[],int tam);
/** Muestra los productos con stock menor a 10
 *
 * \param prod el array se pasa por parametro
 * \param tam tamanio del array
*/
void listarProdCantMenorADiez(eProducto prod[],int tam);



/** Muestra un solo producto
 *
 * \param prod el array se pasa por parametro
*/


void mostrarProd(eProducto prod);
/** Muestra todos los producto
 *
 * \param vec el array se pasa por parametro
 * \param tam tamanio del array vec
*/


void mostrarProds(eProducto vec[], int tam);

/** Agrega un producto
 *
 * \param producto array se pasa por parametro
 * \param tamProd tamanio del array prod
 * \param prov array se pasa por parametro
 * \param tamProv tamanio del array prov
 */



void altaProd(eProducto producto[],int tamProd, eProveedor prov[],int tamProv);

/** Muestra los productos de un proveedor determinado
 *
 * \param prov el array se pasa por parametro
 * \param prod el array se pasa por parametro
 * \param tamProv tamanio del array prov
 * \param tamProd tamanio del array prod
*/


void mostrarProveedorDeterminadoYProductos(eProveedor prov[],eProducto prod[], int tamProv, int tamProd);
/** Muestra un submenu con las opciones
 *
 * \param prod el array se pasa por parametro
 * \param tamProd tamanio del array prod
 * \param prov el array se pasa por parametro
 * \param tamProv tamanio del array prov
 */


void listar(eProducto prod[],int tamProd, eProveedor prov[], int tamProv);
/** Muestra un submenu con las opciones
 *
 * \param prod el array se pasa por parametro
 * \param tamProd tamanio del array prod
 */
void informar(eProducto prod[],int tamProd);

/** Lista los prod del proveedor que provee mas productos
 *
 * \param prod el array se pasa por parametro
 * \param tamProd tamanio del array prod
 * \param prov el array se pasa por parametro
 * \param tamProv tamanio del array prov
 */

void listar9(eProducto prod[],int tamProd,eProveedor prov[],int tamProv);
/** Lista los prod del proveedor que provee menos productos
 *
 * \param prod el array se pasa por parametro
 * \param tamProd tamanio del array prod
 * \param prov el array se pasa por parametro
 * \param tamProv tamanio del array prov
 */

void listar10(eProducto prod[],int tamProd,eProveedor prov[],int tamProv);
/** Muestra el prod mas caro que provee un proveedor
 *
 * \param prod el array se pasa por parametro
 * \param tamProd tamanio del array prod
 * \param prov el array se pasa por parametro
 * \param tamProv tamanio del array prov
 */

void listar11(eProducto prod[],int tamProd, eProveedor prov[],int tamProv);
/** Muestra el prod mas barato que provee un proveedor
 *
 * \param prod el array se pasa por parametro
 * \param tamProd tamanio del array prod
 * \param prov el array se pasa por parametro
 * \param tamProv tamanio del array prov
 */
void listar12(eProducto prod[],int tamProd, eProveedor prov[],int tamProv);


/**
 * Obtiene el indice que coincide con el ID pasado por parametro.
 * @param prod el array se pasa como parametro.
* \param tam tamanio del array
 * @param ID el ID a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro id
 */

int buscarProd(eProducto prod[],int tam, int id);

/** Muestra todos los proveedores con sus productos
 *
 * \param prov el array se pasa por parametro
 * \param prod el array se pasa por parametro
 * \param tamProv tamanio del array prov
 * \param tamProd tamanio del array prod
 */

void mostrarProveedorYProductos(eProveedor prov[],eProducto productos[], int tamProv, int tamProd);



/** Modifica los campos de un producto
 *
 * \param prod el array se pasa por parametro
 * \param tamProd tamanio del array prod
 * \param prov el array se pasa por parametro
 * \param tamProv tamanio del array prov
 */

void modificaProd(eProducto prod[], int tamProd, eProveedor prov[],int tamProv);

/**
 * Borra a un prod del sistema

 * \param prov array se pasa por parametro
 *\param tamProv tamanio del array prov
 * \param prod array se pasa por parametro
 * \param tam tamanio que recibe el array se pasa por parametro
 */
void bajaProd(eProveedor prov[], int tamProv, eProducto prod[], int tamProd);






#endif // FUNCIONES_H_INCLUDED
