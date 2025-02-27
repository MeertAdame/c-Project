//
// Created by Adame Meert on 14/04/2023.
//

/**
 * @file obs.h
 * @brief Design pattern observateur / observer
*/

#ifndef BABA_IS_YOU_OBS_H
#define BABA_IS_YOU_OBS_H

/**
 * @brief The Observer class
 */
class Observer {

public:

    /**
     * @brief destructeur
     */
    virtual ~Observer() {}

    /**
     * @brief Met a jour en fonction de se que l'obsevable fais
     */
    virtual void update() = 0;
};

/**
 * @brief est observé par l'observer
 */
class Observateur {

public:

    /**
     * @brief destructeur
     */
    virtual ~Observateur() {}

    /**
     * @brief rajoute un observer a la liste d'observer qui peuvent mettre a jour le contenu
     * de l'objet courant
     * @param observer l'observer à rajouter dans la liste
     */
    virtual void registerObserver(Observer *observer) = 0;

    /**
     * @brief Permet de retirer le dernier observer de la liste
     */
    virtual void unregisterObserver() = 0;

    /**
     * @brief Préviens l'observer que un changement à été fait
     */
    virtual void notifyObservers() = 0;
};

#endif //BABA_IS_YOU_OBS_H

