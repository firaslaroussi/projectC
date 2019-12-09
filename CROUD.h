#include <gtk/gtk.h>


void retour();
typedef struct
{
int year;
int month;
int day;
}date;
typedef struct
{ 
char poste_de_tresorerie;
int numCarte;
int cdCarte;
int cdIntCarte;
}payment;
void comfirmation();
typedef struct  
{
char id[13];
int role;
char date[30];
char type_devis[30];
char montant[15];
char remise[6];
char total[15];  
}devis;
void afficher_devis (GtkWidget * liste);
void ajouter_devis(devis d );

void modifier(devis d);

typedef struct
{
char identifiant[10];
char motpass[20];
char nom[15];
char prenom[15];
char profession[20];
char sexe[5];
}Client;
void rechercher_client(char id[10]);
void ajouter(devis d,char path[20]);
int exist(char* id, char path[20]);
int verifier(char login [], char password []);
typedef struct
{
char nom[30];
char prenom[30];
char identifiant[30];
char typededevis[30];
char montanttotale[30];
}resident;
void supprimer_facture(char id1[10]);
