#ifndef BOARD_H
#define BOARD_H

#include "model/board.h"
#include "model/babaIsyou.h"
#include "model/board.h"
#include "model/babaIsyou.h"
#include "util/obs.h"
#include "ui_gameUi.h"
#include <QWidget>
#include <QKeyEvent>
#include <QGridLayout>
#include <QPixmap>
#include <QMenu>
#include <QMenuBar>
#include <QLabel>
#include <QTimer>
#include <QPushButton>



namespace Ui {
class gameUi;
}

/**
 * @brief Classe représentant le jeu principal.
 *
 * Cette classe hérite à la fois de QWidget et de Observer. Elle gère la logique et l'affichage du jeu Baba Is You.
 */
class Game : public QWidget, public Observer
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe Game.
     *
     * @param lvl Le niveau à charger.
     * @param parent Le widget parent du jeu.
     */
    explicit Game(std::string lvl, QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe Game.
     */
    ~Game();

    /**
     * @brief Récupère le niveau actuel.
     *
     * @return Le niveau actuel sous forme de chaîne de caractères.
     */
    std::string getLvl();

    /**
     * @brief Méthode de mise à jour appelée lorsqu'un sujet Observable notifie ses observateurs.
     */
    virtual void update() override;

private slots:
    /**
     * @brief Affiche les éléments graphiques du jeu.
     */
    void displayPics();


    /**
     * @brief Gère les événements de pression des touches du clavier.
     *
     * @param event L'événement de pression de touche.
     */
    void keyPressEvent(QKeyEvent *event) override;

    /**
     * @brief Crée le menu du jeu.
     */
    void createMenu();

    /**
     * @brief Sauvegarde la partie en cours.
     */
    void saveGame();

    /**
     * @brief Relance la partie depuis le début.
     */
    void replay();

    /**
     * @brief Quitte le jeu.
     */
    void exit();

    /**
     * @brief Permet de choisir un niveau.
     */
    void chooseLevel();


private:
    QGridLayout *gridLayout;  // Gestionnaire de disposition des éléments graphiques
    std::string level;  // Niveau actuel
    board myBoard;  // Plateau de jeu
    babaIsyou game;  // Instance du jeu Baba Is You
    Ui::gameUi *ui;  // Interface utilisateur du jeu
};

#endif // BOARD_H
