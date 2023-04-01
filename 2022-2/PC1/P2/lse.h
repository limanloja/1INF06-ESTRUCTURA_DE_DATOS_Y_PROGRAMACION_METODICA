/*
*Author: R. Taipe
*/

#ifndef LSE_H
#define LSE_H

typedef struct{
    char tipoCliente;
    int dni;
    char *nombre;
    double saldo;    
}InfoCliente;

typedef InfoCliente ElementoLista;

typedef struct nodo{
    ElementoLista elemento; 
    struct nodo *sig;       
}Nodo;  

typedef struct lista{
    int longitud;
    Nodo *cabeza;
}Lista;     

void construirLista(Lista *);
int esListaVacia( Lista );
Nodo* crearNuevoNodo(ElementoLista , Nodo *);
Nodo* obtenerNodoAnterior( Lista , ElementoLista );
Nodo* obtenerUltimoNodo( Lista );
void insertar_en_orden(Lista *, ElementoLista );
void destruirLista( Lista * );
Nodo* obtenerNodo(Lista , ElementoLista );
void eliminarNodo( Lista *, ElementoLista );
void imprime_elemento(ElementoLista );
void actualizar(Lista *, ElementoLista , double );
void modificar(Lista *);
void mostrar( Lista );
FILE *abrirArchivo(const char *, const char *);
InfoCliente cargarLista (int);
#endif



