#ifndef DIRECTION_H
#define DIRECTION_H

/**
 * @file direction.h
 * @brief deplacement possibles
*/
#include <map>


/**
 * @brief Représente les Direction vers lesquelles baba peut se déplacer
 */
enum class Direction
{
    UP , DOWN , RIGHT, LEFT, STOP
};

/*
 * peut-être utile a l'avenir
 *
inline Direction convertionDir(int dir)
{
    static std::map<int, Direction> direction {
        {0, Direction::RIGHT},
        {1, Direction::UP},
        {2, Direction::LEFT},
        {3, Direction::DOWN},
    };

    auto i = direction.find(dir);

    return i -> second;
}
*/
#endif // DIRECTION_H
