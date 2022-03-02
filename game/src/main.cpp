#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>

#include <player.hpp>
#include <world.hpp>
#include <ray_caster.hpp>

/**
 *  Main function
 *  Here we open the SFML window to start the game
 */
int main() {
    
    // Declare and create a new render-window
    sf::RenderWindow window(sf::VideoMode(1024, 512), "Game");

    // initialize player (at location 300,300)
    Player player(300, 300);

    // initialize world
    World world;

    // parameters
    sf::Color backgroundColor(77, 77, 77, 255);

    /**
     *  The main loop
     *  As long as the window is open this code will keep running
     */
    while (window.isOpen())
    {

        // check for events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed){

                // close window
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
            }
        }

        // movement
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player.forward();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player.left();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player.backward();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player.right();

        /**
         *  Ray casting happens here
         */
        std::vector<Ray> rays = castRays(player, world);

        /**
         *  Draw everything after the calculations
         */
        // Clear the whole window before rendering a new frame
        window.clear(backgroundColor);
        
        // draw the world
        world.draw(window);

        // draw the rays
        drawRays(window, rays, player.x, player.y);

        // draw the player
        player.draw(window);

        // End the current frame and display its contents on screen
        window.display();

        // now sleep for a bit to get a specific framerate (around 60fps)
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
}
