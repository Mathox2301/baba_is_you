#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include "../controller/Controller.h"
#include <QLabel>
#include <QTableWidget>
#include <QFrame>
#include <filesystem>
#include <QPixmap>
#include <QImage>
#include <QString>
#include <QFile>
#include <QMovie>
#include <QHeaderView>
#include <QDebug>
#include <QKeyEvent>

MainWindow::MainWindow(Game& game, Controller& c, QWidget *parent)
    : QMainWindow(parent),
      game(game),
      c(c),
      ui(new Ui::MainWindow)
{

    //colorisation
    ui->setupUi(this);

    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, Qt::black);
    this->setPalette(palette);
    //set up the table
    this->table = new QTableWidget(game.getBoardSize(),game.getBoardSize(),this);
    table->setSelectionMode(QAbstractItemView::NoSelection);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setFocusPolicy(Qt::NoFocus);
    table->horizontalHeader()->setVisible(false);
    table->verticalHeader()->setVisible(false);
    int columnWidth = 25;
    int columnCount = game.getBoardSize();
    palette.setColor(QPalette::Base, Qt::black);
    table->setPalette(palette);
    for (int column = 0; column < columnCount; ++column) {
        table->setColumnWidth(column, columnWidth);

    }

    QMenuBar *menuBar = new QMenuBar(this);
    setMenuBar(menuBar);

    QMenu *fileMenu = menuBar->addMenu(tr("File"));
    QMenu *loadMenu = menuBar->addMenu(tr("Load"));
    QAction *saveAction =  new QAction(tr("Save"),this);
    menuBar->addAction(saveAction);

      // Création d'une action "Quitter" dans le menu "Fichier"
    QAction *quitAction = new QAction(tr("Quitter"), this);
    fileMenu->addAction(quitAction);
    QAction *loadSaveAction = new QAction(tr("Load saved game"),this);
    QAction *loadLvl0Action = new QAction(tr("Load level 0"),this);
    QAction *loadLvl1Action = new QAction(tr("Load level 1"),this);
    QAction *loadLvl2Action = new QAction(tr("Load level 2"),this);
    QAction *loadLvl3Action = new QAction(tr("Load level 3"),this);
    QAction *loadLvl4Action = new QAction(tr("Load level 4"),this);
    loadMenu->addAction(loadSaveAction);
    loadMenu->addAction(loadLvl0Action);
    loadMenu->addAction(loadLvl1Action);
    loadMenu->addAction(loadLvl2Action);
    loadMenu->addAction(loadLvl3Action);
    loadMenu->addAction(loadLvl4Action);
    this->setupView();


    connect(quitAction, &QAction::triggered, this, &MainWindow::close);
    connect(loadLvl0Action, &QAction::triggered, this, std::bind(&MainWindow::load, this, "0"));
    connect(loadLvl1Action, &QAction::triggered, this, std::bind(&MainWindow::load, this, "1"));
    connect(loadLvl2Action, &QAction::triggered, this, std::bind(&MainWindow::load, this, "2"));
    connect(loadLvl3Action, &QAction::triggered, this, std::bind(&MainWindow::load, this, "3"));
    connect(loadLvl4Action, &QAction::triggered, this, std::bind(&MainWindow::load, this, "4"));
    connect(loadSaveAction, &QAction::triggered, this, std::bind(&MainWindow::load, this, "save"));
    connect(saveAction, &QAction::triggered, this, &MainWindow::save);

    //Moves
    connect(ui->btn_up, &QPushButton::clicked, this, &MainWindow::moveU);
    connect(ui->btn_right, &QPushButton::clicked, this, &MainWindow::moveR);
    connect(ui->btn_down, &QPushButton::clicked, this, &MainWindow::moveD);
    connect(ui->btn_left, &QPushButton::clicked, this, &MainWindow::moveL);
}

void MainWindow::move(std::string dir){
    Board old = this->game.getBoard();
    this->c.moveGUI(dir);
    this->displayLevel(old);
    if(this->c.isLevelWin()){
            this->ui->labelMessages->setText("You have win . Congratulations !!!");
            this->toggleButtons();
        }else if(this->c.isLevelLost()){
            this->ui->labelMessages->setText("You are dead. Load to continue");
            this->toggleButtons();
        }
}

void MainWindow::toggleButtons(){
    bool enabled = this->ui->btn_down->isEnabled();
    this->ui->btn_down->setEnabled(!enabled);
    this->ui->btn_up->setEnabled(!enabled);
    this->ui->btn_left->setEnabled(!enabled);
    this->ui->btn_right->setEnabled(!enabled);
}


void MainWindow::moveL(){
    this->move("left");
}
void MainWindow::moveR(){
    this->move("right");
}
void MainWindow::moveU(){
    this->move("up");
}
void MainWindow::moveD(){
    this->move("down");
}

void MainWindow::save(){
    game.save();
}
void MainWindow::load(string lvl){
    Board old = this->game.getBoard();
    game.loadLevel(lvl);
    this->displayLevel(old);
    this->ui->labelMessages->setText("");
    if(!this->ui->btn_up->isEnabled())
        this->toggleButtons();
}

void MainWindow::setupView(){

    std::string source_path = __FILE__;
    std::filesystem::path source_dir = std::filesystem::path(source_path).parent_path();
    std::filesystem::path file_path;
    for(int i {0}; i < this->game.getBoardSize(); ++i){
        for(int j {0}; j < this->game.getBoardSize(); ++j){
            Position pos = Position {i,j};
            if(game.getBoard().isBaba(pos)){
                file_path = source_dir /".."/"images"/"Baba.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);


            }else if(game.getBoard().isLava(pos)){
                file_path = source_dir /".."/"images"/"Lava.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isRock(pos)){
                file_path = source_dir /".."/"images"/"Rock.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isWater(pos)){
                file_path = source_dir /".."/"images"/"Water.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isWall(pos)){
                file_path = source_dir /".."/"images"/"Wall.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isFlag(pos)){
                file_path = source_dir /".."/"images"/"Flag.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isLavaText(pos)){
                file_path = source_dir /".."/"images"/"Text_LAVA.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isFlagText(pos)){
                file_path = source_dir /".."/"images"/"Text_FLAG.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }
            else if(game.getBoard().isWallText(pos)){
                file_path = source_dir /".."/"images"/"Text_WALL.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }
            else if(game.getBoard().isWaterText(pos)){
                file_path = source_dir /".."/"images"/"Text_WATER.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isBabaText(pos)){
                file_path = source_dir /".."/"images"/"Text_BABA.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isGrassText(pos)){
                file_path = source_dir /".."/"images"/"Text_GRASS.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isMetalText(pos)){
                file_path = source_dir /".."/"images"/"Text_METAL.png";
                QPixmap pic = loadPixmapFromPath(file_path);
                QLabel* label = new QLabel();
                label->setPixmap(pic);
                label->setAlignment(Qt::AlignCenter);
                 table->setCellWidget(j,i,label);
                    }
            else if(game.getBoard().isRockText(pos)){
                file_path = source_dir /".."/"images"/"Text_ROCK.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isPush(pos)){
                file_path = source_dir /".."/"images"/"Text_PUSH.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isStop(pos)){
                file_path = source_dir /".."/"images"/"Text_STOP.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isSink(pos)){
                file_path = source_dir /".."/"images"/"Text_SINK.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isKill(pos)){
                file_path = source_dir /".."/"images"/"Text_KILL.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isYou(pos)){
                file_path = source_dir /".."/"images"/"Text_YOU.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isWin(pos)){
                file_path = source_dir /".."/"images"/"Text_WIN.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }
            else if(game.getBoard().isConnector(pos)){
                file_path = source_dir /".."/"images"/"Text_IS.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isGrass(pos)){
                file_path = source_dir /".."/"images"/"Grass.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }
            else if(game.getBoard().isMetal(pos)){
            file_path = source_dir /".."/"images"/"Metal.png";
            QPixmap pic = loadPixmapFromPath(file_path);
            QLabel* label = new QLabel();
            label->setPixmap(pic);
            label->setAlignment(Qt::AlignCenter);
            table->setCellWidget(j,i,label);
        }else{

            }
            this->ui->boardGridLayout->addWidget(table,i,j);
        }
    }
}
void MainWindow::displayLevel(){

}
//Nécessiterait d'être observeur sur toutes les cases pour mise à jour automatique au lieu de tout recheck
void MainWindow::displayLevel(Board old){

    std::string source_path = __FILE__;
    std::filesystem::path source_dir = std::filesystem::path(source_path).parent_path();
    std::filesystem::path file_path;
    for(int i {0}; i < this->game.getBoardSize(); ++i){
        for(int j {0}; j < this->game.getBoardSize(); ++j){
            Position pos = Position {i,j};
            if((old.getSquare(pos)->getCaseList().size() != game.getSquare(pos)->getCaseList().size()) ||
                !std::is_permutation(game.getSquare(pos)->getCaseList().begin(), game.getSquare(pos)->getCaseList().end(), old.getSquare(pos)->getCaseList().begin())){
                qDebug()<< "changed";
                if(game.getBoard().isBaba(pos)){
                file_path = source_dir /".."/"images"/"Baba.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isLava(pos)){
                file_path = source_dir /".."/"images"/"Lava.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isRock(pos)){
                file_path = source_dir /".."/"images"/"Rock.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isWater(pos)){
                file_path = source_dir /".."/"images"/"Water.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isWall(pos)){
                file_path = source_dir /".."/"images"/"Wall.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isFlag(pos)){
                file_path = source_dir /".."/"images"/"Flag.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isLavaText(pos)){
                file_path = source_dir /".."/"images"/"Text_LAVA.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isFlagText(pos)){
                file_path = source_dir /".."/"images"/"Text_FLAG.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }
            else if(game.getBoard().isWallText(pos)){
                file_path = source_dir /".."/"images"/"Text_WALL.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }
            else if(game.getBoard().isWaterText(pos)){
                file_path = source_dir /".."/"images"/"Text_WATER.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isBabaText(pos)){
                file_path = source_dir /".."/"images"/"Text_BABA.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isGrassText(pos)){
                file_path = source_dir /".."/"images"/"Text_GRASS.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isMetalText(pos)){
                file_path = source_dir /".."/"images"/"Text_METAL.png";
                QPixmap pic = loadPixmapFromPath(file_path);
                QLabel* label = new QLabel();
                label->setPixmap(pic);
                label->setAlignment(Qt::AlignCenter);
                 table->setCellWidget(j,i,label);
                    }
            else if(game.getBoard().isRockText(pos)){
                file_path = source_dir /".."/"images"/"Text_ROCK.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isPush(pos)){
                file_path = source_dir /".."/"images"/"Text_PUSH.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isStop(pos)){
                file_path = source_dir /".."/"images"/"Text_STOP.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isSink(pos)){
                file_path = source_dir /".."/"images"/"Text_SINK.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isKill(pos)){
                file_path = source_dir /".."/"images"/"Text_KILL.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isYou(pos)){
                file_path = source_dir /".."/"images"/"Text_YOU.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
                        }
            else if(game.getBoard().isWin(pos)){
                file_path = source_dir /".."/"images"/"Text_WIN.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }
            else if(game.getBoard().isConnector(pos)){
                file_path = source_dir /".."/"images"/"Text_IS.gif";
                QMovie* movie = this->loadMovieFromPath(file_path);
                QLabel* label = new QLabel();
                movie->start();
                label->setMovie(movie);
                label->setAlignment(Qt::AlignCenter);
                table->setCellWidget(j,i,label);
            }else if(game.getBoard().isGrass(pos)){
                    file_path = source_dir /".."/"images"/"Grass.gif";
                    QMovie* movie = this->loadMovieFromPath(file_path);
                    QLabel* label = new QLabel();
                    movie->start();
                    label->setMovie(movie);
                    label->setAlignment(Qt::AlignCenter);
                    table->setCellWidget(j,i,label);
            }else if(game.getBoard().isMetal(pos)){
                file_path = source_dir /".."/"images"/"Metal.png";
                QPixmap pic = loadPixmapFromPath(file_path);
                QLabel* label = new QLabel();
                label->setPixmap(pic);
                label->setAlignment(Qt::AlignCenter);
                  table->setCellWidget(j,i,label);

            }else{
               QLabel* label = new QLabel();
               table->setCellWidget(j,i,label);
            }
            }
        }
    }
}
void MainWindow::keyPressEvent(QKeyEvent* event){
    Board old = this->game.getBoard();
    this->c.moveGUI(event->text().toStdString());
    this->displayLevel(old);

    if(this->c.isLevelWin()){
            this->ui->labelMessages->setText("You have win . Congratulations !!!");
            this->toggleButtons();
        }else if(this->c.isLevelLost()){
            this->ui->labelMessages->setText("You are dead. Load to continue");
            this->toggleButtons();
        }

    }


QPixmap MainWindow::loadPixmapFromPath(const std::filesystem::path& filePath) {
    QString qFilePath = QString::fromStdString(filePath.string());

    if (!QFile::exists(qFilePath)) {

        return QPixmap();
    }

    QImage image(qFilePath);

    if (image.isNull()) {
        return QPixmap();
    }

    QPixmap pixmap = QPixmap::fromImage(image);

    return pixmap;
}

QMovie* MainWindow::loadMovieFromPath(const std::filesystem::path& filePath) {
    QString qFilePath = QString::fromStdString(filePath.string());

    if (!QFile::exists(qFilePath)) {
        return  new QMovie();
    }

    QMovie* movie = new QMovie(qFilePath);
    return movie;
}


MainWindow::~MainWindow()
{
    delete ui;
}
