#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include "conio2.h"
#include "fonction.h"
#include "affichage.h"

int main()
{

    int num_mot=0;
    long a=0, b=0, e=0, d=0, n=0 ;
 char nom_fichier_original[30]="";
 char nom_fichier_crypte[30]="";
 char nom_fichier_claire[30]="";
 FILE *fcrypte= NULL, *fclaire=NULL, *f_original=NULL;
    char moot[30]="";
    char nouv_mot[30]="";
    int choix;
int car=0,lign=0,page=0;
    FILE *f;
    char nomfich[50]="";
    page_2();
    generer_premier(&a,&b);
    e = cle_publique(a,b);
    d = cle_prive(e, a, b);
    n= a*b;
    while( choix!=5)
    {
   system("cls");
    menu ();
    cadre_aff(50,5,46,33);
    gotoxy(50,35);
    printf("donnez votre choix : ");
    scanf("%d",&choix);
    switch(choix)
    {
        case (1):
            mettre_zero(nomfich,50);
            system("cls");
            cadre_aff(50,5,50,20);gotoxy(54,23); //ici 40 était 50
         printf("donnez le nom du fichier : ");
         scanf("%s",nomfich);
         f=fopen(nomfich,"r");
         if ( f==  NULL) { system("cls");
           cadre_aff (50,10,50,20);gotoxy(54,24);
                printf("fichier introuvable\n");}
         else {system("cls"); display(f,&lign,&page);
        fclose(f);
         number_car(nomfich,&car);


         number_mot(nomfich,&num_mot);textcolor(WHITE);
   printf("\n________________________________________________________\n");textcolor(GREEN);
   printf ("\nle nombre de caractere dans le fichier est : %d",car);
   printf("\nle nombre de ligne dans le fichier est : %d", lign);
   printf("\nle nombre de page dans le fichier est : %d", page);
   printf("\nle nombre de mots dans le fichier est : %d\n\n",num_mot);textcolor(WHITE);
   printf("_______________________________________________________\n"); }
   system("pause");

   break;
  case(2):
    mettre_zero(nomfich,50);
    mettre_zero(moot,30);
    mettre_zero(nouv_mot,30);system("cls");cadre_aff (50,10,45,15);gotoxy(54,17);

    printf("donnez le nom du fichier : ");
    scanf("%s",nomfich);gotoxy(54,18);
    printf ("entrez le mot a rechercher : ");
    scanf("%s",moot);gotoxy(54,19);
    printf ("entrez le mot a remplacer : ");
    scanf("%s",nouv_mot);
    system("cls");
    search_replace(nomfich,moot,nouv_mot);
    gotoxy(35,30);
    printf("_________________________________________________");gotoxy(35,31);
    system("pause");
   break;
   case (3):
       system("cls");
       cadre_aff(80,15,40,14);gotoxy(44,18);
     printf("veuillez introduire le nom du fichier texte a crypter : ") ;
     scanf("%s",nom_fichier_original);
     f_original=fopen(nom_fichier_original,"r");gotoxy(44,20);
     printf("veuillez introduire le nom du fichier texte crypt%c : ",130) ;/** début de l'option crypter **/
     scanf("%s",nom_fichier_crypte);
     fcrypte = fopen(nom_fichier_crypte,"wb");
     srand(time(NULL));
     crypt2_rsa(f_original,fcrypte,n,e);
     fclose(fcrypte);
     fclose(f_original);
      system("cls");
       cadre_aff(50,10,35,15);gotoxy(40,19);
       printf("le fichier a %ct%c crypt%c !",130,130,130);
       gotoxy(35,27);
       textcolor(WHITE);
       printf("__________________________________________");
       gotoxy(35,28);
       system("pause");


   break;
    case (4):
         system("cls");
       cadre_aff(80,12,30,15);gotoxy(32,18);
     printf("veuillez introduire le nom du fichier texte a decrypter : ") ;/** début de l'option décrypter **/
     scanf("%s",nom_fichier_crypte);
     fcrypte = fopen(nom_fichier_crypte,"rb");gotoxy(32,21);
     printf("veuillez introduire le nom a donner au fichier texte  decrypt%c : ",130) ;
     scanf("%s",nom_fichier_claire);
     fclaire = fopen (nom_fichier_claire, "w");
     decrypt2_rsa(fcrypte,fclaire,n,d);
     fclose(fcrypte);
     fclose(fclaire);
      system("cls");
       cadre_aff(60,10,35,15);gotoxy(44,18);
       printf ("le fichier a %ct%c d%ccrypt%c !",130,130,130,130);
       gotoxy(35,27);
       textcolor(WHITE);
       printf("__________________________________________");
       gotoxy(35,28);
       system("pause");
    break;
    case (5) :
     system("cls");gotoxy(3,4);textcolor(WHITE);
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
    gotoxy(30,10); printf("P");delay(30);printf("r");delay(30);
     printf("o");delay(30);printf("g");delay(30);printf("r");delay(30);
     printf("a");delay(30);printf("");delay(30);
     printf("m");delay(30);printf("m");delay(30);printf("%c",130);delay(30);
     printf(" ");delay(30);printf("p");delay(30);printf("a");delay(30);
     printf("r");delay(30);printf(" ");delay(30);printf("B");delay(30);
     printf("e");delay(30);printf("r");delay(30);printf("o");delay(30);
     printf("u");delay(30);printf("a");delay(30);
     printf("k");delay(30);printf("e");delay(30);
     printf("n");delay(30);printf(" ");delay(30);printf("M");delay(30);printf("a");delay(30);
     printf("r");delay(30);printf("o");delay(30);printf("u");delay(30);printf("a");delay(30);
     printf(" ");delay(30);printf("et");delay(30);printf(" ");delay(30);printf("A");delay(30);
     printf("r");delay(30);printf("a");delay(30);
     printf("b");delay(30);printf(" ");delay(30);printf("A");delay(30);
     printf("s");delay(30);printf("m");delay(30);printf("a");delay(30);
     printf("\n\n\n\n\n\n");delay(30);





     exit(0);
    break;
    default :
        system("cls");

       cadre_aff(50,10,35,15);gotoxy(44,19);
    printf("\n Ce choix n'existe pas dans le menu !");
    }}

   fclose(f);
   return 0;
}




