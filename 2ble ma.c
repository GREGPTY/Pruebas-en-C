#include<stdio.h>
#include<math.h>
int f=0,c=0,ma1[5][3],ma2[5][3];

void potencia(){
    for(f=0;f<5;f+=1){
        for(c=0;c<=3;c+=1){
                if(c%2==0){
                    ma2[f][c]=pow(ma1[f][c],2);
                }
                else
                    ma2[f][c]=pow(ma1[f][c],3);
        }
    }

}

void main(){
    printf("Introduzca sus 15 numeros\n");
    for(f=0;f<5;f+=1){
        for(c=0;c<=3;c+=1){
                printf("\n%i %i) ",f,c);
            scanf("%i",&ma1[f][c]);
        }
    }
    for(f=0;f<5;f+=1){
        for(c=0;c<=3;c+=1){
                printf("\n%i %i) %i",f,c,ma2[f][c]);
        }
    }
}
