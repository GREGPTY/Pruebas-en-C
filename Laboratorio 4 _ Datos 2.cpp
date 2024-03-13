#include<iostream>
#include<conio.h>
#include<stdlib.h>
//Greg Torres, Miguel Vazquez.
using namespace std;
struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};
void menu();
Nodo *crearNodo(int,Nodo *);
void mostrarArbol(Nodo *,int);
void insertarNodo(Nodo *&,int, Nodo *);
Nodo*arbol=NULL;
void preOrden(Nodo *);
void InOrden(Nodo *);
void PostOrden(Nodo *);

Nodo *crearNodo(int n, Nodo *padre){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->der=NULL;
    nuevo_nodo->izq=NULL;
    nuevo_nodo->padre=padre;
    return nuevo_nodo;
}
void insertarNodo(Nodo *&arbol, int n, Nodo *padre){
    if(arbol==NULL){
        Nodo *nuevo_nodo=crearNodo(n,padre);
        arbol=nuevo_nodo;
    }
    else{
        int valorRaiz=arbol->dato;
        if(n<valorRaiz){
            insertarNodo(arbol->izq,n,arbol);
        }else if(n>valorRaiz){
            insertarNodo(arbol->der,n,arbol);
        }else{
            cout<<"Dato ya existente"<<endl;
        }
    }

}
void mostrarArbol(Nodo *arbol, int cont){
 if(arbol==NULL){
    return;
 }
 else{
    mostrarArbol(arbol->der,cont+1);
    for(int i=0;i<cont;i+=1){
        cout<<"   ";
    }
    cout<<arbol->dato<<endl;
    mostrarArbol(arbol->izq,cont+1);
 }
 }
 void preOrden(Nodo *arbol){
    if(arbol==NULL){ //si el arbol esta vacio solo retorna
        return;
    }
    else{
        cout<<arbol->dato<<" - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
 }
 void InOrden(Nodo *arbol){
     if(arbol==NULL){
        return;
     }
     else{
        InOrden(arbol->izq);
        cout<<arbol->dato<<" - ";
        InOrden(arbol->der);
     }
 }
 void PostOrden(Nodo *arbol){
     if(arbol==NULL){
        return;
     }
     else{
        PostOrden(arbol->izq);
        PostOrden(arbol->der);
        cout<<arbol->dato<<" - ";
     }
 }

int main(){
    system("color 0d");
    menu();

    getche();
    return 0;
}
void menu(){
    int dato,opcion,contador=0;;
    do{
        cout<<"\t Menu"<<endl;
        cout<<"1. Insertar un nuevo nodo "<<endl;
        cout<<"2. Mostrar el arbol"<<endl;
        /*cout<<"3. Elemento a Buscar"<<endl;*/
        cout<<"3. Recorrido del Arbol"<<endl;
        /*cout<<"5. Eliminar un Nodo"<<endl;*/
        cout<<"4. Salir"<<endl;
        cout<<"Opcion: "<<endl;
        cin>>opcion;
        switch(opcion){
        case 1: cout<<"\n Digite un Numero entero: ";
                    cin>>dato;
                    insertarNodo(arbol,dato,NULL);//insertamos un nuevo nodo
                    cout<<"\n";
                    system("pause");
                    break;
        case 2:
            cout<<"\n\nMostrando el Arbol\n\n"<<endl;
                  mostrarArbol(arbol,contador);
                  system("pause");
                break;
        case 3:
            int op2;
            do{
            cout<<"En que orden desea hacer el recorrido \n1. Pre-Order\t2.In-Order\t3. Post-Order\nFor Exit press '4'\n"<<endl;
            cin>>op2;
            switch(op2){
                case 1: preOrden(arbol);
                        system("pause");
                        break;
                case 2: InOrden(arbol);
                        system("pause"); break;
                case 3: PostOrden(arbol);
                        system("pause"); break;
                case 4: break;
                default: cout<<"Option No Available"<<endl;
            }}while(op2!=4);
             break;
        case 4: break;
        default: cout<<"Opcion no Valida, Digite otro";
            break;
        }
    system("cls");
    }while(opcion !=4);
}
