#include "Game.h"
#include "Board.h"
#include <filesystem>
#include<QDebug>

Game::Game() : board(Board()){
    this->observers = std::vector<Observer *>{};
    for(int i {0}; i < this->getBoardSize(); ++i){
        for(int j {0}; j < this->getBoardSize(); ++j){
            this->addObserver(this->getBoard().getSquare(Position(i,j)));
        }
    }
}

/*!
 * \brief start start the game and initialise the attribute of the model
 */
void Game::start(){                     //unused?
    //file format: level/level_x.txt
//    this->board.setUp(0);
        //What else?
}

void Game::setUpRules(){
    for(int i {0}; i < this->getBoardSize(); ++i){
        for(int j {0}; j < this->getBoardSize(); ++j){
            Position pos = Position(i,j);
            if(this->board.isConnector(pos))
                this->ruleUpdate(pos, pos);
        }
    }
}


void Game::nextLevel(){

    ++level;
    if(level >= 5){
        return;
    }
    this->board.clear();
    this->board.setUp(std::to_string(level));
    this->observers.clear();
    for(int i {0}; i < this->getBoardSize(); ++i){
        for(int j {0}; j < this->getBoardSize(); ++j){
            this->addObserver(this->getBoard().getSquare(Position(i,j)));
        }
    }
    setUpRules();

}

void Game::loadLevel(string lvl){
    if(lvl == "save"){
        std::string source_path = __FILE__;
        std::filesystem::path source_dir = std::filesystem::path(source_path).parent_path();
        std::filesystem::path file_path = source_dir /".."/"levels"/"save.txt";
        ifstream LvlFile (file_path);
        if (LvlFile.peek() == EOF){
           cout<<"fichier vide"<<endl;
           return;
        }
    }
    else{
        level = stoi(lvl);
    }
    this->board.clear();
    this->board.setUp(lvl);
    this->observers.clear();
    for(int i {0}; i < this->getBoardSize(); ++i){
        for(int j {0}; j < this->getBoardSize(); ++j){
            this->addObserver(this->getBoard().getSquare(Position(i,j)));
        }
    }
    setUpRules();

}


void Game::move(TypeCase element, Position pos1, Position pos2){
            //Check if element can move, if pos2 is BLOCK//PUSH//limite du plateau

    if(!this->board.contains(pos2) || this->board.getSquare(pos2)->isAttrStop())
        return;


    Position posNext = pos2 + (pos2 - pos1);
    if(this->board.getSquare(pos2)->isAttrPush()){  //Check behind is clear
        while(this->board.contains(posNext) && this->board.getSquare(posNext)->isAttrPush()){
            posNext = posNext + (pos2 - pos1);
        }
        if(!this->board.contains(posNext) || this->board.getSquare(posNext)->isAttrStop())  //Can't move
            return;
    }

    if(this->board.getSquare(pos2)->isAttrPush()){ //Possible multiple pushes
        while(!posNext.equals(pos1)){
            Position posBefore = posNext - (pos2 - pos1);
            for(unsigned i {0}; i < this->board.getSquare(posBefore)->getCaseList().size(); ++i){
                if(this->board.getSquare(posBefore)->getCaseList().at(i).isAttrPush()){
                    TypeCase temp = this->board.getSquare(posBefore)->getCaseList().at(i);
                    map<TypeCase::Action,bool> tmp = board.getSquare(posBefore)->getCaseList().at(i).getAttributes();
                    this->getBoard().getSquare(posNext)->addTypeCase(temp);
                    size_t size = board.getSquare(posNext)->getCaseList().size();
                    board.getSquare(posNext)->getCaseList().at(size-1).setAttributes(tmp);
                    this->getBoard().getSquare(posBefore)->removeTypeCase(temp);

                    //Case SINK and KILL
                    if(this->board.getSquare(posNext)->isAttrKill())
                        this->getSquare(posNext)->removeTypeCase(temp);
                    else if(this->board.getSquare(posNext)->isAttrSink())
                        this->getSquare(posNext)->getCaseList().clear();
                }
            }
            if(board.getSquare(posNext)->isAction() || board.getSquare(posNext)->isElement_Text() || board.getSquare(posNext)->isConnector()){
                this->ruleUpdate(posBefore, posNext);
            }
            posNext = posNext - (pos2 - pos1);
        }
    }

    map<TypeCase::Action,bool> att;

    if(this->board.getSquare(pos1)->getCaseList().size()!=0){
        for (long long unsigned int var = 0; var < board.getSquare(pos1)->getCaseList().size(); ++var) {
            if(this->board.getSquare(pos1)->getCaseList().at(var) == element){
                   map<TypeCase::Action,bool> tmp = board.getSquare(pos1)->getCaseList().at(var).getAttributes();
                   att = tmp;
            }
        }
    }

    this->board.getSquare(pos1)->removeTypeCase(element);
    this->board.getSquare(pos2)->addTypeCase(element);
    board.getSquare(pos2)->getCaseList().back().setAttributes(att);

    //Case SINK and KILL (pos2)
    if(this->board.getSquare(pos2)->isAttrKill())
        this->getSquare(pos2)->removeTypeCase(element);
    else if(this->board.getSquare(pos2)->isAttrSink())
        this->getSquare(pos2)->getCaseList().clear();

    if(board.getSquare(pos2)->isAttrYou() && this->isLevelWon(pos2)){
        this->nextLevel();
    }
}


bool Game::isLevelWon(Position pos){
    return this->board.getSquare(pos)->isAttrYou() && this->board.getSquare(pos)->isAttrWin();
}


bool Game::isLevelLost(){
    return !this->board.isPlayerAlive();
}

/*!
  * \brief Using both position, will check if rules have been broken/created
  * \param pos1 a Position
  * \param pos2 a Position
  */
void Game::ruleUpdate(Position oldPos, Position newPos){
    //Probablement simplifiable. Redondance

    if(this->board.isElement_Text(newPos)){
        if(this->board.isConnector(newPos + East) && this->board.isAction(newPos + East + East)){
            TypeCase::Element_Text elt = this->board.getSquare(newPos)->getElement_Text();
            TypeCase::Action act = this->board.getSquare(newPos + East + East)->getAction();
            TypeCase::Element el = this->getElement(elt);
            this->notifyObservers(el, act, true);
        }
        else if(this->board.isConnector(newPos + South) && this->board.isAction(newPos + South + South)){
            TypeCase::Element_Text elt = this->board.getSquare(newPos)->getElement_Text();
            TypeCase::Action act = this->board.getSquare(newPos + South + South)->getAction();
            TypeCase::Element el = this->getElement(elt);
            this->notifyObservers(el, act, true);
        }
    }

    else if(this->board.isConnector(newPos)){
        if(this->board.isElement_Text(newPos + North) && this->board.isAction(newPos + South)){
            TypeCase::Element_Text elt = this->board.getSquare(newPos+North)->getElement_Text();
            TypeCase::Action act = this->board.getSquare(newPos + South)->getAction();
            TypeCase::Element el = this->getElement(elt);

            this->notifyObservers(el,act,true);
        }
        else if(this->board.isElement_Text(newPos + West) && this->board.isAction(newPos + East)){            
            TypeCase::Element_Text elt = this->board.getSquare(newPos + West)->getElement_Text();
            TypeCase::Action act = this->board.getSquare(newPos + East)->getAction();
            TypeCase::Element el = this->getElement(elt);

            this->notifyObservers(el,act,true);
        }

    }

    else if(this->board.isAction(newPos)){

        if(this->board.isConnector(newPos + North) && this->board.isElement_Text(newPos + North + North)){
            TypeCase::Element_Text elt = this->board.getSquare(newPos+North+North)->getElement_Text();
            TypeCase::Action act = this->board.getSquare(newPos)->getAction();
            TypeCase::Element el = this->getElement(elt);
            this->notifyObservers(el,act,true);
        }
        else if(this->board.isConnector(newPos + West) && this->board.isElement_Text(newPos + West + West)){
            TypeCase::Element_Text elt = this->board.getSquare(newPos  +West + West)->getElement_Text();
            TypeCase::Action act = this->board.getSquare(newPos)->getAction();
            TypeCase::Element el = this->getElement(elt);
            this->notifyObservers(el,act,true);
        }
    }


    if(!(oldPos.getX() == newPos.getX() && oldPos.getY() == newPos.getY())){

        if(this->board.isElement_Text(newPos)){
            if(this->board.isConnector(oldPos + East) && this->board.isAction(oldPos + East + East)){
                TypeCase::Element_Text elt = this->board.getSquare(newPos)->getElement_Text();
                TypeCase::Action act = this->board.getSquare(oldPos + East + East)->getAction();
                TypeCase::Element el = this->getElement(elt);
                this->notifyObservers(el, act, false);
            }
            else if(this->board.isConnector(oldPos + South) && this->board.isAction(oldPos + South + South)){
                TypeCase::Element_Text elt = this->board.getSquare(newPos)->getElement_Text();
                TypeCase::Action act = this->board.getSquare(oldPos + South + South)->getAction();
                TypeCase::Element el = this->getElement(elt);
                this->notifyObservers(el, act, false);
            }
        }

        else if(this->board.isConnector(newPos)){
            if(this->board.isElement_Text(oldPos + North) && this->board.isAction(oldPos + South)){
                TypeCase::Element_Text elt = this->board.getSquare(oldPos+North)->getElement_Text();
                TypeCase::Action act = this->board.getSquare(oldPos + South)->getAction();
                TypeCase::Element el = this->getElement(elt);
                this->notifyObservers(el,act,false);
            }
            else if(this->board.isElement_Text(oldPos + West) && this->board.isAction(oldPos + East)){
                TypeCase::Element_Text elt = this->board.getSquare(oldPos + West)->getElement_Text();
                TypeCase::Action act = this->board.getSquare(oldPos + East)->getAction();
                TypeCase::Element el = this->getElement(elt);
                this->notifyObservers(el,act,false);
            }

        }

        else if(this->board.isAction(newPos)){
            if(this->board.isConnector(oldPos + North) && this->board.isElement_Text(oldPos + North + North)){
                TypeCase::Element_Text elt = this->board.getSquare(oldPos+North+North)->getElement_Text();
                TypeCase::Action act = this->board.getSquare(newPos)->getAction();
                TypeCase::Element el = this->getElement(elt);
                this->notifyObservers(el,act,false);
            }
            else if(this->board.isConnector(oldPos + West) && this->board.isElement_Text(oldPos + West + West)){
                TypeCase::Element_Text elt = this->board.getSquare(oldPos+West+West)->getElement_Text();
                TypeCase::Action act = this->board.getSquare(newPos)->getAction();
                TypeCase::Element el = this->getElement(elt);
                this->notifyObservers(el,act,false);
            }

        }

    }
}


void Game::notifyObservers(TypeCase::Element element, TypeCase::Action act, bool b){
    for(Observer* obs : this->observers){
        (*obs).update(element, act, b);
    }
}


void Game::addObserver(Observer* obs){
    observers.push_back(obs);
}

Board& Game::getBoard(){
    return this->board;
}

int Game::getBoardSize(){
    return this->board.getSize();
}

TypeCase::Element Game::isCurrentPlayer(){
    for (int x = 0; x < getBoardSize(); ++x) {
        for (int y = 0; y < getBoardSize(); ++y) {
            Position pos = Position (x,y);
            if(getBoard().isPlayer(pos) && getBoard().isElement(pos)){
                if(getBoard().isBaba(pos)){
                    return TypeCase::BABA;
                }else if(getBoard().isMetal(pos)){
                    return TypeCase::METAL;
                }else if(getBoard().isWater(pos)){
                    return TypeCase::WATER;
                }else if(getBoard().isRock(pos)){
                    return TypeCase::ROCK;
                }else if(getBoard().isGrass(pos)){
                    return TypeCase::GRASS;
                }else if(getBoard().isWall(pos)){
                    return TypeCase::WALL;
                }else if(getBoard().isLava(pos)){
                    return TypeCase::LAVA;
                }else if(getBoard().isFlag(pos)){
                    return TypeCase::FLAG;
                }
            }
        }
    }
    return TypeCase::NONE;
}
bool Game::isTypeCase(TypeCase tc, Position pos){
    std::vector<TypeCase> v = this->getBoard().getSquare(pos)->getCaseList();
    for(long long unsigned int i=0;i<v.size();i++){
        if(v.at(i)==tc){
            return true;
        }
    }
    return false;
}
std::vector<Position> Game::positionsTypeList(TypeCase tc){
    std::vector<Position> positions {};
    for (int x = 0; x < getBoardSize(); ++x) {
        for (int y = 0; y < getBoardSize(); ++y) {
            Position pos = Position (x,y);
            if(isTypeCase(tc,pos)){
                positions.push_back(pos);
            }
        }
    }
    return positions;
}

Game::~Game(){}

TypeCase::Element Game::getElement(TypeCase::Element_Text elt){
    if(elt == TypeCase::Element_Text::BABA_TEXT)
        return TypeCase::Element::BABA;
    else if(elt == TypeCase::Element_Text::WATER_TEXT)
        return TypeCase::Element::WATER;
    else if(elt == TypeCase::Element_Text::WALL_TEXT)
        return TypeCase::Element::WALL;
    else if(elt == TypeCase::Element_Text::METAL_TEXT)
        return TypeCase::Element::METAL;
    else if(elt == TypeCase::Element_Text::GRASS_TEXT)
        return TypeCase::Element::GRASS;
    else if(elt == TypeCase::Element_Text::ROCK_TEXT)
        return TypeCase::Element::ROCK;
    else if(elt == TypeCase::Element_Text::LAVA_TEXT)
        return TypeCase::Element::LAVA;
    else
        return TypeCase::Element::FLAG;
}
void Game::save(){
    std::string source_path = __FILE__;
    std::filesystem::path source_dir = std::filesystem::path(source_path).parent_path();
    std::filesystem::path file_path = source_dir /".."/"levels"/"save.txt";
    cout << file_path << endl;
    ofstream save (file_path);
    if(save.is_open()){
         save<<getBoardSize()<<" "<<getBoardSize()<<endl;
        for (int i = 0; i < getBoardSize(); ++i) {
            for (int j = 0; j < getBoardSize(); ++j) {
                Position pos = Position (i,j);
                for(long long unsigned int k = 0; k < getBoard().getSquare(pos)->getCaseList().size();k++){
                    TypeCase elt = getBoard().getSquare(pos)->getCaseList().at(k);
                    if(elt.isYou()){
                        save << "you "<<i<<" "<<j<< endl;

                      }else if(elt.isWin()){
                            save << "win "<<i<<" "<<j<< endl;

                     }else if(elt.isWaterText()){
                      save << "text_water "<<i<<" "<<j<< endl;

                      }else if(elt.isWall()){
                    save << "wall "<<i<<" "<<j<< endl;

                    }else if(elt.isWater()){
                    save << "water "<<i<<" "<<j<< endl;

                    }else if(elt.isStop()){
                    save << "stop "<<i<<" "<<j<< endl;

                    }else if(elt.isPush()){
                    save << "push "<<i<<" "<<j<< endl;

                    }else if(elt.isBaba()){
                    save << "baba "<<i<<" "<<j<< endl;

                    }else if(elt.isBabaText()){
                        save << "text_baba "<<i<<" "<<j<< endl;

                    }else if(elt.isWallText()){
                        save << "text_wall "<<i<<" "<<j<< endl;

                    }else if(elt.isFlag()){
                        save << "flag "<<i<<" "<<j<< endl;

                   }else if(elt.isFlagText()){
                        save << "text_flag "<<i<<" "<<j<< endl;

                    }else if(elt.isGrassText()){
                        save << "text_grass "<<i<<" "<<j<< endl;

                    }else if(elt.isGrass()){
                        save << "grass "<<i<<" "<<j<< endl;

                    }else if(elt.isMetal()){
                        save << "metal "<<i<<" "<<j<< endl;

                    }else if(elt.isMetalText()){
                        save << "text_metal "<<i<<" "<<j<< endl;

                    }else if(elt.isKill()){
                        save << "kill "<<i<<" "<<j<< endl;

                    }else if(elt.isSink()){
                        save << "sink "<<i<<" "<<j<< endl;

                    }else if(elt.isRock()){
                        save << "rock "<<i<<" "<<j<< endl;

                    }else if(elt.isRockText()){
                        save << "text_rock "<<i<<" "<<j<< endl;

                    }else if(elt.isConnector()){
                        save << "is "<<i<<" "<<j<< endl;

                    }
                }

            }
    }

    }else{
        cout<<"ERREUR: Le fichier ne peut pas s'ouvrir"<<endl;
    }
}


