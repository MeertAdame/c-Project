#ifndef GAMESTATE_H
#define GAMESTATE_H

/**
 * @file gameState.h
 * @brief etat de la partie
*/
#include <string>
#include <iostream>

/**
 * @brief Représente l'etat de la partie en cours
 */
enum class GameState{
    WIN, LOSE, PLAY
};

std::ostream& operator<<(std::ostream& os, const GameState& state);

#endif // GAMESTATE_H
