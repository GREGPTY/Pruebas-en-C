#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Greg Torres idea general: 5 grupos, 1 matriz de 5x20.

int grp[20][5];
int may[5];
int men[5];
int prom[5];
int prom_gen=0;
int f,c,d;
//unciones para los mayores
int mayy_1(int grp[1][c]){
    int may1=0;
        for(c=0;c<20;c+=1){
            if(grp[1][c]>may1){
                may1=grp[1][c];
            }
        }
    return(may1);
}
int mayy_2(int grp[2][c]){
    int may2=0;

        for(c=0;c<20;c+=1){
            if(grp[2][c]>may2){
                may2=grp[2][c];
         }
        }
    return(may2);
}
int mayy_3(int grp[3][c]){
    int may3=0;
        for(c=0;c<20;c+=1){
            if(grp[3][c]>may3){
                may3=grp[3][c];
            }
         }
    return(may3);
}
int mayy_4(int grp[4][c]){
    int may4=0;
        for(c=0;c<20;c+=1){
            if(grp[4][c]>may4){
                may4=grp[4][c];

         }
        }
    return(may4);
}
int mayy_5(int grp[5][c]){
    int may5=0;
        for(c=0;c<20;c+=1){
            if(grp[5][c]>may5){
                may5=grp[5][c];
         }
        }
    return(may5);
}

//El mas Joven
void men_1(int grp[f][c]){
    int men1=0;

        for(c=0;c<20;c+=1){
            if(grp[1][c]<men1){
                men1=grp[5][c];
         }
        }
    return(men1);
}
void men_2(int grp[f][c]){
    int men2=0;

        for(c=0;c<20;c+=1){
            if(grp[2][c]<men2){
                men2=grp[2][c];
         }
        }
    return(men2);
}
void men_3(int grp[f][c]){
    int men3=0;

        for(c=0;c<20;c+=1){
            if(grp[3][c]<men3){
                men3=grp[3][c];
         }
        }
    return(men3);
}
void men_4(int grp[f][c]){
    int men4=0;

        for(c=0;c<20;c+=1){
            if(grp[4][c]<men[4]){
                men[4]=grp[4][c];
         }
        }
    return(men4);
}
void men_5(int grp[f][c]){
    int men5=0;

        for(c=0;c<20;c+=1){
            if(grp[5][c]<men5){
                men5=grp[5][c];
         }
        }
    return(men5);
}



void main(){
int aa,ab,ac,ad,ae;
for(c=0;c<5;c+=1){
printf("Introduzca las 20 edades para el grupo %i\n",c);
for(f=0;f<20;f+=1){
    printf("\nEspacio %i) ",f);
    scanf("%i",&grp[f][c]);
}

}
    aa=mayy_1(grp[1][c]);
    ab=mayy_2(grp[2][c]);
    ac=mayy_3(grp[3][c]);
    ad=mayy_4(grp[4][c]);
    ae=mayy_5(grp[5][c]);
//grupo1
        printf("\nEl mayor de grupo 1 es: %i ",aa);
        printf("\nEl Menor del grupo 1 es: %i ",men[1]);
//grupo2
        printf("\nEl mayor de grupo 2 es: %i ",ab);
        printf("\nEl Menor del grupo 2 es: %i ",men[2]);

//grupo3
        printf("\nEl mayor de grupo 3 es: %i ",ac);
        printf("\nEl Menor del grupo 3 es: %i ",men[3]);



}
