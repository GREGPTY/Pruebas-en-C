/*
* 1IL123
* Laboratorio 1 - Datos 2
* Greg Torres       8-956-675
* Enrique Gonzales  8-959-1507
* el codigo esta en .cpp
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{
       int nro;        // en este caso es un numero entero
       struct nodo *sgte;
};

typedef struct nodo *Tlista;

Tlista inicio, fin;

void generarLista( Tlista &inicio, Tlista &fin, int n )
{
     Tlista q, t;
    int e;
     for(int i=0; i<n; i++){

         q = new(struct nodo);
            cout<<"Introduzca el numero de la posicion ["<<i<<"]"<<endl;cin>>e;
            q->nro = e;

         if(inicio==NULL)
         {
              q->sgte = inicio;
              inicio  = q;
              fin     = q;
         }
         else
         {
              q->sgte   = fin->sgte;
              fin->sgte = q;
              fin       = q;
         }
     }
     cout<<"\n\n\tLista de numeros generados... "<<endl;

}


void reportarLista(Tlista inicio)
{

     while(inicio != NULL)
     {
          cout <<"  " << inicio->nro ;
          inicio = inicio->sgte;
     }

}

void ordenarLista(Tlista lista)
{
     Tlista actual , siguiente;
     int t;

     actual = lista;
     while(actual->sgte != NULL)
     {
          siguiente = actual->sgte;

          while(siguiente!=NULL)
          {
               if(actual->nro > siguiente->nro)
               {
                    t = siguiente->nro;
                    siguiente->nro = actual->nro;
                    actual->nro = t;
               }
               siguiente = siguiente->sgte;
          }
          actual = actual->sgte;
          siguiente = actual->sgte;

     }

     cout<<"\n\n\tLista ordenada..."<<endl;
}


void menu()
{
    cout<<"\n\t\tORDENAMIENTO DE UNA LISTA ENLAZADA SIMPLE\n\n";
    cout<<" 1. INTRODUCIR NUMEROS                  "<<endl;
    cout<<" 2. MOSTRAR NUMEROS                   "<<endl;
    cout<<" 3. ORDENAR NUMEROS                   "<<endl;
    cout<<" 4. SALIR                            "<<endl;

    cout<<"\n INGRESE OPCION: ";
}


/*                        Funcion Principal
------------------------------------------------------------------*/

int main()
{
    inicio = NULL;
    fin    = NULL;

    int op;     // opcion del menu
    int num;   // elemenento a ingresar

    system("color 0d");

    do
    {
        menu();  cin>> op;

        switch(op)
        {
            case 1:
                 cout<< "\n Cantidad de numeros: "; cin>> num;
                 generarLista( inicio, fin, num );
                break;
            case 2:
                 cout<<"\n\n LISTA:\n\n";
                 reportarLista( inicio );
                break;
            case 3:
                 ordenarLista( inicio );
                break;
            case 4:
                break;
            default: cout<<"Incorrect Option"<<endl;
        }
        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=4);


   system("pause");

   return 0;
}
