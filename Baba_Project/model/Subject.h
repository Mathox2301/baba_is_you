#ifndef SUBJECT_H
#define SUBJECT_H
#include "Observer.h"
#include "TypeCase.h"
#include <vector>
/*!
 * \brief The Subject class represents the class Observable of the design pattern Observable-Observer
 */
class Subject {
private :
    std::vector<Observer *> observers;
public :
    /*!
     * \brief notifyObservers notify the view with the attribute of the model
     * \param string1 a string
     * \param string2 a string
     * \param b a boolean
     */
    virtual void notifyObservers(TypeCase::Element element, TypeCase::Action act, bool b) = 0;
    /*!
     * \brief notifyObservers notify the game that a rule has moved
     * \param pos1 original Position
     * \param pos2 new Position
     */
    /*!
    * \brief addObserver add an Observer to the vector of Observer
    * \param obs an Observer
    */
    virtual void addObserver(Observer* obs) = 0;

    virtual ~Subject(){}
};

#endif // SUBJECT_H
