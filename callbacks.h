#include <gtk/gtk.h>
GtkWidget *login;
GtkWidget *liste_agents;
GtkWidget *ajout_agents;
GtkWidget *modifier_agents;
GtkWidget *supprimer_agents;
GtkWidget *liste_clients;
GtkWidget *ajout_client;
GtkWidget *modifier_clients;
GtkWidget *supprimer_clients;
GtkWidget *window_admin;

typedef struct user user;
struct user{
char nom[30];
char prenom[30];
char cin[30];
char sexe[30];
int age;
char date[30];
char login[30];
char password[9];
int role;

};

void
on_ajouter_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview33_row_activated            (GtkWidget     *button,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Modifier_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);



void
on_Supprimer_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supprimer_a_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modifier_a_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajout_a_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_liste_a_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supprimer_c_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modifier_c_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajout_c_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_liste_c_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button69_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_btn_login_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_ajouter_client_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview36_row_activated            (GtkWidget     *button,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_modifier_client_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_supprimer_client_clicked            (GtkWidget       *button,
                                        gpointer         user_data);
