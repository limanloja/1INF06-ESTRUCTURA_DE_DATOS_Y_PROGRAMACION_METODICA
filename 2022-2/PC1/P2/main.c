#include <stdio.h>
#include <stdlib.h>
#include "lse.h"

int main() {
    int cantDatos = 4;
    Lista LA;
    construirLista(&LA);
    for(int i=0;i<cantDatos;i++){
        ElementoLista info;
        InfoCliente cliente = cargarLista(i);
        info = cliente;
        insertar_en_orden(&LA, info);
    }
    mostrar(LA);
    printf("\n");
    modificar(&LA);
    mostrar(LA);
    return 0;
}