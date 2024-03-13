#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define NC 472395817
#define CAP 2000

float totp=0,bopr=0,bopt=0,dinpa1=0,totallf=0,dina=0,bolsa,sum=0,rest=0,re,reti=0,tot=0,mov[100],totall[100];
float cap_tal=0,a=0,b=0,c=0,tott,totc;
int mo,conteo=1,mot=0,maxi=1500;
char drt[100];
//char dt[100][16];
char nam[16];

float dep(float din){
float capital=0;

bolsa=bolsa+din;
mot+=1;
conteo+=1;
    return(bolsa);
}

float ret(float din){

bolsa-=din;
mot+=1;
conteo+=1;
return(bolsa);
}

float tra(float din){

bolsa-=din;
mot+=1;
conteo+=1;
return(bolsa);
}

void main(){
    /*Para la escritura con espacios
    scanf("%[^\n]"); //hasta que no de un salto de linea lo va a leer
    fflush(stdin); //se utiliza para que no se error ya que limpia el buffer
    */
    int n_c,Resp,a,movd=0,movt=0;
    float aa,dinpa=0,dinmues=0,din,re=0,di=0;
    bolsa=0;
    char nom[30],ressn;
    printf("Por favor introduzca su numero de cuenta \n");
    scanf("%i",&n_c);
    if(n_c==NC){
        printf("\t\t\t Bienvenido a ABC Bank");
     printf("\n Por favor introduzca su nombre: \n");
     fflush(stdin);
     gets(nom);
     //gets(nom);

    printf("\n Comencemos, para abrir una cuenta primero debe hacer un deposito de minimo $100\n");
    scanf("%f",&bolsa);
    if(bolsa<100){
    do{
        printf("\n Cantidad insuficiente, por favor introduzca mas\n");
            scanf("%f",&di);
            bolsa+=di;
    }while(bolsa<100);
    }
    dina=bolsa;
    for(mo=1;mo<=100;mo+=1){

    //do{
        printf("\n\t\t\tABC BANK\n 1. DEPOSITO \n 2. RETIRO\n 3. TRANSFERENCIA\n 4. SALIR\n ");
     scanf("%i",&a);

     switch(a){
case 1:
        printf("\t Monto a Depositar \n ");
        scanf("%f",&din);
        totall[mo]=dep(din);
        mov[mo]=din;
        sum+=din;
        a=(1.25/100);
        cap_tal+=a;
        drt[mo]='d';


        break;
case 2:
    if(movd<4){ //4
    printf("\t Monto a Retirar \n ");
        scanf("%f",&din);
        if(din<bolsa){ //3
                bopr=0;
                bopr=bolsa;
                bopr=bopr-din;
            if(bopr>100){//2
            dinpa+=din;
            dinpa1=dinpa;
                if(dinpa<1500){ //1
                totall[mo]=dep(din);
                mov[mo]=din;
                rest+=din;
                //dt[mo][16]=drt;
                movd+=1;
                drt[mo]='r';
                }
                else{ //1
                mo-=1;
                dinpa1=0;
                dinpa-=din;
                }
            }
            else{ //2
            printf("\nNo puedes quedar con menos de $100 en tu cuenta\n");
            mo-=1;
            }
        }
        else{ //3
            printf("\nNo puedes sacar mas dinero del que tienes\n");
            mo-=1;
        }
     }
    else{ //4
        printf("Haz la cantidad maxima de movimientos en un dia");
        mo-=1;
        }
        break;
case 3:
    if(movt<3){//1
    printf("\t Monto a Transferir \n ");
        scanf("%f",&din);
        if(din<bolsa){//2
                bopt=0;
                bopt=bolsa;
                bopt=bopt-din;
             if(bopt>100){//3
                    re=tra(din);
                    mov[mo]=din;
                    rest+=din;
                    movt+=1;
                    drt[mo]='t';
                    //dt[mo][16]=drt;
             }
             else{//3
                printf("\nNo puede quedar con menos de $100 en su cuenta\n");
                mo-=1;
             }
        }
        else{ //2
            printf("\nNo puedes quedar en 0\n");
            mo-=1;
        }
    }
        else{ //1
            printf("Ya no acepta mas movimientos de transacciones\n");
            mo-=1;
        }
    break;
case 4:
    printf("Saliendo del programa\n");
    break;
default:
    printf("Opcion no aceptada, intente con otra");
    mo-=1;
    }
     if(a==4){
     break;
     }
    //}while(mo==conteo);
    }
    system("cls");
    totp=dina+sum;
    totc=0;
    totc=cap_tal;
    tot=totp-rest;
    tott=0;
    tott=tot+totc;

    printf("\t\t\tBANCO ABC %c ESTADO DE CUENTA\n\n Cliente:%s \nN%c de Cuenta: %i\n\n",45,nom,167,n_c);
    printf("\nN%c \tTipo de Transacci%cn     \t Monto \t\n",167,162);
    for(mo=1;mo<=mot;mo+=1){
    if(drt[mo]=='d'){
    printf("\n%i. \tDeposito                \t $%.2f \t\n",mo,mov[mo]);
    }
    else if(drt[mo]=='r'){
    printf("\n%i. \tRetiro                  \t $%.2f \t\n",mo,mov[mo]);
    }
    else if(drt[mo]=='t'){
    printf("\n%i. \tTransferencia           \t $%.2f \t\n",mo,mov[mo]);
    }
    else{
        printf("\nDafack\n");
    }
    }
    printf("\nSaldo de cuenta: $%.2f ",tott);
    }
    else{
        printf("Usted no aparece en el sistema, lo sentimos");
    }

}
