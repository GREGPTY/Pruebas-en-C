#include<stdio.h>
#include<string.h>
void main(){
//char a[10],*p;
char *p;
//strcpy(a,"hola");//es una funcion que almacena una cadena, el primero es la variable y la segunda el contenido
p="Hola como estas"; //el puntero esta buscando la primera posision de la memoria y rellena las demas
printf("%s\n",p);
getchar();
}
