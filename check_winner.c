//
// Created by zoblaigg on 12/03/24.
//
#include "to_play.h"
#include "initialize.h"
#include "check_winner.h"

//fonction permettant de trouver la ligne gagnante

int ligne_gagnante(char grille[LIGNE_MAX][COLONE_MAX],int ligne)
{
    int j,cpt;  char pion_t;
    pion_t = grille[ligne][0];  cpt=1;
    for(j = 1; j < COLONE_MAX ; j++) {
        if (pion_t == grille[ligne][j] && pion_t != VIDE) {
            cpt++;
        }
        else {
            if (cpt >= NB_GAGNANT) return TRUE;
            pion_t = grille[ligne][j];
            cpt = 1;
        }
    }
    return FALSE;
}

//fonction permettant de trouver la colone gagnante

int colone_gagnante(char grille[LIGNE_MAX][COLONE_MAX],int colone)
{
    int i,cpt; char pion_t;
    pion_t =grille[0][colone]; cpt=1;
    for(i = 1; i < COLONE_MAX ; i++) {
        if (pion_t == grille[i][colone] && pion_t != VIDE) {
            cpt++;
        }
        else {
            if (cpt >= NB_GAGNANT) return TRUE;
            pion_t = grille[i][colone];
            cpt = 1;
        }
    }
    return FALSE;
}


//fonction permettant de trouver la diagonale gagnante de la  gauche vers la droite
int diag1_gagnante_du_bas(char grille[LIGNE_MAX][COLONE_MAX])
{
    int i,j,cpt;  char pion_t;
    for(i = 0; i<= 2; i++){
        pion_t =grille[i][0];   cpt=1;
        for(j = 1; j < COLONE_MAX-i ; j++) {
            if (pion_t == grille[j+i][j] && pion_t != VIDE) {
                cpt++;
            }
            else {
                if (cpt >= NB_GAGNANT) return TRUE;
                pion_t = grille[j+i][j];
                cpt = 1;
            }
        }
    }
    return FALSE;
}


//fonction permettant de trouver la diagonale gagnante de la  gauche vers la droite

int diag1_gagnante_du_haut(char grille[LIGNE_MAX][COLONE_MAX])
{
    int i,j,cpt;  char pion_t;
    for(j = 1; j<= 3; j++){
        pion_t =grille[0][j];   cpt=1;
        for(i = 1; i <= COLONE_MAX-j ; i++) {
            if (pion_t == grille[i][i+j] && pion_t != VIDE) {
                cpt++;
            }
            else {
                if (cpt >= NB_GAGNANT) return TRUE;
                pion_t = grille[i][i+j];
                cpt = 1;
            }
        }
    }
    return FALSE;
}


int compare_diag2(char grille[LIGNE_MAX][COLONE_MAX],int ligne,int colone,int nb_fois)
{
    int i,j,k;
    i=ligne; j=colone ;
    for(k = 0; k < nb_fois; k++){
        i=i+k; j=j-k;
        if( (grille[i][j] == grille[i+1][j-1])
            && (grille[i+1][j-1]== grille[i+2][j-2])
            && (grille[i+2][j-2]== grille[i+3][j-3])
            && grille[i][j] != VIDE) {
            return TRUE;
        }
    }
    return FALSE;
}
//fonction permettant de trouver la diagonale gagnante de la  droite  vers la gauche

int diag2_gagnante(char grille[LIGNE_MAX][COLONE_MAX],int ligne,int colone)
{
    if(     compare_diag2(grille,0,3,1)
            ||  compare_diag2(grille,0,4,2)
            ||  compare_diag2(grille,0,5,3)
            ||  compare_diag2(grille,0,6,3)
            ||  compare_diag2(grille,1,6,2)
            ||  compare_diag2(grille,2,6,1)   ) {
        return TRUE ;
    }
    return FALSE;
}
