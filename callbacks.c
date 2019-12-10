#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "CRUD.h"
#include "afficher.h"



void
on_ajouter_clicked                     (GtkWidget       *button,
                                        gpointer user_data)
{

        struct user a; gint year,month,day;
        GtkWidget* msg=lookup_widget(button,"label297");
        strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry99"))));
        strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry100"))));
        strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry101"))));
        strcpy(a.login,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry102"))));
        strcpy(a.password,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry109"))));
        a.age =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(button,"spinbutton15")));
        strcpy(a.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(button,"combobox6"))));
        GtkWidget  *cal=lookup_widget(button,"calendar12");
        gtk_calendar_get_date(GTK_CALENDAR(cal),&year,&month,&day);
        sprintf(a.date,"%d/%d/%d",day,month,year);
        if(exist(a.cin,"listedesagents.txt")==0)
        { a.role=2;
          ajouter(a,"listedesagents.txt");



          gtk_label_set_text(GTK_LABEL(msg),"Agent Ajouté avec succes");
          gtk_widget_show(msg);}
        else{gtk_label_set_text(GTK_LABEL(msg),"Agent Existe deja!");
             gtk_widget_show(msg);}
}

void
on_treeview33_row_activated            (GtkWidget     *button,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer user_data)
{
        gchar* nom;
        gchar *prenom;
        gchar *cin;
        gchar *sexe;
        gint age;
        gchar* date;
        user u;
        int x;
        GtkTreeModel     *model;
        GtkTreeIter iter;

        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(button));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&nom,1,&prenom,2,&cin,3,&sexe,4,&age,5,&date,-1);
                gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label295")),date);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry107")),nom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry104")),prenom);

                gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label296")),cin);

                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(button,"spinbutton16")),age);
                if(strcmp(sexe,"HOMME")) x=1;
                if(strcmp(sexe,"FEMME")) x=0;

                gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(button,"combobox7")),x);
                FILE* f=fopen("users.txt","r");
                while (fscanf(f,"%s %s %d %s\n",u.login,u.password,&u.role,u.cin)!=EOF)
                {
                        if(strcmp(u.cin,cin)==0)
                        {
                                gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry106")),u.login);
                                gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry110")),u.password);
                        }

                }
                fclose(f);

                gtk_widget_show(lookup_widget(button,"Modifier"));

        }
}


void
on_Modifier_clicked                    (GtkWidget       *button,
                                        gpointer user_data)
{
        struct user a; gchar* date;

        strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry107"))));
        strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry104"))));

        strcpy(a.cin,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label296"))));
        strcpy(a.login,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry106"))));
        strcpy(a.password,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry110"))));
        a.age =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(button,"spinbutton16")));
        strcpy(a.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(button,"combobox7"))));
        strcpy(a.date,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label295"))));

        supprimer(a.cin,"listedesagents.txt");
        ajouter(a,"listedesagents.txt");
        afficher(lookup_widget(button,"treeview33"),"listedesagents.txt",FALSE);
        gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label356")),"Agent Modifié avec succes");

}





void
on_Supprimer_clicked                   (GtkWidget       *button,
                                        gpointer user_data)
{

        GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;

        gchar* cin;

        p=lookup_widget(button,"treeview34");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,2,&cin,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);

           supprimer(cin,"listedesagents.txt");
           gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label355")),"Agent Supprimé avec succes");}
}

void
on_supprimer_a_clicked                 (GtkWidget       *button,
                                        gpointer user_data)
{
        supprimer_agents=create_supprimer_agents();
        afficher(lookup_widget(supprimer_agents,"treeview34"),"listedesagents.txt",TRUE);
        gtk_widget_show(supprimer_agents);
        gtk_widget_hide(window_admin);
}


void
on_modifier_a_clicked                  (GtkWidget       *button,
                                        gpointer user_data)
{
        modifier_agents=create_modifier_agents();
        afficher(lookup_widget(modifier_agents,"treeview33"),"listedesagents.txt",TRUE);
        gtk_widget_show(modifier_agents);
        gtk_widget_hide(window_admin);
}


void
on_ajout_a_clicked                     (GtkWidget       *button,
                                        gpointer user_data)
{
        ajout_agents=create_ajout_agents();
        gtk_widget_show(ajout_agents);
        gtk_widget_hide(window_admin);
}


void
on_liste_a_clicked                     (GtkWidget       *button,
                                        gpointer user_data)
{
        liste_agents=create_liste_agents();
        afficher(lookup_widget(liste_agents,"treeview32"),"listedesagents.txt",TRUE);
        gtk_widget_show(liste_agents);
        gtk_widget_hide(window_admin);
}


void
on_supprimer_c_clicked                 (GtkWidget       *button,
                                        gpointer user_data)
{
        supprimer_clients=create_supprimer_clients();
        afficher(lookup_widget(supprimer_clients,"treeview37"),"clients.txt",TRUE);
        gtk_widget_show(supprimer_clients);
        gtk_widget_hide(window_admin);
}


void
on_modifier_c_clicked                  (GtkWidget       *button,
                                        gpointer user_data)
{
        modifier_clients=create_modifier_clients();
        afficher(lookup_widget(modifier_clients,"treeview36"),"clients.txt",TRUE);
        gtk_widget_show(modifier_clients);
        gtk_widget_hide(window_admin);
}


void
on_ajout_c_clicked                     (GtkWidget       *button,
                                        gpointer user_data)
{
        ajout_client=create_ajout_client();
        gtk_widget_show(ajout_client);
        gtk_widget_hide(window_admin);
}


void
on_liste_c_clicked                     (GtkWidget       *button,
                                        gpointer user_data)
{
        liste_clients=create_liste_clients();
        afficher(lookup_widget(liste_clients,"treeview35"),"clients.txt",TRUE);
        gtk_widget_show(liste_clients);
        gtk_widget_hide(window_admin);
}




void
on_btn_login_clicked                   (GtkWidget       *button,
                                        gpointer user_data)
{
        int x;  char loginn[20],password[20];
        strcpy(loginn,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry120"))));
        strcpy(password,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry121"))));
        x =verifier(loginn,password);
        if(x==1) { window_admin=create_window_admin();
                   gtk_widget_show (window_admin);
                   gtk_widget_hide(login);}
        else gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label354")),"Verifier votre login et password ! ");
}

void
on_ajouter_client_clicked              (GtkWidget       *button,
                                        gpointer user_data)
{
        struct user a; gint year,month,day;
        GtkWidget* msg=lookup_widget(button,"label308");
        strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry111"))));
        strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry112"))));
        strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry113"))));
        strcpy(a.login,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry114"))));
        strcpy(a.password,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry115"))));
        a.age =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(button,"spinbutton17")));
        strcpy(a.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(button,"combobox8"))));
        GtkWidget  *cal=lookup_widget(button,"calendar13");
        gtk_calendar_get_date(GTK_CALENDAR(cal),&year,&month,&day);
        sprintf(a.date,"%d/%d/%d",day,month,year);
        if(exist(a.cin,"clients.txt")==0)
        { a.role=3;
          ajouter(a,"clients.txt");



          gtk_label_set_text(GTK_LABEL(msg),"Client Ajouté avec succes");
          gtk_widget_show(msg);}
        else{gtk_label_set_text(GTK_LABEL(msg),"Client Existe deja!");
             gtk_widget_show(msg);}
}


void
on_treeview36_row_activated            (GtkWidget     *button,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer user_data)
{
        gchar* nom;
        gchar *prenom;
        gchar *cin;
        gchar *sexe;
        gint age;
        gchar* date;
        user u;
        int x;
        GtkTreeModel     *model;
        GtkTreeIter iter;

        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(button));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&nom,1,&prenom,2,&cin,3,&sexe,4,&age,5,&date,-1);
                gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label318")),date);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry118")),nom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry116")),prenom);

                gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label319")),cin);

                gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(button,"spinbutton18")),age);
                if(strcmp(sexe,"HOMME")) x=1;
                if(strcmp(sexe,"FEMME")) x=0;

                gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(button,"combobox9")),x);
                FILE* f=fopen("users.txt","r");
                while (fscanf(f,"%s %s %d %s\n",u.login,u.password,&u.role,u.cin)!=EOF)
                {
                        if(strcmp(u.cin,cin)==0)
                        {
                                gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry117")),u.login);
                                gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry119")),u.password);
                        }

                }
                fclose(f);

                gtk_widget_show(lookup_widget(button,"modifier_client"));
        }
}

void
on_modifier_client_clicked             (GtkWidget       *button,
                                        gpointer user_data)
{
        struct user a; gchar* date;

        strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry118"))));
        strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry116"))));

        strcpy(a.cin,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label319"))));
        strcpy(a.login,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry117"))));
        strcpy(a.password,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry119"))));
        a.age =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(button,"spinbutton18")));
        strcpy(a.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(button,"combobox9"))));
        strcpy(a.date,gtk_label_get_text(GTK_LABEL(lookup_widget(button,"label318"))));

        supprimer(a.cin,"clients.txt");
        ajouter(a,"clients.txt");
        afficher(lookup_widget(button,"treeview36"),"clients.txt",FALSE);
        gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label357")),"Client Modifié avec succes");
}


void
on_supprimer_client_clicked            (GtkWidget       *button,
                                        gpointer user_data)
{

        GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;

        gchar* cin;

        p=lookup_widget(button,"treeview37");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,2,&cin,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);

           supprimer(cin,"clients.txt");
           gtk_label_set_text(GTK_LABEL(lookup_widget(button,"label358")),"Client Supprimé avec succes");}
}
