#include<stdio.h>
#include <stdlib.h>
#include<string.h>
// la estructura para el arreglo
struct person{
    //las partes de la estructura
    char name[15];
    char Ls_name[15];
    int age;
    char status[20];
    char gender[10];
};
void main(){
    int y,opc;
    //declaracion de una variable que sea del tipo de la estructura dentro
    struct person persona[3];
    for(y=0;y<3;y+=1){
//No se pueden colocar espacios ni en el nombre ni el apellido
        printf("Bienvenido al Sitema de Registro Civil\n");
        printf("Introduzca su nombre:\n");
        /*Se usa '&' para acceder a la dirrecion de mi variable tipo estructura y
        con el operador '.' accedemos a la parte de la estructura que queremos*/
        scanf(" %s",&persona[y].name);
        printf("Introduzca su apellido:\n");
        scanf(" %s",&persona[y].Ls_name);
        printf("Introduzca su edad:\n");
        scanf("%i",&persona[y].age);
        printf("Seleccione una de la dos opciones:\n");
        printf("Estado Civil:\n1-Soltero/a\n2-Casado/a\n");
        do{
          scanf("%i",&opc);
          if(opc<1 || opc>2)
           printf("Invalido\n");
        }while(opc<1 || opc>2);
        if(opc==1)
        /*'strcpy' se usa para enviar un dato fijado por nosotros
        a la dirrecion de una varable*/
            strcpy(persona[y].status,"Soltero/a");
        else
            strcpy(persona[y].status,"Casado/a");
        printf("Sexo:\n1-Masculino\n2-Femenino\n");
        do{
          scanf("%i",&opc);
          if(opc<1 || opc>2)
           printf("Invalido:\n");
        }while(opc<1 || opc>2);
        if(opc==1)
            strcpy(persona[y].gender,"Masculino");
        else
            strcpy(persona[y].gender,"Femenino");
        system("cls");

    }
    printf("Nombre\tApellido\tEdad\tEstado\t\tGenero\n");
    for(y=0;y<3;y++){
        printf("%s",persona[y].name);
        printf("\t%s",persona[y].Ls_name);
        printf("\t\t%i",persona[y].age);
        printf("\t%s",persona[y].status);
        printf("\t%s",persona[y].gender);
        printf("\n");
    }
    getchar();
}
