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
void listarProductos(eProducto prod[],int tamProd);
int buscarProv(eProveedor prov[],int tam, int id);
void cantProdConStockMayorADiez(eProducto prod[], int tam);
void cantProdConStockMenorADiez(eProducto prod[], int tam);

void mostrarProd(eProducto prod);
void altaProd(eProducto producto[],int tamProd, eProveedor prov[],int tamProv);

void mostrarProveedorDeterminadoYProductos(eProveedor prov[],eProducto prod[], int tamProv, int tamProd);

void listar(eProducto prod[],int tamProd, eProveedor prov[], int tamProv);
void informar(eProducto prod[],int tamProd);
void listar9(eProducto prod[],int tamProd,eProveedor prov[],int tamProv);
void listar10(eProducto prod[],int tamProd,eProveedor prov[],int tamProv);
void listar11(eProducto prod[],int tamProd, eProveedor prov[],int tamProv);
void listar12(eProducto prod[],int tamProd, eProveedor prov[],int tamProv);


/**
 * Obtiene el indice que coincide con el ID pasado por parametro.
 * @param prod el array se pasa como parametro.
* \param tam tamanio del array
 * @param ID el ID a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro id
 */

int buscarProd(eProducto prod[],int tam, int id);
void mostrarProveedorYProductos(eProveedor prov[],eProducto productos[], int tamProv, int tamProd);

/**
 *  Obtiene la opcion del menu elegida por el usuario
 * \return la opcion elegida por el usuario
 *
 */
int menuModificarProd();
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
