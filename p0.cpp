#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "DM4th/DM4th.h"

using namespace std;

int main(){
 NDArray<number> caminos = items<number>(
 0,1,0,0,
 0,0,0,1,
 0,0,0,0,
 1,0,1,0
 ).reshape(4,4);
 NDArray<number> resultado = warshall(caminos);
 cout<<"El resultado es:"<<endl;
 cout<<resultado<<endl;
 cin.get();
 return 0;
}
