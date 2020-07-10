#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include "affichage.h"
#include "conio2.h"

/**===================partie affichage==================**/


void cadre_aff ( int l , int L , int x , int y ) /// Dessine un cadre de longeur == L et de largeur == l à partir du point M(x,y) de la console
{
    int i ;
    gotoxy(x,y);
    printf("%c",201);
    gotoxy(x,y + L);
    printf("%c",200);
    gotoxy(x+l,y);
    printf("%c",187);
    gotoxy(x+l,y+L);
    printf("%c",188);
    for (i=1 ; i <= l-1 ; i++  )
    {
        gotoxy(x+i,y);
        printf("%c",205);
        gotoxy(x+i,y+L);
        printf("%c",205);
    }
    for (i=1 ; i <= L-1; i++ )
    {
        gotoxy(x,y+i);
        printf("%c",186);
        gotoxy(x+l,y+i);
        printf("%c",186);
    }
}

void cadre1()               /// "CADR2" EST UN PROCEDEUR PERMET D'AFFICHER UN CADRE DANS LA CONSOLE(pour le menu)
{
       int i;
       gotoxy(1,2);
       for (i=0;i<=115;i++)
        {
                            textcolor (BLACK);
                            printf("%c",176);
                          }
       gotoxy(1,13) ;
       for (i=0;i<=115;i++){
                            textcolor (3);
                            printf("%c",176);
                          }
       gotoxy(1,42);
       for (i=0;i<=115;i++){
                            textcolor (BLACK);
                            printf("%c",176);
                          }
       for (i=3;i<=41;i++){
                           gotoxy(1,i) ;
                           textcolor (3);
                           printf("%c",186) ;
                           printf("%c",186) ;
                           gotoxy(115,i);
                           textcolor (3);
                           printf("%c",186) ;
                           printf("%c",186) ;
                         }
      textcolor (15);
}
void parler(char *chaine)  ///faire du sens on introduit juste la chaine de charactere
{
            char temp1[256];
            sprintf(temp1,"echo m=\"%s\" > file.vbs",chaine);
            system(temp1);
            sprintf(temp1,"echo CreateObject(\"SAPI.SpVoice\").Speak m >> file.vbs");
            system(temp1);
            sprintf(temp1,"file.vbs");
            system(temp1);
            remove("file.vbs");
         }
void etoile_cadre()       ///cadre avec des etoiles
{
      int j,k,u;
    textcolor(3);
    Sleep(1000);
    for (j=0;j<28;j++)
    {
     delay(15);
     printf("* * ");
    }
    gotoxy(1,2);
    for(k=0 ; k<38 ; k++)
    {
        delay(15);
        printf("*\n");
    }
    for(u=0;u<41; u++)
    {
    gotoxy(111,u);
    delay(15);
     printf("*");
    }
    gotoxy(3,40);int r;
    for(r=0;r<27;r++){
        delay(15);
        printf("* * ");

    }

}
void page_1()            ///page de couverture
{

    system("color F1");textbackground(WHITE);
     etoile_cadre();

    printf("\n");
    gotoxy(5,3);
    Sleep(500);textcolor(0);
    printf("                                   REPUBLIQUE ALGERIENNE DEMOCRATIQUE ET POPULAIRE \n ");Sleep(200);
    printf("                               MINISTERE DE L'ENSEIGNEMET ET DE LA RECHERCHE SCIENTIFIQUE \n");Sleep(200);
    printf("                                      1ere annee classes preparatoires integres              \n");Sleep(200);
    gotoxy(3,4);
    textcolor(0);
    printf("%C%C%C%C%c%c  %C%C%C%C%C",219,219,219,219,219,219,219,219,219,219,219);gotoxy(3,5);
    printf("%C%C      %c%c            ",219,219,219,219);gotoxy(3,6);
    Sleep(500);
    printf("%c%c      %C%c      %C%C   ",219,219,219,219,219,219);gotoxy(3,7);
    printf("%c%c%C%C%C%C  %c%C%C%C%C   %C%C",219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(3,8);
    Sleep(500);
    printf("%C%C         %C%c   %C%C",219,219,219,219,219,219);gotoxy(3,9);
    printf("%C%C         %C%C   %C%C",219,219,219,219,219,219);gotoxy(3,10);
    printf("%C%C%C%C%C%C  %C%C%C%C%C   %C%C",219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(3,11);
    gotoxy(19,4);
    Sleep(500);
    textcolor(3);
    printf("%c%c",219,219);


        gotoxy(56,14); textcolor(0);
    Sleep(500);
    cadre_aff(45,7,56,14);


    textcolor(1);Sleep(500);
    gotoxy(58,16);Sleep(200);
    printf(" TP1 structure de fichier     ");Sleep(200);
    gotoxy(58,18);
    printf("   et srtucture dynamique (sfsd)      ");Sleep(200);
    textcolor(0);
    gotoxy(47,26);Sleep (500);cadre_aff(50,9,47,26);
    Sleep(500);
    gotoxy(49,28);textcolor(1);Sleep(200);
    printf("       Realise par:                     ");gotoxy(49,30);textcolor(3);Sleep(200);
    printf("       BEROUAKEN MAROUA ~~ ARAB ASMA     ");gotoxy(49,32);textcolor(1);Sleep(200);
    printf("       section : B ~~ groupe : 5       ");

    gotoxy(14,39);
    system("pause");
}

void page_2()
{
    int i,j =50,u;
    system("color 02");
for (i=1;i<=10;i++)
{
    system("cls");
    gotoxy(j,i);
    printf("%C%C%C%C%C%C%C%C%C%C%C%C%C          %C%C%C%C%C%C%C%C%C%C%C%C        %C%C%C%C%C%C%C%C%C",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(j,i+1);
    printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C         %C%C%C%C%C%C%C%C%C%C%C%C      %C%C%C%C%C%C%C%C%C%C%C%C",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(j,i+2);
    printf("%C%C%C         %c%C%C        %C%C%C              %C%C          %C%C ",219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(j,i+3);
    printf("%C%C%C         %C%C%C        %C%C%C              %C%C          %C%C ",219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(j,i+4);
    printf("%C%C%C         %c%C%C        %C%C%C              %C%C          %C%C ",219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(j,i+5);
    printf("%C%C%C         %C%C%C        %C%C%C              %C%C          %C%C ",219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(j,i+6);
    printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C         %C%C%C%C%C%C%C%C%C%C%C%C     %C%C%C%C%C%C%C%C%C%c%C%C%C%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(j,i+7);
    printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C         %C%C%C%C%C%C%C%C%C%C%C%C     %c%C%C%C%C%C%C%C%C%C%C%C%C%C",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(j,i+8);
    printf("%C%C%C         %c%C%C                 %C%C%C     %C%C          %C%C ",219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(j,i+9);
    printf("%C%C%C         %C%C%C                 %C%C%C     %C%C          %C%C ",219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(j,i+10);
    printf("%C%C%C         %c%C%C                 %C%C%C     %C%C          %C%C ",219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(j,i+11);
    printf("%C%C%C         %C%C%C                 %C%C%C     %C%C          %C%C ",219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(j,i+12);
    printf("%C%C%C         %C%C%C        %C%c%C%C%C%C%c%C%C%C%C%C     %C%C          %C%C ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(j,i+13);
    printf("%C%C%C         %C%C%C        %C%C%C%C%C%C%C%C%C%C%C%C     %c%C          %C%C ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);gotoxy(j,i+14);

delay(50);

}
gotoxy(35,28);
    for(u=1;u<86;u++)
    {

        gotoxy( wherex() , 28);
        printf("%c",219);
        gotoxy( wherex()-1 , 29 );
        printf("%c",219);
        delay(10);
    }
    gotoxy(50,32);
    printf("veuillez patienter pour rentrer au menu...\n\n");
    getch();
}


void dessine_menu (int x , int y) // Dessine le mot menu à partir du point M(x,y) de la console
{

 gotoxy(x,y);
 printf("%c%c%c%c%c   %c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c     %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+1);
 printf("%c%c%c%c%c%c %c%c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c    %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+2);
 printf("%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c        %c%c%c%c%c%c   %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+3);
 printf("%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c  %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+3);
 printf("%c%c%c  %c%c%c  %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+4);
 printf("%c%c%c   %c   %c%c%c   %c%c%c        %c%c%c%c  %c%c%c%c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+5);
 printf("%c%c%c       %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c    %c%c%c%c%c   %c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+6);
 printf("%c%c%c       %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c     %c%c%c%c    %c%c%c%c%c%c%c ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}


void menu()
{

    int e,u,a,y,b;
    system("color 02");
 dessine_menu(50,8);
 for (e=1;e<=50;e++)
{
    //system("cls");
    gotoxy(e,23);
printf(" 1/  Afficher le contenu du fichier avec les informations\n");delay(15);
}
dessine_menu(50,8);
 for (y=1;y<=50;y++)
 {
gotoxy(y,24);
printf(" 2/  Rechercher un mot et sa position\n");delay(15); }
dessine_menu(50,8);


 for (u=1;u<=50;u++)
{
gotoxy(u,25);
printf(" 3/  Crypter le fichier\n");delay(15);}


 for (a=1;a<=50;a++)
{
    gotoxy(a,26);
printf(" 4/  Decrypter le fichier\n");delay(15);
}

for (b=1;b<=50;b++)
{
    gotoxy(b,27);
printf(" 5/  Quitter le programme \n");delay(15);
}
}




