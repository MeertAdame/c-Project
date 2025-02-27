//
// Created by adamj on 06-03-23.
//

/**
 * @file element.h
 * @brief composants du jeu
*/

#ifndef BABA_IS_YOU_ELEMENT_H
#define BABA_IS_YOU_ELEMENT_H
#include <string>

/**
 * @brief Représente les elements du jeu
 */
enum Element {

    GRASS, WALL, LAVA, BABA, ROCK, BONE, GOOP, METAL,
    TEXT_GRASS, TEXT_WALL, TEXT_LAVA, TEXT_BABA, TEXT_ROCK, TEXT_BONE,TEXT_GOOP, TEXT_METAL, TEXT_FLAG
    ,WIN, KILL, STOP, YOU, PUSH, BEST, IS, SINK, EMPTY, FLAG, NOTHING

};

/**
 * @brief convertis un elem en string
 * @param elem l'elem a convertir
 * @return le mot correspondant à l'elem
 */
inline std::string toStringElement(Element elem)
{
    std::string str;

    switch (elem) {
        case Element::FLAG :
            str = "  flag  ";
            break;
        case Element::TEXT_FLAG :
            str = "txtFlag ";
            break;
        case Element::GRASS :
            str = " grass  ";
            break;
        case Element::TEXT_GRASS :
            str = "txtGrass";
            break;
        case Element::WALL :
            str = "  wall  ";
            break;
        case Element::TEXT_WALL :
            str = "txtWall ";
            break;
        case Element::LAVA :
            str = "  lava  ";
            break;
        case Element::TEXT_LAVA :
            str = "txtLava "; // <--- ici
            break;
        case Element::BABA :
            str = "  baba  ";
            break;
        case Element::TEXT_BABA :
            str = "txtBaba ";
            break;
        case Element::ROCK :
            str = "  rock  ";
            break;
        case Element::TEXT_ROCK :
            str = "txtRock ";
            break;
            case Element::BONE:
            str = "  bone  ";
            break;
            case Element::TEXT_BONE :
            str = "txtBone ";
            break;
            case Element::GOOP :
            str = "  goop  ";
            break;
            case Element::TEXT_GOOP :
            str = "txtGoop ";
            break;
            case Element::METAL :
            str = " metal  ";
            break;
            case Element::TEXT_METAL :
            str = "txtMetal";
            break;
            case Element::WIN :
            str = "  win   ";
            break;
            case Element::KILL :
            str = "  kill  ";
            break;
            case Element::SINK :
            str = "  sink  ";
            break;
            case Element::STOP :
            str = "  stop  ";
            break;
            case Element::YOU :
            str = "  you   ";
            break;
            case Element::PUSH :
            str = "  push  ";
            break;
            case Element::BEST :
            str = "  best  ";
            break;
            case Element::IS :
            str = "   is   ";
            break;
            case Element::EMPTY :
            str = "        ";
            break;
        case Element::NOTHING :
            str = "        ";
            break;
    }

    return str;
}

inline std::string toStringFile(Element elem)
{
    std::string str;

    switch (elem) {
        case Element::FLAG :
            str = "flag";
            break;
        case Element::TEXT_FLAG :
            str = "text_flag";
            break;
        case Element::GRASS :
            str = "grass";
            break;
        case Element::TEXT_GRASS :
            str = "text_grass";
            break;
        case Element::WALL :
            str = "wall";
            break;
        case Element::TEXT_WALL :
            str = "text_wall";
            break;
        case Element::LAVA :
            str = "lava";
            break;
        case Element::TEXT_LAVA :
            str = "text_lava"; // <--- ici
            break;
        case Element::BABA :
            str = "baba";
            break;
        case Element::TEXT_BABA :
            str = "text_baba";
            break;
        case Element::ROCK :
            str = "rock";
            break;
        case Element::TEXT_ROCK :
            str = "text_rock";
            break;
        case Element::BONE:
            str = "bone";
            break;
        case Element::TEXT_BONE :
            str = "text_bone";
            break;
        case Element::GOOP :
            str = "goop";
            break;
        case Element::TEXT_GOOP :
            str = "text_goop";
            break;
        case Element::METAL :
            str = "metal";
            break;
        case Element::TEXT_METAL :
            str = "text_metal";
            break;
        case Element::WIN :
            str = "win";
            break;
        case Element::KILL :
            str = "kill";
            break;
        case Element::SINK :
            str = "sink";
            break;
        case Element::STOP :
            str = "stop";
            break;
        case Element::YOU :
            str = "you";
            break;
        case Element::PUSH :
            str = "push";
            break;
        case Element::BEST :
            str = "best";
            break;
        case Element::IS :
            str = "is";
            break;
        case Element::EMPTY :
            str = "";
            break;
        case Element::NOTHING :
            str = "        ";
            break;
    }

    return str;
}

#endif //BABA_IS_YOU_ELEMENT_H
