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
    printf("%d\t", elemento.dni);
    printf("%-40s", elemento.nombre);
    printf("%-5.2lf\t\t", elemento.saldo);
    if(elemento.tipoCliente=='C') printf("%s\n", "Cliente");
    else if(elemento.tipoCliente=='V')printf("%s\n", "Vip");
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

void modificar(Lista *pL){
    int cantModificaciones;
    char c;
    int i=0;
    printf("ingrese la cantidad de modificaciones\n");
    scanf("%d", &cantModificaciones);
    do{
        printf("ingrese lo que desea hacer: \n");
        scanf("%c", &c);
        if(c=='I'){           
            break;
        }
        if(c=='A'){
            ElementoLista elemento;
            double saldoActualizar;
            int dni;
            printf("Ingrese el dni y el saldo a actualizar: \n");
            scanf("%d %lf", &dni, &saldoActualizar); 
            elemento.dni= dni;
            actualizar(&pL, elemento, saldoActualizar);
            break;
        }
        if(c=='E'){
            ElementoLista elemento;
            int dni;
            printf("Ingrese el dni del cliente a eliminar: \n");
            scanf("%d", &dni);
            elemento.dni= dni;
            eliminarNodo(&pL, elemento);
            break;
        }
        i++;
    }while(i<cantModificaciones);  
}

InfoCliente cargarLista(int aux){
    FILE *archCli;
    archCli = abrirArchivo("Clientes.txt","r");    
    InfoCliente cliente;   
    char tipoCliente;
    double saldo;
    int dniCliente;
    char nombre[50];  
    int contador = 0;   
    while(1){
        fscanf(archCli,"%c",&tipoCliente);
        if(feof(archCli))break;
        fscanf(archCli,"%d",&dniCliente);
        fscanf(archCli,"%s",&nombre);
        fscanf(archCli,"%lf\n",&saldo);
        cliente.tipoCliente = tipoCliente;
        cliente.dni = dniCliente;
        cliente.nombre = strdup(nombre);
        cliente.saldo = saldo;
        if(contador == aux){
            return cliente;
        }
        contador++;
    } 
}

FILE *abrirArchivo(const char *nombre, const char *modo){
    FILE *arch;
    arch = fopen(nombre,modo);
    if(arch == NULL){
        printf("No se logro abrir el archivo\n");
        exit(1);
    }
}

void mostrar(Lista L){
    Nodo *pNodo;
    printf("%s\t\t%s\t\t\t%s\t\t%s \n","DNI","NOMBRE DEL CLIENTE","SALDO","TIPO DE CLIENTE");
    printf("------------------------------------------------------------------------------------------\n");
    if(esListaVacia(L))
        printf("La lista esta vacia\n");
    else
    {
        pNodo = L.cabeza; //con L accedo a cabeza y con cabeza accedo a nodo
        while ( pNodo != NULL )
        {
            imprime_elemento(pNodo->elemento); 
            pNodo = pNodo->sig;
        }
        printf("\n");
    }
}