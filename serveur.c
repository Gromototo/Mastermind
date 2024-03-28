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

#include "fon.h"     		/* Primitives de la boite a outils */

#define SERVICE_DEFAUT "1111"
#define NB_REQ_MAX 100//Nombre de requetes max
#define BUFF_MAX 4 //Nombre d'octets du buffer

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

/* Procedure correspondant au traitemnt du serveur de votre application */

{
	int num_sock = h_socket(AF_INET, IPPROTO_TCP);

	struct sockaddr_in *p_adr_socket;
	h_bind(num_sock, p_adr_socket);
	adr_socket("s_m", num_sock, SOCK_STREAM, p_adr_socket);

	h_listen(num_sock, SOMAXCONN);
	h_accept(num_sock, p_adr_socket);

	char buffer[BUFF_MAX] ;
	int received = h_reads(num_sock, buffer, BUFF_MAX);

	printf("Received");

}

/******************************************************************************/	

