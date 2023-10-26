#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "AbstractView.h"
#include "../model/Game.h"
#include "../controller/Controller.h"
#include <QTableWidget>
#include <QWidget>
#include <filesystem>
#include <QApplication>
#include <QDebug>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow, public AbstractView
{
    Q_OBJECT
private slots:
    void moveL();
    void moveR();
    void moveU();
    void moveD();
    void save();
    void load(string lvl);

public:
    MainWindow(Game& game, Controller& c, QWidget *parent = nullptr);
    ~MainWindow();
    void displayLevel() override;
    void displayLevel(Board old);
    void keyPressEvent(QKeyEvent* event) override;
    void setupView();

private:
    Game& game;
    Controller& c;
    Ui::MainWindow *ui;
    QTableWidget* table;
    /*!
     * \brief loadPixmapFromPath load a Pixmap with a picture file
     * \param filePath the file path for the picture
     * \return a QPixmap
     */
    QPixmap loadPixmapFromPath(const std::filesystem::path& filePath);
    /*!
     * \brief loadMovieFromPath load a Pixmap with a GIF file
     * \param filePath the file path for the picture
     * \return a QMovie
     */
    QMovie* loadMovieFromPath(const std::filesystem::path& filePath);
    /*!
     * \brief move move the player in a direction
     * \param dir a string
     */
    void move(std::string dir);
    /*!
     * \brief toggleButtons active the buttons
     */
    void toggleButtons();

};
#endif // MAINWINDOW_H
