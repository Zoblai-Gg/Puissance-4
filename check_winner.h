//
// Created by zoblaigg on 12/03/24.
//
#include "initialize.h"
#include "to_play.h"

#ifndef CPI_PUISSANCE4_H
#define CPI_PUISSANCE4_H


int ligne_gagnante(char grille[LIGNE_MAX][COLONE_MAX],int ligne);
int colone_gagnante(char grille[LIGNE_MAX][COLONE_MAX] ,int colone);
int diag1_gagnante_du_bas(char grille[LIGNE_MAX][COLONE_MAX]);
int diag1_gagnante_du_haut(char grille[LIGNE_MAX][COLONE_MAX]);
int diag2_gagnante_du_haut(char grille[LIGNE_MAX][COLONE_MAX]);
int diag2_gagnante_du_bas(char grille[LIGNE_MAX][COLONE_MAX]);
int compare_diag2(char grille[LIGNE_MAX][COLONE_MAX],int ligne,int colone,int nb_fois);
int diag2_gagnante(char grille[LIGNE_MAX][COLONE_MAX],int ligne,int colone);

#endif //CPI_PUISSANCE4_H
