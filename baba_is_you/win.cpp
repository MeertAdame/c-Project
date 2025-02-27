#include "win.h"
#include "ui_win.h"
#include "form.h"

win::win(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::win)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("../images/baba.png"));

    connect(ui->exitButton, &QPushButton::clicked, this, &win::exitButton_clicked);
    connect(ui->continueButton, &QPushButton::clicked, this, &win::continueButton_clicked);
    this->setFixedSize(250,300);

}

win::~win()
{
    delete ui;
}

void win::exitButton_clicked()
{
    QApplication::quit();
}


void win::continueButton_clicked()
{
    close();
    Form *f = new Form();
    f->show();
}

