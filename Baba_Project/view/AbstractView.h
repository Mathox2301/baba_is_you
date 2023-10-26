#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

class AbstractView{
private:

public:
    /*!
     * \brief displayLevel display the level on a terminal
     */
    virtual void displayLevel() = 0;
//    /*!
//     * \brief askDeplacement ask the user for a deplacement
//     */
//    virtual void askDeplacement() = 0;


};
#endif // ABSTRACTVIEW_H
