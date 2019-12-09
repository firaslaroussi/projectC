#include <string.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "CROUD.h"
#include <stdlib.h>
// recherche


	

//ajouter


void ajouter(devis d,char path[20])
{
        FILE *f;
        f=fopen(path,"a+");
        if (f!=NULL)
        {
                fprintf(f,"%s %s %s %s\n",d.type_devis,d.montant,d.remise,d.total);
                fclose(f);
        }
        f=fopen("/home/firas/Projects/devisagent/src/devis.txt","a+");
        if (f!=NULL)
        {
                
                fprintf(f,"%s %s %s %s\n",d.type_devis,d.montant,d.remise,d.total);
                fclose(f);
        }
}


int exist(char*id, char path[20]){
        char new_total[20];
        FILE*f=NULL;
        devis d;
        f=fopen(path,"r");
        while(fscanf(f,"%s %s %s %s\n",d.type_devis,d.montant,d.remise,d.total)!=EOF) {
                if(strcmp(d.total,new_total)==0) return 1;
        }
        fclose(f);
        return 0;
}



int verifier (char login [], char password [])
{
        FILE *f;
        f=fopen("users.txt","r");
        int role=-1;
        char login1[20],password1[20];
        while (fscanf(f,"%s %s %d\n",login1, password1, &role)!=EOF) {
                if (strcmp(login1,login)==0 && strcmp (password1,password)==0)
                {
                        fclose(f);
                        return role;
                }
        }
        fclose(f);
        return (role);
}

devis d;
enum
{
TYPE_DEVIS,MONTANT,REMISE,TOTAL,COLUMNS

};


void afficher_devis (GtkWidget * liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store; 
char type_devis[30];
char montant[30];
char remise[30];
char total[30]; 
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  type_devis",renderer,"text",TYPE_DEVIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  montant",renderer,"text",MONTANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  remise",renderer,"text",REMISE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("  total",renderer,"text",TOTAL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("/home/firas/Projects/devisagent/src/devis.txt","r");

if(f==NULL)

return;
else
{
while(fscanf(f," %s %s %s %s\n",type_devis,montant,remise,total)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPE_DEVIS,type_devis,MONTANT,montant,REMISE,remise,TOTAL,total,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}

void supprimer_facture(char id1[10])
{ 	
	FILE*f ,*s;
    	resident r;

    	f=fopen("/home/firas/Projects/devisagent/src/facture1.txt","r");
	s=fopen("/home/firas/Projects/devisagent/src/factures.tmp.txt","w");
	if(f!=NULL) 
	{
			
    			

			while(fscanf(f,"%s %s %s %s %s ",r.nom ,r.prenom ,r.identifiant,r.typededevis,r.montanttotale)!=EOF)
			{
    				if(strcmp(id1,r.identifiant)==0){continue;}
                                else
    				{	
						fprintf(s," %s %s %s %s %s \n",r.nom ,r.prenom ,r.identifiant,r.typededevis,r.montanttotale);

    				}
			}
			fclose(f);
			fclose(s);

			remove("/home/firas/Projects/devisagent/src/facture1.txt");
			rename("/home/firas/Projects/devisagent/src/factures.tmp.txt","/home/firas/Projects/devisagent/src/facture1.txt");

	}

}

