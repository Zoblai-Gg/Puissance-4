//
// Created by zoblaigg on 12/03/24.
//
#include "to_play.h"
#include "initialize.h"
#include "check_winner.h"


int recup_coor(char chaine[],char lettre)
{
// le terneur de if (c'est juste un if-else)
    char entier, max;
    max = lettre == 'x' ? '6' : '7' ;
    do{
        printf("A quelle  %s voulez vous jouer \n",chaine);
        scanf(" %c",&entier);
    }while(entier < '1' || entier > max);
    return entier-48;
}

void fonction_d_jeu(char grille[LIGNE_MAX][COLONE_MAX],int ligne, int colone,char pion)
{
    grille[ligne][colone]=pion;
}

int detection_case_vide(char grille[LIGNE_MAX][COLONE_MAX], int colone )
{
    int i;
    for(i= LIGNE_MAX-1 ; i >= 0 ; i--){
        if( grille[i][colone] == VIDE){
            return i;
        }
    }
    return -1;
}

//Cette fonction regroupe toutes les fonctions qui vérifient s'il ya un gagnant

int fonction_fin_d_jeu(char grille[LIGNE_MAX][COLONE_MAX],int ligne,int colone)
{
    if(ligne_gagnante(grille,ligne)== TRUE){
        return TRUE;
    }
    else if(colone_gagnante(grille,colone)== TRUE) {
        return TRUE;
    }
    else if(diag1_gagnante_du_haut(grille)== TRUE) {
        return TRUE;
    }
    else if(diag1_gagnante_du_bas(grille)== TRUE) {
        return TRUE;
    }
    else if(diag2_gagnante(grille,ligne,colone)== TRUE) {
        return TRUE;
    }
    else{
        return FALSE;
    }
}

// Cette fontion est très importante,elle constitue le centre du jeu car la plus part des fonction y sont appelées
int tour_d_jeu(char grille[LIGNE_MAX][COLONE_MAX], int tour, char player[])
{
    int colone,ligne;
    printf("\n %s à vous de jouer\n",player);
    do{
        colone =recup_coor("colone",'y')-1;
        ligne= detection_case_vide(grille, colone);
        if(ligne == -1){
            printf("\nCette case n'est pas jouable\nVeuillez resaisir de nouveau\n\n");
        }
    }while(ligne == -1);

    if(tour%2 != 0){
        fonction_d_jeu(grille,ligne,colone,ROND);
    }
    else{
        fonction_d_jeu(grille,ligne,colone,HTAG);
    }
    affichage_grille(grille);
    int End =fonction_fin_d_jeu(grille,ligne,colone);
    return End;
}
