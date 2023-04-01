/* 
 * File:   funcion.h
 * Author: Luis Angel Iman Loja
 * Codigo: 20195861
 * Created on 22 de setiembre de 2022, 17:29
 */

#ifndef FUNCION_H
#define FUNCION_H

typedef struct pollo{
    int codigo;
    char *fecha;
    double peso;
    char *tipo;
}Pollo;

typedef Pollo ElementoPollo;

typedef struct nodo{
    ElementoPollo elemento;
    struct nodo *sig;
} Nodo;

typedef struct cola{
    Nodo *cabeza;
    Nodo *final;
    int longitud;
} Cola;

typedef struct pila{
	Nodo* cima;
	int longitud;
}Pila;


void leerArchivoEncolar(Cola *tad);
void construirCola(Cola *tad);
int esColaVacia (Cola tad);
Nodo *crearNuevoNodoCola(ElementoPollo elemento);
Nodo* creaNuevoNodoPila(ElementoPollo elemento,Nodo* sig);
void encolar(Cola *tad, ElementoPollo elemento);
void mostrarCola (Cola tad);
ElementoPollo desencolar(Cola *tad);
void clasificarPollos(ElementoPollo *elemento);
int esPilaVacia(Pila tad);
void construiPila(Pila *tad);
void apilar (Pila *tad, ElementoPollo elemento);
ElementoPollo desapilar(Pila *tad);
void mostrarPila(Pila tad);
void distribuirBandas(Cola *queue1, Cola *queue2, Cola *queue3, ElementoPollo elemento);
void imprimirReporte(Cola queue1, Cola queue2, Cola queue3);

#endif /* FUNCION_H */

