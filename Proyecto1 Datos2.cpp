#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include<time.h>
#include<stdio.h>
#include <windows.h>
using namespace std;
struct Nodo{
    int dato;
    Nodo *sisguiente;
};
struct NodoT{ //Temporal
    int datt;
    NodoT *Next;
};
NodoT *listat=NULL;//Temporal
Nodo *lista=NULL;
void RandomNum(int,int,int);
void delay();
void menu1();
void menu();
void MostrarLista(Nodo *);
void InsertarLista(Nodo *&,int);
void BuscarElemento(Nodo *,int);
void Game(Nodo *,int);
void EliminarElemento(Nodo *&,int);
void EliminarLista(Nodo *&,int &);
void MostrarMayorMenor(Nodo *);
//temporal
void MostrarListaT(NodoT *);
void InsertarListaT(NodoT *&,int);
void EliminarListaT(NodoT *&,int &);
bool verT(NodoT *,int);//end temp
void delay(clock_t a){
    clock_t start;
    start  = clock();
    while(clock()-start<a){}
    }
int main(){
    int op,op2,data,n;
    char r;
    int finde,intent,intento,intf;char rin;
    intento=15,intf=0;
    system("color 0d");
    RandomNum(10,20,3);
    do{ menu1();
    cin>>op;
    switch(op){
    case 1:system("cls");
        Game(lista,intento);
        break;
    case 2:system("cls");
        do{menu();
        cin>>op2;
        switch(op2){
        case 1:
        int ArrayS,LongS,rangmen;
        /*do{
        cout<<"\tNumber to Add\n\t";cin>>data;
        InsertarLista(lista,data);
        cout<<"Exit? \nNot... Press Anything Character and Press ENTER \nPress 'y' For go out..."<<endl;
        cin>>r;
        system("pause");system("cls");
        }while(r != 'y');*/
        cout<<"How Much Numbers?\n\t";cin>>ArrayS;
        cout<<"Minor Num :\n\t";cin>>rangmen;
        do{cout<<"\n\tBigger Num\n\t";cin>>LongS;
        if(LongS<=(rangmen+ArrayS)){cout<<"El Numero debe de ser mayor a"<<(rangmen+ArrayS)<<endl;}
        }while(LongS<=(rangmen+ArrayS));
        while(lista!=NULL){EliminarLista(lista,n);}
        RandomNum(ArrayS,LongS,rangmen);
        MostrarLista(lista);
        cout<<"\n\thow many attempts will the participant have\n\t(cuantos intentos tendrá el participante)";
        cin>>intento;
        intento+=1;
        break;
        case 2: MostrarLista(lista);cout<<endl;
                cout<<"Vista del Jugador"<<endl;
                MostrarMayorMenor(lista);
            break;
        case 3:
            cout<<"Element to Delete"<<endl;
            cin>>n;
            EliminarElemento(lista,n);cout<<endl;
            break;
        case 4:
            while(lista!=NULL){
                EliminarLista(lista,n);
                cout<<data<<"->";
            }
                cout<<endl;
            system("pause");
            break;
        case 5: break;
        default: cout<<"Invalid Option, Try Again"<<endl; break;
        }system("pause");system("cls");}while(op2!=5);
        case 3: break;
        default: cout<<"Invalid Option, Try Again"<<endl; break;
        }system("pause");system("cls");}while(op!=3);
    return 0;
}
int di=10;//30 para que se vea fluido
void menu(){
        char menuu[35]=" |------------ MENU -----------| ",opc1[35]=" | ----- 1. Add Numbers ------ | ",opc2[35]=" | 2. See All Elements on list | ",opc3[35]=" | --  3. Delete a Element --  | ",opc4[35]=" | 4. Delete All the Elements  | ";
        char ext[35]=" | --------- 5. Exit --------- | ",ende[50]=" |-----------------------------| ";
        cout<<"\t";
        for(int f=0;ende[f]!='\0';f+=1){cout<<ende[f];delay(di);}cout<<"\n\t";
        for(int f=0;menuu[f]!='\0';f+=1){cout<<menuu[f];delay(di);}cout<<"\n\t";
        for(int f=0;opc1[f]!='\0';f+=1){cout<<opc1[f];delay(di);}cout<<"\n\t";
        for(int f=0;opc2[f]!='\0';f+=1){cout<<opc2[f];delay(di);}cout<<"\n\t";
        for(int f=0;opc3[f]!='\0';f+=1){cout<<opc3[f];delay(di);}cout<<"\n\t";
        for(int f=0;opc4[f]!='\0';f+=1){cout<<opc4[f];delay(di);}cout<<"\n\t";
        for(int f=0;ext[f]!='\0';f+=1){cout<<ext[f];delay(di);}cout<<"\n\t";
        for(int f=0;ende[f]!='\0';f+=1){cout<<ende[f];delay(di);}cout<<"\n\t";
        cout<<"\tIntroduce a Option\n\t\t";
        /*while(!kbhit()==false){
        cout<<"\tIntroduce a Option";
        Sleep(150);
        system("cls");
        Sleep(150); //quiero que parpadee pero que no se detenga hasta que no se precione algo
        }; //presionando una tecla salimos del ciclo;*/
    }
void menu1(){
    char ene[35]=" |-----------------------------| ",menuul[35]=" |------------ MENU -----------| ",op1[35]=" | --------- 1. PLAY --------- | ";
    char op2[35]=" | ------- 2. Settings ------- | ",ext[35]=" | --------- 3. Exit --------- | ";
    cout<<"\t";
        for(int f=0;ene[f]!='\0';f+=1){cout<<ene[f];delay(di);}cout<<"\n\t";
        for(int f=0;menuul[f]!='\0';f+=1){cout<<menuul[f];delay(di);}cout<<"\n\t";
        for(int f=0;op1[f]!='\0';f+=1){cout<<op1[f];delay(di);}cout<<"\n\t";
        for(int f=0;op2[f]!='\0';f+=1){cout<<op2[f];delay(di);}cout<<"\n\t";
        for(int f=0;ext[f]!='\0';f+=1){cout<<ext[f];delay(di);}cout<<"\n\t";
        for(int f=0;ene[f]!='\0';f+=1){cout<<ene[f];delay(di);}cout<<"\n\t";

        cout<<"\t    Option: ";
        }
void InsertarLista(Nodo *&lista,int n){
    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
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
    //cout<<"Element '"<<n<<"' Insert \n"<<endl;
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
void Game(Nodo *lista,int intento){
        bool band =false;
        int n,intent,puntaje=0;char rin;
    Nodo *actual=new Nodo();
    actual = lista;
    int f;
        cout<<"\t\tReady?"<<endl;system("pause");
        intent=intento;
        MostrarMayorMenor(lista);
        do{f=0;
        intent-=1;
    cout<<"Numeros Ingresados ";
    MostrarListaT(listat);
    cout<<""<<endl;
        /*do{*/cout<<"\tLives ["<<intent<<"]\n\tScore(in real time): "<<puntaje<<"\n\tFind a Element\n\t Number: ";
        cin>>n;
        //scanf("%i",&n);
        //if(verT(listat,n)==true){cout<<"Numero ya Existente, Intente con Otro"<<endl;}
        //else{cout<<" . "<<endl;}
        //}while(verT(listat,n)==true);
        InsertarListaT(listat,n);
    while((actual!=NULL)&&(actual->dato <= n)){ //Solo porque esta ordenado le agregue: actual->dato<=n
    if(actual->dato==n){
        band=true;}
        actual= actual->sisguiente;
    f+=1;//......................................................................
    }
    if(band==true){
        cout<<"\tNumber '"<<n<<"' Was Found on Position ["<<f<<"], +1 Score \n"<<endl;
        puntaje+=1;
    }
    else{
        cout<<"\tElement Not Found, -1 Score & -1 live \n"<<endl;puntaje-=1;
    }
    cout<<"\n\t You give up?(Te Rindes?)\n\t YES= 'y'\n\t Not Press Any Other Character\n\t Option: ";
        cin>>rin;
    if(rin=='y'){cout<<"QUE COBARDE"<<endl;}
    }while((rin!='y')|(intent>=intento));
    cout<<"\n\tFinal Score: "<<puntaje<<"\n\tGame Over";
    if(rin=='y'){cout<<"Cobarde :v"<<endl;}//
    if(intent==-2){cout<<"Limite de Intentos Conseguidos "<<endl;}
    while(listat!=NULL){EliminarListaT(listat,n);}
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
void MostrarMayorMenor(Nodo *lista){
    int mayor,menor,f=0,c=0;char ocult[50][5];
    Nodo *actual =new Nodo();
    actual=lista;
    mayor=menor=actual->dato;
    while(actual!=NULL){
        if((actual->dato)>mayor){
            mayor=actual->dato;
        }
        else if((actual->dato)<menor){
            menor=actual->dato;
        }
        else{
            ocult[c][5]='0';c+=1;
        }
        actual=actual->sisguiente;
    }
    cout<<"Minor Number -> "<<menor<<"\n";
    for(c=0;ocult[5][c]!='\0';c+=1){cout<<ocult[5][c];delay(10);}cout<<endl;
    cout<<"Bigger Number -> "<<mayor<<endl;
}
void EliminarLista(Nodo *&Lista,int &n){

    Nodo *aux=lista;
    n=aux->dato;
    lista = aux->sisguiente;
    delete aux;
}
void RandomNum(int ArraySize, int NumSize,int rangmen){
        int v[ArraySize];
        srand(time(0)); // iniciando la semilla aleatoria
// Formula a + rand() % (b-a+1)
// eligiendo 15 numeros aleatorios distintos entre 1 y 50
for(int i=0;i<ArraySize;i++)
{
  // Genera numero aleatorio
    int num = rangmen + rand()%((NumSize+1)-(rangmen));
   if(i>0)
   {
      // Verifica si no se ha generado antes
      for(int j=0; j < i; j++)
          if(num==v[j])
          {
             num = rangmen + rand()%((NumSize+1)-(rangmen));
             j=-1;
          }}
    v[i] =num;
    InsertarLista(lista,num);}
   }
//Temporales
void MostrarListaT(NodoT *listat){
    NodoT *actual=new NodoT();
    actual=listat;
    while(actual !=NULL){
        cout<<actual->datt<<" -> ";
        actual=actual->Next;
    }
}
void InsertarListaT(NodoT *&listat,int n){
    NodoT *nuevo_nodo=new NodoT();
    nuevo_nodo->datt=n;

    NodoT *aux1=listat;
    NodoT *aux2;//lo necesitamos si entra al while

    while((aux1!=NULL)&&(aux1->datt < n)){//solo lo ordenara si el numero es mayor o menor
        aux2=aux1;
        aux1=aux1->Next;
    }
    if(listat == aux1){ //se hara si esta al principio de la lista
        listat=nuevo_nodo;
    }
    else{
        aux2->Next=nuevo_nodo;//entro al while...
    }
    nuevo_nodo->Next=aux1;
    cout<<"Element '"<<n<<"' Insert \n"<<endl;
}
void EliminarListaT(NodoT *&listat,int &n){
    NodoT *aux=listat;
    n=aux->datt;
    listat = aux->Next;
    delete aux;
}
bool verT(NodoT *listat,int n){
    bool v=false;
    NodoT *actualt=new NodoT();
    while(actualt!=NULL){
        if(n==actualt->datt){
            v=true;}}
    return v;
}
