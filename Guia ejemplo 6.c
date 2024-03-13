#include<stdio.h>
#include<string.h>
void main(){
char b[3][20];
strcpy(b[0],"hola mundo");//es unb[] funcion que b[]lmb[]cenb[] unb[] cb[]denb[], el primero es lb[] vb[]rib[]ble y lb[] segundb[] el contenido
strcpy(b[1],"estoy contento");
strcpy(b[2],"con la vida");

printf("%c  %u\n",b,b); //con el *(letrb[] p + el numero de posision que queremos buscb[]r)
for(int i=0;i<3;i=+1)
    printf("%s %u\n",b[i],b[i]);
getchar();
}

