//
// Created by zoblaigg on 12/03/24.
//

#include "to_play.h"
#include "initialize.h"
#include "check_winner.h"

void choix_player(char player[T_NAME], char player1[T_NAME], char player2[T_NAME], int tour)
{
    int i=0;
    if(tour % 2 == 0 ){
        while(player2[i] != '\0'){
            player[i]=player2[i];
            i++;
        }
    }
    else{
        while(player1[i] != '\0'){
            player[i]=player1[i];
            i++;
        }
    }
}

void initialisation(char grille[LIGNE_MAX][COLONE_MAX])
{
    int i, j;
    for(i = 0; i < LIGNE_MAX; i++){
        for(j = 0; j < COLONE_MAX; j++){
            grille[i][j]=VIDE;
        }
    }
}

void affichage_grille(char grille[LIGNE_MAX][COLONE_MAX])
{
    int i, j, k;
    printf("\n\n\t");
    for(k = 1; k <= COLONE_MAX; k++) {
        printf("[%2d]\t",k);
    } printf("\n");
    for(i = 0; i < LIGNE_MAX; i++){
// boucle pour les lignes en tiraits
        printf("\t ");
        for(k = 0; k < COLONE_MAX; k++) {
            printf("--------");
        }
//pour le décalage de chaque ligne vers la droite
        printf("\n\t |\t");
        for(j = 0; j < COLONE_MAX; j++){
            printf("  %c\t|",grille[i][j]);
        }
        printf("\n");
    }
// boucle pour les lignes en tiraits
    printf("\t ");
    for(k = 0; k < COLONE_MAX; k++) {
        printf("--------");
    }printf("\n");
}

void recup_nom(char player_name[],char joueur[])
{
    printf("Veuillez saisir le nom du %s\n",joueur);
    scanf(" %s",player_name);
}

//Elle demande à savoir sui doit commencer la partie

int who_start(char player1[],char player2[])
{
    char caracatere;
    do{
        printf("Qui doit commencer la partie ? Veuillez:\n ");
        printf("Taper 1 pour %s\n",player1);
        printf(" Taper 2 pour %s\n",player2);
        scanf(" %c",&caracatere);
    }while(caracatere <'1' || caracatere >'2');
    return caracatere - 48;
}