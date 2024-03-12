#include <stdio.h>
#include "initialize.h"

int main (void)
{
    int i, j, fin,tour,End;
    char grille[LIGNE_MAX][COLONE_MAX];
    char player1[T_NAME],player2[T_NAME], player[T_NAME];
    initialisation(grille);
    affichage_grille(grille);
    recup_nom(player1,"joueur1");
    recup_nom(player2,"joueur2");

//Ici la valeur retouenée de la fonction who_start est soit 1 ou 2  permettant de savoir qui joue en premier en foncton de la parité
    tour =who_start(player1,player2);
    do
    {
        choix_player(player, player1, player2, tour) ;
        End=tour_d_jeu(grille,tour, player);
        if(End ==  TRUE){
            printf("Bravo %s vous rempotez la partie\n",player);
            return 0;
        }
//Boucle pour trouver voir la fin de jeu
        j=1; fin=0;
        for(i = 0;i < T_MAX-1; i++){
            if(grille[i][j] == VIDE){
                fin++;
            }
            j++;
            if(j == T_MAX) break;
        }
        tour++;
    }while( fin != 0);
    printf(" FIN DE LA PARTIE ! \n VOUS AVIEZ FAIT MATCH NULL ! ");

    return 0;
}

