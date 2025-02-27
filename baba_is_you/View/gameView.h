//
// Created by Adame Meert on 13/04/2023.
//

/**
 * @file gameView.h
 * @brief Vue console
*/

#ifndef BABA_IS_YOU_GAMEVIEW_H
#define BABA_IS_YOU_GAMEVIEW_H

#include "../util/obs.h"
#include "../model/board.h"


/**
 * @brief vue du jeu qui hérite d'observer
 */
class gameView : public Observer{

private :

    board* thisBoard ;

    //GUI
    /*
    pictures startImage ;
    pictures gameOverImage ;
     */

public :

        /**
         * @brief constructeur de la vue
         * @param myBoard plateau d'ou vien les informations que
         * l'on vas afficher dans la class
         */
        gameView(board* myBoard);

        /**
         * @brief affiche le plateau de jeu
         */
        void displayBoard();

        /**
         * @brief explique les règles du jeu babaIsYou
         */
        void displayRules();

        /**
         * @brief affiche un message d'erreur quand on entre une mauvaise commande
         */
        void displayError();
        void displayLoseError();

        /**
         * @brief affichage lors d'une defaite
         */
        void displayLose();

        /**
         * @brief affichage lorce que la partie est gagnée
         */
        void displayWin();

        /**
         * @brief affichage juste avant la fin de la compilation
         */
        void displayEnd();

        /**
         * @brief met a jour la vue
         */
        virtual void update() override;
    

};




#endif //BABA_IS_YOU_GAMEVIEW_H
