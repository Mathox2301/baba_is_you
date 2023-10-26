#ifndef TYPECASE_H
#define TYPECASE_H
/*!
 * \brief The TypeCase class represents the type of Square
 */

#include <map>
#include <string>
#include <iostream>
#include <QDebug>

using namespace std;

class TypeCase{
public:
    enum Element{
        BABA = 0,
        WATER = 1,
        WALL = 2,
        METAL = 3,
        GRASS = 4,
        ROCK = 5,
        FLAG = 6,
        LAVA = 7,
        NONE = 8
    };
    enum Element_Text{
        BABA_TEXT = 10,
        WATER_TEXT = 11,
        WALL_TEXT = 12,
        METAL_TEXT = 13,
        GRASS_TEXT = 14,
        ROCK_TEXT = 15,
        FLAG_TEXT = 16,
        LAVA_TEXT = 17
    };
    enum Connector{
        IS = 20

    };
    enum Action{
        STOP = 30,
        PUSH = 31,
        SINK = 32,
        WIN = 33,
        KILL = 34,
        YOU = 35
    };

private:
    Element el;
    Element_Text el_text;
    Connector conn;
    Action act;
    unsigned tp;
    map<TypeCase::Action, bool> attributes {};
    /*!
     * \brief initElements initialize attribute of Elements
     */
    inline void initElements(){
        this->attributes.insert_or_assign(TypeCase::Action::STOP, false);
        this->attributes.insert_or_assign(TypeCase::Action::PUSH, false);
        this->attributes.insert_or_assign(TypeCase::Action::SINK, false);
        this->attributes.insert_or_assign(TypeCase::Action::WIN, false);
        this->attributes.insert_or_assign(TypeCase::Action::KILL, false);
        this->attributes.insert_or_assign(TypeCase::Action::YOU, false);
    }
    /*!
     * \brief initNonElements initilize attributes of Element_Text or Action
     */
    inline void initNonElements(){
        this->attributes.insert_or_assign(TypeCase::Action::STOP, false);
        this->attributes.insert_or_assign(TypeCase::Action::PUSH, true);
        this->attributes.insert_or_assign(TypeCase::Action::SINK, false);
        this->attributes.insert_or_assign(TypeCase::Action::WIN, false);
        this->attributes.insert_or_assign(TypeCase::Action::KILL, false);
        this->attributes.insert_or_assign(TypeCase::Action::YOU, false);
    }

public:
    inline TypeCase(Element el){
        initElements();
        this->el = el;
        this->tp = el;
    }
    inline TypeCase(Element_Text elt){
        initNonElements();
        this->el_text = elt;
        this->tp = elt;
    }
    inline TypeCase(Connector conn){
        initNonElements();
        this->conn = conn;
        this->tp = conn;
    }
    inline TypeCase(Action act){
        initNonElements();
        this->act = act;
        this->tp = act;
    }

    inline bool operator==(TypeCase& other){
        return this->tp == other.tp;
    }
    /*!
     * \brief isPlayer verifies that the player is alive
     * \return true if the player is alive, false otherwise
     */
    inline bool isPlayer(){
        return this->attributes.contains(TypeCase::YOU);
    }
    /*!
     * \brief isGameWin verifies that the game is win
     * \return true if the game is win, false otherwise
     */
    inline bool isGameWin(){
        return this->attributes.contains(TypeCase::WIN);
}
    /*!
     * \brief isElement verifies that a  TypeCase::Element type is in tp
     * \return true if TypeCase::Element is in, false otherwise
     */
    inline bool isElement(){
        return (tp >= 0 && tp < 10);
    }
    /*!
     * \brief isElement_Text verifies that a  TypeCase::Element_text  type is in tp
     * \return true if TypeCase::Element_Text is in, false otherwise
     */
    inline bool isElement_Text(){
        return (tp >= 10 && tp < 20);
    }
    /*!
     * \brief isConnector verifies that a  TypeCase::Connector  type is in tp
     * \return true if TypeCase::Connector is in, false otherwise
     */
    inline bool isConnector(){
        return (tp == TypeCase::Connector::IS);
    }
    /*!
     * \brief isAction verifies that a  TypeCase::Action  type is in tp
     * \return true if TypeCase::Action is in, false otherwise
     */
    inline bool isAction(){
        return (tp >= 30 && tp < 40 );
    }
    /*!
     * \brief isPlayer verifies that a  TypeCase::Action::stop type is in the attributes
     * \return true if TypeCase::Action::STOP is in, false otherwise
     */
    inline bool isAttrStop(){
        return this->attributes.find(TypeCase::Action::STOP)->second;
    }
    /*!
     * \brief isAttrYou verifies that a  TypeCase::Action::YOU type is in the attributes
     * \return true if TypeCase::Action::YOU is in, false otherwise
     */
    inline bool isAttrYou(){
        return this->attributes.find(TypeCase::Action::YOU)->second;
    }
    /*!
     * \brief isAttrPush verifies that a  TypeCase::Action::PUSH type is in the attributes
     * \return true if TypeCase::Action::PUSH is in, false otherwise
     */
    inline bool isAttrPush(){
        return this->attributes.find(TypeCase::Action::PUSH)->second;
    }
    /*!
     * \brief isAttrSink verifies that a  TypeCase::Action::SINK type is in the attributes
     * \return true if TypeCase::Action::SINK is in, false otherwise
     */
    inline bool isAttrSink(){
        return this->attributes.find(TypeCase::Action::SINK)->second;
    }
    /*!
     * \brief isAttrKill verifies that a  TypeCase::Action::KILL type is in the attributes
     * \return true if TypeCase::Action::KILL is in, false otherwise
     */
    inline bool isAttrKill(){
        return this->attributes.find(TypeCase::Action::KILL)->second;
    }
    /*!
     * \brief isAttrWin verifies that a  TypeCase::Action::WIN type is in the attributes
     * \return true if TypeCase::Action::WIN is in, false otherwise
     */
    inline bool isAttrWin(){
        return this->attributes.find(TypeCase::Action::WIN)->second;
    }
    /*!
     * \brief isBaba verifies that a type is a TypeCase::BABA type
     * \return return true if the type is TypeCase is TypeCase::BABA, false otherwise
     */
    inline bool isBaba(){
        return(el == TypeCase::BABA);
    }
    /*!
     * \brief isWater verifies that a type is a TypeCase::WATER type
     * \return return true if the type is TypeCase is TypeCase::WATER, false otherwise
     */
    inline bool isWater(){
        return(el == TypeCase::WATER);
    }
    /*!
     * \brief isWall verifies that a type is a TypeCase::WALL type
     * \return return true if the type is TypeCase is TypeCase::WALL, false otherwise
     */
    inline bool isWall(){
        return(el == TypeCase::WALL);
    }
    /*!
     * \brief isMetal verifies that a type is a TypeCase::METAL type
     * \return return true if the type is TypeCase is TypeCase::METAL, false otherwise
     */
    inline bool isMetal(){
        return(el == TypeCase::METAL);
    }
    /*!
     * \brief isGrass verifies that a type is a TypeCase::GRASS type
     * \return return true if the type is TypeCase is TypeCase::GRASS, false otherwise
     */
    inline bool isGrass(){
        return(el == TypeCase::GRASS);
    }
    /*!
     * \brief isRock verifies that a type is a TypeCase::ROCK type
     * \return return true if the type is TypeCase is TypeCase::ROCK, false otherwise
     */
    inline bool isRock(){
        return(el == TypeCase::ROCK);
    }
    /*!
     * \brief isFlag verifies that a type is a TypeCase::FLAG type
     * \return return true if the type is TypeCase is TypeCase::FLAG, false otherwise
     */
    inline bool isFlag(){
        return(el == TypeCase::FLAG);
    }

    /*!
     * \brief isLava verifies that a type is a TypeCase::LAVA type
     * \return return true if the type is TypeCase is TypeCase::LAVA, false otherwise
     */
    inline bool isLava(){
        return(el == TypeCase::LAVA);
    }
    /*!
     * \brief isBabaText verifies that a type is a TypeCase::BABA_TEXT type
     * \return return true if the type is TypeCase is TypeCase::BABA_TEXT, false otherwise
     */
    inline bool isBabaText(){
        return(el_text == TypeCase::BABA_TEXT);
    };
    /*!
     * \brief isWaterText verifies that a type is a TypeCase::WATER_TEXT type
     * \return return true if the type is TypeCase is TypeCase::WATER_TEXT, false otherwise
     */
    inline bool isWaterText(){
        return(el_text == TypeCase::WATER_TEXT);
    };
    /*!
     * \brief isWallText verifies that a type is a TypeCase::WALL_TEXT type
     * \return return true if the type is TypeCase is TypeCase::WALL_TEXT, false otherwise
     */
    inline bool isWallText(){
        return(el_text == TypeCase::WALL_TEXT);;
    }

    /*!
     * \brief isWallText verifies that a type is a TypeCase::LAVA_TEXT type
     * \return return true if the type is TypeCase is TypeCase::LAVA_TEXT, false otherwise
     */
    inline bool isLavaText(){
        return(el_text == TypeCase::LAVA_TEXT);;
    }

    /*!
     * \brief isGrassText verifies that a type is a TypeCase::GRASS_TEXT type
     * \return return true if the type is TypeCase is TypeCase::GRASS_TEXT, false otherwise
     */
    bool isGrassText(){
        return(el_text == TypeCase::GRASS_TEXT);
    };
    /*!
     * \brief isFlagText verifies that a type is a TypeCase::FLAG_TEXT type
     * \return return true if the type is TypeCase is TypeCase::FLAG_TEXT, false otherwise
     */
    inline bool isFlagText(){
        return(el_text == TypeCase::FLAG_TEXT);
    };
    /*!
     * \brief isRockText verifies that a type is a TypeCase::ROCK_TEXT type
     * \return return true if the type is TypeCase is TypeCase::ROCK_TEXT, false otherwise
     */
    inline bool isRockText(){
        return(el_text == TypeCase::ROCK_TEXT);
    };
    /*!
     * \brief isMetalText verifies that a type is a TypeCase::METAL_TEXT type
     * \return return true if the type is TypeCase is TypeCase::METAL_TEXT, false otherwise
     */
    inline bool isMetalText(){
        return(el_text == TypeCase::METAL_TEXT);
    };


    /*!
     * \brief isPush verifies that a type is a TypeCase::PUSH type
     * \return return true if the type is TypeCase is TypeCase::PUSH, false otherwise
     */
    inline bool isPush(){
        return(act == TypeCase::PUSH);
    };

    /*!
     * \brief isPush verifies that a type is a TypeCase::PUSH type
     * \return return true if the type is TypeCase is TypeCase::PUSH, false otherwise
     */
    inline bool isSink(){
        return(act == TypeCase::SINK);
    };

    /*!
     * \brief isPush verifies that a type is a TypeCase::PUSH type
     * \return return true if the type is TypeCase is TypeCase::PUSH, false otherwise
     */
    inline bool isYou(){
        return(act == TypeCase::YOU);
    };

    /*!
     * \brief isPush verifies that a type is a TypeCase::PUSH type
     * \return return true if the type is TypeCase is TypeCase::PUSH, false otherwise
     */
    inline bool isStop(){
        return(act == TypeCase::STOP);
    };
    /*!
     * \brief isWin verifies that a type is a TypeCase::WIN type
     * \return return true if the type is TypeCase is TypeCase::WIN, false otherwise
     */
    inline bool isWin(){
        return(act == TypeCase::WIN);
    };

    /*!
     * \brief isKill verifies that a type is a TypeCase::KILL type
     * \return return true if the type is TypeCase is TypeCase::KILL, false otherwise
     */
    inline bool isKill(){
        return(act == TypeCase::KILL);
    };

    /*!
     * \brief changeAttr. Change the attribute of a TypeCase
     * \param attribut. One of TypeCase::Action
     * \param active. boolean
     */
    inline void changeAttr(Action attribut, bool active){
        this->attributes.find(attribut)->second = active;
    }
    /*!
     * \brief getElement getter for the attribute el
     * \return a TypeCase::Element
     */
    inline Element getElement(){
        return this->el;
    }
    /*!
     * \brief getElement_Text getter for the attribute el_text
     * \return a TypeCase::Element_Text
     */
    inline Element_Text getElement_Text(){
        return this->el_text;
    }
    /*!
     * \brief getAction getter for the attribute act
     * \return a TypeCase::Action
     */
    inline Action getAction(){
        return this->act;
    }
    /*!
     * \brief getConnector getter for the attribute conn
     * \return a TypeCase::Connector
     */
    inline Connector getConnector(){
        return this->conn;
    }
    /*!
     * \brief getAttributes getter for attributes
     * \return
     */
    inline map<TypeCase::Action,bool> & getAttributes(){
        return this->attributes;
    }
    /*!
     * \brief setAttributes setter for attributes
     * \param map a map of TypeCase::action with boolean
     */
    inline void setAttributes(map<TypeCase::Action,bool> & map){
        this->attributes.clear();
        this->attributes = map;
    }
    inline bool equals(TypeCase tc){
        if(*this == tc){
            return true;
        }
        return false;
    }

};

#endif // TYPECASE_H
