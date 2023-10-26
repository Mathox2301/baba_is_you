#ifndef QSQUARE_H
#define QSQUARE_H
#include <QWidget>
#include "../model/Square.h"
#include <QLabel>

class QSquare : public QWidget{

public:
    QSquare(Square* sq);
    ~QSquare()
    ;
private:

    Square* sq;
    QWidget container;
    QLabel* label = new QLabel(&container);
};

#endif // QSQUARE_H
