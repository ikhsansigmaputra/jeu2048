#ifndef INTERFACE_2048_CURSE_H
#define INTERFACE_2048_CURSE_H
/* ******************** Fonctions d initialisation de ncurses ******************** */
void init_curses();
/* ******************** fonction saisir ******************** */
char SaisieChar(void);
char SaisieOuiNon(void);
char SaisieDirection(void);

/* ******************** fonction d'affichage ******************** */
void AfficheLigne(int n, char c);
void AfficheLaGrille(int tab[][DIM_JEU]);
void AfficheChaineChar(char *c_tab);
void affiche_menu();

#endif
