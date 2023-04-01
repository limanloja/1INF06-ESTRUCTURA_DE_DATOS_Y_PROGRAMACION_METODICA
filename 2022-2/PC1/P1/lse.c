/*
*Author: R. Taipe
*/

#include <stdio.h>
#include <stdlib.h>
#include "lse.h"
#include <string.h>
#define MAX_BUFFER 50

void construirLista(Lista *pL )
{
    pL->cabeza = NULL;
}

int esListaVacia( Lista L )
{
    return L.cabeza == NULL;
} 

Nodo* crearNuevoNodo(ElementoLista elemento, Nodo *sig )
{
    Nodo *pNuevoNodo;
    pNuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    pNuevoNodo->elemento = elemento;
    pNuevoNodo->sig = sig;
    return pNuevoNodo;
}

Nodo* obtenerNodoAnterior( Lista L, ElementoLista valor)
{
    Nodo *pNodo, *pAnterior;
    pAnterior = NULL;
    pNodo = L.cabeza;
    while ( pNodo != NULL )
    {
        if( pNodo->elemento.dni == valor.dni)
            break;
        pAnterior = pNodo;
        pNodo = pNodo->sig;
    }
    return pAnterior;
}

Nodo* obtenerUltimoNodo( Lista L )
{
    Nodo *pNodo, *pUltimo;
    pUltimo = NULL;
    pNodo = L.cabeza;
    while( pNodo != NULL )
    {
        pUltimo = pNodo;
        pNodo = pNodo->sig;
    }
    return pUltimo;
} 

void insertar_en_orden(Lista *pL, ElementoLista elemento){
    Nodo *pNuevoNodo = crearNuevoNodo(elemento, NULL);     
    Nodo *pRecorrido= pL->cabeza;
    Nodo *pUltimo= obtenerUltimoNodo(*pL);
    if (esListaVacia(*pL)){
        pNuevoNodo->sig=pL->cabeza;
        pL->cabeza=pNuevoNodo;
    }else{    
        if(elemento.tipoCliente=='C'){
            while(1){
                Nodo *pAnterior = obtenerNodoAnterior(*pL, pRecorrido->elemento);  
                if(pRecorrido->elemento.tipoCliente=='V'){
                    pNuevoNodo->sig= pRecorrido;
                    if(pAnterior==NULL){
                        pL->cabeza= pNuevoNodo;
                    }else{
                        pAnterior->sig= pNuevoNodo;
                    }      
                    break;
                }
                else{
                    if(pRecorrido->elemento.saldo>elemento.saldo){
                        if(pRecorrido->sig!=NULL){
                            pRecorrido= pRecorrido->sig;
                        }
                        else{
                            pRecorrido->sig= pNuevoNodo;
                            break;
                        }
                    }else{
                        pNuevoNodo->sig=pRecorrido;
                        if(pAnterior==NULL){
                            pL->cabeza=pNuevoNodo;
                        }
                        else
                            pAnterior->sig= pNuevoNodo;
                        break;
                    }                  
                }            
            }
        }else if(elemento.tipoCliente=='V'){
            pRecorrido=pUltimo;
            while(1){
                Nodo *pAnterior = obtenerNodoAnterior(*pL, pRecorrido->elemento);
                if(pRecorrido->elemento.tipoCliente=='C'){
                    pNuevoNodo->sig=pRecorrido->sig;
                    pRecorrido->sig=pNuevoNodo;                   
                    break;
                }         
                else{
                    if(pRecorrido->elemento.saldo<elemento.saldo){
                        pRecorrido= pAnterior;
                    }
                    else{
                        pNuevoNodo->sig=pRecorrido->sig;
                        pRecorrido->sig=pNuevoNodo;
                        break;
                    }
                }
            }
        }     
    }
}

void destruirLista( Lista *pL )
{
    Nodo *pNodo, *pAux;
    pNodo = pL->cabeza;
    while ( pNodo != NULL )
    {
        pAux = pNodo->sig;
        free(pNodo);
        pNodo = pAux;
    }
    pL->cabeza = NULL;
    printf("Todos los nodos han sido eliminados\n");
} 

Nodo* obtenerNodo(Lista L, ElementoLista valor)
{
    Nodo *pNodo;
    pNodo = L.cabeza;   
    while ( pNodo != NULL )
    {
        if(valor.dni == pNodo->elemento.dni)
            break;
        pNodo = pNodo->sig;
    }
    return pNodo;
}

void eliminarNodo( Lista *pL, ElementoLista valor )
{
    Nodo *pNodoEliminar, *pAnterior;
    pNodoEliminar = obtenerNodo( *pL, valor);
    if ( pNodoEliminar == NULL )
        printf("");
    else
    {
        pAnterior = obtenerNodoAnterior(*pL, valor);
        if (pAnterior == NULL)
            pL->cabeza = pNodoEliminar->sig;
        else
            pAnterior->sig =pNodoEliminar->sig;
        free(pNodoEliminar);
    }
} 

void imprime_elemento(ElementoLista elemento){
    printf("%d\t\t", elemento.dni);
    printf("%s\t", elemento.nombre);
    printf("%20.2lf\t", elemento.saldo);
    if(elemento.tipoCliente=='C') printf("%-10s\n", "Cliente");
    else if(elemento.tipoCliente=='V')printf("%-10s\n", "Vip");
}

void imprimeLista(Lista L){
    Nodo *pRecorrido;
    pRecorrido= L.cabeza;
    printf("%s\t\t%s\t%s\t%s\t \n","DNI","NOMBRE DEL CLIENTE","SALDO","TIPO DE CLIENTE");
    while(pRecorrido!=NULL){
        imprime_elemento(pRecorrido->elemento);
        pRecorrido=pRecorrido->sig;
    }
    printf("\n");
}

void actualizar(Lista *pL, ElementoLista valor, double saldoActualizado){
    Nodo *nodoActualizar = pL->cabeza;
    while(nodoActualizar!=NULL){
        if(nodoActualizar->elemento.dni==valor.dni){
            nodoActualizar->elemento.saldo = saldoActualizado;
        }
        else
            nodoActualizar=nodoActualizar->sig;
    }   
}    //funcion que actualiza el saldo
/*
void modificaciones(Lista *pL, char c){
    if(c=='I'){
        ElementoLista info;
        InfoCliente informacion= cargarCliente();
        info=informacion;
        insertar_en_orden(*pL, info);
    }
}
*/
InfoCliente cargarCliente(){
    int dni;
    char nombre[MAX_BUFFER];
    double saldo;
    char tipo;
    scanf("%d\n",&dni);
    lee_cadena(nombre);
    scanf("%lf %c",&saldo,&tipo);
    InfoCliente infoCliente;
    infoCliente.dni = dni;
    infoCliente.nombre=strdup(nombre);
    infoCliente.saldo= saldo;
    infoCliente.tipoCliente = tipo;
    return infoCliente;
}
void lee_cadena(char *buffer){
    fgets(buffer, MAX_BUFFER, stdin);
    buffer[strlen(buffer)-1]='\0';        
}