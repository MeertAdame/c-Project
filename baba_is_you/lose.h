#ifndef LOSE_H
#define LOSE_H

#include <QWidget>
#include <string>

namespace Ui {
class lose;
}

/**
 * @brief Classe représentant la fenêtre de défaite.
 *
 * Cette classe hérite de QWidget et affiche la fenêtre de défaite du jeu.
 */
class lose : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe lose.
     *
     * @param lvl Le niveau actuel.
     * @param parent Le widget parent de la fenêtre.
     */
    explicit lose(std::string lvl, QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe lose.
     */
    ~lose();

private slots:
    /**
     * @brief Gère le clic sur le bouton "Exit".
     */
    void exitButton_clicked();

    /**
     * @brief Gère le clic sur le bouton "Replay".
     */
    void replayButton_clicked();

private:
    Ui::lose *ui;  // Interface utilisateur de la fenêtre de défaite
    std::string lvl;  // Niveau actuel
};

#endif // LOSE_H
