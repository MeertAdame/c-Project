
#include "model/elem.h"
/*
#include "model/board.h"
#include "model/babaIsyou.h"
#include "model/board.h"
#include "model/babaIsyou.h"
#include "View/gameView.h"
#include "controller/gameController.h"
*/
#include <QApplication>
#include <QPushButton>
#include "beggin.h"
#include <iostream>
#include <string>


using namespace std;

//MAIN GUI
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    beggin b;
    b.show();
    return a.exec();
}

/* MAIN CONSOLE
int main()
{

showLvl();
    string nvx = askLevel();
    while (!lvlOk(nvx)){
        cout << "ERROR --> INVALID LEVEL\"" << endl;
        cout << endl;
        nvx = askLevel();
    }
    cout << endl;
    board myBoard (nvx);
    babaIsyou baba(&myBoard);
    gameView view(& myBoard);
    gameController controller(&baba , &view);
    view.displayRules();
    baba.registerObserver(&view);
    controller.startGame();

    return 0;
}
*/



