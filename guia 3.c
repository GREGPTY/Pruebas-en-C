#include<stdio.h>
#include<string.h>
void main(){
char a[10],*p;
strcpy(a,"hola");//es una funcion que almacena una cadena, el primero es la variable y la segunda el contenido
p=a;
printf("%c  %c\n",*(p+1),a[1]); //con el *(letra p + el numero de posision que queremos buscar)
getchar();
}
