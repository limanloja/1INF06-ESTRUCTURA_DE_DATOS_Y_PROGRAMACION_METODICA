/* 
 * File:   main.c
 * Author: Luis Angel Iman Loja
 * Codigo: 20195861
 * Created on 22 de setiembre de 2022, 17:29
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcion.h"

/*
 * 
 */

int main(int argc, char** argv) {
    Cola queue, queue1, queue2, queue3;
    Pila stack1, stack2;
    ElementoPollo elemento, elementoPila;
    construirCola(&queue);
    construirCola(&queue1);
    construirCola(&queue2);
    construirCola(&queue3);
    construiPila(&stack1);
    construiPila(&stack2);
    leerArchivoEncolar(&queue);
    //printf("Banda transportadora:\n");
    //mostrarPila(queue);
    while(!esColaVacia(queue)){
        elemento = desencolar(&queue);
        clasificarPollos(&elemento);
        apilar(&stack1,elemento);
    }
    //printf("Contenedor 1\n");
    //mostrarPila(stack1);
    while(!esPilaVacia(stack1)){
        elementoPila = desapilar(&stack1);
        apilar(&stack2,elementoPila);
    }
    //printf("Contenedor 2\n");
    //mostrarPila(stack2);
    while(!esPilaVacia(stack2)){
        elementoPila = desapilar(&stack2);
        distribuirBandas(&queue1, &queue2, &queue3, elementoPila);
    }
    imprimirReporte(queue1, queue2, queue3);
    return (EXIT_SUCCESS);
}

