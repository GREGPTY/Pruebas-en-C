#include<stdio.h>
#include <stdlib.h>
#include<string.h>
struct person{
    char name[20];
    char L_name[20];
    int age;
    char status[20];
    char gender[10];
};
void main(){
    int y,opc;
    struct person persona[3],*p;
/*Aqui se inicializa nuestro puntero
en la direccion inicial de nuestro arreglo tipo estructura*/
    p=&persona[0];
    for(y=0;y<3;y+=1){
//No se pueden colocar espacios ni en el nombre ni el apellido
        printf("Bienvenido al Sitema de Registro Civil\n");
        printf("Introduzca su nombre:\n");
/*Como estamos usando punteros para llamar a la direccion de su objeto
se usa (*(nombre del puntero+la posicion que vayamos a usar))*/
        scanf(" %s",&(*(p+y)).name);
        printf("Introduzca su apellido:\n");
        scanf(" %s",&(*(p+y)).L_name);
        printf("Introduzca su edad:\n");
        scanf("%i",&(*(p+y)).age);
        printf("Seleccione una de la dos opciones:\n");
        printf("Estado Civil:\n1-Soltero/a\n2-Casado/a\n");
        do{
          scanf("%i",&opc);
          if(opc<1 || opc>2)
           printf("Invalido\n");
        }while(opc<1 || opc>2);
        if(opc==1)
/*Ya que usamos punteros para tener acceso
a su objeto nesitamos usar el operador '->'*/
            strcpy((p+y)->status,"Soltero/a");
        else
            strcpy((p+y)->status,"Casado/a");
        printf("Sexo:\n1-Masculino\n2-Femenino\n");
        do{
          scanf("%i",&opc);
          if(opc<1 || opc>2)
           printf("Invalido:\n");
        }while(opc<1 || opc>2);
        if(opc==1)
            strcpy((p+y)->gender,"Masculino");
        else
            strcpy((p+y)->gender,"Femenino");
        system("cls");
    }
    printf("Nombre\tApellido\tEdad\tEstado\t\tGenero\n");
    for(y=0;y<3;y+=1){
        printf("%s",(*(p+y)).name);
        printf("\t%s",(*(p+y)).L_name);
        printf("\t\t%i",(*(p+y)).age);
        printf("\t%s",(*(p+y)).status);
        printf("\t%s",(*(p+y)).gender);
        printf("\n");
    }
    getchar();
}
