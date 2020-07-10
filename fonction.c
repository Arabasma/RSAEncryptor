#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include "fonction.h"

/**===============================partie tp==============================**/
const int nb_lig = 25;
const int nb_char = 256;

long alea( long a, long b) /** pour génerer des nombres aléatoires **/
{
    unsigned long R ;
    srand(time(NULL));
    R = rand()%(b-a) + a ;
    return R;
}

int premier ( long nb)  /** verifie si un nombre est premier 0=faux , 1=vrai **/
{
  int prem = 1;
  long i=2;

   while ( prem == 1 && i<= sqrt(nb))
      { if (nb%i == 0) {prem = 0;}
        i++; }

   return prem;

}

long max_nb (long a, long b) /**calcule le max entre 2 nombres a et b**/
{
if (a> b) {return  a;}
if  (a< b)  {return b;}
if (a==b ) {return a;}
}

 long PGCD (long x,long y) /** calcule le PGCD de 2 nombres x et y**/
{
 long reste, pgcd;

 if (x*y == 0)
 { if (x>= y) {pgcd = x; }
    else {pgcd=y;}
 }
 else
 { reste = x%y;
   while ( reste > 0)
   { x = y;
     y= reste;
     reste = x % y;
    }
 }
pgcd =y;
 return pgcd;
}

void mettre_zero (char tab[], int taille)
{ int i;
    for (i =0; i<taille; i++)
    { tab[i] ='\0';

    }
}


void generer_premier ( long *p, long *q)        /** génère 2 nombres premiers **/
{
  unsigned long nb1 , nb2=0;
  int prem1=0, prem2=0;
  while (prem1==0 || prem2==0)
  {if (prem1 ==0 ) {nb1 = alea( 25 , 100); }
   if (prem2 ==0) { nb2 = alea( 25, 100); }
   if (prem2 ==0 || nb2==nb1)
  {while (nb1 == nb2 )
   {nb2 = alea( 25, 100);} }
   prem1= premier(nb1);
   prem2= premier (nb2);
  }
  *p=nb1;
  *q=nb2;

}


 long cle_publique (  long p, long q)  /** permet de trouver le nombre e de la clé publique (e,n) avec laquelle on cryptera le fichier **/
{
    long e= max_nb(p,q)+1, ind_euler, pgcd= -1 ;
ind_euler = (p-1)*(q-1);

 while ( pgcd != 1)
{  e++;
    pgcd = PGCD ( e, ind_euler);
}
return e;
}

long cle_prive ( long e, long p, long q) /** permet de trouver d de la clé privé (d,n) avec laquelle on décryptera le fichier **/
{
    long n, b,t, t0,x,r,temp, ind,d;
ind = (p-1)*(q-1);
n = (p-1)*(q-1);
b = e ;
t0 = 0 ;
t  = 1 ;
 x = n / b ;
r = n - x *b;
while (r > 0 )
{     temp = t0 - x*t;
      if ( temp >= 0 ) { temp = temp % ind ;} else { temp = ind - ((-temp) % ind) ;}
      t0 = t;
      t  = temp;
      n = b;
      b = r;
      x  =  n / b;
      r = n - x *b;
}
if (b != 1) { d = -1 ;}  else{d = t ;}
return d;
}

int modulo_puissance (long a, long b, long puissance) /** calcule a^puissance mod b **/
{
   int ind , i;
   unsigned long j=1;
   for (ind=0; ind< puissance ; ind++)
{ j = j*a;
  j = j%b;
}
i = j;
return i;
}

void crypt2_rsa (FILE *f , FILE *f_crypte, long n, long e) /** permet de crypter le fichier F1.txt suivant la méthode RSA**/
{
    int car_claire, car_crypte=0;
  while (!feof(f))
   { car_claire = fgetc(f);
     if ( car_claire != -1)
      { car_crypte = modulo_puissance(car_claire,n,e);
     fwrite (&car_crypte,sizeof(int),1,f_crypte);
      }
   }
}

void decrypt2_rsa (FILE *f_crypte, FILE *f_claire , long n, long d ) /**permet de decrypter le fi**/
{
    int car_crypte ;
  char car_claire ;

fread(&car_crypte, sizeof(int),1 ,f_crypte);
 do
 { if (car_crypte != 0)
   { car_claire = modulo_puissance(car_crypte, n, d);
     fputc(car_claire,f_claire);
   }
     fread(&car_crypte, sizeof(int),1 ,f_crypte);
  } while (!feof(f_crypte));
}


int modulo (int n ,int  d)
{
    while (n>=d )
        n-=d;
    return n;
}


void number_mot(char nom_fichier[50],int *nbr)
{
    int s=0;
    char *m = NULL;
    char ligne[256];
    char delimiteurs[] = " *\t\n,;:.=\"()_{}<>!?&\\";
    FILE *f=NULL;
    f= fopen(nom_fichier, "r");
    while(!feof(f))
   {
     if (fgets(ligne,sizeof(ligne),f)!=NULL)
      {
         m = strtok(ligne,delimiteurs);
         while (m!= NULL)
         { s++;
           m = strtok(NULL,delimiteurs);}
      }
     *nbr=s;}
 fclose(f);
}


void number_car(char nom_fichier[50],int *nb_car)
{
    int nbr=-1;
    FILE *f =NULL;
    f= fopen(nom_fichier,"r");
    while (fgetc(f)!=EOF)
        {nbr++;}
        *nb_car=nbr;
fclose(f);
}


void display(FILE *f,int *nb_ligne,int *nb_page)
{
    int cpt=0,page=0,lig=0;
    char ligne[256]="";
    char *old,*sv;
    old=setlocale(LC_ALL,NULL);
    sv=strdup(old);

   while (!feof(f))
    {

      if(  fgets (ligne,sizeof(ligne),f)!=NULL)
      {  if (cpt == 0)
          { page ++;
            printf(" \n\n                           ||  La page numero %d  ||\n\n\n",page); }
        setlocale(LC_CTYPE,"");
        printf("%s\n",ligne);
        lig++;
        cpt++;
        if (cpt == 20) {cpt=0;}
      }
    }
    *nb_ligne=lig;*nb_page=page;
    setlocale(LC_ALL,sv);

}

void search_replace (char nom_fichier [50],char mot_recherche [30], char mot_remplace [30])
{ char ligne[256]="";char ligne1[256]=""; char nouvelle_lig [1000]="";
  int nb_occur =0,i=0, num_lig =0, num_page=1, taille_mot=0, pos=0, ind=0, j=0,k=0, taille_chaine=0, taille=0, compteur =0;//num_lig1
  char *m1 = NULL;
  char delimiteurs[] = " *\t\n;:.=\"()_{},<>[]!?&\\$''";
  FILE *g =NULL, *f=NULL;
  rename(nom_fichier,"copie.txt");
  g=fopen(nom_fichier,"w+");
  f=fopen("copie.txt","r+");

 if(f==NULL || g==NULL) {
        system("cls");cadre_aff (50,10,35,15);gotoxy(39,18);
        printf("Fichier introuvable");  }

 else
 {  taille_mot = strlen(mot_remplace);
    taille = strlen(mot_recherche);
   while (!feof(f))
   {  if ( fgets(ligne,sizeof(ligne),f))
       {  strcpy(ligne1, ligne);
          m1 = strtok(ligne,delimiteurs);
          pos =0;
          ind=0;
          num_lig ++; j=0;
          while (m1 != 0)
           {  pos ++;
             if (strcmp(m1,mot_recherche) == 0)
             {  nb_occur++; k=0; j= j+ taille;
               for (k=0; k< taille_mot; k++)
               { nouvelle_lig[i]= mot_remplace[k];
                 i++; }
                 if (compteur==0 ) { cadre_aff(90,20,10,10); }    compteur++; //ici 85,40
                 gotoxy(12,13+compteur);
                 printf("le mot a %ct%C trouv%c a la page numero %d , la ligne numero %d , la position numero : %d\n",130,130,130,num_page, num_lig, pos); delay(15);
                 ind = i;
            }

             else
            { taille_chaine = strlen(m1);
              for ( i = ind ; i< (ind+taille_chaine); i++ )
               { nouvelle_lig[i]= ligne1[j];
                 j++; }
            }
             ind=i;
             m1 = strtok(NULL,delimiteurs);
             if ( m1!= NULL)
               { while (ligne1[j] != m1[0])
                 { nouvelle_lig[i]= ligne1[j] ;
                   j++;
                   i++;} }
              ind=i;
             if (i== 1000) { fputs(nouvelle_lig,g); i=0 ;mettre_zero(nouvelle_lig,1000);}
             if (num_lig == 20 ) { num_page ++; num_lig=0;}
          }
        while  (j< 256)  { nouvelle_lig[i]=ligne1[j]; j++; i++;}
        if ( (i != 0) || (i==1000) ) {fputs(nouvelle_lig,g);mettre_zero(nouvelle_lig,1000); i=0;}
       }

    }
  fputs(nouvelle_lig,g);
 } if (nb_occur != 0)
{   gotoxy(12,33);
    printf("_______________________________________________________\n");
    gotoxy(12,34);
   system("pause");
    system ("cls"); cadre_aff (60,10,35,15);gotoxy(39,18); //system ("cls"); gotoxy (54,wherey()+1);
    printf("Le nombre d'occurance du mot %s est : %d ",mot_recherche,nb_occur);
    gotoxy(35,30);
    printf("_______________________________________________________\n");
    gotoxy(35,31);
   system("pause");
    system ("cls"); cadre_aff (50,10,35,15);gotoxy(39,18);
   printf("le mot a %ct%c bien remplac%c",130,130,130); }
  else
  {
   gotoxy(39,18);
   printf("\n Le mot %s n'existe pas dans ce fichier \n",mot_recherche);
  }
 fclose(f);
 fclose(g);

 remove("copie.txt");

}
