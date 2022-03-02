/**
 *  Implementation file of the player
 */

#include <player.hpp>
#include <SFML/Graphics.hpp>

Player::Player(int x, int y) {
    
    // store variables
    this->x = x;
    this->y = y;
};

/** 
 *  Method to draw the player
 */
void Player::draw(sf::RenderWindow& window){

    // create small rectangle for the player
    sf::RectangleShape rectangle(sf::Vector2f(10, 10));

    // set the correct position
    rectangle.setPosition(this->x, this->y);
    rectangle.setFillColor(sf::Color(255, 255, 0));


    // draw the rectangle
    window.draw(rectangle);
};