#include <stdio.h>
void main(){
    int A=27;
    int *p;
    //Inicializacion de p con la direccion de A
    //p=&A;
    p=A;
    //Ver contenido de A
    printf("Contenido de A(Visto mediante A)= %d\n",A);
    printf("Contenido de A(Visto mediante p)= %d\n",*p);
    printf("Direccion de A= %p\n",&A);  //direccion de memoria %p
    printf("Direccion de A= %p\n",&p);
    printf("Direccion de A= %p\n",p);
    printf("%p",p);
}
