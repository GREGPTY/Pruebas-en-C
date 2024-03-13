#include "DM4th/DM4th.h"

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
