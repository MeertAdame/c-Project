//
// Created by Adame Meert on 22/03/2023.
//

/**
 * @file elem.h
 * @brief représente un composant du jeu
*/
#include "element.h"
#include "elementType.h"
#include <iostream>
#include <map>


#ifndef BABA_IS_YOU_ELEM_H
#define BABA_IS_YOU_ELEM_H

/**
 * @brief Représente l'element d'un square
 * Celui-ci est composé obligatoirement d'une valeur et d'un type
 */
class elem {

private:
    Element value;
    ElementType type;

public:

    /**
     * @brief constructeur de l'elem
     * @param e la valeur de l'element
     * @param t le type de l'element
     */
    elem(Element e, ElementType t);

    /**
     * constructeur par defaut de l'elem
     * la valeur est mise a empty et le type a Element
     */
    elem();

    /**
     * @brief accesseur de la valeur de l'elem
     * @return la valeur de l'elem
     */
    Element getValue()const;

    /**
     * @brief accesseur du type de l'elem
     * @return le type de l'elem
     */
    ElementType getType()const;

    /**
     * @brief Surcharge de l'opérateur d'affichage "<<"
     * @param os l'affichage
     * @param el la référence de l'objet a afficher
     * @return retourne se l'element sous forme d'affichage dans la sortie sandard
     */
    friend std::ostream& operator<< (std::ostream& os, const elem& el);

    /**
     * @brief Surcharge de l'opérateur de comparaison "==" pour comparer deux éléments
     * @param other l'element a comparer
     * @return vrai si ils sont pareils
     */
    bool operator==(const elem& other) const;

    /**
     * @brief Surcharge de l'opérateur de comparaison "!=" pour comparer deux éléments
     * @param other l'element a comparer
     * @return vrai si ils sont différents
     */
    bool operator!=(const elem& other) const;


};

/**
 * @brief convertis le string donné en elem
 * @param str mot lue par le fichier
 * @return l'elem associé au mot 'str'
 */
inline elem convertionElem(std::string str)
{
    static std::map<std::string, elem> elemMap{

        {"grass", elem(Element::GRASS, ElementType::ELEMENT)},
        {"wall", elem(Element::WALL, ElementType::ELEMENT)},
        {"lava", elem(Element::LAVA, ElementType::ELEMENT)},
        {"baba", elem(Element::BABA, ElementType::ELEMENT)},
        {"rock", elem(Element::ROCK, ElementType::ELEMENT)},
        {"bone", elem(Element::BONE, ElementType::ELEMENT)},
        {"goop", elem(Element::GOOP, ElementType::ELEMENT)},
        {"metal", elem(Element::METAL, ElementType::ELEMENT)},
        {"text_grass", elem(Element::TEXT_GRASS, ElementType::ELEMENT_TEXT)},
        {"text_wall", elem(Element::TEXT_WALL, ElementType::ELEMENT_TEXT)},
        {"text_lava", elem(Element::TEXT_LAVA, ElementType::ELEMENT_TEXT)},
        {"text_baba", elem(Element::TEXT_BABA, ElementType::ELEMENT_TEXT)},
        {"text_rock", elem(Element::TEXT_ROCK, ElementType::ELEMENT_TEXT)},
        {"text_bone", elem(Element::TEXT_BONE, ElementType::ELEMENT_TEXT)},
        {"text_goop", elem(Element::TEXT_GOOP, ElementType::ELEMENT_TEXT)},
        {"text_metal", elem(Element::TEXT_METAL, ElementType::ELEMENT_TEXT)},
        {"win", elem(Element::WIN, ElementType::EFFET)},
        {"kill", elem(Element::KILL, ElementType::EFFET)},
        {"stop", elem(Element::STOP, ElementType::EFFET)},
        {"you", elem(Element::YOU, ElementType::EFFET)},
        {"push", elem(Element::PUSH, ElementType::EFFET)},
        {"best", elem(Element::BEST, ElementType::EFFET)},
        {"sink", elem(Element::SINK, ElementType::EFFET)},
        {"empty", elem(Element::EMPTY, ElementType::EFFET)},
        {"is", elem(Element::IS, ElementType::CONNECTEUR)},
        {"text_flag", elem(Element::TEXT_FLAG, ElementType::ELEMENT_TEXT)},
        {"flag", elem(Element::FLAG, ElementType::ELEMENT)}
    };

    auto i = elemMap.find(str);

    if(i != elemMap.end()){

        return i -> second;
    } else {
        return elem(Element::EMPTY, ElementType::ELEMENT);
    }
}

#endif //BABA_IS_YOU_ELEM_H
