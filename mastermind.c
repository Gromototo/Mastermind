#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int min(int a, int b){
    return a<b?a:b;
}

/*========================================================================
============================= MASTER MIND ================================
=========================================================================*/



/*si char marche pas mettre int*/

//generer une sequence de n chiffres entre 0 et m-1 (couleurs 0 à m-1)
char * sequence(int n, int m, char *tab){
    int i;
    for(i=0; i<n; i++){
        tab[i] = rand()%m;
    }
    return tab;
}

//calculer le poids d'une sequence de n chiffres entre 0 et m-1 (nombre de chaque couleurs dans la sequence)
//par exemple si n=4, m=6 et sequence = 0014, poids = 2 1 0 0 1 0
void calcul_poids(int n, int m, char *sequence, char *poids){
    int i;
    for(i=0; i<n; i++){
        poids[sequence[i]] += 1;
    }

}

//comparer deux sequences de n chiffres entre 0 et m-1 et leur poids respectif
//retourne le nombre de chiffres bien placés et mal placés
//par exemple si n=4, m=6, sequence1 = 0014, poids1 = 2 1 0 0 1 0, sequence2 = 0210, poids2 = 2 1 1 0 0 0
void compare(int n, int m, char *sequence, char *poids, char *sequence2, char *poids2,char *reponse){
    int i;
    char place = 0;
    char couleur = 0;
    for(i=0; i<n; i++){
        if(sequence[i] == sequence2[i]){
            place++;
        }
    }


    for (int y =0; y < m; y++){
        couleur += min(poids[y], poids2[y]);
    }
    reponse[0] = place;
    reponse[1] = couleur - place;

}

//afficher une sequence de n chiffres entre 0 et m-1

void afficher(int n, char *sequence){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", sequence[i]);
    }
    printf("\n");
}

//recuper une sequence de n chiffres entre 0 et m-1

void recuperer(int n,int m, char *sequence){
    int i = 0;
    char c;
    while ((c = getchar()) != '\n' & i < n){;
        sequence[i] = c - '0';
        i++;
    }
}

//initialise le jeu

void init(int n, int m, char *code, char *couleur){
    srand(time(NULL));
    sequence(n, m, code);
    calcul_poids(n, m, code, couleur);
}