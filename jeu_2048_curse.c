#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "constante.h"
#include "fonctions_2048.h"
#include "interface_2048_curse.h"
/* ************* fonction principale ************** */

int main (void) {
    int tab[DIM_JEU][DIM_JEU], key, int_jeu_2048, score=0;
    char continuer='y';
    srand(time(NULL));
    
    init_curses();
    bkgd(COLOR_PAIR(1));
    affiche_menu();    
    key=getch();    
   
    while(key!=ESCAPE)
    {
	if(key == KEY_F(2)) 
	{
	  clear();
	  affiche_menu();
	  InitJeu(tab, &score);
	  do
	  {
	    int_jeu_2048 = jeu_2048(tab, &score);
	    if(int_jeu_2048 == 3)
	    {
		move(4,0);
		printw(" Vous avez atteint l'objectif ! \n");
		printw(" Vous voulez continuer? (y/n) ");
		continuer = SaisieOuiNon();
	    }
	  }
	  while (continuer == 'y' && int_jeu_2048 > 1);
	  
	  if(int_jeu_2048 == 0)
	      printw(" Vouz avez perdu. \n");
	  if(int_jeu_2048 == 1)
	      printw(" Vouz ne pouvez plus retasser. \n");
	}
	key=getch();
    }
    
    endwin();
    
    return 0;
}