//
// Created by zoblaigg on 12/03/24.
//
#include <stdio.h>

#ifndef CPI_INITIALIZE_H
#define CPI_INITIALIZE_H
#define HTAG '#'
#define VIDE ' '
#define ROND 'O'
#define T_MAX 7
#define LIGNE_MAX T_MAX-1
#define COLONE_MAX T_MAX
#define TRUE 1
#define FALSE 0
#define T_NAME 100
#define NB_GAGNANT  4

void choix_player(char player[T_NAME], char player1[T_NAME], char player2[T_NAME], int tour);
void initialisation(char grille[LIGNE_MAX][COLONE_MAX]);
void affichage_grille(char grille[LIGNE_MAX][COLONE_MAX]);
void recup_nom(char player_name[],char joueur[]);
int who_start(char joueur1[],char joueur2[]);
int tour_d_jeu(char grille[LIGNE_MAX][COLONE_MAX],int tour, char player[T_NAME]);

#endif //CPI_INITIALIZE_H
