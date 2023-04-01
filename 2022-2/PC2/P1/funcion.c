/* 
 * File:   funcion.c
 * Author: Luis Angel Iman Loja
 * Codigo: 20195861
 * Created on 22 de setiembre de 2022, 17:29
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcion.h"

void leerArchivoEncolar(Cola *tad){
    FILE *archPollo;
    archPollo = fopen("Pollos.txt", "r");
    int codigo;
    char fecha[20];
    double peso;
    Pollo pollo;
    while(1){
        fscanf(archPollo,"%d %s %lf",&codigo,fecha,&peso);
        if(feof(archPollo)) break;
        pollo.codigo = codigo;
        pollo.fecha = strdup(fecha);
        pollo.peso = peso;
        encolar(tad, pollo);
    }
}

void construirCola(Cola *tad){
    tad -> cabeza = NULL;
    tad -> final = NULL;
    tad -> longitud = 0;
}

int esColaVacia (Cola tad){
    return tad.cabeza == NULL;
}

Nodo *crearNuevoNodoCola(ElementoPollo elemento){
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo -> elemento = elemento;
    pNuevoNodo -> sig = NULL;
    return pNuevoNodo;
}

void encolar(Cola *tad, ElementoPollo elemento){
    Nodo *pNuevoNodo;
    Nodo *pFinal;
    pNuevoNodo = crearNuevoNodoCola (elemento);
    if(esColaVacia(*tad)){
	tad -> cabeza = pNuevoNodo;
    }else{
	pFinal = tad->final;
	pFinal -> sig = pNuevoNodo;
    }
    tad -> final = pNuevoNodo;
    tad -> longitud++;
}

ElementoPollo desencolar(Cola *tad){
    Nodo *pNodo;
    ElementoPollo elemento;
    pNodo = tad -> cabeza;
    elemento = pNodo -> elemento;
    tad -> cabeza = pNodo -> sig;
    if(tad -> cabeza == NULL)
	tad -> final = NULL;
    free(pNodo);
    tad -> longitud--;
    return elemento;
}

void mostrarCola (Cola tad){
    Nodo *pNodo;
    int estaImprimiendoCabeza = 1;
    if(esColaVacia(tad))
    	printf("Cola vacía\n");
    else{
	pNodo = tad.cabeza;
	while(pNodo != NULL){
            if(!estaImprimiendoCabeza)
		printf("\n");
            estaImprimiendoCabeza = 0;
            printf("%d\t%s\t%.02lf",pNodo->elemento.codigo,pNodo->elemento.fecha, 
                    pNodo->elemento.peso);
            pNodo = pNodo -> sig; 
	}
    	printf("\n\n");
    }
}

Nodo* creaNuevoNodoPila(ElementoPollo elemento,Nodo* sig){
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo -> elemento = elemento;
    pNuevoNodo -> sig = sig;
    return pNuevoNodo;
}


void construiPila(Pila *tad){
    tad->cima = NULL;
    tad->longitud = 0;
}

int esPilaVacia(Pila tad){
    return tad.cima == NULL;
}

void clasificarPollos (ElementoPollo *elemento){
    if((*elemento).peso<=1){
        (*elemento).tipo = "Tuttus";
    }else if((*elemento).peso>1 && (*elemento).peso<=1.8){
        (*elemento).tipo = "Morkys";
    }else if((*elemento).peso>=1.8){
       (*elemento).tipo = "Don tico";
    }
}

void apilar (Pila *tad, ElementoPollo elemento){
    Nodo *pNuevoNodo;
    pNuevoNodo = creaNuevoNodoPila(elemento,tad->cima);
    tad->cima = pNuevoNodo;
    tad->longitud++;
}

ElementoPollo desapilar(Pila *tad){
    Nodo *pNodo;
    ElementoPollo elemento;
    pNodo = tad -> cima;
    elemento = pNodo -> elemento;
    tad -> cima = pNodo -> sig;
    tad -> longitud--;
    free(pNodo);
    return elemento;
}

void mostrarPila(Pila tad){
    Nodo *pNodo;
    int estaImprimiendoCabeza = 1;
    if (esPilaVacia(tad))
	printf("Pila vacia\n");
    else{
	printf("[ ");
	pNodo = tad.cima;
        while(pNodo != NULL){
            if(!estaImprimiendoCabeza)
		printf(", \n");
                estaImprimiendoCabeza = 0;
                printf("%d %s %.02lf %s",pNodo->elemento.codigo,
                        pNodo->elemento.fecha, pNodo->elemento.peso,
                        pNodo->elemento.tipo);
		pNodo = pNodo -> sig;
            }
        printf("]\n");
    }
}

void distribuirBandas(Cola *queue1, Cola *queue2, Cola *queue3, ElementoPollo elemento){
    if(elemento.tipo == "Tuttus"){
        encolar(queue1,elemento);
    }else if(elemento.tipo == "Morkys"){
        encolar(queue2,elemento);
    }
    else if(elemento.tipo == "Don tico"){
        encolar(queue3,elemento);
    }
}

void imprimirReporte(Cola queue1, Cola queue2, Cola queue3){
    printf("Tipos: Tuttus\n");
    printf("Codigo\t   Fecha\tPeso\n");
    printf("===========================================\n");
    mostrarCola(queue1);
    printf("Tipos: Morkys\n");
    printf("Codigo\t   Fecha\tPeso\n");
    printf("===========================================\n");
    mostrarCola(queue2);
    printf("Tipos: Don tico\n");
    printf("Codigo\t   Fecha\tPeso\n");
    printf("===========================================\n");
    mostrarCola(queue3);
}