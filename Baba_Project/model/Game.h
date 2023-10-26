#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Subject.h"
#include "Facade.h"//facade doit contenir une instance de Game pour pouvoir accéder à ses méthodes + en ajouter qqes une qui nous faciliterais la tache
/*!
 * \brief The Game class represents a game in progress
 */
class Game : public Subject, public Facade{
private :
    Board board;
    std::vector<Observer *> observers;
    Position::Direction North {0,-1};
    Position::Direction South {0,1};
    Position::Direction East {1,0};
    Position::Direction West {-1,0};
    unsigned level {0};

public:
    /*!
     * \brief Game the constructor of the Game class
     */
    Game();
    /*!
     * \brief start start the game and initialise the attribute of the model
     */
    void start() override;
    /*!
     * \brief setUpRules Checks the board for rules and set them up
     */
    void setUpRules() override;
    /*!
     * \brief nextLevel pass to the next level
     */
    void nextLevel() override;
    /*!
     * \brief loadLevel load a level
     * \param lvl a level
     */
    void loadLevel(string lvl) override;
    /*!
     * \brief move move the player in a direction
     * \param pos1 the starting position
     * \param pos2 the position to reach
     */
    void move(TypeCase element, Position pos1,Position pos2) override;
    /*!
     * \brief isLevelWon
     * \return a boolean if the game is win, false otherwise
     */
    bool isLevelWon(Position pos) override;
    /*!
     * \brief isLevelLost
     * \return a boolean if the game is lost, false otherwise
     */
    bool isLevelLost() override;
    /*!
      * \brief Using both position, will check if rules have been broken/created
      * \param pos1 original Position
      * \param pos2 new Position
      */
    void ruleUpdate(Position pos1, Position pos2) override;

    /*!
     * \brief notifyObservers notify the subject(TypeCase of type Element) with the attribute
     * \param string1 a string
     * \param string2 a string
     * \param b a boolean
     */
    void notifyObservers(TypeCase::Element element, TypeCase::Action act, bool b) override;
    /*!
    * \brief addObserver add an Observer to the vector of Observer
    * \param obs an Observer
    */
    void addObserver(Observer* obs) override;
    /*!
     * \brief getBoard getter for the attribute board
     * \return board an object Board
     */
    Board& getBoard()override;
    /*!
     * \brief getBoardSize getter for the size of the attribute board
     * \return an integer for the size of the board
     */
    int getBoardSize()override;
    /*!
     * \brief isCurrentPlayer find and return the TypeCase which represents the player
     * \return a TypeCase representing the player
     */
    TypeCase::Element isCurrentPlayer()override;
    /*!
     * \brief isTypeCase
     * \param tc
     * \param pos
     * \return
     */
    bool isTypeCase(TypeCase tc, Position pos)override;
    /*!
     * \brief positionsTypeList return a vector of all positions of Square containing a TypeCase
     * \param tc a TypeCase
     * \return a vector of Position
     */
    std::vector<Position> positionsTypeList(TypeCase tc)override;


    /*!
     * \brief getSquare Get the Square at given position
     * \param pos a Position
     * \return Square
     */
    inline Square* getSquare(Position pos) override{
        return this->board.getSquare(pos);
    }
    /*!
     * \brief save save the current level in a file
     */
    void save()override;

    ~Game();

private:
    /*!
     * \brief getElement Get the Element corresponding at the Element_Text
     * \param elt a TypeCase::Element_Text
     * \return a TypeCase::Element_Text
     */
    TypeCase::Element getElement(TypeCase::Element_Text elt);
};

#endif // GAME_H
