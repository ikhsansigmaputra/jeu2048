#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "constante.h"
#include "fonctions_2048.h"
#include "interface_2048.h"

/* ************* fonction principale ************** */
int main (void) {
    srand(time(NULL));
    int tab[DIM_JEU][DIM_JEU], int_jeu_2048, score=0;
    char continuer='y';
    InitJeu(tab, &score);
    
    do
    {
      int_jeu_2048 = jeu_2048(tab, &score);
      if(int_jeu_2048 == 3)
      {
	  AfficheChaineChar("Vous avez gagné ! \n");
          AfficheChaineChar("Vous voulez continuer? (y/n) ");
          continuer = SaisieOuiNon();
      }
    }
    while (continuer == 'y' && int_jeu_2048 > 1);
    
    if(int_jeu_2048 == 0)
        AfficheChaineChar("Vouz avez perdu \n");
    
    return 0;
}