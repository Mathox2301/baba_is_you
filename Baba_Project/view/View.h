#ifndef VIEW_H
#define VIEW_H
#include "../model/Game.h"
#include "AbstractView.h"
#include "../controller/Controller.h"

/*!
 * \brief The View class represents the View of the Game
 *
 */
class View : public AbstractView{
private:
    Game& game;
    Controller& c;
public:
    View(Game& game, Controller& c);
    /*!
     * \brief displayLevel display the level on a terminal
     */
    void displayLevel() override;

    /*!
     * \brief start the game
     */
    void start();

//    /*!
//     * \brief askDeplacement ask the user for a deplacement
//     */
//    void askDeplacement();

};

#endif // VIEW_H
