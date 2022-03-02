/** 
 *  The player class
 */


#ifndef PLAYER__H
#define PLAYER__H

#include <SFML/Graphics.hpp>

class Player
{
    public:

    float x;
    float y;
    float dx;
    float dy;
    float angle = 0.0;

    /**
     *  Constructor
     */
    Player(float x, float y);

    // methods for movement
    void left();
    void right();
    void forward();
    void backward();


    /**
     *  Draw method
     */
    void draw(sf::RenderWindow& window);
};

#endif
