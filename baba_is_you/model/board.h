//
// Created by Adame Meert on 13/03/2023.
//
#include "square.h"
#include "position.h"
#include "elem.h"
/**
 * @file board.h
 * @brief Gère le plateau de jeu ainsi que ses règles
*/

#ifndef BABA_IS_YOU_BOARD_H
#define BABA_IS_YOU_BOARD_H

#include "position.h"
#include "elem.h"
#include "../controller/file.h"


/**
 * @brief Représentation du plateau de jeu de Baba Is You.
 */
class board {


private:
    std::vector<std::pair<elem, elem>> rules;
    std::string lvl;
    file fichier ;
    std::vector<std::vector<square>>  plateau;

public :


    /**
    * @brief Constructeur de la classe Board.
    * @param lvl Niveau du jeu à charger.
    */
    board(std::string lvl);


    /**
    * @brief Accesseur pour le niveau du jeu chargé.
    * @return Le niveau du jeu chargé.
    */
    std::string getLvl() const;

    /**
    * @brief Accesseur pour la hauteur du plateau de jeu.
    * @return La hauteur du plateau de jeu.
     */
    int getHeight() const;

    /**
    * @brief Accesseur pour la longueur du plateau de jeu.
    * @return La longueur du plateau de jeu.
    */
    int getLenght() const;

    /**
    * @brief Accesseur pour les règles actuelles du plateau de jeu.
    * @return Un vecteur contenant les paires d'éléments de chaque règle.
    */
    std::vector<std::pair<elem, elem>> getRules()const;

    /**
    * @brief Vérifie si une position contient un élément spécifique.
    * @param pos Position à vérifier.
    * @param element Élément à vérifier.
    * @return Vrai si la position contient l'élément spécifié, faux sinon.
    */
    bool contains(position pos,elem element);

    /**
    * @brief Modifie l'élément présent à une position donnée sur le plateau de jeu.
    * @param pos Position à modifier.
    * @param element Nouvel élément à placer à cette position.
    */
    void setElem(position pos, elem element);

    /**
    * @brief Supprime l'élément présent à une position donnée sur le plateau de jeu.
    * @param pos Position à vider.
    */
    void removeElem(position pos);

    /**
    * @brief Accesseur pour l'élément présent à une position donnée sur le plateau de jeu.
    * @param pos Position à interroger.
    * @return L'élément présent à cette position.
    */
    elem getElem(position pos);

    /**
    * @brief Met à jour les règles actuelles du plateau de jeu.
    *
    * Cette méthode doit être appelée après chaque modification du plateau de jeu pour
    * s'assurer que les règles sont à jour.
    */
    void updateRules();



    /**
    * @brief Récupère la liste des positions des joueurs présents sur le plateau
    * @return La liste des positions des joueurs
    */
    std::vector<position> getPlayersPos();

    /**
     * @brief Vérifie l'objet sur lequel on applique un effet donné
     * @param elem l'effet à vérifier
     * @return l'objet qui correspond a l'effet
     */
    elem getEffet(Element elem);

    /**
     * @brief Accesseur pour le plateau de jeu
     * @return le plateau de jeu
     */
    std::vector<std::vector<square>> getPlateau() const;

private :

    /**
    * @brief Ajoute une nouvelle règle a la liste de règle.
    * @param elemLeft Élément de gauche de la règle.
    * @param elemRight Élément de droite de la règle.
    */
    void addRule(elem elemLeft, elem elemRight);

    /**
     * @brief vérifie si le régle est valide de façon horizontale
     * @param elemLeft l'element qui se trouve a gauche du connecteur
     * @param elemRight l'element qui se trouve a droite du connecteur
     * @return Vrai si la structure de la règle est valide
     */
    bool checkHorizontal(elem elemLeft, elem elemRight);

    /**
     * @brief vérifie si le régle est valide de façon verticale
     * @param elemLeft l'element qui se trouve en haut du connecteur
     * @param elemRight l'element qui se trouve en bas du connecteur
     * @return Vrai si la structure de la règle est valide
     */
    bool checkVertical(elem elemUp, elem elemDown);
};


#endif //BABA_IS_YOU_BOARD_H
