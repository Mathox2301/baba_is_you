#ifndef POSITION_H
#define POSITION_H
#include <string>
/*!
 * \brief The Position class represents a position on the board
 */
class Position {
private :
    int x;
    int y;

public:
    /*!
     * \brief Position the constructor of the Position class
     * \param x
     * \param y
     */
    Position(int x,int y);
    /*!
    * \brief Position copy constructor
    * \param other an other Position
    */
    Position(Position& other);

    Position(const Position& other);

    Position() = default;

    ~Position();
    /*!
     * \return the value of the attribute x
     */
    int getX();
    /*!
     * \return the value of the attribute y
     */
    int getY();
    /*!
     * \brief equals compare two Position and look if they are the same
     * \return true if the current Position is equals to the other, false otherwise
     */
    bool equals(const Position& other);
    Position operator+( Position direction);
    Position operator-( Position direction);



    typedef std::pair<int,int> Direction;

    Position operator+ (Direction dir);

};


#endif // POSITION_H
