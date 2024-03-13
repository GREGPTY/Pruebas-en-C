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

Nodo *lista=NULL;
void RandomNum(Nodo *,int, int,int,int);
void delay();
void menu1();
void menu();
void MostrarLista(Nodo *);
void InsertarLista(Nodo *&,int);
void BuscarElemento(Nodo *,int);
void EliminarElemento(Nodo *&,int);
void EliminarLista(Nodo *&,int &);
void Debuel(Nodo *,int,int);
void revision(Nodo *,int,int,int);//number, refin,refma

void delay(clock_t a)
{
    clock_t start;
    start  = clock();
    while(clock()-start<a)
    {

    }
}
int main(){
    system("color 0d");
    int op,op2,data,n;int ArrayS,LongS;int opi;
    char r;
    int finde,intent,intento,intf,refin,refma;refin=-1000,refma=1000;
    char rin;
    cout<<"\tProgram Started 1st you need to now: Reference '<' is: "<<refin<<" and Reference '>' is: "<<refma<<endl;
    cout<<"\t\t\t\t\tYou can change this in Option N.5\n\n\n"<<endl;
    do{ menu();
        cin>>op2;
        switch(op2){
        case 1:
            do{
            cout<<"\t\tAdd Manual Press 1\n\t\tAdd Automatic Press 2 \n\t\tFor Exit Press 3\n\t\t  ";
            cin>>opi;
            switch(opi){
        case 1:
        do{
        cout<<"\tNumber to Add\n\t";cin>>data;
        revision(lista,data,refin,refma);
        //InsertarLista(lista,data);
        cout<<"Exit? \nNot... Press Anything Character and Press ENTER \nPress 'y' For go out..."<<endl;
        cin>>r;
        system("pause");system("cls");
        }while(r != 'y');
        break;
        case 2:
        cout<<"How Much Numbers?\n\t";cin>>ArrayS;
        cout<<"\n\t Long Num\n\t";cin>>LongS;
        RandomNum(lista,ArrayS,LongS,refin,refma);
        cout<<"\n\thow many attempts will the participant have\n\t(cuantos intentos tendrá el participante)";
        /*cin>>intento;
        intento+=1;*/
        break;
        case 3: break;
        default: break;
        }}while(opi!=3);
        break;
        case 2: MostrarLista(lista);cout<<endl;
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
        case 5:
            bool va;va=true;int e,r;
            printf("Option %c5 \n",248);
            cout<<"Valor Menor (Referencia): ";cin>>refin; cout<<"\nValor mayor (Referencia): ";cin>>refma;cout<<endl;
            InsertarLista(lista,refin);InsertarLista(lista,refma);
            Debuel(lista,refin,refma);
            break;
        case 6:
            break;
        case 7:
            while(lista!=NULL){
            MostrarLista(lista);
            cout <<data<<endl;}
        break;
        default: cout<<"Invalid Option, Try Again"<<endl; break;
        }system("pause");system("cls");}while(op2!=7);
    return 0;
}
int di=6;//30 para que se vea fluido
void menu(){
        char menuu[35]=" |------------ MENU -----------| ",opc1[35]=" | ----- 1. Add Numbers ------ | ",opc2[35]=" | 2. See All Elements on list | ",opc3[35]=" | --  3. Delete a Element --  | ",opc4[35]=" | 4. Delete All the Elements  | ";
        char ext[35]=" | --------- 6. Exit --------- | ",ende[50]=" |-----------------------------| ",opc5[35]=" | 5. References by References | ";
        cout<<"\t";
        for(int f=0;ende[f]!='\0';f+=1){cout<<ende[f];delay(di);}cout<<"\n\t";
        for(int f=0;menuu[f]!='\0';f+=1){cout<<menuu[f];delay(di);}cout<<"\n\t";
        for(int f=0;opc1[f]!='\0';f+=1){cout<<opc1[f];delay(di);}cout<<"\n\t";
        for(int f=0;opc2[f]!='\0';f+=1){cout<<opc2[f];delay(di);}cout<<"\n\t";
        for(int f=0;opc3[f]!='\0';f+=1){cout<<opc3[f];delay(di);}cout<<"\n\t";
        for(int f=0;opc4[f]!='\0';f+=1){cout<<opc4[f];delay(di);}cout<<"\n\t";
        for(int f=0;opc5[f]!='\0';f+=1){cout<<opc5[f];delay(di);}cout<<"\n\t";
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
void Debuel(Nodo *lista,int me,int ma){
    bool va;va=true;int temp;
    Nodo *actual=new Nodo();
    actual=lista;
    while(actual !=NULL){
        temp=actual->dato;
        if((actual->dato)< me){
            EliminarElemento(lista,temp);
            cout<<"Elemento eliminado -> "<<actual->dato<<"\n";
        }else if((actual->dato)>ma){
            EliminarElemento(lista,actual->dato);
            cout<<"Elemento eliminado -> "<<actual->dato<<"\n";
        }else{
            cout<<"El Dato Quedo Bien -> "<<actual->dato<<"\n";
        }
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
void revision(Nodo *lista,int ne,int me,int ma){
    int n;n=ne;
    Nodo *actual=new Nodo();
    actual=lista;
    while((actual!=NULL)){//|(actual->dato==n)){
            if(actual->dato==n){
                cout<<"\tThis Number is Already Existent, Try with another Number: \n\t";
                cin>>n;actual=lista;
            }else if(!((n<=me)||(ma>=n))){
                cout<<"\tYou Can't add this number Because\n Is greater that '"<<ma<<"' Or Is less than '"<<me<<"'\n\t";
                cin>>n;actual=lista;
            }
            else{
            actual=actual->sisguiente;
            }}
    InsertarLista(lista,n);
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
void RandomNum(Nodo *lista,int ArraySize, int NumSize,int me,int ma){
        //Nodo *actual=new Nodo();
        //actual=lista;
        int v[ArraySize];
        srand(time(0)); // iniciando la semilla aleatoria
// Formula a + rand() % (b-a+1)
// eligiendo n numeros aleatorios distintos entre 1 y NumZise
for(int i=0;i<ArraySize;i++)
{
  // Genera numero aleatorio
    int num = 1 + rand()%NumSize;
   if(i>0)
   {// Verifica si no se ha generado antes
      for(int j=0; j < i; j++)
          if(num==v[j])
          {
             num = 1 + rand()%NumSize;
             j=-1;
          }else if(!((num<=me)||(ma>=num))){
                num = 1 + rand()%NumSize;
                j-1;
          }else{}
          }
    v[i] =num;
    InsertarLista(lista,num);}
   }

