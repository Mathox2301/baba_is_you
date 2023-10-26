#include "QSquare.h"

QSquare::QSquare(Square* sq):sq(sq){
    //Apparence de la square // utiliser image
}

QSquare::~QSquare(){
    delete this->sq;
}

