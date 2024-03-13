#include<iostream>
#include<conio.h>
#include<stdlib.h>
//Greg Torres, Miguel Vazquez.

using namespace std;
typedef struct nodo{
    int dato;
    nodo *der,*izq;
}*Nodo;
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

void mostrarArbol(Nodo arbol, int cont){
 if(arbol==NULL){
    return;
 }
 else{
    mostrarArbol(arbol->der,cont+1);
    for(int i=0;i<cont;i+=1){
        cout<<"   ";
    }
    cout<<arbol->dato<<endl;
    numNodos+=1;
    mostrarArbol(arbol->izq,cont+1);
 }
 }
 bool busqueda(Nodo arbol,int n){
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
 void preOrden(Nodo arbol){
    if(arbol==NULL){ //si el arbol esta vacio solo retorna
        return;
    }
    else{
        cout<<arbol->dato<<" - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
 }
 void InOrden(Nodo arbol){
     if(arbol==NULL){
        return;
     }
     else{
        InOrden(arbol->izq);
        cout<<arbol->dato<<" - ";
        InOrden(arbol->der);
     }
 }
 void PostOrden(Nodo arbol){
     if(arbol==NULL){
        return;
     }
     else{
        PostOrden(arbol->izq);
        PostOrden(arbol->der);
        cout<<arbol->dato<<" - ";
     }
 }

Nodo unirNodoA(Nodo izq, Nodo der)
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    Nodo centro = unirNodoA(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}
void eliminar(Nodo &arbol, int x)
{
     if(arbol==NULL) return;

     if(x<arbol->dato)
         eliminar(arbol->izq, x);
     else if(x>arbol->dato)
         eliminar(arbol->der, x);

     else
     {
         Nodo p = arbol;
         arbol = unirNodoA(arbol->izq, arbol->der);
         delete p;
     }
}

void recorrerxNivel(Nodo arbol){
     struct cola q;
     inicializaCola(q);
     cout << "\t";

     if(arbol!=NULL){
         encola(q, arbol);
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

int alturaAB(Nodo arbol){

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
int AltEsp(Nodo arbol, int n){
    int z=0;
    if(arbol->dato!=n){
        z=1000;
    }
    if((arbol->dato>n)&&(arbol->izq != NULL)){
        z=AltEsp(arbol->izq,n)+1;
    }
    if((arbol->dato<n)&&(arbol->der != NULL)){
        z=AltEsp(arbol->der, n)+1;
    }
    return z;
}
int Mayor(Nodo arbol,int Maxi,int co){
    if(arbol==NULL){
        if(co<=0){
            cout<<"Arbol Vacio"<<endl;return 0;
        }else{return Maxi;}
    }else{
        if ((arbol->dato)>Maxi){
            Maxi=arbol->dato;
        }
    co+=1;
    Mayor(arbol->izq,Maxi,co);
    Mayor(arbol->der,Maxi,co);
    }
}
int Menor(Nodo arbol,int Min,int co){
    if(arbol==NULL){
        if(co<=0){
            cout<<"Arbol Vacio"<<endl;return 0;
        }else{return Min;}
    }else{
        if ((arbol->dato)<Min){
            Min=arbol->dato;
        }
    co+=1;
    Menor(arbol->izq,Min,co);
    Menor(arbol->der,Min,co);
    }
}
void menu(){
    int data,opcion,contador=0;Nodo arbol=NULL;
    int r[22]={8,3,-2,-7,9,5,12,4,16,41,68,22,31,25,52,13,53,73,11,19,40,57};
    for(int i=0;i<20;i+=1){
        int e;
        e=r[i];
        insertarNodo(arbol,e);
    }
    do{
        cout<<"\t Menu"<<endl;
        cout<<"1. Insertar un nuevo nodo "<<endl;
        cout<<"2. Mostrar el arbol"<<endl;
        cout<<"3. Elemento a Buscar"<<endl;
        cout<<"4. Recorrido del Arbol"<<endl;
        cout<<"5. Eliminar un Nodo"<<endl;
        cout<<"6. Altura del arbol"<<endl;
        cout<<"7. Recorrido por Nivel (amplitud)"<<endl;
        cout<<"8. Total de Nodos"<<endl;
        cout<<"9. Nodo Minimo y Maximo"<<endl;
        cout<<"10. Salir"<<endl;
        cout<<"Opcion: "<<endl;
        cin>>opcion;
        switch(opcion){
        case 1: cout<<"\n Digite un Numero entero: ";
                    cin>>data;
                    insertarNodo(arbol,data);//insertamos un nuevo nodo
                    cout<<"\n";
                    system("pause");
                    break;
        case 2:
            cout<<"\n\nMostrando el Arbol\n\n"<<endl;
                  mostrarArbol(arbol,0);
                  system("pause");
                break;
        case 3:
            cout<<"Digite el elemento a buscar: "<<endl;
            cin>>data;
            if(busqueda(arbol,data)==true ){
                cout<<"\nElemento "<<data<<", fue encontrado en el arbol"<<endl;
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
            cin>>data;
            eliminar(arbol,data);
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
            recorrerxNivel(arbol);
            cout<<"Recorrido por niveles finalizado"<<endl;
            system("pause");
            break;
        case 8:     mostrarArbol(arbol, 0);
                    cout << "\n\n El numero de nodos es : ";
                    cout << numNodos<<endl;
                    system("pause");
            break;
        case 9:
                int Maxi,Min,a,b,conta; Maxi=-1000000000,Min=1000000000;
                a=Mayor(arbol,Maxi,0);b=Menor(arbol,Min,0);
                cout<<"El Nodo Mayor es: "<<a<<", Altura: "<<AltEsp(arbol,a)<<"\t Nodo Menor: "<<b<<", Altura: "<<AltEsp(arbol,b)<<" "<<endl;
            cout<<endl;system("pause");
            break;
        case 10: break;
        default: cout<<"Opcion no Valida, Digite otro";
            break;
        }
    system("cls");
    }while(opcion !=10);
}
int main(){
    system("color 0d");
    menu();

    getche();
    return 0;
}
