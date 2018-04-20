#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
/** \sumar suma dos numeros tipo float
 *
 * \a primer numero que recibe tipo float
 * \b segundo numero que recibe tipo float
 * \return resultado de la suma
 *
 */


float sumar(float a, float b){

    float resultado;
        resultado = a + b;

    return resultado;
}
/** \restar  resta dos numeros tipo float
 * \c 1er numero tipo float
 * \d 2do numero tipo float
 * \return rsultado de la resta
 *
 */

float restar(float c, float d){
    float resultado;
        resultado = c-d;
    return resultado;

}
/** \division  divide dos numeros tipo float
 *
 * \e 1er nro tipo float
 * \f 2do nro tipo float
 * \return resultado de la division
 *
 */

float division (float e, float f){
    float resultado;

        resultado = e/f;

    return resultado;
  }
/** \multiplicacion   multiplica dos nros
 *
 * \g 1er nro float
 * \h 2do nro float
 * \return resultado de la multiplicacion
 *
 */

float multiplicacion(float g, float h){
    float resultado;

    resultado = g*h;
    return resultado;
}
/** \factorial  calcula el factorial de un nro
 *
 * \i unico nro tipo float que recibe
 *
 * \return resultado del factorial
 *
 */

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


