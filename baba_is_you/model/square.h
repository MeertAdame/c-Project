//
// Created by Adame Meert on 09/03/2023.
//

/**
 * @file square.h
 * @brief Case du jeu ainsi que les éléments qui se trouve a l'interieur
*/

#ifndef BABA_IS_YOU_SQUARE_H
#define BABA_IS_YOU_SQUARE_H
#include <vector>
#include "position.h"
#include "elem.h"

/**
 * @brief Représente une case du plateau de jeu
 */
class square {

private :
    std::vector<elem> pixel;
    position pos;

public :

    /**
     * @brief constructeur de la case
     * @param elem la liste d'element que contient le square
     * @param pos la position ou se trouve la case dans le plateau
     */
    square(std::vector<elem> elems, position pos);

    /**
     * @brief constructeur par defaut
     */
    square();

    /**
     * @brief accesseur de la liste d'element
     * @return la liste d'element que contient une case
     */
    std::vector<elem> getElements() const;

    /**
     * @brief accesseur de la position de la case
     * @return la position a laquelle se trouve la case dans le plateau de jeu
     */
    position getPosition() const;

    /**
     * @brief rajoute un elem dans la liste d'element de la case
     * @param x
     */
    void push(elem x);

    /**
     * @brief retire l'element qui se trouve a la fin de la liste d'elem
     */
    void pop() ;



    /**
     * @brief Surcharge l'opérateur d'affichage
     * @param os l'affichage
     * @param sq la référence du square à afficher
     * @return le square sous forme d'affichage dans la sortie standard
     */
    friend std::ostream& operator<<(std::ostream& os, const square& sq);

};

#endif //BABA_IS_YOU_SQUARE_H
