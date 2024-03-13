#include<stdio.h>
#include<math.h>

int M1[5][3],M2[5][3];

void potencia(){
    int f,c;
    for(f=0;f<5;f+=1){
        for(c=0;c<3;c+=1){
            if(c%2==0)
                M2[f][c]=pow(M1[f][c],2);
            else
                M2[f][c]=pow(M1[f][c],3);
        }
    }
}

void main(){
    int f,c;
    printf("Introduzca los 15 valores\n");
    for(f=0;f<5;f+=1){
        for(c=0;c<3;c+=1){
            printf("\n%i,%i). ",f,c);
            scanf("%i",&M1[f][c]);
        }
    }
    for(f=0;f<5;f+=1){
        for(c=0;c<3;c+=1){
        printf("\n%i,%i). %i",f,c,M1[f][c]);
        }
    }
    printf("\n");

    for(f=0;f<5;f+=1){
        for(c=0;c<3;c+=1){
            printf("\n%i,%i). %i",f,c,M2[f][c]);
        }
    }
}
