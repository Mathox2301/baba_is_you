#include "Board.h"
#include "Square.h"
#include <istream>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <filesystem>
using namespace std;


Board::Board(){
    setUp("0");
}

void Board::setUp(std::string lvl){
    std::string source_path = __FILE__;
    std::filesystem::path source_dir = std::filesystem::path(source_path).parent_path();
    std::filesystem::path file_path ;
     if(lvl == "save"){
             file_path = source_dir /".."/"levels"/"save.txt";
     }
    else if(lvl == "0"){
    file_path = source_dir /".."/"levels"/"level_0.txt";
    }else if(lvl =="1"){
       file_path = source_dir /".."/"levels"/"level_1.txt";
    }
    else if(lvl =="2"){
            file_path = source_dir /".."/"levels"/"level_2.txt";
        }
    else if(lvl =="3"){
             file_path = source_dir /".."/"levels"/"level_3.txt";
        }
    else if(lvl=="4"){
             file_path = source_dir /".."/"levels"/"level_4.txt";
        }

     ifstream LvlFile (file_path);
     if (file_path==source_dir /".."/"levels"/"save.txt" && LvlFile.peek() == EOF){
        cout<<"fichier vide"<<endl;
        return;
     }
     if(LvlFile){
        string mot ;
        getline(LvlFile,mot);
        const char delimiter = ' ';
        string arr[3];
        size_t pos = 0;
        int i = 0;
        while ((pos = mot.find(delimiter)) != std::string::npos) {
                std::string token = mot.substr(0, pos);
                arr[0] = token;
                mot.erase(0, pos+1);
            }
        this->board =  std::vector(stoi(arr[0]),std::vector<Square>(stoi(arr[0])));
        mot = "";
        while (getline(LvlFile,mot)){
            while ((pos = mot.find(delimiter)) != std::string::npos) {
                    std::string token = mot.substr(0, pos);
                    arr[i++] = token;
                    mot.erase(0, pos + 1);
                }
            if(i==3){

            }else{
                arr[i] = mot;
            }

            int x = stoi(arr[1]);
            int y = stoi(arr[2]);
            Position pos = Position (x,y);

             if(arr[0]=="wall"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::WALL;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);

            }
            else if(arr[0]=="text_wall"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::WALL_TEXT;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="water"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::WATER;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="text_water"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::WATER_TEXT;
                 this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="you"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::YOU;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="baba"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::BABA;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="text_baba"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::BABA_TEXT;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
             else if(arr[0]=="text_lava"){
                 Square s = Square(pos);
                 TypeCase tp = TypeCase::LAVA_TEXT;
                 this->board[x][y] = s;
                 this->board[x][y].addTypeCase(tp);
             }
             else if(arr[0]=="lava"){
                 Square s = Square(pos);
                 TypeCase tp = TypeCase::LAVA;
                 this->board[x][y] = s;
                 this->board[x][y].addTypeCase(tp);
             }
            else if(arr[0]=="metal"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::METAL;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="text_metal"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::METAL_TEXT;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="rock"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::ROCK;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="text_rock"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::ROCK_TEXT;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="flag"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::FLAG;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="text_flag"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::FLAG_TEXT;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="grass_text"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::GRASS_TEXT;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="grass"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::GRASS;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="stop"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::STOP;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="sink"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::SINK;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="push"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::PUSH;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="is"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::IS;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="win"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::WIN;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
            else if(arr[0]=="kill"){
                Square s = Square(pos);
                TypeCase tp = TypeCase::KILL;
                this->board[x][y] = s;
                this->board[x][y].addTypeCase(tp);
            }
             i=0;

        }
        LvlFile.close();
    }else{
        cout<<"ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
}


bool Board::contains(Position pos){
    return(pos.getX() < this->getSize() && pos.getX() >= 0 && pos.getY() < this->getSize() && pos.getY() >= 0);
}

bool Board::isPlayerAlive(){
    for(unsigned i = 0; i < this->board.size(); ++i){
        for(unsigned j = 0; j < this->board[i].size(); ++j){
            if(this->board[i][j].isAttrYou())
                return true;
        }
    }
    return false;
}


void Board::clear(){
    this->board.clear();
}

bool Board::isPlayer(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isPlayer();
    else
        return false;   //throw error?
}


bool Board::isFlag(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isFlag();
    else
        return false;
}

bool Board::isWater(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isWater();
    else
        return false;
}

bool Board::isRock(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isRock();
    else
        return false;
}

bool Board::isGrass(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isGrass();
    else
        return false;
}

bool Board::isMetal(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isMetal();
    else
        return false;
}

bool Board::isBaba(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isBaba();
    else
        return false;
}

bool Board::isWall(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isWall();
    else
        return false;
}

bool Board::isLava(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isLava();
    else
        return false;
}

bool Board::isElement_Text(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isElement_Text();
    else
        return false;
}
bool Board::isElement(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isElement();
    else
        return false;
}
bool Board::isConnector(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isConnector();
    else
        return false;
}

bool Board::isAction(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isAction();
    else
        return false;
}
bool Board::isWin(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isWin();
    else
        return false;
}
bool Board::isPush(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isPush();
    else
        return false;
}
bool Board::isSink(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isSink();
    else
        return false;
}
bool Board::isStop(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isStop();
    else
        return false;
}
bool Board::isKill(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isKill();
    else
        return false;
}
bool Board::isYou(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isYou();
    else
        return false;
}
bool Board::isBabaText(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isBabaText();
    else
        return false;
}
bool Board::isRockText(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isRockText();
    else
        return false;
}
bool Board::isWallText(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isWallText();
    else
        return false;
}
bool Board::isWaterText(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isWaterText();
    else
        return false;
}
bool Board::isMetalText(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isMetalText();
    else
        return false;
}
bool Board::isGrassText(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isGrassText();
    else
        return false;
}
bool Board::isFlagText(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isFlagText();
    else
        return false;
}
bool Board::isLavaText(Position pos){
    if(this->contains(pos))
        return this->board[pos.getX()][pos.getY()].isLavaText();
    else
        return false;
}
Square* Board::getSquare(Position pos){
    if(this->contains(pos))
        return &this->board[pos.getX()][pos.getY()];
    //else throw error
}

int Board::getSize(){
    return this->board.size();
}

void Board::setSquare(Position pos, Square s){
    this->board[pos.getX()][pos.getY()] = s;
}





