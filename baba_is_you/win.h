#ifndef WIN_H
#define WIN_H

#include <QWidget>

namespace Ui {
class win;
}

/**
 * @brief Classe représentant la fenêtre de victoire.
 *
 * Cette classe hérite de QWidget et affiche la fenêtre de victoire du jeu.
 */
class win : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe win.
     *
     * @param parent Le widget parent de la fenêtre.
     */
    explicit win(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe win.
     */
    ~win();

private slots:
    /**
     * @brief Gère le clic sur le bouton "Exit".
     */
    void exitButton_clicked();

    /**
     * @brief Gère le clic sur le bouton "Continue".
     */
    void continueButton_clicked();

private:
    Ui::win *ui;  // Interface utilisateur de la fenêtre de victoire
};

#endif // WIN_H
