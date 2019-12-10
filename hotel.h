#include <gtk/gtk.h>


typedef struct 
{char destination [10] ;
char nom_hotel[20] ;
char  id_hotel [20] ;
char nbre_etoiles [20] ; 
}Hotel1;


void ajouter_h (Hotel1 h);
void afficher_h (GtkWidget *liste);

