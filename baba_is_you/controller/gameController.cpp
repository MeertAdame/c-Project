//
// Created by adamj on 22-03-23.
//

#include "gameController.h"



gameController::gameController(babaIsyou* game , gameView* view){
    thisView = view ;
    thisgame = game ;
}


void gameController::startGame() {



    thisView->displayBoard();

    while(thisgame->getState() == GameState::PLAY){



        std::string dir;

        do {
            std::cout << "Entrez une commande : ";
            std::istream& commande = std::cin;
            commande >> dir;
            std::transform(dir.begin(), dir.end(), dir.begin(), ::tolower);
            if(dir != "up" && dir != "down" && dir != "right" && dir != "left" && dir != "save" && dir != "exit")
                thisView->displayError();
        } while (dir != "up" && dir != "down" && dir != "right" && dir != "left" && dir != "save"&& dir != "exit");

        Direction direction ;
        if(dir == "left"){
            direction = Direction::LEFT;
        } else if(dir == "right") {
            direction = Direction::RIGHT;
        }else if(dir == "up"){
            direction = Direction::UP ;
        }else if(dir == "down"){
            direction = Direction::DOWN ;
        } else if(dir == "save"){

            std::string fileName;
            std::cout << "Entrez une nom de fichier : ";
            std::istream& name = std::cin;
            name >> fileName;
            std::transform(fileName.begin(), fileName.end(), fileName.begin(), ::tolower);

            std::ofstream file(fileName + ".txt");

            thisView->displayBoard();

            std::cout << std::endl;
            std::cout << std::endl;

            file << thisgame->getMyBoard()->getLenght() << " " << thisgame->getMyBoard()->getHeight() << std::endl;


            for(int i = 0; i < thisgame->getMyBoard()->getHeight(); i++)
            {
                for(int j = 0; j < thisgame->getMyBoard()->getHeight(); j++)
                {
                    position pos (j, i);

                    if(thisgame->getMyBoard()->getElem(pos).getValue() != Element::EMPTY ){
                        file << toStringFile(thisgame->getMyBoard()->getElem(pos).getValue()) ;
                        file << " "<<j << " " << i << std::endl;
                    }
                }
            }
        } else if(dir == "exit") {
            thisView->displayEnd();
            exit(1);
        }

        thisgame->move(direction);

        if(thisgame->getState() == GameState::LOSE){

        std::string restart;

            do {
                thisView->displayLose();
                std::istream& commande = std::cin;
                commande >> restart;
                std::transform(restart.begin(), restart.end(), restart.begin(), ::tolower);
                if(restart != "oui" && restart != "non")
                    thisView->displayLoseError();
            } while (restart != "oui" && restart != "non");

            if(restart == "oui"){
                board myBoard(thisgame->getMyBoard()->getLvl());
                babaIsyou baba(&myBoard);
                gameView view(&myBoard);
                gameController controller(&baba, &view);
                baba.registerObserver(&view);
                controller.startGame();
            }else if(restart == "non"){
                thisView->displayEnd();
                exit(1);
            }

        }else if(thisgame->getState()== GameState::WIN){
                this->thisView->displayWin();
                showLvl();
            std::string nvx = askLevel();
            while (!lvlOk(nvx)){
                std::cout << "ERROR --> INVALID LEVEL" << std::endl;
                std::cout << std::endl;
                nvx = askLevel();
            }

                board myBoard(nvx);
                babaIsyou baba(&myBoard);
                gameView view(&myBoard);
                gameController controller(&baba, &view);
                baba.registerObserver(&view);
                controller.startGame();

        }
    }

}


