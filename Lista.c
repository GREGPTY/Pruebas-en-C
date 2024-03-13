
#include <stdlib.h>
#include <string.h>
#define NULL 0

typedef struct Libro{
    char titulo[50];
    char autor[50];
    char isbn[13];
};
typedef struct Nodo{
    Libro libro; //el nodo guardara un libro
    struct Nodo* siguiente; //un puntero al siguiente nodo
}; //creando mis nodos

typedef struct Lista {
    Nodo* cabeza;//guarda el nodo a la cabeza
    int longitud;
};

Nodo* CrearNodo(Libro* libro){
    Nodo* nodo =(Nodo *)malloc(sizeof (Nodo));//el tamaño del nodo
    strncpy(nodo->libro.titulo,libro->titulo,50);
    strncpy(nodo->libro.autor,libro->autor,50);
    strncpy(nodo->libro.isbn,libro->isbn,13);
    nodo->siguiente=NULL;
    return nodo;
}
void DstruirNodo(Nodo* nodo){
    free(nodo);
    return;
}
void InsertarPrincipio(Lista* lista, Libro* libro){
    Nodo* nodo= CrearNodo(libro);
    nodo->siguiente =lista->cabeza;
    lista->cabeza =nodo;
    lista->longitud+=1;
    }
void InsertarFinal(Lista* lista, Libro* libro){
    Nodo* nodo= CrearNodo(libro);
    if(lista->cabeza == NULL){//solo miro si la lista esta vacia
        lista->cabeza=nodo;
    }
    else{
        Nodo* puntero =lista->cabeza;
        while(puntero->siguiente){//cuando llegamos al ultimo del bucle como no tiene siguiente saldra
        puntero=puntero->siguiente;
        }
    puntero->siguiente=nodo;
    }
    lista->longitud+=1;
}
void InsertarDespues(int n, Lista* lista, Libro* libro){//insertar despues de n "libros"
    Nodo* nodo = CrearNodo(libro);
    if(lista->cabeza == NULL){//solo miro si la lista esta vacia
        lista->cabeza=nodo;}
    else{
        Nodo* puntero =lista->cabeza;
        int posicion = 0;
        while(posicion < n && puntero->siguiente){//cuando llegamos al ultimo del bucle como no tiene siguiente saldra
            puntero=puntero->siguiente;
            posicion+=1;
        }
        nodo->siguiente = puntero->siguiente; //primero lo conectamos por la derecha
        puntero->siguiente=nodo; //y luego lo conectamos por la izquierda
    }
    lista->longitud+=1;
}
Libro* Obtener(int n, Lista* lista){
    if(lista->cabeza == NULL){//solo miro si la lista esta vacia
        return NULL;
    }else{
        Nodo* puntero =lista->cabeza;
        int posicion = 0;
        while(posicion < n && puntero->siguiente){//cuando llegamos al ultimo del bucle como no tiene siguiente saldra
            puntero=puntero->siguiente;
            posicion+=1;
        }
        if(posicion != n){
            return NULL; //no hay la suficiente cantidad de libros
        }else{
        return &puntero->libro;}
}
int Contar(Lista* lista){
    return lista->longitud;
}
int EstaVacia(Lista* lista){
    return lista->cabeza==NULL;
}
void EliminarPrincipio(Lista* lista){
   if(lista->cabeza){
    Nodo* eliminado =lista->cabeza;
    lista->cabeza=lista->cabeza->siguiente;//hago que ahora el 2do elemento sea la cabeza de mi lista
    DestruirNodo(eliminado);
    lista->longitud-=1;
   }
}
void EliminarUltimo(Lista* lista){
    if(lista->cabeza){
        Nodo* puntero = lista->cabeza;
        while(puntero->siguiente->siguiente){//asi nos detendremos en el penultimo elemento
            puntero= puntero->siguiente;
        }
        Nodo* eliminado= puntero->siguiente;
        puntero->siguiente=NULL;
        DestruirNodo(eliminado);
        lista->longitud-=1;
    }else{
        Nodo* eliminado = lista->cabeza;
        lista->cabeza=NULL;
        DestruirNodo(eliminado);
        lista->longitud-=1;
    }
}
void EliminarElemento(int n,Lista* lista){
    if(lista->cabeza){
        if(n==0){
            Nodo* eliminado = lista->cabeza;
            lista->cabeza=lista->cabeza->siguiente;
            DestruirNodo(eliminado);
            lista->longitud-=1;
        }else if(n<lista->longitud){
            Nodo* puntero=lista->cabeza;
            int posicion=0;
            while(posicion<(n-1)){
            puntero=puntero->siguiente;
            posicion+=1;
            }
            Nodo* eliminado=puntero->siguiente;
            puntero->siguiente=eliminado->siguiente;
            DestruirNodo(eliminado);
            lista->longitud-=1;
        }}}

void main(){
	int num,op;
	char lib,aut;
	printf("Que opci%cn desea hacer?",162);
	scanf("%i",&op);
	switch(op){
	case 1:
	printf("Opci%cn 1...",162);
	break;
	default:
	printf("Opci%cn no Valida... intente con otra opci%cn",162,162);
	break;
	}
}
