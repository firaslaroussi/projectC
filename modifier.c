void modifier (char NOM[], char PRENOM[],int CIN , char LOGIN [], char PASSWORD [])
{
	char NOMk[20], PRENOMk[20], LOGINk[20],PASSWORDk[20];
	FILE *f, *tmp;
	f=fopen("/home/imen/Projects/maquettesfinale/listedesagents.txt","r");
	tmp=fopen("/home/imen/Projects/maquettesfinale/listedesagents.tmp","a+");
	while(fscanf(f,"%s %s %d %s %s",NOMk,PRENOMk,CINk,LOGINk,PASSWORDk)!=EOF){
		if(!strcmp(NOM,NOMk) && !strcmp(PRENOM,PRENOMk)){fprintf(tmp,"%s %s %d %s %s\n",NOM,PRENOM,CIN,LOGIN,PASSWORD);}
		else fprintf(tmp,"%s %s %d %s %s \n",NOMk,PRENOMk,CINk,LOGINk,PASSWORDk);
}
fclose(f);
fclose(tmp);
rename("/home/imen/Projects/maquettesfinale/listedesagents.tmp","/home/imen/Projects/listedesagent.txt");
}
