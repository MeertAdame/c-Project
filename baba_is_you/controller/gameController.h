//
// Created by adamj on 22-03-23.
//

/**
 * @file gameController.h
 * @brief Fais le lien entre la vue et le model
*/
#ifndef BABA_IS_YOU_GAMECONTROLLER_H
#define BABA_IS_YOU_GAMECONTROLLER_H
#include "../View/gameView.h"
#include "../model/babaIsyou.h"

/**
 * @brief Classe gameController : Contrôleur du jeu Baba is You.
 *
 * Cette classe est chargée de gérer le flux de jeu, en interagissant avec l'objet
 * babaIsyou (modèle) et gameView (vue).
 */
class gameController {

private :
    babaIsyou* thisgame;
    gameView* thisView;

public :
    /**
     * @brief Constructeur de gameController.
     * @param game Un pointeur vers l'objet babaIsyou (modèle) à utiliser.
     * @param v Un pointeur vers l'objet gameView (vue) à utiliser.
     */
    gameController(babaIsyou* game , gameView* v);


    /**
     * @brief Démarre le jeu en lançant la boucle principale de jeu.
     * Cette fonction gère l'interaction entre l'utilisateur, le modèle et la vue.
     */
    void startGame();


};


inline bool lvlOk(std::string level){
    for (int i = 0; i < listLvl().size(); ++i) {
        if(listLvl().at(i) == level) {
            return true;
        }
    }
    return false;
}

/**
 * @brief demande le niveau que le joueur veut jouer
 * @return le nom du niveau
 */
inline std::string askLevel(){



    std::string level;
    std::cout << "Entre le niveau que tu veux jouer (n'oublie pas .txt) : ";
    std::istream& nvx = std::cin;
    nvx >> level;
    std::transform(level.begin(), level.end(), level.begin(), ::tolower);

    return level;
}


#endif //BABA_IS_YOU_GAMECONTROLLER_H
