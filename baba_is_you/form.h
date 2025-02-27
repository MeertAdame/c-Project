#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "controller/file.h"
#include <QGroupBox>
#include <QMessageBox>
#include <QApplication>
#include <QRadioButton>
#include <QButtonGroup>

namespace Ui {
class Form;
}

/**
 * @brief Classe représentant un formulaire.
 *
 * Cette classe hérite de QWidget et permet de créer un formulaire avec des fonctionnalités spécifiques.
 */
class Form : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe Form.
     *
     * @param parent Le widget parent du formulaire.
     */
    explicit Form(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe Form.
     */
    ~Form();

private slots:
    /**
     * @brief Ajoute des boutons radio à l'interface utilisateur.
     */
    void addRadioButtons();

    /**
     * @brief Gère le clic sur le bouton "Exit".
     */
    void exitClicked();

    /**
     * @brief Gère le clic sur le bouton "Continue".
     */
    void continueClicked();

private:
    Ui::Form *ui;  // Interface utilisateur du formulaire
    QString level;  // Niveau sélectionné
    std::vector<std::string> listLevel = listLvl();  // Liste des niveaux disponibles
};

#endif // FORM_H
