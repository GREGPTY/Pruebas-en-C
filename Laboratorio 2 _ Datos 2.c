//#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NULL 0
//Programa que carga los nodos de un árbol binario en memoria.
struct treenodo {
 struct treenodo *izqptr; //puntero al nodo izquierdo
 char dato[40]; //dato del nodo
 struct treenodo *derptr; }; // puntero al nodo derecho};
void crear(treenodo *nodo) //crea un Árbol binario
{
char resp[1];
clrscr();
cout<< "Introduzca el dato ";
gets (nodo->dato);
cout <<"Hay nodos a la Izquierda, introduzca S/N ";
gets(resp);
if (strcmp(resp, "S")= = 0) {
 nodo->izqptr= new (treenodo);
 crear(nodo->izqptr); }
else
 nodo->izqptr=NULL;
cout <<"Hay nodos a la Derecha, introduzca S/N ";
gets(resp);
if (strcmp(resp, "S")= = 0) {
 nodo->derptr = new (treenodo);
 crear(nodo->derptr); }
else
 nodo->derptr =NULL;
return;
}
void main(){
treenodo *nodo; // puntero al nodo
nodo= new treenodo;
crear (nodo);
getch();
}
