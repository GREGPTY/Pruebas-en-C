#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define NULL 0
using namespace std;  // reconoce el cin y cout
//Programa que crea una lista enlazada
struct nodo {
   char dato[40];
   struct nodo *sig;
};
void crear(nodo *principio)
{
cout<< "Entre el dato  Escriba FIN para terminar: ";
cin>> principio->dato;
if (strcmp(principio->dato, "FIN") == 0)
    principio->sig=NULL;
else {
    //reserva espacio para el siguiente nodo
   principio->sig= new nodo;
    crear(principio->sig);
    }
return;
}
void imprimir(nodo *principio) //Imprime la lista enlazada
{
   if(principio->sig != NULL){
      cout<<principio->dato<<endl;
      imprimir(principio->sig);
   }
   return;
}
main()
{
nodo *principio;   // puntero al principio de la lista
principio= new nodo;
system("cls");
crear (principio);
imprimir(principio);
getch();
}
