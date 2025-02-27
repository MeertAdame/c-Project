#include "form.h"
#include "ui_form.h"
#include "gameUi.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("../images/baba.png"));

    connect(ui->continueButton, &QPushButton::clicked, this, &Form::continueClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &Form::exitClicked);
    addRadioButtons();
    this->setFixedSize(500,550);

}

void Form::addRadioButtons()
{
    for (int i = 0; i < listLevel.size(); ++i) {
        QRadioButton *radioButton = new QRadioButton(QString::fromStdString(listLevel.at(i)), this);
        QFont font("Arial", 10);
        radioButton->setFont(font);
        ui->verticalLayout->addWidget(radioButton);
    }
}

void Form::continueClicked()
{
    QList<QRadioButton*> allRadios = findChildren<QRadioButton*>();


    bool radioChecked = false;
    for (QRadioButton *radio : allRadios) {
        if (radio->isChecked()) {
            radioChecked = true;
            level = radio->text();
            break;
        }
    }

    if (!radioChecked) {
        QMessageBox::critical(this, tr("Erreur"), tr("Aucun niveau n'est sélectionnée !"));
    }else{
        std::string lvl = level.toStdString();
        std::cout << level.toStdString() << std::endl ;
        close();
        Game *g = new Game(lvl);
        g->show();
    }

}


void Form::exitClicked(){
    QApplication::quit();
}

Form::~Form()
{
    delete ui;
}
