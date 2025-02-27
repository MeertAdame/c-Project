#ifndef BEGGIN_H
#define BEGGIN_H

#include <QWidget>
#include <QLabel>
#include <QResizeEvent>
#include <QKeyEvent>
#include <QVBoxLayout>


namespace Ui {
class beggin;
}


/**
 * @brief Classe représentant la fenêtre de démarrage du programme.
 */
class beggin : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de la classe beggin.
     *
     * @param parent Le widget parent de la fenêtre.
     */
    explicit beggin(QWidget *parent = nullptr);

    /**
     * @brief Destructeur de la classe beggin.
     */
    ~beggin();


private:
    /**
     * @brief Redimensionne la fenêtre et met à jour l'image de fond en conséquence.
     *
     * @param event L'événement de redimensionnement.
     */
    void resizeEvent(QResizeEvent *event) override;

    /**
     * @brief Définit l'image de fond de la fenêtre.
     *
     * @param imagePath Le chemin vers l'image à utiliser comme fond.
     */
    void setBackground(const QString& imagePath);


    /**
     * @brief Gère les événements de pression des touches du clavier.
     *
     * @param event L'événement de pression de touche.
     */
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::beggin *ui;  // Interface utilisateur de la fenêtre
};

#endif // BEGGIN_H
