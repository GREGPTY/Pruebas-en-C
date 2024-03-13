#include <iostream>
#include <stdio.h>
#include<conio.h>

using namespace std;
int main(){
    int n[10];
    ///int *pun =new int;
    int *punt=new int[10];
    for(int a=0;a<10;a+=1){
        cout<<"Introduzca la nota del estudiante ["<<a<<"]"<<endl;
        //cin>>n[a];
        //punt[a]=n[a];
        cin>>punt[a];
        n[a]=punt[a];
    }
    cout<<endl;
    for(int a=0;a<10;a+=1){
        cout<<"\tPosicion ["<<a<<"]\n\tNota "<<punt[a]<<" Posicion en memoria "<<&punt[a]<<endl;
    }
    cout<<endl;
    for(int a=9;a>=0;a-=1){
        cout<<"\tPosicion ["<<a<<"]\n\tNota "<<punt[a]<<" Posicion en memoria "<<&punt[a]<<endl;
    }
    cout<<endl;
    for(int a=0;a<10;a+=1){
        if((punt[a]==60)||(punt[a]==70)||(punt[a]==80)||(punt[a]==90)){
            cout<<"\tAntes\n\tPosicion ["<<a<<"]\n\tNota "<<punt[a]<<" Posicion en memoria "<<&punt[a]<<endl;
            int e;
            e=punt[a];
            e+=1;
            punt[a]=e;
            cout<<"\tAhora\n\tPosicion ["<<a<<"]\n\tNota "<<punt[a]<<" Posicion en memoria "<<&punt[a]<<endl;
        }
    }
    cout<<endl;
    for(int a=0;a<10;a+=1){
        if(punt[a]==63){
            int s=75;
            cout<<"\tAntes\n\tPosicion ["<<a<<"]\n\tNota "<<punt[a]<<" Posicion en memoria "<<&punt[a]<<endl;
            punt[a]=s;
            cout<<"\tAhora\n\tPosicion ["<<a<<"]\n\tNota "<<punt[a]<<" Posicion en memoria "<<&punt[a]<<endl;
        }
    }

    return 0;
}
