//
// Created by Adame Meert on 13/04/2023.
//

#include "gameView.h"


gameView::gameView(board* myBoard) {
    thisBoard = myBoard;
}

void gameView::displayBoard() {



    std::cout << " NIVEAU --> " << thisBoard->getLvl() << " <---" << std::endl;

    for (int row = 0; row < thisBoard->getHeight(); ++row) {
        for (int col = 0; col < thisBoard->getLenght(); ++col) {

            const auto &topElement = thisBoard->getPlateau().at(row).at(col).getElements().at(
                    thisBoard->getPlateau().at(row).at(col).getElements().size() - 1).getValue();

            std::cout << toStringElement(topElement) << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

}

void gameView::displayRules() {

    std::cout << "--- BIEVENUE ---" <<std::endl;
    std::cout << std::endl;
    std::cout << "| ----------------------------------------------------------------------------------------------------- |"<< std::endl;
    std::cout << "|  Le but du jeu est de déplacer Baba vers le drapeau pour gagner.                                         |" << std::endl;
    std::cout << "|  Cependant, les règles du jeu peuvent changer en utilisant des mots-clés.                             |" << std::endl;
    std::cout << "|  Par exemple, si vous avez les mots 'Baba', 'Is' et 'You' alignés, vous pouvez contrôler Baba.        |" << std::endl;
    std::cout << "|  De même, si vous avez les mots 'Wall', 'Is' et 'Stop' alignés, les murs vous empêcheront de passer.  |" << std::endl;
    std::cout << "|  Vous pouvez déplacer Baba en tapant : Up / Down / Right / Left .                                     |" << std::endl;
    std::cout << "|  Vous pouvez sauver à tout moment votre partie en tapant : save                                       |" << std::endl;
    std::cout << "|  Vous pouvez quitter en tapant : exit                                                                 |" << std::endl;
    std::cout << "| ----------------------------------------------------------------------------------------------------- |" << std::endl;

}

void gameView::displayError(){

    std::cout << "ERROR -> DOWN / LEFT / UP / RIGHT / save / exit " << std::endl;
}

void gameView::displayLoseError()
{
    std::cout << "ERROR -> oui / non " << std::endl;
}

void gameView::displayLose()
{


    std::cout<< "----- GAME OVER -----" << std::endl;
    std::cout<< "----- REJOUER ? -----" << std::endl;
    std::cout<< "----- OUI / NON -----" << std::endl;

}

void gameView::displayWin()
{

        std::cout << "Félicitations !  Niveau terminé !" << std::endl;
        std::cout << "                                     " << std::endl;
        std::cout << "     *        *        *        *     " << std::endl;
        std::cout << " *        *        *        *        " << std::endl;
        std::cout << "     *        *        *        *     " << std::endl;
        std::cout << " *        *        *        *        " << std::endl;
        std::cout << "     *        *        *        *     " << std::endl;
        std::cout << " *        *        *        *        " << std::endl;
        std::cout << "                                     " << std::endl;



}

void gameView::displayEnd()
{


    std::cout << "MERCI D'AVOIR JOUER ! A LA PROCHAINE " << std::endl;
}

void gameView::update() {
    this->displayBoard();
}
