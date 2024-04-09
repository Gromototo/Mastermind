

char * sequence(int n, int m, char *tab);

//calculer le poids d'une sequence de n chiffres entre 0 et m-1 (nombre de chaque couleurs dans la sequence)
//par exemple si n=4, m=6 et sequence = 0014, poids = 2 1 0 0 1 0

char* poids(int n, int m, char *sequence, char *poids);

//comparer deux sequences de n chiffres entre 0 et m-1 et leur poids respectif
//retourne le nombre de chiffres bien placés et mal placés
//par exemple si n=4, m=6, sequence1 = 0014, poids1 = 2 1 0 0 1 0, sequence2 = 0210, poids2 = 2 1 1 0 0 0
//retourne 2*10 + 3 = 23

char compare(int n, char *sequence, char *poids, char *sequence2, char *poids2,char *reponse);

//afficher une sequence de n chiffres entre 0 et m-1

void afficher(int n, char *sequence);

//recuper une sequence de n chiffres entre 0 et m-1

void recuperer(int n,int m, char *sequence);

//initialise le jeu

void init(int n, int m, char *code, char *couleur);