#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include<climits>
#define V 8
using namespace std;

void Menu();

int shortest_path(int[], int);
int minDist(int [],bool[]);
void Dijkstra(int **,int );
int findMiVertex(int*,bool*,int);
void dijkstra2(int**,int);

void matriz();

int n = 0;
int **ady;
int **adyt;
int op = -1;

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
int shortest_path(int dist[V], int n)
{
   cout<<"Vertex "<<"\t"<<"Distance from Source\n";
   for (int i = 0; i < V; i++)
   cout<<" \t\t \n"<< i<<" \t\t "<<dist[i];
}
int minDist(int dist[V], bool Set[V])
{
   int min = INT_MAX, min_index;
   for (int i = 0; i < V; i++)
   if (Set[i] == false && dist[i] <= min)
   min = dist[i], min_index = i;
   return min_index;
}
void Dijkstra(int g[V][V], int src)
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
   shortest_path(dist, V);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
int findMiVertex(int* distance, bool* visited,int n){
    int minVertex = -1;
    for(int i=0;i<n;i+=1){
        if(!visited[i] && distance[i]<distance[minVertex]){
            minVertex=i;
        }
    }return minVertex;
}
void dijkstra2(int** edges, int n){
    int* distance = new int[n];
    bool* visited = new bool[n];
    for(int i = 0; i < n; i+=1){
        distance[i]=INT_MAX;
        visited[i]=false;
    }
    distance[0]=0;

    for(int i = 0; i<n-1;i+=1){
        int minVertex=findMiVertex(distance,visited,n);
        visited[minVertex]=true;
        for(int j=0;j<n;j++){
            if(edges[minVertex][j] !=0 && !visited[j]){
                int dist = distance[minVertex]+edges[minVertex][j];
                if(dist<distance[j]){
                    distance[j]=dist;
                }
            }
        }
    }
    for(int i=0; i<n;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete [] visited;
    delete [] distance;
}/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    cout<<"hi"<<endl;
    matriz();
    return 0;
}

void matriz() {
            system("cls");
            int Mp[8][8]={{0,10,12,0,9,0,7,0},{15,0,9,15,0,0,17,05},{12,9,0,0,0,17,10,0},{0,15,0,0,0,05,0,12},{9,0,0,0,0,0,0,05},{0,0,17,05,0,0,0,0},{07,17,10,0,0,0,0,0},{0,05,0,12,05,0,0,0}};
            //char Place[8][30]={{"Eclipse_Towers"},{"Maze_Bank"},{"Diamond_Casino"},{"LA_Airport"},{"Santa_Monica_State_Beach"},{"Maze_Bank_Arena"},{"Beverly_Hills"},{"Little_Seoul"}};
            //char P2[30];
            int g=0,h=1,a=0,b=0,p=0,l=0,n,c=1,c2=1,cont=0,q=0,comp,opt;
            char letf[10]={'A','B','C','D','E','F','G','H','I','J'},letc[10]={'A','B','C','D','E','F','G','H','I','J'};
            cout<<"\t1. Crear Una Matriz nueva\n\t2.Usar La Matriz Base"<<endl;
            cin>>opt;
            if(opt==1){
            cout << "Introduzca la cantidad de nodos: ";
            cin >> n;
            }
            else{n=8;}

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
            if(opt==1){
            for (int f = 0; f < n; f++) {
                    g++;
                    h=1;
                for (int c = 0; c < n; c++) {
                    cout << "Ingrese los datos de la posicion [ " << letf[f] << " ][ " << letc[c] << " ]: ";
                    cin >> ady[f][c];
                    adyt[f][c]=ady[f][c];
                    h++;
                }
            }}
            else{
               for (int f = 0; f < n; f++) {
                    g++;
                    h=1;
                for (int c = 0; c < n; c++) {
                    ady[f][c]=Mp[f][c];
                    adyt[f][c]=ady[f][c];
                    h++; }}}
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
            /*for(int e=0;e<8;e+=1){
                    P2[30]=Place[e][30];
                    cout<<"\t\t"<<P2[30]<<endl;}
            system("cls");*/
            do {
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
                    /*for (int i = 0; i < n; i++) {
                        cout<<"\t\t";
                        cout<<Place[i][30];
                        cout << endl;
                    }*/
                cout << "\n\t\t\tSubMenu"<<endl;
                cout << " 1.Matriz Traspuesta" << endl;
                cout << " 2.Calles de doble direccion" << endl;
                cout << " 3.Construir Matriz A" << endl;
                cout << " 4.Circuitos" << endl;
                cout << " 5.Grado de entrada y salida" << endl;
                cout << " 6. Buscar el camino mas rapido" << endl;
                cout << " 7.Volver al menu principal" <<endl;
                cout << " Opcion:" << endl;
                cin >> op;
                if(op==1){
                    l=n*n;
                        cout << endl;
                        cout << endl;
                        cout << "\t\t\t\t\t  MATRIZ Traspuesta" << endl;
                        cout << endl;
                    for (int i = 0; i < n; i++) {
                        cout<<"\t\t";
                        for (int j = 0; j < n; j++) {
                            cout << "|   " << adyt[j][i] << "   |";
                        }
                        cout << endl;
                    }
                    int same[l];

                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if(adyt[j][i]==adyt[i][j]){
                                same[a]=1;
                                a++;
                            }
                            else{
                                same[a]=0;
                                a++;
                            }
                        }
                    }
                    for(int i=0;i<l;i++){
                        if(same[i]==1){
                            cont++;
                        }
                    }
                    if(cont==l){
                        cout<<"Las matrices son iguales"<<endl;
                    }
                    else{
                        cout<<"Las matrices son distintas"<<endl;
                    }
                    system("pause");
                }

                else if(op==2){
                    for(int i = 0;i < n;i=i+1){
                        for(int j = 0;j < n;j=j+1){
                            if(j!=i){
                                if(ady[i][j] == 1 && ady[j][i] == 1){
                                cout<<"\n\tExiste camino doble en la posicion ["<<letf[i]<<"]["<<letc[j]<<"] y en la posicion ["<<letc[j]<<"]["<<letf[i]<<"]"<<endl;
                                comp = 1;
                                }
                            }
                        }
                    }
                    if(comp == 0)
                        cout<<"\n\tNo existen vias de doble camino en la matriz."<<endl;
                system("pause");
                }

                else if(op==3){
                    int i,j,suma;
                    int matrizC[n][n] = {0};

                        for(i = 0;i < n;i++){
                            for(j = 0;j < n;j++){
                                matrizC[i][j] = ady[i][j];
                            }
                        }

                        for(i=0;i < n;i++){
                            for(j=0;j< n;j++){
                                suma = ady[i][j] + ady[j][i];
                                if(suma==2){
                                    matrizC[i][j] = 1;
                                }
                                else{
                                    matrizC[i][j] = suma;
                                }
                            }
                        }
                        cout << endl;
                        cout << endl;
                        cout << "\t\t\t\t\t  MATRIZ A" << endl;
                        cout << endl;
                        for(i=0;i < n;i++){
                            cout<<"\t\t";
                                for(j=0;j< n;j++){
                                    cout << "|   " << matrizC[i][j] << "   |";
                                }
                            cout << endl;
                        }
                                            system("pause");
                }

                else if(op==4){
                    int i , j , c1 = 0 , c2 = 0, entrada[n] = {0}, salida[n]={0}, suma[n] = {0};
                    char let[6]={'A','B','C','D','E','F'};
            while(c1 < n){
                for(j = 0;j < n;j++){
                    for(i = 0;i < n;i++){
                        entrada[c1] = entrada[c1] + ady[i][j];
                    }
                    c1++;
                }
            }
            while(c2 < n){
                for(i = 0;i < n;i++){
                    for(j = 0;j < n;j++){
                        salida[c2] = salida[c2] + ady[i][j];
                    }
                    c2++;
                }
            }
            //suma los grados de entrada y salida de cada vertice
            for(i=0;i<n;i++){
                suma[i] = entrada[i] + salida[i];
            }
            //si la suma es par, hay circuito en ese vertice
            for(i=0;i<n;i++){
                if(suma[i] % 2 == 0){
                    cout<<"\nSi hay circuito en el vertice "<<let[i]<<"\n"<<endl;
                }
                else{
                    cout<<"\nNo hay circuito en el vertice "<<let[i]<<"\n"<<endl;
                }
            }
                    system("pause");
                }
                else if(op==5){
                        a=0;b=0;
                        int s[6]={0,0,0,0,0,0},e[6]={0,0,0,0,0,0};
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            e[b]=e[b]+ady[j][b];
                            s[a]=s[a]+ady[a][j];
                        }
                        a++;
                        b++;
                    }
                    cout << endl;
                    cout << endl;
                    for(int i=0;i<n;i++){
                        cout << "Grado de Entrada de "<<letc[i]<<" es:[" <<e[i]<<"]"<< " y el de Salida es:["<<s[i]<<"]"<<endl;
                        cout<<endl;
                    }
                    system("pause");
                }
            else if(op==6){
                    int way;
                do{
                cout<<"Introduzca Su Busqueda"<<endl;
                cin>>way;
                if(!(way<=-1||way>=8)){
                Dijkstra(Mp,way);
                cout<<endl;}
                else{cout<<"Ese Valor no es valido"<<endl;}
                }while(way<=-1||way>=8);
                system("pause");
                    int node = way;



                system("pause");
            }
            else if(op==7){
                    Menu();
            }

            else{
                cout << "Introduzca un valor valido" << endl;
                system("pause");
            }
	} while (op != 7);
}

