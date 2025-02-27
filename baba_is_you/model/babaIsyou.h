//
// Created by Adame Meert on 13/03/2023.
//

/**
 * @file babaIsyou.h
 * @brief Façade du jeu gére les actions concrétes de l'utilisateur
*/

#ifndef BABA_IS_YOU_BABAISYOU_H
#define BABA_IS_YOU_BABAISYOU_H
#include <iostream>
#include <vector>
#include "board.h"
#include "gameState.h"
#include "../util/obs.h"

/**
 * @brief Classe qui représente le jeu Baba Is You.
 * Elle contient un plateau de jeu (classe Board), l'état du jeu (classe GameState)
 * et des méthodes pour effectuer des mouvements, vérifier les conditions de victoire, etc.
 * Cette classe implémente l'interface Observateur et peut donc être observée par d'autres classes.
 */
class babaIsyou : public Observateur{

private :
    board* myBoard;
    GameState state;
    std::vector<Observer*> observers;

public:

    /**
     * @brief Constructeur de la classe babaIsyou.
     * @param b un pointeur vers un objet de la classe board représentant le plateau de jeu.
     */
    babaIsyou(board* b);

    /**
     * @brief Méthode qui retourne le plateau de jeu.
     * @return un pointeur vers un objet de la classe board représentant le plateau de jeu.
     */
    board *getMyBoard() const;

    /**
     * @brief Méthode qui retourne l'état du jeu.
     * @return un objet de la classe GameState représentant l'état du jeu.
     */
    GameState getState() const;

    /**
     * @brief Méthode qui permet de déplacer le joueur dans une direction donnée.
     * Elle permet égallement de pousser des elements si possible.
     * @param dir la direction dans laquelle le joueur doit être déplacé.
     */
    void move(Direction dir);

    /**
     * @brief Méthode qui permet à un observateur de s'enregistrer auprès de la classe babaIsyou.
     * @param observer un pointeur vers l'objet de l'observateur qui souhaite s'enregistrer.
     */
    virtual void registerObserver(Observer *observer) override;

    /**
     * @brief Méthode qui permet à un observateur de se désenregistrer auprès de la classe babaIsyou.
     */
    virtual void unregisterObserver() override;

    /**
     * @brief Méthode qui notifie tous les observateurs enregistrés auprès de la classe babaIsyou.
     */
    virtual void notifyObservers() override;

private:

    /**
     * @brief Méthode qui vérifie si un mouvement dans une direction donnée est possible à partir d'une position donnée.
     * @param dir la direction du mouvement.
     * @param pos la position de départ.
     * @return true si le mouvement est possible, false sinon.
     */
    bool isPossibleMove(Direction dir, position pos);

    /**
     * @brief Méthode qui vérifie si les conditions de victoire sont satisfaites.
     * @return true si le joueur a gagné, false sinon.
     */
    bool checkWinCondition();

    /**
     * @brief Méthode savoir le nombre d'objet que le joueur doit pousser.
     * @param player la position du joueur.
     * @param dir la direction dans laquelle le rocher doit être poussé.
     * @return le nombre d'objet voisin que baba peut pousser.
     */
    int pushRock(position player, Direction dir);

    /**
     * @brief Méthode vérifie la position du dernier square d'une chaine.
     * @param player
     * @param dir
     * @return la position du dernier square de la chaîne de pousse.
     */
    position posChain(position player, Direction dir);

    /**
    * @brief Convertit un texte en un objet "elem".
    * @param txt Un objet "elem" représentant le texte à convertir.
    * @return Un objet "elem" représentant l'élément converti.
    */
    elem convertTxtToElem(elem txt);

    /**
     * @brief applique la règle is sink (si il y'en a une)
     */
    void applyIsSink();

    /**
     * @brief applique la règle qui transforme les elem A en elem B (si il y'en a une)
     */
    void applyTransform();
};




#endif //BABA_IS_YOU_BABAISYOU_H
