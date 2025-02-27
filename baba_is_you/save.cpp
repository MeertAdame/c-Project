#include "save.h"
#include "ui_save.h"
#include "form.h"



save::save(babaIsyou game, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::save), game(game)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("../images/baba.png"));

    connect(ui->continueButton, &QPushButton::clicked, this, &save::continueButton_clicked);
    this->setFixedSize(250,300);

}

save::~save()
{
    delete ui;
}

void save::continueButton_clicked()
{

    QLineEdit *lineEdit = this->findChild<QLineEdit*>("lineEdit");
    QString text = lineEdit->text().trimmed(); //trimmed pour supprimer les espace au debut et a la fin

    if(text.isEmpty()){
        QMessageBox::critical(this, tr("Erreur"), tr("Vous n'avez rien ecris !"));

    }else{

        std::string fileName = text.toStdString();
        std::transform(fileName.begin(), fileName.end(), fileName.begin(), ::tolower);
        std::ofstream file(fileName + ".txt");

        board *myBoard = game.getMyBoard(); // Référence constante pour éviter les appels répétitifs à game.getMyBoard()

        file << myBoard->getLenght() << " " << myBoard->getHeight() << std::endl;

        for(int i = 0; i < myBoard->getHeight(); i++)
        {
            for(int j = 0; j < myBoard->getHeight(); j++)
            {
                position pos (j, i);

                if(myBoard->getElem(pos).getValue() != Element::EMPTY ){
                    file << toStringFile(myBoard->getElem(pos).getValue()) ;
                    file << " "<<j << " " << i << std::endl;
                }
            }
        }
        close();
        Form *f = new Form();
        f->show();
    }
}

