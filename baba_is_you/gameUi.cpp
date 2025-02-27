#include "gameUi.h"
#include "form.h"
#include "qmenubar.h"
#include "save.h"
#include "win.h"
#include "lose.h"

Game::Game(std::string lvl, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameUi),
    level(lvl),
    myBoard(level),
    game(&myBoard),
    gridLayout(new QGridLayout(this))
{

    game.registerObserver(this);
    ui->setupUi(this);
    this->setWindowIcon(QIcon("../images/baba.png"));
    createMenu();
    displayPics();
    this->adjustSize();
    this->setFixedSize(650,700);

}


Game::~Game()
{
    delete ui;
}

void Game::displayPics()
{
    static const std::unordered_map<Element, QString> imagePathMap = {
        {Element::WALL, "../images/wall.png"},
        {Element::BABA, "../images/baba.png"},
        {Element::TEXT_BABA, "../images/Text_BABA.png"},
        {Element::FLAG, "../images/flag.png"},
        {Element::PUSH, "../images/Text_PUSH.png"},
        {Element::TEXT_GRASS, "../images/Text_GRASS.png"},
        {Element::KILL, "../images/Text_HOT.png"},
        {Element::TEXT_WALL, "../images/Text_WALL.png"},
        {Element::TEXT_GOOP, "../images/Text_Water.png"},
        {Element::GRASS, "../images/grass.png"},
        {Element::IS, "../images/Text_IS.png"},
        {Element::SINK, "../images/Text_SINK.png"},
        {Element::STOP, "../images/Text_STOP.png"},
        {Element::WIN, "../images/Text_WIN.png"},
        {Element::YOU, "../images/Text_YOU.png"},
        {Element::TEXT_LAVA, "../images/Text_LAVA.png"},
        {Element::TEXT_ROCK, "../images/Text_ROCK.png"},
        {Element::TEXT_FLAG, "../images/Text_FLAG.png"},
        {Element::ROCK, "../images/rock.png"},
        {Element::GOOP, "../images/water.png"},
        {Element::LAVA, "../images/lava.png"},
        {Element::EMPTY, "../images/empty.png"}
    };

    const int newWidth = 30;

    QLayoutItem* item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    gridLayout->setSpacing(3);

    for (int i = 0; i < game.getMyBoard()->getHeight(); ++i) {
        for (int j = 0; j < game.getMyBoard()->getLenght(); ++j) {
            const Element icon = game.getMyBoard()->getPlateau().at(i).at(j).getElements().back().getValue();

            const auto it = imagePathMap.find(icon);
            if (it == imagePathMap.end()) {
                continue;
            }

            const QString& imagePath = it->second;

            QPixmap pixmap(imagePath);

            int newHeight = pixmap.height() * newWidth / pixmap.width();
            QPixmap scaledPixmap = pixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

            std::unique_ptr<QLabel> imageLabel = std::make_unique<QLabel>();
            imageLabel->setPixmap(scaledPixmap);
            gridLayout->addWidget(imageLabel.get(), i, j);
            imageLabel.release();
        }
    }
}

void Game::keyPressEvent(QKeyEvent *event)
{
    setFocusPolicy(Qt::StrongFocus);

    Direction dir {};

    if (event->key() == Qt::Key_Left) {
        dir = Direction::LEFT;

    } else if (event->key() == Qt::Key_Right) {
        dir = Direction::RIGHT;

    } else if (event->key() == Qt::Key_Up) {
        dir = Direction::UP;

    } else if (event->key() == Qt::Key_Down) {
        dir = Direction::DOWN;

    } else if (event->key() == Qt::Key_S && (event->modifiers() == Qt::ControlModifier || event->modifiers() == Qt::MetaModifier)){
        Game::saveGame();
    } else if (event->key() == Qt::Key_R && (event->modifiers() == Qt::ControlModifier || event->modifiers() == Qt::MetaModifier)){
        Game::replay();
    } else if (event->key() == Qt::Key_X && (event->modifiers() == Qt::ControlModifier || event->modifiers() == Qt::MetaModifier)){
        Game::exit();
    } else if (event->key() == Qt::Key_F && (event->modifiers() == Qt::ControlModifier || event->modifiers() == Qt::MetaModifier)){
        chooseLevel();
    } else {
        dir = Direction::STOP;
    }

    game.move(dir);

}
void Game::createMenu()
{
    QMenuBar *menuBar = new QMenuBar();
    QMenu *menuFile = new QMenu("File");
    menuBar->addMenu(menuFile);

    struct MenuItem {
        QIcon icon;
        QString text;
        std::function<void()> action;
    };

    std::vector<MenuItem> menuItems = {
        {QIcon("../icon/save.png"), "Save", [this]() { saveGame(); }},
        {QIcon("../icon/replay.png"), "Replay", [this]() { replay(); }},
        {QIcon("../icon/exit.png"), "Exit", [this]() { exit(); }},
        {QIcon("../icon/level.png"), "Choose level", [this]() { chooseLevel(); }},
        {QIcon("../icon/giveUp.png"), "Give Up", [this]() { chooseLevel(); }}
    };

    for (const auto& menuItem : menuItems) {
        std::unique_ptr<QAction> action = std::make_unique<QAction>(menuItem.icon, menuItem.text, this);
        menuFile->addAction(action.get());
        gridLayout->setMenuBar(menuBar);
        connect(action.get(), &QAction::triggered, menuItem.action);
        action.release();
    }
}

void Game::saveGame()
{
    close();
    save *s = new save(game);
    s->show();
}

void Game::exit()
{
    QApplication::quit();
}

void Game::replay()
{
    close();
    Game *g = new Game(level);
    g->show();
}

void Game::chooseLevel()
{
    close();
    Form *f = new Form();
    f->show();
}



void Game::update()
{
    displayPics();
    if(game.getState()== GameState::WIN){
        win *w = new win();
        w->show();
        close();
    }

    if(game.getState()== GameState::LOSE){
        lose *l = new lose(level);
        l->show();
        close();
    }
}


