/*
Battleships
Version 1.0
Written by:  Greg Torres
*/
#include<stdio.h>
#include<strings.h>
#include<conio.h>
#include<time.h>
void delay(clock_t a)
{
    clock_t start;
    start  = clock();
    while(clock()-start<a)
    {

    }
}
int main()
{
    //A:Aircraft carrier
    //B:Battleship
    //D:destroyer
    //C:corvette
    int i,j,k=0,x,y,chk=0,win=0,uposa[5][2],uposb[4][2],uposd[3][2],uposc[2][2],a=0,b=0,c=0,d=0,probab,diff;
    char gridu[10][10],griduv[10][10],gridc[10][10],gridcv[10][10],orin[2],tempstr[10],str[20]="Battleships V1.0",str1[50]="Written By: Greg Torres Sproul",ch;
   for(i=0;i<10;i++)
    {
        printf("\n");
    }
    for(i=0;i<30;i++)
    {
        printf(" ");
    }
    for(i=0;str[i]!='\0';i++)
    {
        printf("%c",str[i]);
        delay(60);
    }
    printf("\n");
    for(i=0;i<30;i++)
    {
        printf(" ");
    }
    for(i=0;str1[i]!='\0';i++)
    {
        printf("%c",str1[i]);
        delay(60);
    }
    delay(1500);
    system("cls");
    for(;;)
    {
        system("cls");
        for(i=0;i<10;i++)
            printf("\n");
        for(i=0;i<30;i++)
            printf(" ");
        printf("1.Play Battleships\n");
        for(i=0;i<30;i++)
            printf(" ");
        printf("2.Rules\n");
        ch=getch();
        if(ch==49)
            break;
        if(ch==50)
        {
            system("cls");
            printf("Prepárate, porque una guerra ha sido declarada. Es hora de una guerra naval.\n");
            printf("1.Tienes que derrotar a tu oponente destruyendo todas sus naves de guerra antes de que él destruya al tuyo.\n");
            printf("2.El campo de batalla es una cuadrícula de 10x10 donde colocas tus naves.\n");
            printf("3.Puedes colocar tus naves ingresando su orientación, es horizontal o vertical. Para la orientación horizontal, escriba 'h' en la opción de orientación y escriba 'v' para vertical\n");
            printf("4.Y sus coordenadas x y (ambas separadas por un espacio) donde x es el número de fila e y es el número de columna\n");
            printf("5.Tienes una flota de 4 barcos de combate: portaaviones (5 unidades de largo), acorazado (4 unidades de largo), destructor (3 unidades de largo) y corbeta (2 unidades de largo)\n");
            printf("6.Después de colocar tus naves, puedes atacar el área enemiga. Para atacar un área específica, ingrese su coordenada x y (separada por un espacio)\n");
            printf("8.Si tu ataque golpea la nave enemiga, será denotado por una 'H'. Y obtienes un turno extra\n");
            printf("9.Si tu ataque falla, se indicará con un '*' y tu turno terminará\n");
            printf("pulsa enter para continuar.........");
            fflush(stdin);
            gets(tempstr);
            continue;
        }
    }
    system("cls");
    for(i=0;i<10;i++)
        printf("\n");
    for(i=0;i<30;i++)
    printf(" ");
    printf("Selecciona el nivel de dificultad:\n");
    for(i=0;i<30;i++)
    printf(" ");
    printf("1.easy\n");
    for(i=0;i<30;i++)
    printf(" ");
    printf("2.medium\n");
    for(i=0;i<30;i++)
    printf(" ");
    printf("3.hard\n");
    ch=getch();
    if(ch==49)
        diff=9;
    if(ch==50)
        diff=8;
    if(ch==51)
        diff=6;
    system("cls");
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            gridc[i][j]='.';
            gridu[i][j]='.';
            gridcv[i][j]='.';
        }
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<30;j++)
            printf(" ");
        if(i==0)
        {
            printf("  ");
            for(j=0;j<10;j++)
            printf("%d ",j);
            printf("\n");
            for(j=0;j<30;j++)
            printf(" ");
        }
        printf("%d ",i);
        for(j=0;j<10;j++)
            printf("%c ",gridu[i][j]);
        printf("\n");
    }
   /*Aircraft carrier*/
    for(;;)
    {
        printf("Aircraft Carrier:\n");
        printf("Orientation: ");
        scanf("%s",&orin);
        printf("x and y coordinates: ");
        scanf("%d %d",&x,&y);
        if(strcmp(orin,"h")==0)
        {
            if(y>5 || y<0 || x>9 || x<0)
            {
                printf("Can't place the ship. try again\n No se puede colocar el barco. Inténtalo de nuevo\n");
                continue;
            }
            else
            {
                for(i=y;i<y+5;i++)
                {
                    gridu[x][i]='A';
                    uposa[k][0]=x;
                    uposa[k][1]=i;
                    k++;
                }
                break;
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>5 || x<0 || y>9 || y<0)
            {
                printf("Can't place the ship. try again\n No se puede colocar el barco. Inténtalo de nuevo\n");
                continue;
            }
             else
            {
                for(i=x;i<x+5;i++)
                {
                    gridu[i][y]='A';
                    uposa[k][0]=i;
                    uposa[k][1]=y;
                    k++;
                }
                break;
            }
        }
    }
    k=0;
    system("cls");
    for(i=0;i<10;i++)
    {
        for(j=0;j<30;j++)
            printf(" ");
        if(i==0)
        {
            printf("  ");
            for(j=0;j<10;j++)
            printf("%d ",j);
            printf("\n");
            for(j=0;j<30;j++)
            printf(" ");
        }
        printf("%d ",i);
        for(j=0;j<10;j++)
            printf("%c ",gridu[i][j]);
        printf("\n");
    }
    /*B:Battleship*/
    for(;;)
    {
        chk=0;
        printf("Battleship:\n");
        printf("Orientation: ");
        scanf("%s",&orin);
        printf("x and y coordinates: ");
        scanf("%d %d",&x,&y);
        if(strcmp(orin,"h")==0)
        {
            if(y>6 || y<0 || x>9 || x<0)
            {
                printf("Can't place the ship. try again\n");
                continue;
            }
            else
            {

                for(i=y;i<y+4;i++)
                {
                    if(gridu[x][i]!='.')
                    {
                        printf("Can't place the ship. try again\n");
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+4;i++)
                    {
                        gridu[x][i]='B';
                        uposb[k][0]=x;
                        uposb[k][1]=i;
                        k++;
                    }
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>6 || x<0 || y>9 || y<0)
            {
                printf("Can't place the ship. try again\n");
                continue;
            }
             else
            {
                 for(i=x;i<x+4;i++)
                {
                    if(gridu[i][y]!='.')
                    {
                        printf("Can't place the ship. try again\n");
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                   for(i=x;i<x+4;i++)
                    {
                        gridu[i][y]='B';
                        uposb[k][0]=i;
                        uposb[k][1]=y;
                        k++;
                    }
                    break;
                }
            }
        }
    }
    k=0;
    system("cls");
    for(i=0;i<10;i++)
    {
        for(j=0;j<30;j++)
            printf(" ");
        if(i==0)
        {
            printf("  ");
            for(j=0;j<10;j++)
            printf("%d ",j);
            printf("\n");
            for(j=0;j<30;j++)
            printf(" ");
        }
        printf("%d ",i);
        for(j=0;j<10;j++)
            printf("%c ",gridu[i][j]);
        printf("\n");
    }
    /*Destroyer*/
    for(;;)
    {
        chk=0;
        printf("Destroyer:\n");
        printf("Orientation: ");
        scanf("%s",&orin);
        printf("x and y coordinates: ");
        scanf("%d %d",&x,&y);
        if(strcmp(orin,"h")==0)
        {
            if(y>7 || y<0 || x>9 || x<0)
            {
                printf("Can't place the ship. try again\n");
                continue;
            }
            else
            {
                for(i=y;i<y+3;i++)
                {
                    if(gridu[x][i]!='.')
                    {
                        printf("Can't place the ship. try again\n");
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+3;i++)
                    {
                        gridu[x][i]='D';
                        uposd[k][0]=x;
                        uposd[k][1]=i;
                        k++;
                    }
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>7 || x<0 || y>9 || y<0)
            {
                printf("Can't place the ship. try again\n");
                continue;
            }
             else
            {
                 for(i=x;i<x+3;i++)
                {
                    if(gridu[i][y]!='.')
                    {
                        printf("Can't place the ship. try again\n");
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+3;i++)
                    {
                        gridu[i][y]='D';
                        uposd[k][0]=i;
                        uposd[k][1]=y;
                        k++;
                    }
                    break;
                }
            }
        }
    }
    k=0;
    system("cls");
    for(i=0;i<10;i++)
    {
        for(j=0;j<30;j++)
            printf(" ");
        if(i==0)
        {
            printf("  ");
            for(j=0;j<10;j++)
            printf("%d ",j);
            printf("\n");
            for(j=0;j<30;j++)
            printf(" ");
        }
        printf("%d ",i);
        for(j=0;j<10;j++)
            printf("%c ",gridu[i][j]);
        printf("\n");
    }
    /*Corvette*/
    for(;;)
    {
        chk=0;
        printf("Corvette:\n");
        printf("Orientation: ");
        scanf("%s",&orin);
        printf("x and y coordinates: ");
        scanf("%d %d",&x,&y);
        if(strcmp(orin,"h")==0)
        {
            if(y>8 || y<0 || x>9 || x<0)
            {
                printf("Can't place the ship. try again\n");
                continue;
            }
            else
            {
                for(i=y;i<y+2;i++)
                {
                    if(gridu[x][i]!='.')
                    {
                        printf("Can't place the ship. try again\n");
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+2;i++)
                    {
                        gridu[x][i]='C';
                        uposc[k][0]=x;
                        uposc[k][1]=i;
                        k++;
                    }
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>8 || x<0 || y>9 || y<0)
            {
                printf("Can't place the ship. try again\n");
                continue;
            }
             else
            {
                 for(i=x;i<x+2;i++)
                {
                    if(gridu[i][y]!='.')
                    {
                        printf("Can't place the ship. try again\n");
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+2;i++)
                    {
                        gridu[i][y]='C';
                        uposc[k][0]=i;
                        uposc[k][1]=y;
                        k++;
                    }
                    break;
                }
            }
        }
    }
    system("cls");
    for(i=0;i<10;i++)
    {
        for(j=0;j<30;j++)
            printf(" ");
        if(i==0)
        {
            printf("  ");
            for(j=0;j<10;j++)
            printf("%d ",j);
            printf("\n");
            for(j=0;j<30;j++)
            printf(" ");
        }
        printf("%d ",i);
        for(j=0;j<10;j++)
            printf("%c ",gridu[i][j]);
        printf("\n");
    }
    printf("Press enter to continue......");
    fflush(stdin);
    gets(tempstr);
    srand(time(NULL));
    /*Aircraft carrier cpu*/
    for(;;)
    {
        if(rand()%2 == 1)
            strcpy(orin,"h");
        else strcpy(orin,"v");
        x=rand()%10;
        y=rand()%10;
        if(strcmp(orin,"h")==0)
        {
            if(y>5 || y<0 || x>9 || x<0)
            {
                continue;
            }
            else
            {
                for(i=y;i<y+5;i++)
                    gridc[x][i]='A';
                break;
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>5 || x<0 || y>9 || y<0)
            {
                continue;
            }
             else
            {
                for(i=x;i<x+5;i++)
                    gridc[i][y]='A';
                break;
            }
        }
    }
    /*B:Battleship cpu*/
    for(;;)
    {
        chk=0;
        if(rand()%2 == 1)
            strcpy(orin,"h");
        else strcpy(orin,"v");
        x=rand()%10;
        y=rand()%10;
        if(strcmp(orin,"h")==0)
        {
            if(y>6 || y<0 || x>9 || x<0)
                continue;
            else
            {
                for(i=y;i<y+4;i++)
                {
                    if(gridc[x][i]!='.')
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+4;i++)
                        gridc[x][i]='B';
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>6 || x<0 || y>9 || y<0)
            {
                continue;
            }
             else
            {
                 for(i=x;i<x+4;i++)
                {
                    if(gridc[i][y]!='.')
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+4;i++)
                        gridc[i][y]='B';
                    break;
                }
            }
        }
    }
    /*Destroyer cpu*/
    for(;;)
    {
        chk=0;
        if(rand()%2 == 1)
            strcpy(orin,"h");
        else strcpy(orin,"v");
        x=rand()%10;
        y=rand()%10;
        if(strcmp(orin,"h")==0)
        {
            if(y>7 || y<0 || x>9 || x<0)
            {
               continue;
            }
            else
            {
                for(i=y;i<y+3;i++)
                {
                    if(gridc[x][i]!='.')
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+3;i++)
                        gridc[x][i]='D';
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>7 || x<0 || y>9 || y<0)
            {
                continue;
            }
             else
            {
                 for(i=x;i<x+3;i++)
                {
                    if(gridc[i][y]!='.')
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+3;i++)
                        gridc[i][y]='D';
                    break;
                }
            }
        }
    }
    /*Corvette cpu*/
    for(;;)
    {
        chk=0;
        if(rand()%2 == 1)
            strcpy(orin,"h");
        else strcpy(orin,"v");
        x=rand()%10;
        y=rand()%10;
        if(strcmp(orin,"h")==0)
        {
            if(y>8 || y<0 || x>9 || x<0)
            {
                continue;
            }
            else
            {
                for(i=y;i<y+2;i++)
                {
                    if(gridc[x][i]!='.')
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=y;i<y+2;i++)
                        gridc[x][i]='C';
                    break;
                }
            }
        }
        if(strcmp(orin,"v")==0)
        {
            if(x>8 || x<0 || y>9 || y<0)
            {
                continue;
            }
             else
            {
                 for(i=x;i<x+2;i++)
                {
                    if(gridc[i][y]!='.')
                    {
                        chk=1;
                        break;
                    }
                }
                if(chk==1)
                    continue;
                else
                {
                    for(i=x;i<x+2;i++)
                        gridc[i][y]='C';
                    break;
                }
            }
        }
    }
   /* system("cls");
    for(i=0;i<10;i++)
    {
        if(i==0)
        {
            printf("  ");
            for(j=0;j<10;j++)
            printf("%d ",j);
            printf("\n");
        }
        printf("%d ",i);
        for(j=0;j<10;j++)
            printf("%c ",gridc[i][j]);
        printf("\n");
    }    printf("Press enter to continue......");
    fflush(stdin);
    gets(tempstr);*/
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            griduv[i][j]=gridu[i][j];
    }
    for(;;)
    {
        system("cls");
        for(i=0;i<10;i++)
        {
            for(j=0;j<30;j++)
            printf(" ");
            if(i==0)
            {
                printf("  ");
                for(j=0;j<10;j++)
                printf("%d ",j);
                printf("\n");
                for(j=0;j<30;j++)
                printf(" ");
            }
            printf("%d ",i);
            for(j=0;j<10;j++)
                printf("%c ",gridcv[i][j]);
            printf("\n");
        }
        printf("\n");
        for(i=0;i<10;i++)
        {
            for(j=0;j<30;j++)
            printf(" ");
            if(i==0)
            {
                printf("  ");
                for(j=0;j<10;j++)
                printf("%d ",j);
                printf("\n");
                for(j=0;j<30;j++)
                printf(" ");
            }
            printf("%d ",i);
            for(j=0;j<10;j++)
                printf("%c ",griduv[i][j]);
            printf("\n");
        }
        for(;;)
        {
            printf("Enter x and y: ");
            scanf("%d %d", &x,&y);
            if(x>9 || x<0 || y>9 || y<0 || gridcv[x][y]=='H' || gridcv[x][y]=='*')
            {
                printf("Invalid input. Try again\n");
                continue;
            }
            else
            {
                if(gridc[x][y]=='A' || gridc[x][y]=='B'||gridc[x][y]=='C'||gridc[x][y]=='D')
                {
                    if(gridcv[x][y]!='H')
                    {
                        gridcv[x][y]='H';
                        system("cls");
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<30;j++)
                            printf(" ");
                            if(i==0)
                            {
                                printf("  ");
                                for(j=0;j<10;j++)
                                    printf("%d ",j);
                                printf("\n");
                                for(j=0;j<30;j++)
                                printf(" ");
                            }
                            printf("%d ",i);
                            for(j=0;j<10;j++)
                                printf("%c ",gridcv[i][j]);
                            printf("\n");
                        }
                        printf("\n");
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<30;j++)
                            printf(" ");
                            if(i==0)
                            {
                                printf("  ");
                                for(j=0;j<10;j++)
                                    printf("%d ",j);
                                printf("\n");
                                for(j=0;j<30;j++)
                                printf(" ");
                            }
                            printf("%d ",i);
                            for(j=0;j<10;j++)
                                printf("%c ",griduv[i][j]);
                            printf("\n");
                        }
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<10;j++)
                            {
                                if(gridcv[i][j]=='H')
                                    win++;
                            }
                        }
                        if(win==14)
                        {
                            printf("\nYou win!\n");
                            break;
                        }
                        win=0;
                        continue;
                    }
                    else
                    {
                        printf("Invalid Input. Try again\n");
                        continue;
                    }
                }
                else
                {
                    gridcv[x][y]='*';
                    break;
                }
            }
        }
        for(;;)
        {
            probab=rand()%diff;
            if(probab==diff-3&& a<5)
            {
                x=uposa[a][0];
                y=uposa[a][1];
                a++;
            }
            else if(probab==diff-2 && b<4)
            {
                x=uposb[b][0];
                y=uposb[b][1];
                b++;
            }
            else if(probab==diff-5 && d<3)
            {
                x=uposd[d][0];
                y=uposd[d][1];
                d++;
            }
            else if(probab==diff-6 && c<2)
            {
                x=uposc[c][0];
                y=uposc[c][1];
                c++;
            }
            else
            {
                x=rand()%10;
                y=rand()%10;
            }
            if(x>9 || x<0 || y>9 || y<0 || griduv[x][y]=='H' || griduv[x][y]=='*')
            {
                continue;
            }
            else
            {
                if(gridu[x][y]=='A' || gridu[x][y]=='B'||gridu[x][y]=='C'||gridu[x][y]=='D')
                {
                    if(griduv[x][y]!='H')
                    {
                        griduv[x][y]='H';
                        system("cls");
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<30;j++)
                            printf(" ");
                            if(i==0)
                            {
                                printf("  ");
                                for(j=0;j<10;j++)
                                    printf("%d ",j);
                                printf("\n");
                                for(j=0;j<30;j++)
                                printf(" ");
                            }
                            printf("%d ",i);
                            for(j=0;j<10;j++)
                                printf("%c ",gridcv[i][j]);
                            printf("\n");
                        }
                        printf("\n");
                        for(i=0;i<10;i++)
                        {
                            for(j=0;j<30;j++)
                            printf(" ");
                            if(i==0)
                            {
                                printf("  ");
                                for(j=0;j<10;j++)
                                    printf("%d ",j);
                                printf("\n");
                                for(j=0;j<30;j++)
                                printf(" ");
                            }
                            printf("%d ",i);
                            for(j=0;j<10;j++)
                                printf("%c ",griduv[i][j]);
                            printf("\n");
                        }
                        delay(1000);
                        continue;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    griduv[x][y]='*';
                    break;
                }
            }

        }
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                if(gridcv[i][j]=='H')
                    win++;
            }
        }
        if(win==14)
        {
            printf("\nYou win!\n");
            break;
        }
        win=0;
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                if(griduv[i][j]=='H')
                    win++;
            }
        }
        if(win==14)
        {
            printf("\nYou lose!\n");
            break;
        }
        win=0;
    }
    return 0;
}
