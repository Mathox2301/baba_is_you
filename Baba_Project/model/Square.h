#ifndef SQUARE_H
#define SQUARE_H

#include "Position.h"
#include "Observer.h"
#include <vector>
#include <iostream>

/*!
 * \brief The Square class represents a square of the board of the game
 */
class Square: public Observer{
private:
    Position pos{0,0};      //nécessaire?
    std::vector<TypeCase> caseList {};

 public:
    Square();
    /*!
     * \brief Square the constructor of the Square class
     * \param pos a Position
     */
    Square(Position pos);

   /*!
    * \brief update update the attribute of the model
    * \param element a string representing an Element
    * \param attribut a string representing an Action
    * \param active a boolean representing if the Action is enable or not
    */
   void update(TypeCase::Element element, TypeCase::Action act, bool active) override;

   /*!
    *
    * \brief isPlayer look if the current Square contains TypeCase::YOU
    * \return true if Square contains YOU, false otherwise
    */
   bool isPlayer();

   /*!
    * \brief isGameWin look if the current Square contains TypeCase::YOU and TypeCase::WIN
    * \return true if Square contains YOU and WIN, false otherwise
    */
   bool isGameWin();
   /*!
    * \brief isFlag look if the current Square contains TypeCase FLAG
    * \return true if Square contains FLAG, false otherwise
    */
   bool isFlag();
   /*!
    * \brief isWater look if the current Square contains the TypeCase WATER
    * \return true if Square contains WATER, false otherwise
    */
   bool isWater();
   /*!
    * \brief isRock look if the current Square contains the TypeCase ROCK
    * \return true if Square contains ROCK, false otherwise
    */
   bool isRock();
   /*!
    * \brief isGrass look if the current Square contains the TypeCase GRASS
    * \return true if Square contains GRASS, false otherwise
    */
   bool isGrass();
   /*!
    * \brief isMetal look if the current Square contains the TypeCase METAL
    * \return true if Square contains METAL, false otherwise
    */
   bool isMetal();
   /*!
    * \brief isBaba look if the current Square contains the TypeCase BABA
    * \return true if Square contains ROCK, false otherwise
    */
   bool isBaba();
   /*!
    * \brief isWall look if the current Square contains the TypeCase WALL
    * \return true if Square contains WALL, false otherwise
    */
   bool isWall();

   /*!
    * \brief isLava look if the current Square contains the TypeCase LAVA
    * \return true if Square contains LAVA, false otherwise
    */
   bool isLava();

   /*!
    * \brief isElement_Text look if the current Square contains a type of case from the enum class Element_Text
    * \return true if Square contains an Element_Text, false otherwise
    */
   bool isElement_Text();
   /*!
    * \brief isBabaText look if the current Square contains the TypeCase BABA_TEXT
    * \return true if the Square contains the TypeCase::Element_Text::BABA_TEXT,false otherwise
    */
   bool isBabaText();
   /*!
    * \brief isWaterText look if the current Square contains the TypeCase WATER_TEXT
    * \return true if the Square contains the TypeCase::Element_Text::WATER_TEXT,false otherwise
    */
   bool isWaterText();
   /*!
    * \brief isWallText look if the current Square contains the TypeCase WALL_TEXT
    * \return true if the Square contains the TypeCase::Element_Text::WALL_TEXT,false otherwise
    */
   bool isWallText();
   /*!
    * \brief isGrassText look if the current Square contains the TypeCase GRASS_TEXT
    * \return true if the Square contains the TypeCase::Element_Text::GRASS_TEXT,false otherwise
    */
   bool isGrassText();
   /*!
    * \brief isFlagText look if the current Square contains the TypeCase FLAG_TEXT
    * \return true if the Square contains the TypeCase::Element_Text::FLAG_TEXT,false otherwise
    */
   bool isFlagText();
   /*!
    * \brief isRockText look if the current Square contains the TypeCase ROCK_TEXT
    * \return true if the Square contains the TypeCase::Element_Text::ROCK_TEXT,false otherwise
    */
   bool isRockText();
   /*!
    * \brief isMetalText look if the current Square contains the TypeCase METAL_TEXT
    * \return true if the Square contains the TypeCase::Element_Text::METAL_TEXT,false otherwise
    */
   bool isMetalText();
   /*!
    * \brief isLavaText look if the current Square contains the TypeCase LAVA_TEXT
    * \return true if the Square contains the TypeCase::Element_Text::LAVA_TEXT,false otherwise
    */
   bool isLavaText();
   /*!
    * \brief isPush look if the current Square contains the TypeCase PUSH
    * \return true if the Square contains the TypeCase::Action::PUSH,false otherwise
    */
   bool isPush();
   /*!
    * \brief isWin look if the current Square contains the TypeCase WIN
    * \return true if the Square contains the TypeCase::Action::WIN,false otherwise
    */
   bool isWin();
   /*!
    * \brief isStop look if the current Square contains the TypeCase STOP
    * \return true if the Square contains the TypeCase::Action::STOP,false otherwise
    */
   bool isStop();
   /*!
    * \brief isSink look if the current Square contains the TypeCase SINK
    * \return true if the Square contains the TypeCase::Action::SINK,false otherwise
    */
   bool isSink();
   /*!
    * \brief isYou look if the current Square contains the TypeCase YOU
    * \return true if the Square contains the TypeCase::Action::YOU,false otherwise
    */
   bool isYou();
   /*!
    * \brief isKill look if the current Square contains the TypeCase KILL
    * \return true if the Square contains the TypeCase::Action::KILL,false otherwise
    */
   bool isKill();

   /*!
    * \brief isConnector look if the current Square contains a type of case from the enum Connector
    * \return true if Square contains a Connector, false otherwise
    */
   bool isConnector();
   /*!
    * \brief isAction look if the current Square contains a type of case from the enum Action
    * \return true if Square contains an Action, false otherwise
    */
   bool isAction();

   /*!
    * \brief isElement look if the current Square contains a type of case from the enum Element
    * \return true if Square contains an Element, false otherwise
    */
   bool isElement();

   /*!
    * \brief getElement_text getter for TypeCase::Element_Text
    * \return TypeCase::Element_Text
    */
   TypeCase::Element_Text getElement_Text();

   /*!
    * \brief getAction getter for TypeCase::Action
    * \return TypeCase::Action
    */
   TypeCase::Action getAction();

   /*!
    * \brief addTypeCase. Add a type of case (TypeCase) to the Square
    * \param tp. A type of case (TypeCase)
    */
   void addTypeCase(TypeCase tp);

   /*!
    * \brief removeTypeCase. Remove a type of case (TypeCase) from the Square
    * \param tp. A type of case (TypeCase)
    */
   void removeTypeCase(TypeCase tp);

   /*!
    * \brief getCaseList getter for caseList
    * \return a vector of TypeCase containing the the TypeCase(s) currently on the Square
    */
   std::vector<TypeCase>& getCaseList();

   /*!
    * \brief getPosition getter for pos
    * \return the Position of the Square
    */
   Position getPosition();      //unused?

   /*!
    * \brief isAttrPush Checks if this Square contains a TypeCase that has the attribute PUSH
    * \return bool
    */
   inline bool isAttrPush(){
       for (unsigned var = 0; var < caseList.size(); ++var) {
           if(caseList.at(var).isAttrPush()){
               return true;
           }
       }
       return false;
   }

   /*!
    *\brief isAttrWin Checks if this Square contains a TypeCase that has the attribute WIN
    * \return bool
    */
   inline bool isAttrWin(){
       for (unsigned var = 0; var < caseList.size(); ++var) {
           if(caseList.at(var).isAttrWin()){
               return true;
           }
       }
       return false;
   }

   /**
    * @brief isAttrStop Checks if this Square contains a TypeCase that has the attribute STOP
    * @return bool
    */
   inline bool isAttrStop(){
       for (unsigned var = 0; var < caseList.size(); ++var) {
           if(caseList.at(var).isAttrStop()){
               return true;
           }
       }
       return false;
   }

   /*!
    * \brief isAttrSink Checks if this Square contains a TypeCase that has the attribute SINK
    * \return bool
    */
   inline bool isAttrSink(){
       for (unsigned var = 0; var < caseList.size(); ++var) {
           if(caseList.at(var).isAttrSink()){
               return true;
           }
       }
       return false;
   }

   /*!
    * \brief isAttrYou Checks if this Square contains a TypeCase that has the attribute YOU
    * \return bool
    */
   inline bool isAttrYou(){
       for (unsigned var = 0; var < caseList.size(); ++var) {
           if(caseList.at(var).isAttrYou()){
               return true;
           }
       }
       return false;
   }

   /*!
    * \brief isAttrKill Checks if this Square contains a TypeCase that has the attribute KILL
    * \return bool
    */
   inline bool isAttrKill(){
       for (unsigned var = 0; var < caseList.size(); ++var) {
           if(caseList.at(var).isAttrKill()){
               return true;
           }
       }
       return false;
   }

   /**
    * @brief isAttrNone Checks if the Square cointains no attributes
    * @return bool
    */
   inline bool isAttrNone(){
       for (unsigned var = 0; var < caseList.size(); ++var) {
           if(caseList.at(var).isAttrKill() || caseList.at(var).isAttrPush() || caseList.at(var).isAttrSink()
                   || caseList.at(var).isAttrStop() || caseList.at(var).isAttrWin() || caseList.at(var).isAttrYou()){
               return false;
           }
       }
       return true;
   }

   TypeCase getFirstElement();

   ~Square();
};

#endif // SQUARE_H
