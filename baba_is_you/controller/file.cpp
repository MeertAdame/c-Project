//
// Created by Adame Meert on 09/03/2023.
//

#include "file.h"


file::file(std::string level){


    //std::ifstream fichier("../baba_is_you/ressource/"+level);
    std::ifstream fichier("../ressource/"+level);
    std::string str ;
    int dir;
    int x,y ;

    if (fichier.is_open()) {
        std::string ligne;

            std::getline(fichier, ligne);
            std::istringstream lgn(ligne);
            lgn >> length >> width ;

        while (std::getline(fichier, ligne)) {
            std::istringstream lgn(ligne);
            lgn >> str >> x >> y >> dir;
            position pos {x, y};
            std::pair<std::string, position> paire {str, pos};
            vec.push_back(paire);
        }
        fichier.close();
    } else {
        std::cout << "Impossible d'ouvrir le fichier" << std::endl;
        exit(1);
    }
}

int file::getLength() const
{
    return length;
}

int file::getWidth() const
{
    return width;
}

std::vector<std::vector<square>> file::init()
{
    std::vector<std::vector<square>>  deuxDim(width, std::vector<square>(length));
    for (int i = 0; i < deuxDim.size(); ++i) {
        for (int j = 0; j < deuxDim.at(i).size(); ++j) {

            position pos {j, i};
            std::vector<elem> el {{Element::EMPTY, ElementType::ELEMENT}};
            square sqEmpty {el, pos};
            deuxDim.at(i).at(j) = sqEmpty;
        }
    }

    for (int i = 0; i < vec.size(); ++i) {

        std::vector<elem> elems { elem(Element::EMPTY, ElementType::ELEMENT), convertionElem(vec.at(i).first)};
        position pos {vec.at(i).second.getX(),vec.at(i).second.getY()};
        square sq {elems, pos};
        deuxDim.at(vec.at(i).second.getY()).at(vec.at(i).second.getX()) = sq;
    }

    return deuxDim ;
}
