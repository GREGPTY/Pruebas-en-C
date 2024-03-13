#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int dato,canti;
    char lugar[50];
    Nodo *sisguiente;
};

Nodo *lista=NULL;
void menu();
void MostrarLista(Nodo *);
void InsertarLista(Nodo *&,int,int);
void BuscarElemento(Nodo *,int);
void EliminarElemento(Nodo *&,int);
void EliminarLista(Nodo *&,int &);

int main(){
    char Place[8][30]={{"Eclipse_Towers"},{"Maze_Bank"},{"Diamond_Casino"},{"LA_Airport"},{"Santa_Monica_State_Beach"},{"Maze_Bank_Arena"},{"Beverly_Hills"},{"Little_Seoul"}};
    int op,data,n;
    char r,name[50];
    system("color 0d");
    do{
    menu();cin>>op;
    switch(op){
    case 1:
    do{
    cout<<"Introduce a Number, and a Name"<<endl;
    cin>>data;
    cin>>name[50];
    InsertarLista(lista,data,name[50]);
    cout<<"Exit? \nNot... Press Anything Character and Press ENTER \nPress 'y' For go out..."<<endl;
    cin>>r;
    system("pause");system("cls");
    }while(r != 'y');
    break;
    case 2: MostrarLista(lista);
        break;
    case 3:
        cout<<"Element to Find"<<endl;
        cin>>n;
        BuscarElemento(lista,n);
        break;
    case 4:
        cout<<"Element to Delete"<<endl;
        cin>>n;
        EliminarElemento(lista,n);
        break;
    case 5:
            while(lista!=NULL){
                EliminarLista(lista,n);
                cout<<data<<"->";
            }
            system("pause");
        break;
    case 6: cout<<"Bye"<<endl;
        break;
    default: cout<<"Invalid Option, Try Again"<<endl; break;
    }system("pause");system("cls");
    }while(op!=6);
    getche();
    return 0;
}
void menu(){
        cout<<"\n\t\tMenu: \n1. Add Numbers \n2. See Elements on list\n3. Find a Element\n4. Delete a Element"<<endl;
        cout<<"5. Delete All the Elements 6.\n Exit\n"<<endl;
    }

void InsertarLista(Nodo *&lista,int n,int canti){
    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->canti;

    Nodo *aux1=lista;
    Nodo *aux2;//lo necesitamos si entra al while

    while((aux1!=NULL)&&(aux1->dato < n)){//solo lo ordenara si el numero es mayor o menor
        aux2=aux1;
        aux1=aux1->sisguiente;
    }
    if(lista == aux1){ //se hara si esta al principio de la lista
        lista=nuevo_nodo;
    }
    else{
        aux2->sisguiente=nuevo_nodo;//entro al while...
    }
    nuevo_nodo->sisguiente=aux1;
    cout<<"Element '"<<n<<"' Insert \n"<<endl;
}
void MostrarLista(Nodo *lista){
    Nodo *actual=new Nodo();

    actual=lista;
    while(actual !=NULL){
        cout<<actual->dato<<" -> ";
        actual=actual->sisguiente;
    }
}
void BuscarElemento(Nodo *lista,int n){
    bool band =false;

    Nodo *actual=new Nodo();
    actual = lista;
    int f=0;
    while((actual !=NULL)&&(actual->dato <= n)){ //Solo porque esta ordenado le agregue: actual->dato<=n
        if(actual->dato==n){
            band=true;}
        actual= actual->sisguiente;
    f+=1;
    }
    if(band==true){
        cout<<"Number '"<<n<<"' Was Found on Position ["<<f<<"] \n"<<endl;
    }
    else{
        cout<<"Element Not Found \n"<<endl;
    }
}
void EliminarElemento(Nodo *&lista,int n){
    if(lista!=NULL){
        Nodo *aux_borrar;
        Nodo *anterior=NULL;
        aux_borrar=lista;

        while((aux_borrar!=NULL)&&(aux_borrar->dato!=n)){
            anterior=aux_borrar;
            aux_borrar=aux_borrar->sisguiente;
        }
        if(aux_borrar==NULL){
            cout<<"The Element Does Not Exist"<<endl;
        }else if(anterior==NULL){
            lista=lista->sisguiente;
            delete aux_borrar;      cout<<"The Element Has Been Deleted"<<endl;
        }else{
            anterior->sisguiente=aux_borrar->sisguiente;
            delete aux_borrar;      cout<<"The Element Has Been Deleted"<<endl;
        }
    }
    else{
        cout<<"Empty List"<<endl;
    }
}
void EliminarLista(Nodo *&Lista,int &n){

    Nodo *aux=lista;
    n=aux->dato;
    lista = aux->sisguiente;
    delete aux;
}
