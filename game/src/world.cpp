/**
 *  Implementation file of the player
 */

#include <world.hpp>
#include <SFML/Graphics.hpp>

World::World() {
    
};

/** 
 *  Method to draw the world
 */
void World::draw(sf::RenderWindow& window){

    // loop over world dimensions
    int x,y,xo,yo;
    for (y=0; y<this->height; y++){
        for (x=0; x<this->width; x++){
            
            // initialize a rectangle shape
            sf::RectangleShape rectangle(sf::Vector2f(this->blockSize-1, this->blockSize-1));

            // set posiiton
            // xo = x*blockSize; yo = y*blockSize;
            rectangle.setPosition(x*blockSize, y*blockSize);

            // draw the walls and background
            if (this->map[y*width+x] == 1) rectangle.setFillColor(sf::Color(255, 255, 255));             
            else rectangle.setFillColor(sf::Color(0, 0, 0));

            // draw the rectangle
            window.draw(rectangle);
        }
    }
};