/** 
 *  The player class
 */


#ifndef PLAYER__H
#define PLAYER__H

#include <SFML/Graphics.hpp>

class Player
{
    public:

    int x;
    int y;

    /**
     *  Constructor
     */
    Player(int x, int y);


    /**
     *  Draw method
     */
    void draw(sf::RenderWindow& window);
};

#endif
