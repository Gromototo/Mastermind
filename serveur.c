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

	char buffer[BUFF_MAX] ;
	int read = h_reads(soc_com, buffer, BUFF_MAX);
  printf("Nb octets lus: %i\n", read);
  printf("Message recu: %s\n", buffer);
	h_close(soc_com);
	h_close(soc_serv);

}


/******************************************************************************/	

