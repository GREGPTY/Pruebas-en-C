/*Universidad Tecnológica de Panamá
Facultad de Ingeniería de Sistemas Computacionales
Departamento de Computación y Simulación de Sistemas
Lic. en Ingeniería de Sistemas y Computación

LABORATORIO N°. 1 CONCEPTOS BÁSICOS DE CONJUNTOS
ESTRUCTURAS DISCRETAS PARA LA COMPUTACIÓN
Facilitador: Ing. Jacqueline S. de Ching

Integrantes:José De Gracia 8-947-207
            Milagros Vergara 8-956-924
Grupo: 1IL121
Fecha: 28 Abril 2019 */

#include <graphics.h>
int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    setfillstyle(SOLID_FILL,BLUE);
    rectangle(80, 70, 395, 330);
    floodfill(238, 200, WHITE);

    setfillstyle(SOLID_FILL,GREEN);
    circle(200, 200, 100);
    floodfill(110, 200, WHITE);
    setfillstyle(SOLID_FILL,GREEN);
    circle(275, 200, 100);
    floodfill(355, 200, WHITE);


    settextstyle(1,0,11);
    outtextxy(130,5,"Universidad Tecnológica de Panamá");
    settextstyle(1,0,11);
    outtextxy(80, 20,"Facultad de Ingeniería de Sistemas Computacionales");
    settextstyle(1,0,11);
    outtextxy(25, 40,"LABORATORIO N°. 1 CONCEPTOS BÁSICOS DE CONJUNTOS");
    settextstyle(4,0,12);
    outtextxy(125, 190, "A");
    settextstyle(4,0,12);
    outtextxy(325, 190, "B");
    settextstyle(4,0,12);
    outtextxy(230, 190, "C");
    settextstyle(4,0,12);
    outtextxy(355, 100, "U");
    settextstyle(4,0,12);
    outtextxy(100, 300, "(AUB)");
    settextstyle(1,0,11);
    outtextxy(100, 335, "Unión de A y B");
    settextstyle(1,0,11);
    outtextxy(100, 360, "Integrantes:José De Gracia 8-947-207");
    settextstyle(1,0,11);
    outtextxy(170, 380, "Milagros Vergara 8-956-924");

    getch();
    closegraph();
    return 0;
}
