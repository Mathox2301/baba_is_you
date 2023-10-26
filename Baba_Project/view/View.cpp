#include "View.h"
#include <ostream>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

View::View(Game& game,Controller& c) : game(game), c(c)
{}

void View::start(){
    while(!this->game.isLevelLost()){
        this->displayLevel();
        c.askDeplacement();
    }
    this->displayLevel();
    cout<<"impossible de continuer"<<endl;
}

void View::displayLevel(){
    //à changer pour mettre dans terminal
    for (int i = 0; i < game.getBoardSize(); ++i) {
        for (int j = 0; j < game.getBoardSize(); ++j) {
            Position pos = Position (j,i);
            if(game.getBoard().isBaba(pos)){
                cout<<"|  baba  ";
            }else if(game.getBoard().isLava(pos)){
                cout<<"|  lava  ";
            }else if(game.getBoard().isRock(pos)){
                cout<<"|  rock  ";
            }else if(game.getBoard().isWater(pos)){
                cout<<"| water  ";
            }else if(game.getBoard().isMetal(pos)){
                cout<<"| metal  ";
            }else if(game.getBoard().isGrass(pos)){
                cout<<"| grass  ";
            }else if(game.getBoard().isWall(pos)){
                cout<<"|  wall  ";
            }else if(game.getBoard().isFlag(pos)){
                cout<<"|  flag  ";
            }else if(game.getBoard().isLavaText(pos)){
                cout<<"|lavaText";
            }else if(game.getBoard().isFlagText(pos)){
                cout<<"|flagText";
            }
            else if(game.getBoard().isWallText(pos)){
                cout<<"|wallText";
            }
            else if(game.getBoard().isWaterText(pos)){
                            cout<<"|waterTxt";
                        }
            else if(game.getBoard().isBabaText(pos)){
                            cout<<"|babaText";
                        }
            else if(game.getBoard().isGrassText(pos)){
                            cout<<"|grassTxt";
                        }
            else if(game.getBoard().isMetalText(pos)){
                            cout<<"|metalTxt";
                        }
            else if(game.getBoard().isRockText(pos)){
                            cout<<"|rockText";
                        }
            else if(game.getBoard().isPush(pos)){
                            cout<<"|  push  ";
                        }
            else if(game.getBoard().isStop(pos)){
                            cout<<"|  stop  ";
                        }
            else if(game.getBoard().isSink(pos)){
                            cout<<"|  sink  ";
                        }
            else if(game.getBoard().isKill(pos)){
                            cout<<"|  kill  ";
                        }
            else if(game.getBoard().isYou(pos)){
                            cout<<"|  you   ";
                        }
            else if(game.getBoard().isWin(pos)){
                            cout<<"|  win   ";
            }
            else if(game.getBoard().isConnector(pos)){
                            cout<<"|   is   ";
            }else{
                            cout<<"|        ";
            }
        }
        cout<<"|"<<endl;

    }
}

