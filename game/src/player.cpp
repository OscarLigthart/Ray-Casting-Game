/**
 *  Implementation file of the player
 */

#include <player.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>

#define PI 3.1415926535

Player::Player(float x, float y) {
    
    // store variables
    this->x = x;
    this->y = y;

    // calculate dx and dy
    this->dx = cos(this->angle)*5;
    this->dy = sin(this->angle)*5;
};

/**
 *  Movement functions
 */
void Player::left(){
    this->angle -= 0.1; 
    if(this->angle < 0) {this->angle+=2*PI;}
    this->dx = cos(this->angle)*5;
    this->dy = sin(this->angle)*5;
};

void Player::right(){
    this->angle += 0.1; 
    if(this->angle > 2*PI) {this->angle-=2*PI;}
    this->dx = cos(this->angle)*5;
    this->dy = sin(this->angle)*5;
};

void Player::forward(){
    this->x += this->dx;
    this->y += this->dy;
};

void Player::backward(){
    this->x -= this->dx;
    this->y -= this->dy;
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

    // create line to show direction
    sf::RectangleShape line(sf::Vector2f(15, 2));
    line.setPosition(this->x + 5, this->y + 5);
    line.setFillColor(sf::Color(255, 255, 0));

    // rotate in degrees
    line.rotate(this->angle * 180/PI);
    window.draw(line);
};