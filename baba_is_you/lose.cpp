#include "lose.h"
#include "ui_lose.h"
#include "gameUi.h"

lose::lose(std::string lvl, QWidget *parent) :
    QWidget(parent), lvl(lvl),
    ui(new Ui::lose)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("../images/baba.png"));
    connect(ui->exitButton, &QPushButton::clicked, this, &lose::exitButton_clicked);
    connect(ui->replayButton, &QPushButton::clicked, this, &lose::replayButton_clicked);
    this->setFixedSize(250,300);

}

lose::~lose()
{
    delete ui;
}

void lose::exitButton_clicked()
{
    QApplication::quit();
}


void lose::replayButton_clicked()
{
    close();
    Game *g = new Game(lvl);
    g->show();
}

