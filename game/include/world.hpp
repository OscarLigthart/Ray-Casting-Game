/** 
 *  The player class
 */


#ifndef WORLD__H
#define WORLD__H

#include <SFML/Graphics.hpp>

class World
{
    public:

    // parameters
    int height = 8;
    int width = 8;
    int blockSize = 64;

    // map
    int map[64] = {
        1,1,1,1,1,1,1,1,
        1,0,1,0,0,0,0,1,
        1,0,1,0,0,1,0,1,
        1,0,0,0,0,1,0,1,
        1,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,1,
        1,0,1,0,0,0,0,1,
        1,1,1,1,1,1,1,1,
    };

    /**
     *  Constructor
     */
    World();

    /**
     *  Draw method
     */
    void draw(sf::RenderWindow& window);
};

#endif
