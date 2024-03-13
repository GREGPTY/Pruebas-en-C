#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <limits.h>
#include<climits>
#define V 8
using namespace std;
//GREG TORRES, JOSE TORRES
//EMPRESA: DIAMOND WATHER C.
void Menu();
void matriz();
int n = 0;
int **ady;
int **adyt;
int op = -1;

struct Nodo{
    int dato,canti;
    Nodo *sisguiente;
};
Nodo *lista=NULL;
void menu();
void MostrarLista(Nodo *);
void InsertarLista(Nodo *&,int,int);
int BuscarElemento(Nodo *,int);
void EliminarElemento(Nodo *&,int);
void EliminarLista(Nodo *&,int &);
//////LISTA ENLAZADA////////////////////////////////////////////
void InsertarLista(Nodo *&lista,int n,int cantid){
    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->canti=cantid;
    Nodo *aux1=lista;
    Nodo *aux2;//lo necesitamos si entra al while
    int a=n,b=cantid;
    while((aux1!=NULL)&&(aux1->dato < n)){//solo lo ordenara si el numero es mayor o menor
        aux2=aux1;
        aux1=aux1->sisguiente;
    }
    if(lista == aux1){ //se hara si esta al principio de la lista
        lista=nuevo_nodo;}
    /*else if(nuevo_nodo->dato==n){
        lista=nuevo_nodo;}*/

    else{
        aux2->sisguiente=nuevo_nodo;//entro al while...
    }
    nuevo_nodo->sisguiente=aux1;
    cout<<"Element '"<<n<<"' Insert \n"<<endl;
}
void adddis(Nodo *lista,int n, int ca){
    Nodo *actu=new Nodo();
    actu->canti=ca;
    Nodo *aux1=lista;
    Nodo *aux2;//lo necesitamos si entra al while
    while((aux1!=NULL)&&(aux1->dato < n)){//solo lo ordenara si el numero es mayor o menor
        aux2=aux1;
        aux1=aux1->sisguiente;
    }
    if(lista == aux1){ //se hara si esta al principio de la lista
        lista=actu;}
    /*else if(nuevo_nodo->dato==n){
        lista=nuevo_nodo;}*/

    else{
        aux2->sisguiente=actu;//entro al while...
    }
    actu->sisguiente=aux1;
    cout<<"Element '"<<n<<"' Insert \n"<<" and new Distance"<<actu->canti<<endl;


}
void MostrarLista(Nodo *lista){
    Nodo *actual=new Nodo();
    actual=lista;
    while(actual !=NULL){
        cout<<" | Nodo: "<<actual->dato<<" | Cantidad -> "<<actual->canti<<endl;
        actual=actual->sisguiente;
    }
}
int BuscarElemento(Nodo *lista,int n){
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
    return band;
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
void EliminarLista(Nodo *&Lista,int &n,int &can){
    Nodo *aux=lista;
    can=aux->canti;
    n=aux->dato;
    lista = aux->sisguiente;
    delete aux;
}
//////LISTA ENLAZADA////////////////////////////////////////////

void Menu() {
	system("cls");

	cout << "\t\t\tMenu"<<endl;
	cout << " 1.Ingresar Nueva Matriz" << endl;
	cout << " 2.Salir" << endl;
	cout << " Opcion:" << endl;
	cin >> op;

	do {
		if(op==1){
			matriz();
			system("pause");
			Menu();
        }

		else if(op==2){
			exit(0);
		}

		else{
			cout << "Introduzca un valor valido" << endl;
			system("pause");
			Menu();
		}

	} while (op != 2);

}
int shortest_path(int dist[V], int n,int tr,int wa2)
{
   cout<<"Vertex "<<"\t"<<"Distance from Source\n";
   for (int i = 0; i < V; i++){
   cout<<" \t\t \n"<< i<<" \t\t "<<dist[i];}
   cout<<"\n\t Desde "<<tr<<" A "<<wa2<<" es: "<<dist[wa2]<<endl;
}
int minDist(int dist[V], bool Set[V])
{
   int min = INT_MAX, min_index;
   for (int i = 0; i < V; i++)
   if (Set[i] == false && dist[i] <= min)
   min = dist[i], min_index = i;
   return min_index;
}
void Dijkstra(int g[V][V], int src,int bu)
{
   int dist[V];
   bool Set[V];
   for (int i = 0; i < V; i++)
   dist[i] = INT_MAX, Set[i] = false;
   dist[src] = 0;
   for (int c = 0; c < V- 1; c++)
   {
      int u = minDist(dist, Set);
      Set[u] = true;
      for (int j = 0; j < V; j++)
    if (!Set[j] && g[u][j] && dist[u] != INT_MAX && dist[u]+ g[u][j] < dist[j])
    {
    dist[j] = dist[u] + g[u][j];
      }
   }
   shortest_path(dist, V,src,bu);
}
void Lugar(){
    string Place[V]={"0.Eclipse_Towers","1.Maze_Bank","2.Diamond_Casino","3.LA_Airport","4.Santa_Monica_State_Beach","5.Maze_Bank_Arena","6.Beverly_Hills","7.Little_Seoul"};
    for(int e=0;e<8;e+=1){
                    cout<<"\t\t "<<Place[e]<<endl;}
}

void matriz() {
            system("cls");
            int Mp[V][V]={{0,10,12,0,9,0,7,0},{10,0,9,15,0,0,17,05},{12,9,0,0,0,17,10,0},{0,15,0,0,0,05,0,12},{9,0,0,0,0,0,0,05},{0,0,17,05,0,0,0,0},{07,17,10,0,0,0,0,0},{0,05,0,12,05,0,0,0}};
            int cant[V]={44,26,18,10,20,29,53,18};
            string Place[V]={"Eclipse_Towers","Maze_Bank","Diamond_Casino","LA_Airport","Santa_Monica_State_Beach","Maze_Bank_Arena","Beverly_Hills","Little_Seoul"};

            //char P2[30];
            int g=0,h=1,a=0,b=0,p=0,l=0,n,c=1,c2=1,cont=0,q=0,comp,opt;

            char letf[10]={'A','B','C','D','E','F','G','H','I','J'},letc[10]={'A','B','C','D','E','F','G','H','I','J'};
            cout<<"Usando La Matriz Base"<<endl;

            n=8;

            int matriz[n][n];
            int m[n],z[n];
            ady = new int*[n];
            for (int i = 0; i <= n; i++) {
                ady[i] = new int[n];
            }

            adyt = new int*[n];
            adyt[n][n];
            for (int i = 0; i <= n; i++) {
                adyt[i] = new int[n];
            }
            adyt[n][n];

               for (int f = 0; f < n; f++) {
                    g++;
                    h=1;
                for (int c = 0; c < n; c++) {
                    ady[f][c]=Mp[f][c];
                    adyt[f][c]=ady[f][c];
                    h++; }}
            system("cls");
            cout << endl;
            cout << endl;
            cout << "\t\t\t\t\t  MATRIZ M" << endl;
            cout << endl;
            for(int i=0;i<n;i++){
                    matriz[0][i+1]=c;
                    c++;
                }
                for(int i=0;i<n;i++){
                    matriz[i+1][0]=c2;
                    c2++;
                }
                for(int i=1;i<n;i++){
                    for(int j=1;j<n;j++){
                        matriz[i][j]=0;
                    }
                }
            for (int i = 0; i < n; i++) {
                    cout<<"\t\t";
                for (int j = 0; j < n; j++) {
                    cout << "|  " << ady[i][j] << "   |";
                }
                cout << endl;
            }
            system("cls");
                system("cls");
                    cout << endl;
                    cout << endl;
                    cout << "\t\t\t\t\t  MATRIZ M" << endl;
                    cout << endl;
                    for(int i=0;i<n;i++){
                        matriz[0][i+1]=c;
                        c++;
                    }
                    for(int i=0;i<n;i++){
                        matriz[i+1][0]=c2;
                        c2++;
                    }
                    for(int i=1;i<n;i++){
                        for(int j=1;j<n;j++){
                            matriz[i][j]=0;
                        }
                    }
                    for (int i = 0; i < n; i++) {
                        cout<<"\t\t";
                        for (int j = 0; j < n; j++) {
                            cout << "|   " << ady[i][j] << "   |";
                        }
                        cout << endl;
                    }
                    int re;
                    for(int e=0;e<8;e+=1){
                    cout<<"\t\tEn "<<Place[e]<<" hay: "<<cant[e]<<""<<endl;
                    re=cant[e];
                    InsertarLista(lista,e,re);
                    }

                    MostrarLista(lista);
                    /*for (int i = 0; i < n; i++) {
                        cout<<"\t\t";
                        cout<<Place[i][30];
                        cout << endl;
                    }*/
                do {
                cout << "\n\t\t\tSubMenu"<<endl;
                cout << " 1.Ver las longitudes desde 0" << endl;
                cout << " 2.Pedir Producto" << endl;
                cout << " 3. Buscar el camino mas rapido de un lugar al otro(longitud)" << endl;
                cout << " 4.Volver al menu principal" <<endl;
                cout << " Opcion:" << endl;
                cin >> op;
                if(op==1){
                    MostrarLista(lista);
                    Dijkstra(Mp,0,0);
                    system("pause");
                }
                else if(op==2){
                    int pl1,pl2,pr;
                    int a,b,c,d;//variables de suma y resta
                    cout<<"\t\tDesde donde se encuentra?"<<endl;
                    Lugar();
                    cin>>pl1;
                    cout<<"----------------------------------------------------------------"<<endl;
                    MostrarLista(lista);
                    Dijkstra(Mp,pl1,pl1);
                    cout<<"----------------------------------------------------------------"<<endl;
                    cout<<"Que lugar desea? y cuantos desea?(no agregues menos de lo que hay en el stock o el otro lugar quedara en negativo)"<<endl;
                    cin>>pl2;
                    cin>>pr;
                    a=cant[pl1];b=cant[pl2];
                    EliminarElemento(lista,pl1);EliminarElemento(lista,pl2);
                    a+pr;b-pr;
                    adddis(lista,pl1,a);adddis(lista,pl2,a);
                    cant[pl1]=a;cant[pl2]=b;
                                        system("pause");
                }

            else if(op==3){
                    int way,wa22;
                do{
                cout<<"Introduzca Su Busqueda(desde su inicio) y el destino"<<endl;
                cin>>way;cin>>wa22;
                if(!(way<=-1||way>=8)&&!(wa22<=-1||wa22>=8)){
                Dijkstra(Mp,way,wa22);//agregarle "hasta"
                cout<<endl;}
                else{cout<<"Ese Valor no es valido"<<endl;}
                }while(way<=-1||way>=8);
                system("pause");
                    //int node = way;
                      //              dijkstra2(Mp,V);
                MostrarLista(lista);
                system("pause");
            }
            else if(op==4){break;
            }

            else{
                cout << "Introduzca un valor valido" << endl;
                system("pause");
            }
	} while (op != 4);
}
int main(){
    matriz();
    return 0;
}
