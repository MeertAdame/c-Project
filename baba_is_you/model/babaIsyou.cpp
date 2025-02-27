
//
// Created by Adame Meert on 13/03/2023.
//

#include "babaIsyou.h"

void babaIsyou::registerObserver(Observer *observer)
{
    observers.push_back(observer);
}

void babaIsyou::unregisterObserver()
{
    observers.pop_back();
}

void babaIsyou::notifyObservers() 
{
    for (const auto observer : observers) {
        observer->update();
    }
}

babaIsyou::babaIsyou(board* b)
{
    myBoard = b;
    state = GameState::PLAY;
    myBoard->updateRules();
}

GameState babaIsyou::getState() const
{
    return state;
}

bool babaIsyou::isPossibleMove(Direction dir, position pos)
{


    bool possible = true;

    // Vérifier si la prochaine position sort du tableau de jeu
    if(pos.nextPos(dir).getX() < 0 || pos.nextPos(dir).getY() < 0
            || pos.nextPos(dir).getX() > myBoard->getHeight()-1
            || pos.nextPos(dir).getY() > myBoard->getLenght()-1)
    {
        possible = false;
    }

    // Vérifier s'il y a un obstacle à la prochaine position
    if (possible && myBoard->getPlateau().at(pos.nextPos(dir).getY()).at(pos.nextPos(dir).getX())
        .getElements().back().getValue() == myBoard->getEffet(Element::STOP).getValue()) {
        possible = false;
    }



    return possible;
}



void babaIsyou::move(Direction dir)
{
    std::vector<position> players {myBoard->getPlayersPos()};

    for (int i = 0; i < players.size(); ++i) {

        if(isPossibleMove(dir, posChain(players.at(i), dir)))
        {

            //move normale sans push
            if(pushRock(players.at(i), dir) == 0)
            {
                if(myBoard->contains(players.at(i).nextPos(dir), myBoard->getEffet(Element::KILL)))
                {
                    myBoard->removeElem(players.at(i));
                } else {
                  myBoard->setElem(players.at(i).nextPos(dir), myBoard->getElem(players.at(i)));
                  myBoard->removeElem(players.at(i));
                }
            }
            //push
            else {

                int cpt {pushRock(players.at(i), dir)};
                switch (dir) {
                    case Direction::RIGHT :
                        while (cpt > 0){
                            position rock {players.at(i).getX()+cpt, players.at(i).getY()};
                            myBoard->setElem(rock.nextPos(dir), myBoard->getElem(rock));
                            myBoard->removeElem(rock);
                            --cpt;
                        }
                        break;
                    case Direction::LEFT :
                        while (cpt > 0){
                            position rock {players.at(i).getX()-cpt, players.at(i).getY()};
                            myBoard->setElem(rock.nextPos(dir), myBoard->getElem(rock));
                            myBoard->removeElem(rock);
                            --cpt;
                        }
                        break;
                    case Direction::UP :
                        while (cpt > 0){
                            position rock {players.at(i).getX(), players.at(i).getY()-cpt};
                            myBoard->setElem(rock.nextPos(dir), myBoard->getElem(rock));
                            myBoard->removeElem(rock);
                            --cpt;
                        }
                        break;
                    case Direction::DOWN :
                        while (cpt > 0){
                            position rock {players.at(i).getX(), players.at(i).getY()+cpt};
                            myBoard->setElem(rock.nextPos(dir), myBoard->getElem(rock));
                            myBoard->removeElem(rock);
                            --cpt;
                        }
                        break;
                case Direction::STOP :
                    break;
                }

                //mov de baba
                if(myBoard->contains(players.at(i).nextPos(dir), myBoard->getEffet(Element::KILL)))
                {
                    myBoard->removeElem(players.at(i));
                } else {
                  myBoard->setElem(players.at(i).nextPos(dir), myBoard->getElem(players.at(i)));
                  myBoard->removeElem(players.at(i));
                }

            }
        }
    }



    applyIsSink();
    myBoard->updateRules();
    applyTransform();




    if (checkWinCondition()){
        state = GameState::WIN;
    } else if(myBoard->getPlayersPos().size() == 0) {
        state = GameState::LOSE;
    } else {
        state = GameState::PLAY;
    }

    notifyObservers();
}


void babaIsyou::applyTransform() {
    for (int i = 0; i < myBoard->getRules().size(); ++i) {
        if(myBoard->getRules().at(i).second.getType() == ElementType::ELEMENT_TEXT)
        {
            for (int j = 0; j < myBoard->getHeight(); ++j) {
                for (int k = 0; k < myBoard->getLenght(); ++k) {
                    elem txt {myBoard->getRules().at(i).second.getValue(),myBoard->getRules().at(i).second.getType()};

                    if(myBoard->getPlateau().at(j).at(k).getElements().back()
                      .getValue() == convertTxtToElem(myBoard->getRules().at(i).first).getValue()){
                        position pos {k, j};
                        myBoard->removeElem(pos);
                        myBoard->setElem(pos, convertTxtToElem(txt));
                    }
                }
            }
        }
    }
}

void babaIsyou::applyIsSink() {
    for (int j = 0; j < myBoard->getHeight(); ++j) {
        for (int k = 0; k < myBoard->getLenght(); ++k) {
            position pos{k, j};
            if (myBoard->contains(pos,myBoard->getEffet(Element::SINK))
                && myBoard->getPlateau().at(pos.getY()).at(pos.getX()).getElements().size() > 2) {

                int nbElem {static_cast<int>(myBoard->getPlateau().at(pos.getY()).
                                             at(pos.getX()).getElements().size())};
                while (nbElem > 1){
                    myBoard->removeElem(pos);
                    nbElem--;
                }
            }
        }
    }
}


elem babaIsyou::convertTxtToElem(elem txt){

    elem convert{Element::EMPTY, ElementType::ELEMENT};
    switch (txt.getValue()) {
        case Element::TEXT_GRASS :
            convert = {Element::GRASS, ElementType::ELEMENT};
            break;
        case Element::TEXT_LAVA :
            convert = {Element::LAVA, ElementType::ELEMENT};
            break;
        case Element::TEXT_FLAG :
            convert = {Element::FLAG, ElementType::ELEMENT};
            break;
        case Element::TEXT_METAL:
            convert = {Element::METAL, ElementType::ELEMENT};
            break;
        case Element::TEXT_GOOP :
            convert = {Element::GOOP, ElementType::ELEMENT};
            break;
        case Element::TEXT_BONE :
            convert = {Element::BONE, ElementType::ELEMENT};
            break;
        case Element::TEXT_ROCK :
            convert = {Element::ROCK, ElementType::ELEMENT};
            break;
        case Element::TEXT_BABA :
            convert = {Element::BABA, ElementType::ELEMENT};
            break;
        case Element::TEXT_WALL :
            convert = {Element::WALL, ElementType::ELEMENT};
            break;
    default :
        convert = {Element::NOTHING, ElementType::ELEMENT};
    }
    return convert;
}

position babaIsyou::posChain(position player, Direction dir)
{

    int lastRock = pushRock(player, dir);
    position pos {};

    switch (dir) {
        case Direction::UP:
            pos = position(player.getX(), player.getY() - lastRock);
            break;
        case Direction::DOWN:
            pos = position(player.getX(), player.getY() + lastRock);
            break;
        case Direction::RIGHT:
            pos = position(player.getX() + lastRock, player.getY());
            break;
        case Direction::LEFT:
            pos = position(player.getX() - lastRock, player.getY());
            break;
    case Direction::STOP:
            break;
    }

    return pos;
}

int babaIsyou::pushRock(position player, Direction dir)
{
    int cpt{};
    const int maxHeight = myBoard->getHeight() - 1;
    const int maxLength = myBoard->getLenght() - 1;

    while (true) {
        if (player.nextPos(dir).getX() < 0 || player.nextPos(dir).getX() > maxHeight
            || player.nextPos(dir).getY() < 0 || player.nextPos(dir).getY() > maxLength) {
            break; // Sortir de la boucle while
        }

        const elem nextElem = myBoard->getElem(player.nextPos(dir));
        const ElementType nextElemType = nextElem.getType();

        if (nextElem == myBoard->getEffet(Element::PUSH)
            || nextElemType == ElementType::ELEMENT_TEXT
            || nextElemType == ElementType::EFFET
            || nextElemType == ElementType::CONNECTEUR) {
            ++cpt;
        } else {
            break; // Sortir de la boucle while
        }

        switch (dir) {
            case Direction::RIGHT:
                player = position(player.getX() + 1, player.getY());
                break;
            case Direction::LEFT:
                player = position(player.getX() - 1, player.getY());
                break;
            case Direction::UP:
                player = position(player.getX(), player.getY() - 1);
                break;
            case Direction::DOWN:
                player = position(player.getX(), player.getY() + 1);
                break;
            default:
                break;
        }
    }

    return cpt;
}


bool babaIsyou::checkWinCondition()
{
    std::vector<position> players {myBoard->getPlayersPos()};
    for (int i = 0; i < players.size(); ++i) {
        if(myBoard->contains(players.at(i), myBoard->getEffet(Element::WIN))){
            return true;
        }
    }
    return false;
}

board *babaIsyou::getMyBoard() const {
    return myBoard;
}


