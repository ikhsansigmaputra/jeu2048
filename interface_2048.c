#include <stdio.h>
#include "constante.h"
#include "interface_2048.h"

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
        c = SaisieChar();
    }
    while(c!='y' && c!='n');
    
    return c;
}

char SaisieDirection(void)
{
    char c;
    do {
        c = SaisieChar();
    }
    while(c!='2' && c!='4' && c!='6' && c!='8' && c!=ESCAPE);
    
    return c;
}

/* ******************** fonction d'affichage ******************** */
void AfficheLigne(int n, char c)
{
    int i;
    for(i=0; i<n; i++)
        printf("%c",c);
    printf("\n");
}

void AfficheLaGrille(int tab[][DIM_JEU])
{
    int i, j, ln_ligne=25;
    AfficheLigne(ln_ligne,'-');
    for(i=0; i<DIM_JEU; i++)
    {
        for(j=0; j<DIM_JEU; j++)
        {
            if(tab[i][j] == 0)       // verifier si le valeur = 0 ou pas
                printf("|     ");
            else
                printf("|%5d", tab[i][j]);
        }
        printf("|\n");
        AfficheLigne(ln_ligne,'-');
    }        
}

void AfficheChaineChar(char *c_tab)
{
    printf("%s", c_tab);
}

void AfficheScore(int score)
{
    printf("Score : %d \n", score);
}