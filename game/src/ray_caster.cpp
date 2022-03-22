
#include <math.h>
#include <ray_caster.hpp>
#include <SFML/Graphics.hpp>
#include <player.hpp>
#include <world.hpp>
#include <iostream>

#define PI 3.1415926535
#define P2 PI/2
#define P3 3*PI/2
#define DR 0.0174533

/**
 *  Method to cast a set of rays from the player's FOV
 */
std::vector<Ray> castRays(Player player, World world) {

    // initialize variables
    int r, mx, my, mp, dof; float rx, ry, ra, xo, yo;

    // extract player variables
    float pa = player.angle;
    float px = player.x;
    float py = player.y;

    // ray angle is the player angle
    ra = pa;

    // initialize vector of rays
    std::vector<Ray> rays;

    // define starting ray
    int numRays = 360;
    ra = pa - DR * numRays;
    if (ra < 0) { ra += 2*PI; } if (ra>2*PI) {ra -= 2*PI;} // set ray limits

    for (r=0; r<numRays; r++){
        
        /**
         *  Check horizontal lines
         */
        dof = 0;
        float disH=1000000, hx=px, hy=py;
        float aTan=-1/tan(ra);

        // looking up
        if (ra>PI) { 
            ry=(((int)py>>6)<<6) - 0.0001;  // the bit shift equals /64 and *64
            rx=(py-ry)*aTan+px;
            yo = -world.blockSize; // world block size
            xo = -yo*aTan;
        }

        // looking down
        if (ra<PI) { 
            ry=(((int)py>>6)<<6) + 64; 
            rx=(py-ry)*aTan+px;
            yo = world.blockSize; // world block size
            xo = -yo*aTan;
        }

        // straight left or right
        if (ra==0 || ra==PI) { rx=px; ry=py; dof=8; }

        while (dof<8){
            mx=(int) (rx)>>6; my=(int) (ry)>>6; mp=my*world.height+mx; 
            if(mp > 0 && mp<world.height*world.width && world.map[mp] == 1) { 
                hx = rx;    
                hy = ry;
                disH = dist(px,py,hx,hy,ra);
                dof=8; 
            } // wall hit

            else {
                rx+=xo; ry+=yo; dof+=1; // next line
            }
        }

        /**
         *  Check Vertical lines
         */
        dof = 0;
        float disV=1000000, vx=px, vy=py;
        float nTan=-tan(ra);

        // looking left
        if (ra>P2 && ra<P3) { 
            rx=(((int)px>>6)<<6) - 0.0001;  // the bit shift equals /64 and *64
            ry=(px-rx)*nTan+py;
            xo = -world.blockSize; // world block size
            yo = -xo*nTan;
        }

        // looking right
        if (ra<P2 || ra>P3) { 
            rx=(((int)px>>6)<<6) + 64; 
            ry=(px-rx)*nTan+py;
            xo = world.blockSize; // world block size
            yo = -xo*nTan;
        }

        // straight up or down
        if (ra==0 || ra==PI) { rx=px; ry=py; dof=8; }

        while (dof<8){
            mx=(int) (rx)>>6; my=(int) (ry)>>6; mp=my*world.height+mx; 
            if(mp > 0 && mp<world.height*world.width && world.map[mp] == 1) { 
                vx = rx;    
                vy = ry;
                disV = dist(px,py,vx,vy,ra);
                dof=8; 
            } // wall hit

            else {
                rx+=xo; ry+=yo; dof+=1; // next line
            }
        }

        // get shortest ray
        if (disV<disH) { rx=vx; ry=vy; }
        if (disH<disV) { rx=hx; ry=hy; }
        
        // create Ray
        Ray ray = { 
            .x = rx,
            .y = ry,
        };  

        // add ray to vector
        rays.push_back(ray);

        // shift ray by one degree for next loop
        ra += DR;
        if (ra < 0) { ra += 2*PI; } if (ra>2*PI) {ra -= 2*PI;} // set ray limits
    }

    // return the rays
    return rays;
};

/**
 *  Method to calculate distance using Pythagoras
 */
float dist(float ax, float ay, float bx, float by, float ang)
{
    return ( sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)) );
}

void drawRays(sf::RenderWindow& window, std::vector<Ray> rays, float px, float py) {

    // loop over rays
    for (const auto& ray: rays) {

        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(px + 5, py + 5), sf::Color::Green),
            sf::Vertex(sf::Vector2f(ray.x, ray.y), sf::Color::Green)
        };

        window.draw(line, 2, sf::Lines);
    }

}