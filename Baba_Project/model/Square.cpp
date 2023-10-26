#include "Square.h"
#include <iostream>
Square::Square(){
    this->caseList = std::vector<TypeCase>();
}
Square::Square(Position pos){ //Position nécessaire?
    this->pos = pos;
    this->caseList = std::vector<TypeCase>{};
}



void Square::update(TypeCase::Element element, TypeCase::Action act, bool active){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isElement() && caseList.at(var).getElement() == element){
            caseList.at(var).changeAttr(act, active);
        }
    }
}


bool Square::isConnector(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isConnector()){
            return true;
        }
    }
    return false;
}

bool Square::isPlayer(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isAttrYou()){
            return true;
        }
    }
    return false;
}

bool Square::isGameWin(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isWin()){
            return true;
        }
    }
    return false;
}

bool Square::isBaba(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isBaba()){
            return true;
        }
    }
    return false;
}

bool Square::isElement_Text(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isElement_Text()){
            return true;
        }
    }
    return false;
}

bool Square::isElement(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isElement()){
            return true;
        }
    }
    return false;
}

bool Square::isAction(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isAction()){
            return true;
        }
    }
    return false;
}

bool Square::isGrass(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isGrass()){
            return true;
        }
    }
    return false;
}
bool Square::isWall(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isWall()){
            return true;
        }
    }
    return false;
}

bool Square::isWater(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isWater()){
            return true;
        }
    }
    return false;
}
bool Square::isMetal(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isMetal()){
            return true;
        }
    }
    return false;
}
bool Square::isRock(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isRock()){
            return true;
        }
    }
    return false;
}
bool Square::isFlag(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isFlag()){
            return true;
        }
    }
    return false;
}

bool Square::isLava(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isLava()){
            return true;
        }
    }
    return false;
}
bool Square::isWaterText(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isWaterText()){
            return true;
        }
    }
    return false;
}
bool Square::isWallText(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isWallText()){
            return true;
        }
    }
    return false;
}
bool Square::isMetalText(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isMetalText()){
            return true;
        }
    }
    return false;
}
bool Square::isGrassText(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isGrassText()){
            return true;
        }
    }
    return false;
}
bool Square::isBabaText(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isBabaText()){
            return true;
        }
    }
    return false;
}
bool Square::isFlagText(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isFlagText()){
            return true;
        }
    }
    return false;
}
bool Square::isRockText(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isRockText()){
            return true;
        }
    }
    return false;
}

bool Square::isLavaText(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isLavaText()){
            return true;
        }
    }
    return false;
}


bool Square::isStop(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isStop()){
            return true;
        }
    }
    return false;
}
bool Square::isSink(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isSink()){
            return true;
        }
    }
    return false;
}
bool Square::isPush(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isPush()){
            return true;
        }
    }
    return false;
}
bool Square::isWin(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isWin()){
            return true;
        }
    }
    return false;
}
bool Square::isYou(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isYou()){
            return true;
        }
    }
    return false;
}
bool Square::isKill(){
        for (unsigned var = 0; var < caseList.size(); ++var) {
            if(caseList.at(var).isKill()){
                return true;
            }
        }
        return false;

}
TypeCase::Element_Text Square::getElement_Text(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isElement_Text()){
            return caseList.at(var).getElement_Text();
        }
    }
}
//erreur car possiblement rien retrourner même si check préalable mais non visible dans la fonction
//trouver alternative pour toujours renvoyer quelque chose

TypeCase::Action Square::getAction(){
    for (unsigned var = 0; var < caseList.size(); ++var) {
        if(caseList.at(var).isAction())
            return caseList.at(var).getAction();
    }
}

void Square::addTypeCase(TypeCase tp){
    this->caseList.push_back(tp);

}
void Square::removeTypeCase(TypeCase tp){
    for(unsigned j = 0; j <= caseList.size(); ++j){
        if(caseList.at(j)==tp){
            caseList.erase(caseList.begin()+j);
            return;
        }
    }

}
std::vector<TypeCase>& Square::getCaseList(){
    return this->caseList;
}
Position Square::getPosition(){
    return this->pos;
}

TypeCase Square::getFirstElement(){
                if(isBaba()){
                    return TypeCase::BABA;


                }else if(isLava()){
                    return TypeCase::LAVA;

                }else if(  isRock(  )){
                    return TypeCase::ROCK;


                }else if(  isWater(  )){
                    return TypeCase::WATER;

                }else if(  isGrass(  )){
                    return TypeCase::GRASS;

                }else if(  isWall(  )){

                }else if(  isFlag(  )){
                    return TypeCase::FLAG;

                }else if(  isLavaText()){
                    return TypeCase::LAVA_TEXT;

                }else if(  isFlagText(  )){
                    return TypeCase::FLAG_TEXT;

                }
                else if(  isWallText(  )){
                    return TypeCase::WALL_TEXT;

                }
                else if(  isWaterText(  )){
                    return TypeCase::WATER_TEXT;

                            }
                else if(  isBabaText(  )){
                    return TypeCase::BABA_TEXT;

                }else if(  isMetalText()){
                    return TypeCase::METAL_TEXT;

                        }
                else if(  isRockText(  )){
                    return TypeCase::ROCK_TEXT;

                            }
                else if(  isPush(  )){
                    return TypeCase::PUSH;

                            }
                else if(  isStop(  )){
                    return TypeCase::STOP;

                            }
                else if(  isSink(  )){
                    return TypeCase::SINK;

                            }
                else if(  isKill(  )){
                    return TypeCase::KILL;

                            }
                else if(  isYou(  )){
                    return TypeCase::YOU;

                            }
                else if(  isWin()){
                    return TypeCase::WIN;

                }
                else if(  isConnector()){
                    return TypeCase::IS;


                }else{
                    return TypeCase::METAL;

                }
}

Square::~Square(){}


