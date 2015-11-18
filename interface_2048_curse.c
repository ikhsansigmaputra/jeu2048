#include <stdio.h>
#include <ncurses.h>
#include "constante.h"
#include "interface_2048_curse.h"

/* ******************** Fonctions d initialisation de ncurses ******************** */
void init_curses()
{
    initscr();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    init_pair(2,COLOR_GREEN,COLOR_WHITE);
    init_pair(3,COLOR_RED,COLOR_WHITE);
    curs_set(1);
    noecho();
    keypad(stdscr,TRUE);
}
/* ******************** fonction saisir ******************** */

char SaisieChar(void)
{
    char c;
    do {
        scanf("%c",&c);
    }
    while(c==32 || c==10 || c==13);
    return c;
}

char SaisieOuiNon(void)
{  
    char c;
    do {
	echo();
        c = getch();
	noecho();
    }
    while(c!='y' && c!='n');
    
    return c;
}

char SaisieDirection(void)
{
    int key;
    
    key = getch();
    
    switch(key)
    {
        case 258 : return '2'; // bas
        case 260 : return '4'; // gauche
        case 261 : return '6'; // droit
        case 259 : return '8'; // haut
        case ESCAPE : return 'e';
        default : return '-';
    }
    
}

/* ******************** fonction d'affichage ******************** */
void AfficheLigne(int n, char c)
{
    int i;
    for(i=0; i<n; i++)
        printw("%c",c);
    printw("\n");
}

void AfficheLaGrille(int tab[][DIM_JEU])
{
    int i, j, ln_ligne = 25;
    move(6,0);
    AfficheLigne(ln_ligne,'-');
    for(i=0; i<DIM_JEU; i++)
    {
        for(j=0; j<DIM_JEU; j++)
        {
            if(tab[i][j] == 0)       // verifier si le valeur = 0 ou pas
                printw("|     ");
            else
                printw("|%5d", tab[i][j]);
        }
        printw("|\n");
        AfficheLigne(ln_ligne,'-');
    }        
}

void AfficheScore(int score)
{
    printw(" Score : %d \n", score);
    refresh();
}

void affiche_menu()
{
    clear();
    move(1,1);
    printw("Appuyer sur F2 pour faire une nouvelle partie\n ");
//     printw("Appuyer sur F3 pour parametrer la partie\n ");
    printw("Appuyez sur ESC pour  sortir de la partie ou  du jeu\n");
    refresh();
}