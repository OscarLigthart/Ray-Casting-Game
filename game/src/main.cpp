#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>


/**
 *  Main function
 *  Here we open the SFML window to start the game
 */
int main() {
    
    // Declare and create a new render-window
    sf::RenderWindow window(sf::VideoMode(1024, 512), "Game");

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
        }

        /**
         *  Draw the board after running all processes
         */
        // Clear the whole window before rendering a new frame
        window.clear();

        // End the current frame and display its contents on screen
        window.display();

        // now sleep for a bit to get a specific framerate (around 60fps)
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}
