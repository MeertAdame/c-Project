//
// Created by Adame Meert on 13/03/2023.
//

#include "board.h"



board::board(std::string level) : lvl(level), fichier(lvl) {

    std::vector<std::vector<square>> initV2 {fichier.init()};
    for (int i = 0; i < initV2.size(); ++i) {
        plateau.push_back(initV2.at(i));
    }

}

std::vector<std::vector<square>> board::getPlateau() const
{
    return plateau;
}

int board::getHeight() const
{
    return fichier.getWidth() ;
}

int board::getLenght() const
{
    return fichier.getLength() ;
}

bool board::contains(position pos,elem element)
{

    for (elem all_element : plateau.at(pos.getY()).at(pos.getX()).getElements()) {
        if(all_element == element){
            return true ;
        }
    }
    return false;
}

void board::setElem(position pos, elem element) {

    plateau.at(pos.getY()).at(pos.getX()).push(element);

}

void board::removeElem(position pos) {

    plateau.at(pos.getY()).at(pos.getX()).pop();
}

elem board::getElem(position pos)
{
    std::vector<elem> listElem = plateau.at(pos.getY()).at(pos.getX()).getElements();

    return listElem.back();
}

void board::updateRules()
{
    rules.clear();

    const int height = getHeight();
    const int length = getLenght();

    for(const auto & ligne : plateau) {
        for(const auto & col : ligne) {
            const auto& elements = col.getElements();
            if (!elements.empty()) {
                const elem& element = elements.back();
                if (element.getType() == ElementType::CONNECTEUR) {
                    const position& pos = col.getPosition();

                    const elem& currentElement = elements.back();
                    const elem elemLeft = (pos.getX() > 0 && pos.getX() < height - 1) ?
                                plateau.at(pos.getY()).at(pos.getX() - 1).getElements().back() : currentElement;
                    const elem elemRight = (pos.getX() > 0 && pos.getX() < height - 1) ?
                                plateau.at(pos.getY()).at(pos.getX() + 1).getElements().back() : currentElement;
                    const elem elemUp = (pos.getY() > 0 && pos.getY() < length - 1) ?
                                plateau.at(pos.getY() - 1).at(pos.getX()).getElements().back() : currentElement;
                    const elem elemDown = (pos.getY() > 0 && pos.getY() < length - 1) ?
                                plateau.at(pos.getY() + 1).at(pos.getX()).getElements().back() : currentElement;

                    const bool firstIf = board::checkHorizontal(elemLeft, elemRight);
                    const bool secondIf = board::checkVertical(elemUp, elemDown);

                    if (firstIf) {
                        addRule(elemLeft, elemRight);
                    }
                    else if (secondIf) {
                        addRule(elemUp, elemDown);
                    }
                }
            }
        }
    }
}


bool board::checkHorizontal(elem elemLeft, elem elemRight) {
    return elemLeft.getType() == ElementType::ELEMENT_TEXT
           && (elemRight.getType() == ElementType::ELEMENT_TEXT
               || elemRight.getType() == ElementType::EFFET);
}

bool board::checkVertical(elem elemUp, elem elemDown) {
    return elemUp.getType() == ElementType::ELEMENT_TEXT
           && (elemDown.getType() == ElementType::ELEMENT_TEXT
               || elemDown.getType() == ElementType::EFFET);
}

void board::addRule(elem elemLeft, elem elemRight) {
    std::pair<elem, elem> rule {{elemLeft}, {elemRight}};
    rules.push_back(rule);
}

std::vector<std::pair<elem, elem>> board::getRules() const
{
    return rules;
}

std::vector<position> board::getPlayersPos()
{

    updateRules();
    std::vector<position> players;

    int you{};
    for (int i = 0; i < rules.size(); ++i) {
        if(rules.at(i).second.getValue() == Element::YOU) you = i;
    }

    switch (rules.at(you).first.getValue()) {
        case Element::TEXT_FLAG :
            for (int i = 0; i < plateau.size(); ++i) {
                for (int j = 0; j < plateau.at(i).size(); ++j) {
                    std::vector<elem> vctElem = plateau.at(i).at(j).getElements();
                    if(vctElem.at(vctElem.size()-1).getValue()== Element::FLAG) {
                        position pos{j, i};
                        players.push_back(pos);
                    }
                }
            }
            break;
        case Element::TEXT_METAL :
            for (int i = 0; i < plateau.size(); ++i) {
                for (int j = 0; j < plateau.at(i).size(); ++j) {
                    std::vector<elem> vctElem = plateau.at(i).at(j).getElements();
                    if(vctElem.at(vctElem.size()-1).getValue()== Element::METAL) {
                        position pos{j, i};
                        players.push_back(pos);
                    }
                }
            }
            break;
        case Element::TEXT_GOOP :
            for (int i = 0; i < plateau.size(); ++i) {
                for (int j = 0; j < plateau.at(i).size(); ++j) {
                    std::vector<elem> vctElem = plateau.at(i).at(j).getElements();
                    if(vctElem.at(vctElem.size()-1).getValue()== Element::GOOP) {
                        position pos{j, i};
                        players.push_back(pos);
                    }
                }
            }
            break;
        case Element::TEXT_BONE :
            for (int i = 0; i < plateau.size(); ++i) {
                for (int j = 0; j < plateau.at(i).size(); ++j) {
                    std::vector<elem> vctElem = plateau.at(i).at(j).getElements();
                    if(vctElem.at(vctElem.size()-1).getValue()== Element::BONE) {
                        position pos{j, i};
                        players.push_back(pos);
                    }
                }
            }
            break;
        case Element::TEXT_ROCK :
            for (int i = 0; i < plateau.size(); ++i) {
                for (int j = 0; j < plateau.at(i).size(); ++j) {
                    std::vector<elem> vctElem = plateau.at(i).at(j).getElements();
                    if(vctElem.at(vctElem.size()-1).getValue()== Element::ROCK) {
                        position pos{j, i};
                        players.push_back(pos);
                    }
                }
            }
            break;
        case Element::TEXT_BABA :
            for (int i = 0; i < plateau.size(); ++i) {
                for (int j = 0; j < plateau.at(i).size(); ++j) {
                    std::vector<elem> vctElem {plateau.at(i).at(j).getElements()
                    .at(plateau.at(i).at(j).getElements().size()-1)};

                    if(vctElem.at(vctElem.size()-1).getValue()== Element::BABA) {
                        position pos{j, i};
                        players.push_back(pos);
                    }
                }
            }
            break;
        case Element::TEXT_LAVA :
            for (int i = 0; i < plateau.size(); ++i) {
                for (int j = 0; j < plateau.at(i).size(); ++j) {
                    std::vector<elem> vctElem = plateau.at(i).at(j).getElements();
                    if(vctElem.at(vctElem.size()-1).getValue()== Element::LAVA) {
                        position pos{j, i};
                        players.push_back(pos);
                    }
                }
            }
            break;
        case Element::TEXT_WALL:
            for (int i = 0; i < plateau.size(); ++i) {
                for (int j = 0; j < plateau.at(i).size(); ++j) {
                    std::vector<elem> vctElem = plateau.at(i).at(j).getElements();
                    if(vctElem.at(vctElem.size()-1).getValue()== Element::WALL) {
                        position pos{j, i};
                        players.push_back(pos);
                    }
                }
            }
            break;
        case Element::TEXT_GRASS :
            for (int i = 0; i < plateau.size(); ++i) {
                for (int j = 0; j < plateau.at(i).size(); ++j) {
                    std::vector<elem> vctElem = plateau.at(i).at(j).getElements();
                    if(vctElem.at(vctElem.size()-1).getValue()== Element::GRASS) {
                        position pos{j, i};
                        players.push_back(pos);
                    }
                }
            }
            break;
    default :
        players.clear();
    }

    if(you == 0 && rules.at(you).second.getValue() != Element::YOU)
        players.clear();



    return players;
}

elem  board::getEffet(Element effet)
{

    int stop{};
    for (int i = 0; i < rules.size(); ++i) {
        if(rules.at(i).second.getValue() == effet) stop = i;
    }


    elem el {Element::EMPTY, ElementType::ELEMENT};

    switch (rules.at(stop).first.getValue()) {
        case Element::TEXT_GRASS :
            el = {Element::GRASS, ElementType::ELEMENT};
            break;
        case Element::TEXT_WALL :
            el = {Element::WALL, ElementType::ELEMENT};
            break;
        case Element::TEXT_LAVA :
            el = {Element::LAVA, ElementType::ELEMENT};
            break;
        case Element::TEXT_BABA :
            el = {Element::BABA, ElementType::ELEMENT};
            break;
        case Element::TEXT_ROCK :
            el = {Element::ROCK, ElementType::ELEMENT};
            break;
        case Element::TEXT_BONE :
            el = {Element::BONE, ElementType::ELEMENT};
            break;
        case Element::TEXT_GOOP :
            el = {Element::GOOP, ElementType::ELEMENT};
            break;
        case Element::TEXT_METAL :
            el = {Element::METAL, ElementType::ELEMENT};
            break;
        case Element::TEXT_FLAG :
            el = {Element::FLAG, ElementType::ELEMENT};
            break;
    default :
        el = {Element::NOTHING, ElementType::ELEMENT};
    }

    if(stop == 0 && rules.at(stop).second.getValue() != effet)
        el = {Element::NOTHING, ElementType::ELEMENT};

    return el;
}

std::string board::getLvl() const {
    return lvl;
}









