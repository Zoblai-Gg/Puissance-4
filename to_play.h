//
// Created by zoblaigg on 12/03/24.
//
#include "initialize.h"

#ifndef CPI_TO_PLAY_H
#define CPI_TO_PLAY_H

int recup_coor(char chaine[],char lettre);
void fonction_d_jeu(char grille[LIGNE_MAX][COLONE_MAX],int ligne, int colone,char pion);
int fonction_fin_d_jeu(char grille[LIGNE_MAX][COLONE_MAX],int ligne,int colone);
int detection_case_vide(char grille[LIGNE_MAX][COLONE_MAX], int colone );
int tour_d_jeu(char grille[LIGNE_MAX][COLONE_MAX], int tour, char player[]);

#endif //CPI_TO_PLAY_H
