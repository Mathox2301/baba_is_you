#ifndef CONTROLLER_H
#define CONTROLLER_H
/*!
 * \brief The Controller class represents the controller of the game
 */
#include "../model/Game.h"

class Controller {
private :
    Game& game;
public :
    Controller(Game& game);
//    /*!
//     * \brief start start the game
//     */
//    void start();

    /*!
     *\brief isLevelLost checks if the current game is lost
     * \return bool
     */
    bool isLevelLost();
    /*!
     * \brief isLevelWin
     * \param pos the position of the player
     * \return bool
     */
    bool isLevelWin();

    /*!
     * \brief askDeplacement take input for a move in a console view
     */
    void askDeplacement();

    /*!
     * \brief moveGUI take input for a move in a GUI view
     * \param dir a string, the direction
     */
    void moveGUI(std::string dir);

};

#endif // CONTROLLER_H
