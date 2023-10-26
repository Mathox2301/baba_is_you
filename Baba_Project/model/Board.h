#ifndef BOARD_H
#define BOARD_H
#include "Square.h"
#include <array>
#include <fstream>
/*!
 * \brief The Board class represents the board of the game
 */
using namespace std;
class Board {

private:
    std::vector<std::vector<Square>> board;
public:

    /*!
     * \brief Board the constructor of the Board class
     * \param size Size of the square board.
     */
    Board ();
    Board(const Board& other) : board(other.board) {
    }
    /*!
     * \brief setUp set up the Board with a given fire
     * \param file the file location
     */
    void setUp(std::string file);

    /*!
     * \brief contains Return true if the position is in the Board
     * \param pos. Position
     * \return boolean
     */
    bool contains(Position pos);

    /*!
     * \brief clear Clears the board
     */
    void clear();

    /*!
     * \brief isPlayerAlive Checks if the player is dead
     * \return true if TypeCase::BABA still exists
     */
    bool isPlayerAlive();

    /*!
     * \brief isGameWin Checks if the level has been complete
     * \param Pos. The player's Position
     * \return
     */
    bool isGameWin(Position Pos);

    /*!
     * \brief isPlayer check if the square contains the attribute YOU
     * \param pos Position
     * \return true if Square contains TypeCase::YOU, false otherwise
     */
    bool isPlayer(Position pos);

    /*!
     * \brief isFlag check if the square contains the TypeCase::FLAG
     * \param pos Position
     * \return true if Square contains TypeCase::FLAG, false otherwise
     */
    bool isFlag(Position pos);
    /*!
     * \brief isWater check if the square contains the TypeCase::WATER
     * \param pos Position
     * \return true if Square contains TypeCase::WATER, false otherwise
     */
    bool isWater(Position pos);
    /*!
     * \brief isRock check if the square contains the TypeCase::ROCK
     * \param pos Position
     * \return true if Square contains TypeCase::ROCK, false otherwise
     */
    bool isRock(Position pos);
    /*!
     * \brief isGrass check if the square contains the TypeCase::GRASS
     * \param pos Position
     * \return true if Square contains TypeCase::GRASS, false otherwise
     */
    bool isGrass(Position pos);
    /*!
     * \brief isMetal check if the square contains the TypeCase::METAL
     * \param pos Position
     * \return true if Square contains TypeCase::METAL, false otherwise
     */
    bool isMetal(Position pos);
    /*!
     * \brief isBaba check if the square contains the TypeCase::BABA
     * \param pos Position
     * \return true if Square contains TypeCase::BABA, false otherwise
     */
    bool isBaba(Position pos);
    /*!
     * \brief isWall check if the square contains the TypeCase::WALL
     * \param pos Position
     * \return true if Square contains TypeCase::WALL, false otherwise
     */
    bool isWall(Position pos);
    /*!
     * \brief isLava look if the Square at Position pos contains the TypeCase LAVA
     * \return true if Square contains TypeCase::LAVA, false otherwise
     */
    bool isLava(Position pos);
    /*!

     * \brief isElement_Text check if the square contains the TypeCase::Element_Text
     * \param pos Position
     * \return true if Square contains a TypeCase::Element_Text, false otherwise
     */
    bool isElement_Text(Position pos);
    /*!
     * \brief isConnector check if the square contains the TypeCase::Connector
     * \param pos Position
     * \return true if Square contains a TypeCase::Connector, false otherwise
     */
    bool isConnector(Position pos);
    /*!
     * \brief isAction check if the square contains the TypeCase::Actions
     * \param pos Position
     * \return true if Square contains an TypeCase::Action, false otherwise
     */
    bool isAction(Position pos);

    /*!
     * \brief getSquare getter for a square
     * \param pos Position
     * \param pos a Position
     * \return Square* the Square at given Position
     */
    Square* getSquare(Position pos);



    int getSize();
    /*!
     * \brief isBabaText look if the Square at Position pos contains the TypeCase BABA_TEXT
     * \return true if Square contains TypeCase::BABA_TEXT, false otherwise
     */
    bool isBabaText(Position pos);
    /*!
     * \brief isWaterText look if the Square at Position pos contains the TypeCase WATER_TEXT
     * \return true if Square contains TypeCase::WATER_TEXT, false otherwise
     */
    bool isWaterText(Position pos);
    /*!
     * \brief isWallText look if the Square at Position pos contains the TypeCase WALL_TEXT
     * \return true if Square contains TypeCase::WALL_TEXT, false otherwise
     */
    bool isWallText(Position pos);
    /*!
     * \brief isGrassText look if the Square at Position pos contains the TypeCase GRASS_TEXT
     * \return true if Square contains TypeCase::GRASS_TEXT, false otherwise
     */
    bool isGrassText(Position pos);
    /*!
     * \brief isFlagText look if the Square at Position pos contains the TypeCase FLAG_TEXT
     * \return true if Square contains TypeCase::FLAG_TEXT, false otherwise
     */
    bool isFlagText(Position pos);
    /*!
     * \brief isRockText look if the Square at Position pos contains the TypeCase ROCK_TEXT
     * \return true if Square contains TypeCase::ROCK_TEXT, false otherwise
     */
    bool isRockText(Position pos);
    /*!
     * \brief isMetalText look if the Square at Position pos contains the TypeCase METAL_TEXT
     * \return true if Square contains TypeCase::METAL_TEXT, false otherwise
     */
    bool isMetalText(Position pos);
    /*!
     * \brief isLavaText look if the Square at Position pos contains the TypeCase LAVA_TEXT
     * \return true if Square contains TypeCase::LAVA_TEXT, false otherwise
     */
    bool isLavaText(Position pos);
    /*!
     * \brief isPush look if the Square at Position pos contains the TypeCase PUSH
     * \return true if Square contains TypeCase::PUSH, false otherwise
     */
    bool isPush(Position pos);
    /*!
     * \brief isWin look if the Square at Position pos contains the TypeCase WIN
     * \return true if Square contains TypeCase::WIN, false otherwise
     */
    bool isWin(Position pos);
    /*!
     * \brief isStop look if the Square at Position pos contains the TypeCase STOP
     * \return true if Square contains TypeCase::STOP, false otherwise
     */
    bool isStop(Position pos);
    /*!
     * \brief isYou look if the Square at Position pos contains the TypeCase SINK
     * \return true if Square contains TypeCase::SINK, false otherwise
     */
    bool isSink(Position pos);
    /*!
     * \brief isYou look if the current Square contains the TypeCase YOU
     * \return true if Square contains TypeCase::YOU, false otherwise
     */
    bool isYou(Position pos);
    /*!
     * \brief isKill look if the Square at Position pos contains the TypeCase KILL
     * \return true if Square contains TypeCase::KILL, false otherwise
     */
    bool isKill(Position pos);
    /*!
     * \brief isElement look if the Square at Position pos contains a type of case from the enum class Element
     * \return true if Square contains TypeCase::Element, false otherwise
     */
    bool isElement(Position pos);
    void setSquare(Position pos, Square s);


};

#endif // BOARD_H
