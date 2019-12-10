typedef struct
{
char destination[20];
char date[10];
int nbr_etoil;
}hotel;

typedef struct
{
int nbr_personne;
int nbr_adulte;
int nbr_enfant;
char type[20];
}chambre;

void rechercher(hotel h);
float devis(chambre ch);

