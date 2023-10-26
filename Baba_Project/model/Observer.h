#ifndef OBSERVER_H
#define OBSERVER_H
#include "TypeCase.h"
/*!
 * \brief The Observer class represents the class Observer of the design pattern Observable-Observer
 */
class Observer {
public:
    /*!
     * \brief update the attribute of the model
     * \param element Enumeration from TypeCase::Element
     * \param act Enumeration from TypeCase::Action
     * \param b boolean
     */
    virtual void update(TypeCase::Element element, TypeCase::Action act, bool b) = 0;

    virtual ~Observer(){}
};

#endif // OBSERVER_H
