#include <stdio.h>
#include <stdlib.h>
#include "constante.h"
#include "fonctions_2048.h"
#include "interface_2048.h"
#include "interface_2048_curse.h"

/* ******************** fonction independent de l'affichage ********************
*/

void swap(int *a, int *b)
{
    int temp;
    
    temp = *b;
    *b   = *a;
    *a   = temp;   
}

void InitGrille(int T[][DIM_JEU])
{
    int i,j;
    for(i=0; i<DIM_JEU; i++)
        for(j=0; j<DIM_JEU; j++)
            T[i][j] = 0;
}

int ValeurAleatoire(void)
{
    int r;
    r = rand()%(TAUX_DE_2);
    if(r==0)
        r=4;
    else
        r=2;
    
    return r;   
}

int RetasseLigne(int T[DIM_JEU][DIM_JEU], int retasse_a_droite)
{
    int i, j, jdec, rtn=0;
    if(retasse_a_droite)
    {
        for(i=0; i<DIM_JEU; i++){
            for(j=DIM_JEU-1; j>0; j--){
                if (T[i][j]==0){
                    jdec=j;
                    do {
                        jdec--;
                    }
                    while(T[i][jdec]==0 && jdec>0);
                    if(T[i][jdec] != 0){
                        swap(&T[i][j], &T[i][jdec]);
                        rtn++;
                    }    
                }
            }
        }
    }
    else
    {
        for(i=0; i<DIM_JEU; i++){
            for(j=0; j<DIM_JEU-1; j++){
                if (T[i][j]==0){
                    jdec=j;
                    do {
                        jdec++;
                    }
                    while(T[i][jdec]==0 && jdec<DIM_JEU-1);
                    if(T[i][jdec] != 0){
                        swap(&T[i][j], &T[i][jdec]);
                        rtn++;
                    }    
                }
            }
        }
    }
    return rtn;
}

int RetasseCollone(int T[DIM_JEU][DIM_JEU], int retasse_vers_bas)
{
    int i, j, idec, rtn=0;
    if(retasse_vers_bas)
    {
        for(j=0; j<DIM_JEU; j++){
            for(i=DIM_JEU-1; i>0; i--){
                if (T[i][j]==0){
                    idec=i;
                    do {
                        idec--;
                    }
                    while(T[idec][j]==0 && idec>0);
                    if(T[idec][j] != 0){
                        swap(&T[i][j], &T[idec][j]);
                        rtn++;
                    }    
                }
            }
        }
    }
    else
    {
        for(j=0; j<DIM_JEU; j++){
            for(i=0; i<DIM_JEU-1; i++){
                if (T[i][j]==0){
                    idec=i;
                    do {
                        idec++;
                    }
                    while(T[idec][j]==0 && idec<DIM_JEU-1);
                    if(T[idec][j] != 0){
                        swap(&T[i][j], &T[idec][j]);
                        rtn++;
                    }    
                }
            }
        }
    }
    return rtn;  
}

int AdditionLigne(int T[DIM_JEU][DIM_JEU], int retasse_a_droite, int *score)
{
    int i, j, rtn=0;
    if(retasse_a_droite)
    {
        for(i=0; i<DIM_JEU; i++){
            for(j=DIM_JEU-1; j>0; j--){
                if (T[i][j]==T[i][j-1] && T[i][j]!=0){
                    T[i][j]=T[i][j]+T[i][j-1];
                    *score = *score + T[i][j];
                    T[i][j-1]=0;
                    rtn++;
                }
            }
        }
    }
    else
    {
        for(i=0; i<DIM_JEU; i++){
            for(j=0; j<DIM_JEU-1; j++){
                if (T[i][j]==T[i][j+1] && T[i][j]!=0){
                    T[i][j]=T[i][j]+T[i][j+1];
                    *score = *score + T[i][j];
                    T[i][j+1]=0;
                    rtn++;
                }
            }
        }
    }
    return rtn;
}

int AdditionCollone(int T[DIM_JEU][DIM_JEU], int retasse_vers_bas, int *score)
{
    int i, j, rtn=0;
    if(retasse_vers_bas)
    {
        for(j=0; j<DIM_JEU; j++){
            for(i=DIM_JEU-1; i>0; i--){
                if (T[i][j]==T[i-1][j] && T[i][j]!=0){
                    T[i][j]=T[i][j]+T[i-1][j];
                    *score = *score + T[i][j];
                    T[i-1][j]=0;
                    rtn++;
                }
            }
        }
    }
    else
    {
        for(j=0; j<DIM_JEU; j++){
            for(i=0; i<DIM_JEU-1; i++){
                if (T[i][j]==T[i+1][j] && T[i][j]!=0){
                    T[i][j]=T[i][j]+T[i+1][j];
                    *score = *score + T[i][j];
                    T[i+1][j]=0;
                    rtn++;
                }
            }
        }
    }
    return rtn;
}

void OrdiJoue(int T[DIM_JEU][DIM_JEU])
{
    int rn_ligne, rn_col, case_vide=0, i, j;
    
    for(i=0;i<DIM_JEU;i++)
    {
        for(j=0;j<DIM_JEU;j++)
        {
            if(T[i][j]==0)
                case_vide++;      
        }
    }
    
    if (case_vide>0) 
    {
        do
        {
            rn_ligne=rand()%4;
            rn_col=rand()%4;
        }
        while(T[rn_ligne][rn_col]!=0);
        
        T[rn_ligne][rn_col]=ValeurAleatoire();
    }
}

int JouerJoue(int T[DIM_JEU][DIM_JEU], char direction, int *score)
{
    int ret=0, add=0, retasse_a_droite, retasse_vers_bas;
    if(direction == '6' || direction == '4')
    {
        if(direction == '6')
            retasse_a_droite = 1;
        else
            retasse_a_droite = 0;
        
        ret = RetasseLigne(T, retasse_a_droite);
        add = AdditionLigne(T, retasse_a_droite, score);
        if(add)
        {
            RetasseLigne(T, retasse_a_droite);
        }
    }
    
    if(direction == '2' || direction == '8')
    {
        if(direction == '2')
            retasse_vers_bas = 1;
        else
            retasse_vers_bas = 0;
        
        ret = RetasseCollone(T,retasse_vers_bas);
        add = AdditionCollone(T,retasse_vers_bas, score);
        if (add)
        {
            RetasseCollone(T,retasse_vers_bas);
        }
    }
    return ret + add;
    
}

int JoueEncore(int T[DIM_JEU][DIM_JEU])
{
    int i,j, case_vide=0, ret, gagne=0;
    
    for(i=0;i<DIM_JEU;i++)
    {
        for(j=0;j<DIM_JEU;j++)
        {
            if(T[i][j]==0)
                case_vide++;
            
            if(T[i][j]>=OBJECTIFS)
                gagne=1;
            
        }
    }
    
    if(case_vide<=0 && gagne==0)
        ret=0; // on ne peut plus bouger et on n'a pas gagné
    if(case_vide<=0 && gagne==1)
        ret=1; // 
    if(case_vide>0 && gagne==0)
        ret=2;
    if(case_vide>0 && gagne==1)
        ret=3;
            
    return ret; // while ret > 1 on peut encore jouer        
}

int nb_case_vide(int T[DIM_JEU][DIM_JEU])
{
    int i,j, case_vide=0;
    
    for(i=0;i<DIM_JEU;i++)
    {
        for(j=0;j<DIM_JEU;j++)
        {
            if(T[i][j]==0)
                case_vide++;    
        }
    }
    
    return case_vide; // while ret > 1 on peut encore jouer
}
int est_gagne(int T[DIM_JEU][DIM_JEU])
{
    int i,j;
    
    for(i=0;i<DIM_JEU;i++)
    {
        for(j=0;j<DIM_JEU;j++)
        {        
            if(T[i][j]>=OBJECTIFS)
                return 1; 
        }
    }
    
    return 0;
}

void InitJeu(int T[DIM_JEU][DIM_JEU], int *score)
{
    *score=0;
    InitGrille(T);
    OrdiJoue(T);
    OrdiJoue(T);
    AfficheLaGrille(T);
    AfficheScore(*score);
}

void jeu_une_fois(int T[DIM_JEU][DIM_JEU], int *score)
{
    char direction;
    
//     AfficheChaineChar("Entrez la direction: ");
    direction = SaisieDirection();
    if(JouerJoue(T, direction, score))
        OrdiJoue(T);
    AfficheLaGrille(T);
    AfficheScore(*score);

}

int jeu_2048(int T[DIM_JEU][DIM_JEU], int *score)
{
    do {
        if(!est_gagne(T))
        {
            do
                jeu_une_fois(T, score);
            while(JoueEncore(T)==2);
        }
        else
        {
            do
                jeu_une_fois(T, score);
            while(nb_case_vide(T));
        }
    }
    while (!(nb_case_vide(T)) && est_possible_additioner(T));
    
    return JoueEncore(T);
}

int est_possible_additioner(int T[DIM_JEU][DIM_JEU])
{
    int i,j;
    for(i=0;i<DIM_JEU;i++)
    {
        for(j=0;j<DIM_JEU;j++)
        {
            if(j>0 && T[i][j]==T[i][j-1])
                return 1;
            if(j<3 && T[i][j]==T[i][j+1])
                return 1;
            
            if(i>0 && T[i][j]==T[i-1][j])
                return 1;
            if(i<3 && T[i][j]==T[i+1][j])
                return 1;
        }
    }
    return 0;
}