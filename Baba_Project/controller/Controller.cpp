#include <iostream>
#include "Controller.h"

#include<QDebug>

using namespace std;

Controller::Controller(Game& game) : game(game)
{}

bool Controller::isLevelLost(){
    return this->game.isLevelLost();
}

bool Controller::isLevelWin(){
    std::vector<Position> v  = game.positionsTypeList(game.isCurrentPlayer());
    for (int var = 0; var < v.size(); ++var) {
        if(game.isLevelWon(v.at(var))){
            game.getSquare(v.at(var))->update(game.isCurrentPlayer(),TypeCase::YOU,false);

            return true;
        }

    }
    return false;
}

void Controller::askDeplacement(){

    string s {};
    cout << "entrer un deplacement : z,q,s,d,load,save" << endl;
    cin >> s;

    TypeCase elt = this->game.isCurrentPlayer();
    std::vector<Position> v = this->game.positionsTypeList(elt);
    Position::Direction E (1,0);
    Position::Direction W (-1,0);
    Position::Direction S (0,1);
    Position::Direction N (0,-1);
    if (elt.isElement() && s == "z") {
        for (long long unsigned int var = 0; var < v.size(); ++var) {
            Position pos = v.at(var) + N;
            this->game.move(elt,v.at(var),pos);
        }
    } else if (elt.isElement() && s == "s") {
        for (long long unsigned int var = 0; var < v.size(); ++var) {
            Position pos = v.at(var) + S;
            this->game.move(elt,v.at(var),pos);
        }
    } else if (elt.isElement() && s == "q") {
        for (long long unsigned int var = 0; var < v.size(); ++var) {
            Position pos = v.at(var) + W;
            this->game.move(elt,v.at(var),pos);
        }
    } else if (elt.isElement() && s == "d") {
        for (long long unsigned int var = 0; var < v.size(); ++var) {
            Position pos = v.at(var) + E;
            this->game.move(elt,v.at(var),pos);
        }
    }else if(s=="load"){
        cout<<"quelle niveau voulez-vous charger (0,1,2,3,4,save)"<<endl;
        cin>>s;
        game.loadLevel(s);

    }else if(s=="save"){
        cout<<"niveau sauvegardé"<<endl;
        game.save();
    }
    else {
        cout << "ce n'est pas une commande" << endl;
        return;
    }
}

void Controller::moveGUI(std::string dir){
    TypeCase::Element elt = this->game.isCurrentPlayer();
    if(elt == TypeCase::Element::NONE)
        return;
    std::vector<Position> v = this->game.positionsTypeList(elt);
    Position::Direction E (1,0);
    Position::Direction W (-1,0);
    Position::Direction S (0,1);
    Position::Direction N (0,-1);
    if (dir == "up" || dir == "z") {
        for (long long unsigned int var = 0; var < v.size(); ++var) {
            Position pos = v.at(var) + N;
            this->game.move(elt,v.at(var),pos);
        }
    } else if (dir == "down" || dir == "s") {
        for (long long unsigned int var = 0; var < v.size(); ++var) {
            Position pos = v.at(var) + S;
            this->game.move(elt,v.at(var),pos);
        }
    } else if (dir == "left" || dir == "q") {
        for (long long unsigned int var = 0; var < v.size(); ++var) {
            Position pos = v.at(var) + W;
            this->game.move(elt,v.at(var),pos);
        }
    } else if (dir == "right" || dir == "d") {
        for (long long unsigned int var = 0; var < v.size(); ++var) {
            Position pos = v.at(var) + E;
            this->game.move(elt,v.at(var),pos);
        }
    }
}
