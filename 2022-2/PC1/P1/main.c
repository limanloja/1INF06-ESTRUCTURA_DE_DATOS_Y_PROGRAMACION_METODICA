/*
*Author: R. Taipe
*/

#include <stdio.h>
#include <stdlib.h>
#include "lse.h"

int main() {
    Lista L1;
    construirLista(&L1);
    int n=5;
    for(int i=0;i<n;i++){       //puede cambiar el n para la cantidad de datos que se desea agregar a la lista
        ElementoLista info;
        InfoCliente cliente = cargarCliente();
        info= cliente;
        insertar_en_orden(&L1, info);
    }  
    imprimeLista(L1);
    return 0;
}

/*PRUEBE LOS DATOS CON INSERCION EN CONSOLA*/
/*EJEMPLO*/

/*
123
Renato
12.3
C
1234
Pedro
10.23
V
1235
Luis
12.3
C
1236
Valeria
100.34
V
1237
Inca
121.2
C 
 */