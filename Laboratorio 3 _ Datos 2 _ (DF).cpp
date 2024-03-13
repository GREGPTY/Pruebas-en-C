#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Nodo{
    char date;
    Nodo *Siguiente;};

struct treenodo {
 struct treenodo *izqptr; //puntero al nodo izquierdo
 char dato; //dato del nodo
 struct treenodo *derptr; }; // puntero al nodo derecho};
void agregarPila(Nodo *&,char);
void sacarPila(Nodo *&,char &);
void menu();
void PreOrden(treenodo *,Nodo *&);
void MostrarPila(Nodo *);

void crear(treenodo *nodo){ //crea un Árbol binario{
char resp[1];
cout<< "Introduzca el dato ";
cin>>nodo->dato;
cout <<"Hay nodos a la Izquierda, introduzca S/N ";
cin>>resp;
if (strcmp(resp,"S")== 0) {
 nodo->izqptr= new (treenodo);
 crear(nodo->izqptr); }
else
 nodo->izqptr=NULL;
cout <<"Hay nodos a la Derecha, introduzca S/N ";
gets(resp);
if (strcmp(resp,"S")== 0) {
 nodo->derptr = new (treenodo);
 crear(nodo->derptr); }
else
 nodo->derptr =NULL;
return;
}
//pila=Null;

void agregarPila(Nodo *&pila,char n){
        Nodo *nuevoNodo=new Nodo();
        nuevoNodo->date=n;
        nuevoNodo->Siguiente=pila;
        pila=nuevoNodo;
}
void sacarPila(Nodo *&pila,char &n){
    Nodo *aux=pila;
    n=aux->date;
    pila=aux->Siguiente;
    delete aux;
}
//void MostrarPila(Nodo *){

//}
void PreOrden(treenodo *nodo,Nodo *&pila){
    char n;
    treenodo *P= nodo;
    while(pila!=NULL){sacarPila(pila,n);}
    P=nodo;
    while(P!=NULL){
        cout<<P->dato;
        if((P->derptr)!=NULL){
            agregarPila(pila,P->dato);
        }
        if((P->izqptr)!=NULL){
            P=P->izqptr;
        }else{
            cout<<P->dato;
            sacarPila(pila,P->dato);
        }
    }

}
int main(){
    Nodo *pila=NULL;
    treenodo *nodo; // puntero al nodo
    nodo= new treenodo;
    char n,res;int op,num;
    do{menu();
    cin>>op;
    switch(op){
        case 1:
            crear(nodo);
        break;
        case 2:
            /*do{
            cout<<"agrega un elemento"<<endl;
            cin>>n;agregarPila(pila,n);
            cout<<"Salir? Y para salir, cualquier otro para seguir ";cin>>res;
            }while(res!='y');*/
        break;
        case 3:
            while(pila!=NULL){
                    sacarPila(pila,n);
                if(pila!=NULL){
                    cout<<n<<" , ";
                }else{
                    cout<<n<<".";
                }}
            break;
        case 4:
                cout<<"Cuantos elementos desea eliminar?"<<endl;
                cin>>num;
                for(int e=1;e<=num;e+=1){
                if(pila!=NULL){
                    sacarPila(pila,n);
                if(pila!=NULL){
                    cout<<n<<" , ";
                }else{
                    cout<<n<<"."<<endl;
                }}
                else{cout<<"Lista Vacia"<<endl;break;}
                }
            break;
        case 5:
            PreOrden(nodo,pila);
            break;
        case 6:
            break;
        default:cout<<"Opcion No Valida"<<endl;break;
    }}while(op!=6);
    return 0;
}
void menu(){
    cout<<"\n1. Agregar datos al arbol\n2.Agregar a la pila 1 elemento \n3. Eliminar toda la pila\n4. Eliminar n elemento en la pila\n5. PreOrden\n6. Salir\nOpcion:"<<endl;
}
