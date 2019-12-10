#include <stdio.h>
#include <string.h>
#include "callbacks.h"
#include <gtk/gtk.h>


void ajouter(user a,char path[20])
{
        FILE *f;
        f=fopen(path,"a+");
        if (f!=NULL)
        {
                fprintf(f,"%s %s %s %s %d %s\n",a.nom,a.prenom,a.cin, a.sexe, a.age,a.date);
                fclose(f);
        }
        f=fopen("users.txt","a+");
        if (f!=NULL)
        {
                fprintf(f,"%s %s %d %s\n",a.login,a.password,a.role,a.cin);
                fclose(f);
        }
}


int exist(char*cin, char path[20]){
        FILE*f=NULL;
        user a;
        f=fopen(path,"r");
        while(fscanf(f,"%s %s %s %s %d %s\n",a.nom,a.prenom,a.cin, a.sexe, &a.age,a.date)!=EOF) {
                if(strcmp(a.cin,cin)==0) return 1;
        }
        fclose(f);
        return 0;
}
void supprimer(char*cin, char path[20]){
        FILE*f=NULL;
        FILE*f1=NULL;
        user a;
        f=fopen(path,"r");

        f1=fopen("ancien.txt","w+");
        while(fscanf(f,"%s %s %s %s %d %s\n",a.nom,a.prenom,a.cin, a.sexe, &a.age,a.date)!=EOF) {
                if(strcmp(cin,a.cin)!=0)

                        fprintf(f1,"%s %s %s %s %d %s\n",a.nom,a.prenom,a.cin, a.sexe, a.age,a.date);
        }
        fclose(f);
        fclose(f1);
        remove(path);
        rename("ancien.txt",path);
        f=fopen("users.txt","r");
        f1=fopen("ancien.txt","w+");
        while(fscanf(f,"%s %s %d %s\n",a.login,a.password,&a.role,a.cin)!=EOF) {
                if(strcmp(cin,a.cin)!=0)

                        fprintf(f1,"%s %s %d %s\n",a.login,a.password,a.role,a.cin);
        }
        fclose(f);
        fclose(f1);
        remove("users.txt");
        rename("ancien.txt","users.txt");
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
