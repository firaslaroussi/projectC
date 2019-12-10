#include <stdio.h>
#include <string.h>
#include "hebergement.h"
#include <gtk/gtk.h>


enum
{
	date,
	destination,
	nbr_etoils,
	columns
}

// rechercher un hotel

void rechercher(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

char date [20] ;
char destination [20] ;
int nbr_etoils ;
store=NULL ;

FILE *f;
store = gtk_tree_view_get_model(liste);
if(store==NULL)


renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     date",renderer,"text",date,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     destination",renderer,"text",destination,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column); 


renderer = gtk_cell_renderer_text_new () ;
  column = gtk_tree_view_column_new_with_attributes("     nbr_etoils",renderer,"text",nbr_etoils,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("/home/hedi/Projets/hc/src/hotel.txt","r");

if (f==NULL)
{
  return ;}
else 
{
  f =fopen("/home/hedi/Projets/hc/src/hotel.txt","a+") ;
while ((fscanf(f,"%s %s  %d \n",date,destination,nbr_etoils)!=EOF))
{
gtk_list_store_append(store,&iter);

gtk_list_store_set (store,&iter,date,destination,nbr_etoils, -1);}
fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


//calculer devis

float devis(chambre ch)
{

}


