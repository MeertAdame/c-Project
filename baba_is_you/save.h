#ifndef SAVE_H
#define SAVE_H

#include <QWidget>
#include "model/babaIsyou.h"
#include <QLineEdit>
#include <QMessageBox>

namespace Ui {
class save;
}

/**
 * @brief Classe représentant la fenêtre de sauvegarde.
 *
 * Cette classe hérite de QWidget et affiche la fenêtre de sauvegarde du jeu.
 */
class save : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe save.
     *
     * @param game L'instance du jeu Baba Is You.
     * @param parent Le widget parent de la fenêtre.
     */
    explicit save(babaIsyou game, QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe save.
     */
    ~save();

private slots:
    /**
     * @brief Gère le clic sur le bouton "Continue".
     */
    void continueButton_clicked();

private:
    Ui::save *ui;  // Interface utilisateur de la fenêtre de sauvegarde
    babaIsyou game;  // Instance du jeu Baba Is You
};

#endif // SAVE_H
