//
// Created by Adame Meert on 09/03/2023.
//

/**
 * @file file.h
 * @brief Cette class s'occupe de récuprer les donnnées qui se trouve dans le fichier lu
 */

#ifndef BABA_IS_YOU_FILE_H
#define BABA_IS_YOU_FILE_H
#include <iostream>
#include <fstream>
#include "../model/square.h"
#include <filesystem>
#include <sstream>


/**
 * @brief Cette class permet de lire un fichier et de récupérer les données de celui-ci
 */
class file {

private:
    int length;
    int width;
    std::vector<std::pair<std::string, position>> vec;

public:

    /**
     * @brief Constructeur de la classe "file"
     * @param lvl : niveau du jeu
     */
    file(std::string level);

    /**
     * @brief Obtenez la longueur du niveau
     * @return la longueur du niveau
     */
    int getLength() const;

    /**
     * @brief Obtenez la largeur du niveau
     * @return la largeur du niveau
     */
    int getWidth() const;

    /**
     * @brief Initialise le vecteur de square
     * @return un vecteur de vecteurs de square initialisés
     */
    std::vector<std::vector<square>> init();
};

inline std::vector<std::string> listLvl()
{
    std::vector<std::string> filenames;
   //std::string path = "../baba_is_you/ressource";
    std::string path = "../ressource";



    for(const auto & entry : std::filesystem::directory_iterator(path)){
        if(entry.is_regular_file()){
            filenames.push_back(entry.path().filename().string());
        }
    }

    return filenames;
}

inline void showLvl(){
    for (int i = 0; i < listLvl().size(); ++i) {
        std::cout << listLvl().at(i) << std::endl;
    }
}






#endif //BABA_IS_YOU_FILE_H
