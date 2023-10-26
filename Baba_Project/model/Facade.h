#ifndef FACADE_H
#define FACADE_H
#include "Board.h"
#include "Position.h"
#include "TypeCase.h"
#include "Square.h"
/*!
 * \brief The Facade class represents the design pattern Façade of the game
 */
class Facade {
public :
    /*!
     * \brief start start the game and initialise the attribute of the model
     */
    virtual void start() = 0;
    /*!
     * \brief nextLevel pass to the next level
     */

    virtual void setUpRules() = 0;
    /*!
     * \brief nextLevel pass to the next level
     */
    virtual void nextLevel() = 0;
    /*!
     * \brief loadLevel load a level
     * \param lvl a level
     */
    virtual void loadLevel(string lvl)=0;
    /*!
     * \brief move move the player in a direction
     * \param pos1 the starting position
     * \param pos2 the position to reach
     */
    virtual void move(TypeCase element, Position pos1, Position pos2) = 0;
    /*!
     * \brief isLevelWon
     * \return a boolean if the game is win, false otherwise
     */
    virtual bool isLevelWon(Position pos) = 0;
    /*!
     * \brief isLevelLost
     * \return a boolean if the game is lost, false otherwise
     */
    virtual bool isLevelLost() = 0;

    /*!
     * \brief ruleUpdate: Check if a rule was broken at pos1 / created at pos2 and update the Squares accordingly
     * \param pos1 Position
     * \param pos2 Position
     */
    virtual void ruleUpdate(Position pos1, Position pos2) = 0;

    /*!
     * \brief getBoard getter for the attribute board
     * \return board an object Board
     */
    virtual Board& getBoard()=0;
    /*!
     * \brief getBoardSize getter for the size of the attribute board
     * \return an integer for the size of the board
     */
    virtual int getBoardSize()=0;
    /*!
     * \brief isCurrentPlayer find and return the TypeCase which represents the player
     * \return a TypeCase representing the player
     */
   virtual TypeCase::Element isCurrentPlayer()=0;
    /*!
     * \brief isTypeCase
     * \param tc
     * \param pos
     * \return
     */
    virtual bool isTypeCase(TypeCase tc, Position pos)=0;
    /*!
     * \brief positionsTypeList return a vector of all positions of Square containing a TypeCase
     * \param tc a TypeCase
     * \return a vector of Position
     */
    virtual std::vector<Position> positionsTypeList(TypeCase tc)=0;

    /*!
     * \brief getSquare Get the Square at given position
     * \param pos a Position
     * \return Square
     */
    virtual Square* getSquare(Position pos) = 0;

    /*!
     * \brief save save the current level in a file
     */
    virtual void save()=0;
    /*!
     * \brief getLvlDimension
     * \return an integer representing the length and the width of the game
     */

    virtual ~Facade(){}


};

#endif // FACADE_H
