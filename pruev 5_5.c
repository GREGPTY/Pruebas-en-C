#include<stdio.h>
#include<math.h>

int f,c,b=1;
int mt5[5][5];

void main(){

    for(f=0;f<5;f+=1){
        for(c=0;c<5;c+=1){
            printf("Espacio (%i,%i): ",f,c);
            scanf("%i",&mt5[f][c]);
            if(mt5[f][c] %3==0){

            }
            else if(mt5[f][c] %5==0){

            }
            else if(mt5[f][c] %7==0){

            }
            else{
                c-=1;
            }
        }
    }


    for(f=0;f<5;f+=1){
        for(c=0;c<5;c+=1){
            printf("%i\t",mt5[f][c]);
        }
    }

}
