#include "beggin.h"
#include "ui_beggin.h"
#include "form.h"

beggin::beggin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::beggin)
{
    ui->setupUi(this);
    setBackground("../images/fond_debut.jpg");
    this->setWindowIcon(QIcon("../images/baba.png"));

}

beggin::~beggin()
{
    delete ui;
}


void beggin::setBackground(const QString& imagePath)
{
    QPixmap bkgnd(imagePath);
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    setPalette(palette);
}


void beggin::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    setBackground("../images/fond_debut.jpg");
}

void beggin::keyPressEvent(QKeyEvent *event)
{
    setFocusPolicy(Qt::StrongFocus);
    if (event->key() == Qt::Key_Space) {
        Form *f = new Form();
        f->show();
        close();
    }
}

