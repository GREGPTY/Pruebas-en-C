#include<iostream>
#include<conio.h>
#include<stdlib.h>
//Greg Torres, Miguel Vazquez.

using namespace std;
typedef struct nodo{
    int dato;
    nodo *der,*izq;
}Nodo;
int numNodos = 0; // nummero de nodos del arbol Nodo
int numK = 0, k;     //  nodos menores que un numero k ingresado

struct nodoCola{
    Nodo ptr;
    struct nodoCola *sgte;
};
struct cola{
    struct nodoCola *delante;
    struct nodoCola *atras;
};

void inicializaCola(struct cola &q)
{
    q.delante = NULL;
    q.atras = NULL;
}

void encola(struct cola &q, Nodo n)
{
     struct nodoCola *p;
     p = new(struct nodoCola);
     p->ptr = n;
     p->sgte = NULL;
     if(q.delante==NULL)
         q.delante = p;
     else
         (q.atras)->sgte = p;
     q.atras = p;
}
Nodo desencola(struct cola &q)
{
    struct nodoCola *p;
    p = q.delante;
    Nodo n = p->ptr;
    q.delante = (q.delante)->sgte;
    delete(p);
    return n;
}

/*void menu();
Nodo *crearNodo(int,Nodo *);
void mostrarArbol(Nodo *,int);
void insertarNodo(Nodo *&,int, Nodo *);
Nodo*arbol=NULL;
bool busqueda(Nodo *,int);
void preOrden(Nodo *);
void InOrden(Nodo *);
void PostOrden(Nodo *);
void preOrdenN(Nodo *);
void inOrdenN(Nodo *);
void postOrdenN(Nodo *);
void eliminar(Nodo *,int);
void recorrerxNivel(Nodo);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruirNodo(Nodo *);*/

Nodo crearNodo(int n){
    Nodo nuevo_nodo = new(struct nodo);
    nuevo_nodo->dato=n;
    nuevo_nodo->der=NULL;
    nuevo_nodo->izq=NULL;
    return nuevo_nodo;
}
void insertarNodo(Nodo &arbol, int n){
    if(arbol==NULL){
        arbol=crearNodo(n);;
    }
    else{
        int valorRaiz=arbol->dato;
        if(n<valorRaiz){
            insertarNodo(arbol->izq,n);
        }else if(n>valorRaiz){
            insertarNodo(arbol->der,n);
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

void recorrerxNivel(Nodo arbol){
     struct cola q;
     inicializaCola(q);
     cout << "\t";

     if(arbol!=NULL){
         encola(q, nodo);

         while(q.delante!=NULL)
         {
             arbol = desencola(q);
             cout << arbol->dato<< ' ';

             if((arbol->izq)!=NULL)
                 encola(q, arbol->izq);
             if((arbol->der)!=NULL)
                 encola(q, arbol->der);
         }
     }
}

int alturaAB(Nodo *arbol){

    int AltIzq, AltDer;

    if(arbol==NULL)
        return -1;
    else
    {
        AltIzq = alturaAB(arbol->izq);
        AltDer = alturaAB(arbol->der);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}
void menu(){
    int dato,opcion,contador=0;
    /*int r[10]={3,8,9,5,12,4,100,25,52};
    for(int i=0;i<10;i+=1){
        int e;
        e=r[i];
        insertarNodo(arbol,e,NULL);
    }*/
    do{
        cout<<"\t Menu"<<endl;
        cout<<"1. Insertar un nuevo nodo "<<endl;
        cout<<"2. Mostrar el arbol"<<endl;
        cout<<"3. Elemento a Buscar"<<endl;
        cout<<"4. Recorrido del Arbol"<<endl;
        cout<<"5. Eliminar un Nodo"<<endl;
        cout<<"6. Altura del arbol"<<endl;
        cout<<"7. Recorrido por Nivel"<<endl;
        cout<<"8. Salir"<<endl;
        cout<<"Opcion: "<<endl;
        cin>>opcion;
        switch(opcion){
        case 1: cout<<"\n Digite un Numero entero: ";
                    cin>>dato;
                    insertarNodo(arbol,dato);//insertamos un nuevo nodo
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
        case 6:
            cout<<"Mostrando la altura"<<endl;
                int r;
                r=alturaAB(arbol);
            cout<<"La altura es de "<<r<<" "<<endl;
            system("pause");
            break;
        case 7:
            cout<<"Iniciando el Recorrido por niveles"<<endl;
            //recorrerxNivel(arbol);
            cout<<"Recorrido por niveles finalizado"<<endl;
            system("pause");
            break;
        case 8: break;
        default: cout<<"Opcion no Valida, Digite otro";
            break;
        }
    system("cls");
    }while(opcion !=8);
}
int main(){
    system("color 0d");
    menu();

    getche();
    return 0;
}
