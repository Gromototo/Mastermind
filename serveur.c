/******************************************************************************/
/*			Application: ....			              */
/******************************************************************************/
/*									      */
/*			 programme  SERVEUR 				      */
/*									      */
/******************************************************************************/
/*									      */
/*		Auteurs :  ....						      */
/*		Date :  ....						      */
/*									      */
/******************************************************************************/	

#include<stdio.h>
#include <curses.h>

#include<sys/signal.h>
#include<sys/wait.h>
#include<stdlib.h>

//remettre fon.h
#include "fon.h"     		/* Primitives de la boite a outils */
#include "mastermind.h"

#include <stdlib.h>

#define SERVICE_DEFAUT "1111"
#define NB_REQ_MAX 100//Nombre de requetes max
#define BUFF_MAX 8 //Nombre d'octets du buffer

void serveur_appli (char *service);   /* programme serveur */


/******************************************************************************/	
/*---------------- programme serveur ------------------------------*/

int main(int argc,char *argv[])
{

	char *service= SERVICE_DEFAUT; /* numero de service par defaut */


	/* Permet de passer un nombre de parametre variable a l'executable */
	switch (argc)
 	{
   	case 1:
		  printf("defaut service = %s\n", service);
		  		  break;
 	case 2:
		  service=argv[1];
            break;

   	default :
		  printf("Usage:serveur service (nom ou port) \n");
		  exit(1);
 	}

	/* service est le service (ou numero de port) auquel sera affecte
	ce serveur*/
	
	serveur_appli(service);
}


/******************************************************************************/	
void serveur_appli(char *service)
//service = SERVICE_DEFAUT//


/* Procedure correspondant au traitemnt du serveur de votre application */

{
	int soc_serv = h_socket(AF_INET, SOCK_STREAM);

	struct sockaddr_in *p_adr_serveur, p_adr_client;
	adr_socket("2001", "0.0.0.0", SOCK_STREAM, &p_adr_serveur);
	//adr_socket("2000", "127.0.0.1", SOCK_STREAM, &p_adr_client);

	h_bind(soc_serv, p_adr_serveur);

  h_listen(soc_serv, SOMAXCONN);
	int soc_com = h_accept(soc_serv, &p_adr_client);



/*--------------jeu------------------
generer un code secret
calculer poids du code secret

tant que jeu pas fini
	attendre proposition
	calculer poids de la proposition
	renvoie de la reponse
fin tant que
-----------------------------------
	*/
char code[4];
char poids[6];
char poids_proposition[6];

for (int i  = 0; i < 6; i++)
{
	poids[i] = 0;
	poids_proposition[i] = 0;
}

char proposition[4];
char reponse[2];
init(4, 6, code, poids);
int nombre_de_tours = 2;

printf("code: %d %d %d %d\n", code[0], code[1], code[2], code[3]);

for (int i = 0; i < nombre_de_tours; i++)
{
	//attendre proposition
	h_reads(soc_com, proposition, 4);
	printf("proposition: %d %d %d %d\n", proposition[0], proposition[1], proposition[2], proposition[3]);

	//calculer poids de la proposition
	calcul_poids(4, 6, proposition, poids_proposition);

	printf("poids proposition: %d %d %d %d %d %d\n", poids_proposition[0], poids_proposition[1], poids_proposition[2], poids_proposition[3], poids_proposition[4], poids_proposition[5]);

	compare(4, proposition, poids_proposition, code, poids,reponse);

	printf("\n response: %d %d\n", reponse[0], reponse[1]);
	//renvoie de la reponse
	h_writes(soc_com, reponse, 2);


}

	h_close(soc_com);
	h_close(soc_serv);
}

/******************************************************************************/	

