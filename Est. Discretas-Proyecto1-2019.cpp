#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<time.h>
int color[4]={YELLOW,LIGHTGREEN,LIGHTRED,LIGHTBLUE}; //Arreglo que contiene los 4 colores
int CantColor[8]={0,0,0,0,0,0,0,0}; //Arreglo que contiene el color de cada pais
int cA,cB,cC,cD,cE,cF,cG,cH; //variable del color de cada pais
char city[8] = {'A','B','C','D','E','F','G','H'};
//                   A,B,C,D,E,F,G,H
int matriz[8][8] = {{0,1,1,1,1,0,0,0},//A
                    {1,0,1,1,0,1,0,0},//B
                    {1,1,0,0,0,0,0,0},//C
                    {1,1,0,0,1,1,1,1},//D
                    {1,0,0,1,0,0,1,0},//E
                    {0,1,0,1,0,0,0,0},//F
                    {0,0,0,1,1,0,0,1},//G
                    {0,0,0,1,0,0,1,0}};//H
bool confirm(int color) //Funcion que verifica si ya se han pintado 2 ciudades del mismo color
{
    int cont=0,i;
    for(i=0;i<8;i++)
    {
        if(CantColor[i]==color) //Recorre el arreglo buscando si ya hay 2 paises con el mismo colo
            cont++;
    }
    if (cont>2)
        return false; //Si encuentra que ya hay 2 pintadas envia false
    else
        return true;

}
void color_A()
{
    int i;
    srand(time(NULL));
    i = 0 + rand()%(4);
    cA= color[i];
    CantColor[0]=cA;
}
void color_D()
{
    int i;
    bool pass;
    do
    {
        srand(time(NULL));
        i = 0 + rand()%(4);
        cD = color[i];
        CantColor[1]=cD;
    }while((cD==cA)||( confirm(cD)==false));

}
void color_E()
{
    int i;
    do
    {
        srand(time(NULL));
        i = 0 + rand()%(4);
        cE = color[i];
        CantColor[2]= cE;
    }while((cE==cA || cE == cD)||(confirm(cE)== false));
}
void color_B()
{
    int i;
    bool pass;
    do
    {
        srand(time(NULL));
        i = 0 + rand()%(4);
        cB= color[i];
        CantColor[3]= cB;
        confirm(cB);
    }while((cB==cA || cB == cD)||(confirm(cB) == false));
}
void color_G()
{
    int i;
    bool pass;
    do
    {
        srand(time(NULL));
        i = 0 + rand()%(4);
        cG = color[i];
        CantColor[4]= cG;
    }while((cG==cE || cG == cD)||(confirm(cG) == false));
}
void color_C()
{
     int i;
     bool pass;
    do
    {
        srand(time(NULL));
        i = 0 + rand()%(4);
        cC = color[i];
        CantColor[5]= cC;
    }while((cC==cA || cC == cB)||( confirm(cC) == false));
}
void color_F()
{
    int i;
    bool pass;
    do
    {
        srand(time(NULL));
        i = 0 + rand()%(4);
        cF = color[i];
        CantColor[6]= cF;
    }while((cF==cB || cF == cD)||(confirm(cF) == false));
}
void color_H()
{
    int i;
    bool pass;
    do
    {
        srand(time(NULL));
        i = 0 + rand()%(4);
        cH = color[i];
        CantColor[7] = cH;
        confirm(cH);
    }while((cH==cD || cH == cG)||(confirm(cH) == false));
}
void AdjMatrix()
{
    int i,j;
    printf("\t");
    for(i=0;i<8;i++)
        printf("%c\t",city[i]);
    for(i=0;i<8;i++)
    {
        printf("\n%c\t",city[i]);
        for(j=0;j<8;j++)
            printf("%i\t",matriz[i][j]);
    }

}
void Map()
{
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
    cleardevice();
    settextstyle(0,0,4);
    outtextxy(40,0," Mapa de Ciudades");
    // Rectangulo A
    setfillstyle(SOLID_FILL,cA);
    rectangle(200,200,300,350);
    floodfill(205,205,WHITE);
    settextstyle(0,0,4);
    outtextxy(235,250,"A");
        // Rectangulo B
    setfillstyle(SOLID_FILL,cB);
    rectangle(100,165,199,275);
    floodfill(105,170,WHITE);
    settextstyle(0,0,4);
    outtextxy(140,200,"B");
    // Rectangulo C
    setfillstyle(SOLID_FILL,cC);
    rectangle(100,276,199,375);
    floodfill(105,280,WHITE);
    settextstyle(0,0,4);
    outtextxy(140,290,"C");
    // Rectangulo D
    setfillstyle(SOLID_FILL,cD);
    rectangle(200,100,370,199);
    floodfill(205,105,WHITE);
    settextstyle(0,0,4);
    outtextxy(270,130,"D");
    // Rectangulo E
    setfillstyle(SOLID_FILL,cE);
    rectangle(301,200,410,280);
    floodfill(305,205,WHITE);
    settextstyle(0,0,4);
    outtextxy(340,220,"E");
    // Rectangulo F
    setfillstyle(SOLID_FILL,cF);
    rectangle(123,103,200,100);//
    floodfill(305,285,WHITE);
    settextstyle(0,0,4);
    outtextxy(340,310,"F");
    // Rectangulo G
    setfillstyle(SOLID_FILL,cG);
    rectangle(371,150,480,199);
    floodfill(375,155,WHITE);
    settextstyle(0,0,4);
    outtextxy(410,155,"G");
    //Rectangulo H
    setfillstyle(SOLID_FILL,cH);
    rectangle(371,80,480,198);
    floodfill(375,85,WHITE);
    settextstyle(0,0,4);
    outtextxy(410,100,"H");
    getch();
    setbkcolor(BLACK);
    cleardevice();
    closegraph();
}
//Grafo
void Graph()
{
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
    setbkcolor(BLACK);
    cleardevice();
    settextstyle(0,0,4);
    outtextxy(40,0," Grafo de Ciudades");
    // Circulo A
    setfillstyle(SOLID_FILL,cA);
    circle(250,200,30);
    floodfill(250,200,WHITE);
    settextstyle(0,0,2);
    outtextxy(240,190,"A");
    // Circulo B
    setfillstyle(SOLID_FILL,cB);
    circle(150,180,30);
    floodfill(150,180,WHITE);
    settextstyle(0,0,2);
    outtextxy(140,170,"B");
    // Circulo C
    setfillstyle(SOLID_FILL,cC);
    circle(150,280,30);
    floodfill(150,280,WHITE);
    settextstyle(0,0,2);
    outtextxy(140,270,"C");
    // Circulo D
    setfillstyle(SOLID_FILL,cD);
    circle(250,100,30);
    floodfill(250,100,WHITE);
    settextstyle(0,0,2);
    outtextxy(240,90,"D");
    // Circulo E
    setfillstyle(SOLID_FILL,cE);
    circle(340,190,30);
    floodfill(340,190,WHITE);
    settextstyle(0,0,2);
    outtextxy(330,180,"E");
    // Circulo F
    setfillstyle(SOLID_FILL,cF);
    circle(300,280,30);
    floodfill(300,280,WHITE);
    settextstyle(0,0,2);
    outtextxy(290,270,"F");
    // Circulo G
    setfillstyle(SOLID_FILL,cG);
    circle(390,130,30);
    floodfill(390,130,WHITE);
    settextstyle(0,0,2);
    outtextxy(380,120,"G");
    // Circulo H
    setfillstyle(SOLID_FILL,cH);
    circle(340,60,30);
    floodfill(340,60,WHITE);
    settextstyle(0,0,2);
    outtextxy(330,50,"H");
    line(250,170,250,130);
    line(220,190,180,180);
    line(220,210,175,265);
    line(260,220,300,250);
    line(280,200,312,200);
    line(280,110,340,160);
    line(340,220,300,250);
    line(280,100,320,80);
    line(360,80,390,100);
    line(370,180,390,160);
    getch();
    closegraph();
}
int main()
{
    int menu;
    color_A();
    color_D();
    color_E();
    color_B();
    color_G();
    color_C();
    color_F();
    color_H();
    do
    {
        system("cls");
        printf("\n\t\t\t\t\t\tProyecto #1\n\n\n");
        printf("\t\t1. Pantalla de Presentacion\n");
        printf("\t\t2. Conjunto Relacion\n");
        printf("\t\t3. Matriz de adyacencia\n");
        printf("\t\t4. Mapa de ciudades\n");
        printf("\t\t5. Grafo de ciudades\n");
        printf("\t\t6. Salir del programa\n\n");
        printf("\t\tIngrese su Opcion: ");
        scanf("%i",&menu);
        system("cls");
        switch(menu)
        {
            case 1:
      printf("\t\t\t\t\t\tUniversidad Tecnologica de Panamá\n\n");
     printf("\t\t\t\t\t      Facultad de Sistemas Computacionales\n\n");
     printf("\t\t\t\t\tLicenciatura en Ingenieria en Sistemas y Computacion\n\n");
     printf("\t\t\t\t\tDepartamento de Computacion y Simulacion de Sistemas\n\n");
     printf("\t\t\t\t\t    Estructuras Discretas para la Computacion\n\n");
     printf("\t\t\t\t\t\t\tProyecto N°1\n\n");
     printf("\t\t\t\t\t\t\t    Tema:\n\t\t\t\t\t\t     Tecnicas de Conteo\n\n");
     printf("\t\t\t\t\t\t\t Facilitador:\n\t\t\t\t\t\t  Ing.  Jacqueline S. de Ching\n\n");
     printf("\t\t\t\t\t\t\t  Integrantes:\n");
     printf("\t\t\t\t\t\tYahelis Montenegro  8-954-188\n");
     //printf("\t\t\t\t\t\tAnthony Avila\n\n");
     printf("\t\t\t\t\t\t\t     Grupo:\n");
     printf("\t\t\t\t\t\t\t    1IL-124\n");
                break;
            case 2:
                printf("\t\t\tRelation Set\n\n");
                printf("Conjunto = {A,B,C,D,E,F,G,H}\n\n");
                 break;
            case 3:
                printf("\t\t\t Adj Matrix\n\n");
                AdjMatrix();
                printf("\n\n\n");
                break;
            case 4:
                Map();
                 break;
            case 5:
                Graph();
                break;
            case 6:
                system("exit");
                 break;
            default:
                printf("Error... Try Again");
                 break;
        }
        system("pause");
    }while(menu !=6);
    return 0;
}
