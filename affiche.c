#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include "affiche.h"
#include "CROUD.h"
resident r;
enum
{
NOM,PRENOM,IDENTIFIANT,TYPEDEDEVIS,MONTANTTOTALE,COLUMNS

};


void afficher_supp (GtkWidget * liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 
char nom[30];
char prenom[30];
char identifiant[30];
char typededevis[30];
char montanttotale[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  identifiant",renderer,"text",IDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  typededevis",renderer,"text",TYPEDEDEVIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  montanttotale",renderer,"text",MONTANTTOTALE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("/home/firas/Projects/devisagent/src/facture1.txt","r");

if(f==NULL)

return;
else
{
while(fscanf(f," %s %s %s %s %s\n",nom,prenom,identifiant,typededevis,montanttotale)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,IDENTIFIANT,identifiant,TYPEDEDEVIS,typededevis,MONTANTTOTALE,montanttotale,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}


