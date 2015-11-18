#ifndef FONCTIONS_2048_H
#define FONCTIONS_2048_H
/* ******************** fonction independent de l'affichage ******************** */
void swap(int *a, int *b);
void InitGrille(int T[][DIM_JEU]);
int ValeurAleatoire(void);
int RetasseLigne(int T[DIM_JEU][DIM_JEU], int retasse_a_droite);
int RetasseCollone(int T[DIM_JEU][DIM_JEU], int retasse_vers_bas);
int AdditionLigne(int T[DIM_JEU][DIM_JEU], int retasse_a_droite, int *score);
int AdditionCollone(int T[DIM_JEU][DIM_JEU], int retasse_vers_bas, int *score);
void OrdiJoue(int T[DIM_JEU][DIM_JEU]);
int JouerJoue(int T[DIM_JEU][DIM_JEU], char direction, int *score);
int JoueEncore(int T[DIM_JEU][DIM_JEU]);
int nb_case_vide(int T[DIM_JEU][DIM_JEU]);
int est_gagne(int T[DIM_JEU][DIM_JEU]);
void InitJeu(int T[DIM_JEU][DIM_JEU], int *score);
void jeu_une_fois(int T[DIM_JEU][DIM_JEU], int *score);
int jeu_2048(int T[DIM_JEU][DIM_JEU], int *score);
int est_possible_additioner(int T[DIM_JEU][DIM_JEU]);
#endif
