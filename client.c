/******************************************************************************/
/*			Application: ...					*/
/******************************************************************************/
/*									      */
/*			 programme  CLIENT				      */
/*									      */
/******************************************************************************/
/*									      */
/*		Auteurs : ... 					*/
/*									      */
/******************************************************************************/	


#include <stdio.h>
#include <curses.h> 		/* Primitives de gestion d'ecran */
#include <sys/signal.h>
#include <sys/wait.h>
#include<stdlib.h>

#include "fon.h"   		/* primitives de la boite a outils */
#include "mastermind.h"

#define SERVICE_DEFAUT "1111"
#define SERVEUR_DEFAUT "127.0.0.1"
#define BUFF_MAX 8 //Nombre d'octets du buffer

void client_appli (char *serveur, char *service);


/*****************************************************************************/
/*--------------- programme client -----------------------*/

int main(int argc, char *argv[])
{

	char *serveur= SERVEUR_DEFAUT; /* serveur par defaut */
	char *service= SERVICE_DEFAUT; /* numero de service par defaut (no de port) */


	/* Permet de passer un nombre de parametre variable a l'executable */
	switch(argc)
	{
 	case 1 :		/* arguments par defaut */
		  printf("serveur par defaut: %s\n",serveur);
		  printf("service par defaut: %s\n",service);
		  break;
  	case 2 :		/* serveur renseigne  */
		  serveur=argv[1];
		  printf("service par defaut: %s\n",service);
		  break;
  	case 3 :		/* serveur, service renseignes */
		  serveur=argv[1];
		  service=argv[2];
		  break;
    default:
		  printf("Usage:client serveur(nom ou @IP)  service (nom ou port) \n");
		  exit(1);
	}

	/* serveur est le nom (ou l'adresse IP) auquel le client va acceder */
	/* service le numero de port sur le serveur correspondant au  */
	/* service desire par le client */
	
	client_appli(serveur,service);
}

/*****************************************************************************/
void client_appli (char *serveur,char *service)

/* procedure correspondant au traitement du client de votre application */

{

	int soc_cli = h_socket(AF_INET, SOCK_STREAM);

	struct sockaddr_in *p_adr_serveur, *p_adr_client;
	adr_socket("2001", "0.0.0.0", SOCK_STREAM, &p_adr_serveur);
	adr_socket("2000", "127.0.0.1", SOCK_STREAM, &p_adr_client);

	h_connect(soc_cli, p_adr_serveur);

  char Message[6];
  scanf("%s",Message);
	int error = h_writes(soc_cli, Message, BUFF_MAX);
  printf("Nb octets écrits: %i\n", error);


	h_close(soc_cli);



/*--------------jeu-----------------
tant que le jeu n'est pas fini
	proposer un code
	envoyer le code au serveur
	attendre la reponse du serveur
	afficher la reponse
fin tant que
*/
char code[4];
char reponse[2];

for (int i = 0; i < 2; i++)
{
	recuperer(4, 6, code);

	//envoie le code au serveur

	//attendre la reponse du serveur

	//afficher la reponse
	printf("Bien placé: %d, Mal placé: %d\n", reponse[0], reponse[1]);
}


// 	int jeu =1;
// while (jeu)
// {
// 	char Message[6];
// 	scanf( "%s", Message );;
// 	int error = h_writes(soc_cli, Message, BUFF_MAX);
//   printf("Nb octets écrits: %i\n", error);
//   h_close(soc_cli);
// }
 }

/*****************************************************************************/

