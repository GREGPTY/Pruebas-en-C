#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

typedef int tipo;

                 struct estudiante
                         {   int codigo[5];
			     char nombre[50];
                             char genero[1];
                             } ;

                 struct nodo{              //esta es la estructura del nodo
                 tipo s_dato;
                 nodo* s_sig;
                 };

void crear(nodo**);
void insertar(nodo**, tipo);
void quitar(nodo**, tipo);
void recorrer(nodo**);
int buscar();

int  main()
{
nodo* cabeza;
int dat;
int dato;
char op;

struct estudiante x;
crear(&cabeza);
system("pause");

df;                              //tambien se puede hacer con do while
cout << "1.-INSERTAR" << endl;
cout << "2.-VER" << endl;
cout << "3.-QUITAR" << endl;
op = getch();
switch(op)
{
case '1':
cout << "introduce el codigo: ";
scanf("%s",&x->codigo);
cout << "introduce el nombre: ";
scanf("%d",&x->nombre);
cout << "introduce el Sexo: ";
scanf("%d",&x->genero);


insertar(&cabeza, dat);

system("pause");
goto df;

case '2':
recorrer(&cabeza);
system("pause");
goto df;

case '3':
cout << "introduzca dato a quitar";
cin >> dato;
quitar(&cabeza,dato);
goto df;

}
}

        void crear(nodo** siguiente)
        {
        *siguiente = NULL;
        }

           void insertar(nodo**siguiente, tipo dato)
           {
           struct estudiante *x;
           nodo* aux;
           x=s_sig= NUll;
           aux = estudiante;
           aux->s_dato = dato;
           aux->s_sig = (*siguiente);
           *siguiente = aux;
           }

           void quitar(nodo**siguiente, tipo dato)
           {
           nodo* ptr,*ant;
           ptr = *siguiente;
           ant = NULL;
           while (ptr!= NULL && ptr->s_dato!=dato)
           {
           ant = ptr;
           ptr = ptr->s_sig;

           }
           if ( ptr->s_dato!=dato)
           {
           cout << "dato no existe";
           }

           else
           ant->s_sig = ptr->s_sig;
           delete ptr;
           }


       void recorrer(nodo**siguiente)
       {
       nodo* ptr;
       ptr = *siguiente;
       while (ptr!= NULL)
       {
       cout << ptr->s_dato << endl;       // aqui es donde necesito mostrar la estructura

       ptr=ptr->s_sig;
       }

}
