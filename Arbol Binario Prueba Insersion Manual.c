#include<iostream>
#include<conio.h>
#include<stdlib.h>
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
bool busqueda(Nodo *,int);
void preOrden(Nodo *);
void InOrden(Nodo *);
void PostOrden(Nodo *);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruirNodo(Nodo *);

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
        }else{
            insertarNodo(arbol->der,n,arbol);
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
 bool busqueda(Nodo *arbol,int n){
    if(arbol==NULL){
        return false;
    }
    else if(arbol-> dato==n){
        return true;
    }
    else if(n<arbol->dato){
        return busqueda(arbol->izq,n);
    }
    else {
        return busqueda(arbol->der,n);
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
 void eliminar(Nodo *arbol,int n){
    if(arbol==NULL){
        return;
    }
    else if(n < arbol->dato){//si es menor busca por la izquierda
        eliminar(arbol->izq,n);
    }
    else if(n> arbol->dato){//si es mayor busca por la derecha
        eliminar (arbol->der,n);
    }
    else{
        eliminarNodo(arbol); //si ya lo encuentras eliminalo pero...
    }
 }
 void eliminarNodo(Nodo *nodoEliminar){ //pero debes cumplir estas condiciones para eliminarlo
    if((nodoEliminar->izq)&&(nodoEliminar->der)){ //Si el nodo tiene 2 hijos
        Nodo *menor = minimo(nodoEliminar->der);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    }
    else if(nodoEliminar->izq){//si tiene hijo izq
            reemplazar(nodoEliminar,nodoEliminar->izq);
            destruirNodo(nodoEliminar);
    }
    else if(nodoEliminar->der){
        reemplazar(nodoEliminar,nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }
    else{ //nodo sin hijos
        reemplazar(nodoEliminar,NULL);
        destruirNodo(nodoEliminar);
    }
 }
 //funcion para determinar el nodo mas izquiera posible
Nodo *minimo(Nodo *arbol){
    if(arbol ==NULL){//Si el arbol esta vacio
        return NULL;
    }
    else if(arbol->izq){//si tiene hijo izquierdo
        return minimo(arbol->izq);
    }else{//si no tiene hijo izquierdo
    return arbol;
    }
}
//funcino paa reemplazar 2 nodos
void reemplazar(Nodo *arbol,Nodo *nuevoNodo){
    if(arbol->padre){
        //hay que asignarle su nuevo hijo
        if(arbol->dato== arbol->padre->izq->dato){
            arbol->padre->izq=nuevoNodo;
        }else if(arbol->dato==arbol->padre->der->dato){
            arbol->padre->der=nuevoNodo;
        }
    }
    if(nuevoNodo){
                    //hay que asignarle su nuevo padre
        nuevoNodo->padre=arbol->padre;
    }
}
void destruirNodo(Nodo *nodo){
    nodo->izq=NULL;
    nodo->der=NULL;
    delete nodo;
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
        cout<<"3. Elemento a Buscar"<<endl;
        cout<<"4. Recorrido del Arbol"<<endl;
        cout<<"5. Eliminar un Nodo"<<endl;
        cout<<"6. Salir"<<endl;
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
            cout<<"Digite el elemento a buscar: "<<endl;
            cin>>dato;
            if(busqueda(arbol,dato)==true ){
                cout<<"\nElemento "<<dato<<", fue encontrado en el arbol"<<endl;
            }
            else{
                cout<<"\nElemento no Encontrado";
            }
            cout<<"\n";
            system("pause");
        break;
        case 4:
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
        case 5:
            cout<<"Nodo a eliminar"<<endl;
            cin>>dato;
            eliminar(arbol,dato);
            cout<<endl;
            system("pause");
            break;
        case 6: break;
        default: cout<<"Opcion no Valida, Digite otro";
            break;
        }
    system("cls");
    }while(opcion !=6);
}

