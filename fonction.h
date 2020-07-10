#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED


long alea( long a, long b);
int premier ( long nb);
long max_nb (long a, long b);
long PGCD (long x,long y);
void mettre_zero (char tab[], int taille);
void generer_premier ( long *p, long *q);
long cle_publique (  long p, long q);
long cle_prive ( long e, long p, long q);
int modulo_puissance (long a, long b, long puissance);
void crypt2_rsa (FILE *f , FILE *f_crypte, long n, long e);
void decrypt2_rsa (FILE *f_crypte, FILE *f_claire , long n, long d );
void number_mot(char nom_fichier[50],int *nbr);
int modulo (int n ,int  d);
void number_car(char nom_fichier[50],int *nb_car);
void display(FILE *f,int *nb_ligne,int *nb_page);
void search_replace (char nom_fichier [50],char mot_recherche [30], char mot_remplace [30]);
#endif // FONCTION_H_INCLUDED
