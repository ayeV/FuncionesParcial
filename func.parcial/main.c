#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//Me pide que ponga los headers aca
float sumar(float a, float b);
int main()
{

    float x=100;
    float y=2;
    float rta=0;

    rta= sumar(x,y);
    printf("suma: %.2f",rta);


    return 0;
}

