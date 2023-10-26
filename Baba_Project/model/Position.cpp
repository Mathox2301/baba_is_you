#include "Position.h"
#include <iostream>
#include <ostream>

using namespace std;

Position::Position(int x, int y){
    this->x=x;
    this->y=y;
}

Position::Position(Position& other):x{other.x},y{other.y}{}

Position::Position(const Position& other):x{other.x},y{other.y}{}

Position::~Position(){}

int Position::getX(){
    return this->x;
}

int Position::getY(){
    return this->y;
 }
bool Position::equals(const Position& other){
    if(other.x==this->x && other.y==this->y){
        return true;
    }
    return false;
}

Position Position::operator+(Position other){
    Position pos = Position(this->x+other.getX(),this->y+other.getY());
    return pos;
}

Position Position::operator-(Position other){
    Position pos = Position(this->x-other.getX(),this->y-other.getY());
    return pos;
}

Position Position::operator+ (Direction dir){
    return Position(this->getX()+dir.first, this->getY() + dir.second);
}
