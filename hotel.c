#include <stdio.h> 
#include <string.h> 
#include "hotel.h"
#include <gtk/gtk.h> 



enum 
{ 

    DESTINATION,
    NOM_HOTEL,
    ID_HOTEL,
    NBRE_ETOILES,
    COLUMNS,
};

//ajouter un hotel 

void ajouter_h(Hotel1 h) 
{     
   FILE *f ;       
   f=fopen("/home/hedi/Téléchargements/projectfinale1/src/hotel.txt","a+") ;
   if (f!=NULL) 
   { 
   fprintf(f,"%s %s %s %s \n",h.destination,h.nom_hotel,h.id_hotel,h.nbre_etoiles);
fclose(f);
}
}


// Afficher un hotel 


void afficher_h(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

char destination [20] ;
char nom_hotel [20] ;
char id_hotel [20] ;
char nbre_etoiles [20];
store=NULL ;

FILE *f;
store = gtk_tree_view_get_model(liste);
if(store==NULL)


renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     destination",renderer,"text",DESTINATION,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     nom_hotel",renderer,"text",NOM_HOTEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column); 


renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("id_hotel     ",renderer,"text",ID_HOTEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     nbre_etoiles",renderer,"text",NBRE_ETOILES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("/home/hedi/Téléchargements/projectfinale1/src/hotel.txt","r");

if (f==NULL)
{
  return ;}
else 
{
  f =fopen("/home/hedi/Téléchargements/projectfinale1/src/hotel.txt","a+") ;
while ((fscanf(f,"%s %s %s %s \n",destination,nom_hotel,id_hotel,nbre_etoiles)!=EOF))
{
gtk_list_store_append(store,&iter);

gtk_list_store_set (store,&iter,DESTINATION,destination,NOM_HOTEL,nom_hotel,ID_HOTEL,id_hotel,NBRE_ETOILES,nbre_etoiles, -1);}
fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}

