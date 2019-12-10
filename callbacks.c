#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"


void
on_rechercher_clicked                  (GtkButton      *button,
                                        gpointer         user_data)
{
GtkWidget *hebergemnt_date_destination;
GtkWidget *afficher_hotel;
GtkWidget *treeview1;

hebergemnt_date_destination=lookup_widget(button,"hebergemnt_date_destination");
gtk_widget_destroy(hebergemnt_date_destination);
afficher_hotel=lookup_widget(button,"fenetre_afficher");
afficher_hotel=create_afficher_hotel();
gtk_widget_show(afficher_hotel);
treeview1=lookup_widget(afficher_hotel,"treeview1");
rechercher(treeview1);
}


void
on_confirmer_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_devis_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *hebergemnt_date_destination, *afficher_hotel;
hebergemnt_date_destination=lookup_widget(button ,"hebergemnt_date_destination");

gtk_widget_destroy(hebergemnt_date_destination);
afficher_hotel=create_afficher_hotel();
gtk_widget_show(afficher_hotel);
}


void
on_reserver_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}

