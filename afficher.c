#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include "interface.h"
#include "callbacks.h"
#include "afficher.h"

void afficher(GtkWidget *plistview, char path[20],gboolean test)
{
        enum { COL_NOM,
               COL_PRENOM,
               COL_CIN,
               COL_SEXE,
               COL_AGE,
               COL_DATE,
               NUM_COLS};
        user a;
        GtkListStore *liststore;
        GtkCellRenderer *celrender;
        GtkTreeViewColumn *col;
        liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_UINT,G_TYPE_STRING);
        FILE *f;
        f=fopen(path,"r");
        if(f!=NULL) {
                while(fscanf(f,"%s %s %s %s %d %s\n",a.nom,a.prenom,a.cin,a.sexe,&a.age,a.date)!=EOF) {
                        GtkTreeIter iter;
                        gtk_list_store_append(liststore, &iter);
                        gtk_list_store_set(liststore, &iter,
                                           COL_NOM, a.nom,
                                           COL_PRENOM, a.prenom,
                                           COL_CIN, a.cin,
                                           COL_SEXE,a.sexe,
                                           COL_AGE,a.age,
                                           COL_DATE,a.date,

                                           -1);
                }

                fclose(f);

                if(test) {
                        celrender = gtk_cell_renderer_text_new();
                        col = gtk_tree_view_column_new_with_attributes("    NOM    ",celrender,"text",COL_NOM,NULL);
                        gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

                        celrender = gtk_cell_renderer_text_new();
                        col = gtk_tree_view_column_new_with_attributes("    PRENOM    ",celrender,"text",COL_PRENOM,NULL);
                        gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);
                        celrender = gtk_cell_renderer_text_new();
                        col = gtk_tree_view_column_new_with_attributes("    CIN    ",celrender,"text",COL_CIN,NULL);
                        gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

                        celrender = gtk_cell_renderer_text_new();
                        col = gtk_tree_view_column_new_with_attributes("    SEXE    ",celrender,"text",COL_SEXE,NULL);
                        gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

                        celrender = gtk_cell_renderer_text_new();
                        col = gtk_tree_view_column_new_with_attributes("    AGE    ",celrender,"text",COL_AGE,NULL);
                        gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

                        celrender = gtk_cell_renderer_text_new();
                        col = gtk_tree_view_column_new_with_attributes("    DATE INSCRI    ",celrender,"text",COL_DATE,NULL);
                        gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);



                }
                gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

        }

}
