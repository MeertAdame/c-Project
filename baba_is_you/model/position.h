//
// Created by Adame Meert on 09/03/2023.
//

/**
 * @file position.h
 * @brief  Représente une position dans le plateau de jeu
*/

#ifndef BABA_IS_YOU_POSITION_H
#define BABA_IS_YOU_POSITION_H
#include "direction.h"

/**
 * @brief Représente une position dans le plateau de jeu
 */
class position {

private :
    int x;
    int y;

public :
    /**
     * @brief constructeur par defaut de la position
     */
    position();

    /**
     * @brief constructeur de la position
     * @param x_
     * @param y_
     */
    position(int x_, int y_);

    /**
     * @brief accesseur de la coordonée en X
     * @return
     */
    int getX()const;

    /**
     * @brief accesseur de la coordonée en Y
     * @return
     */
    int getY()const;

    /**
     * @brief donne la provhaîne position du joueur en fonction
     * de la direction vers laquelle il se deplacera
     * @param dir
     * @return
     */
    position nextPos(Direction dir) const;

    /**
     * @brief Surcharge de l'opérateur de comparaison "==" pour comparer deux positions
     * @param other la position a comparer
     * @return vrai si les positions sont identiques
     */
    bool operator==(const position& other) const;


};


#endif //BABA_IS_YOU_POSITION_H
