/** 
 *  The ray caster functions
 */


#ifndef RAY_CASTER__H
#define RAY_CASTER_H

#include <SFML/Graphics.hpp>
#include <world.hpp>
#include <player.hpp>

/**
 *  Struct for each ray to save
 */
struct Ray {
    float x;
    float y;
};

/**
 *  Method to cast rays to hit a wall
 */
std::vector<Ray> castRays(Player player, World world);

/**
 *  Method to calculate distance using Pythagoras
 */
float dist(float ax, float ay, float bx, float by, float ang);

/**
 *  Method to draw the cast rays
 */
void drawRays(sf::RenderWindow& window, std::vector<Ray> rays, float px, float py);

#endif