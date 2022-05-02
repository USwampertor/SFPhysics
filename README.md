# The Simple Fast Physics Library for SFML

This is a basic 2D collision library for SFML.  Its is quite fast (although some future further optimizations are intended).  
It presents an API similar to SFML's API in that it is totally pointerless.  Simple games can be written with just stack allocation.

Its features and limitations are as follows:

## NUGET PACKAGE
https://www.nuget.org/packages/SFPhysics/

## FEATURES
* Fast collision detection and response.
* No internal memory allocation other then that done by library classes (e.g. list<T>)
* Pointerless API
* Hooks for responding to collisions and movement
* Collision bounds visualization (very useful for application debugging)
* Currently has prebuilt Physics SFML extensions for CircleShape, RectangleShape, Sprite and ConvexShape

## LIMITATIONS
* Only supports Circular bounds and Axis-Aligned Bounding Boxes
* Only support simple hard bodies (no joints)
* Euler integrator can miss inter-frame collisions
* Currently undocumented

## EXAMPLES
https://github.com/profK/Breakout2  

## PLANNED EXTENSIONS
* Location-bin based collision acceleration
* "Sleeping" based collision acceleration
* Documentation
  
## RELEASE NOTES
Version 1.5 has been released.  It is feature complete and passses all the tests I have for it.  The largest addition is the
collision pruning based on motion.
There still may be bugs.  And documentation is still forthcoming.

## Getting Started
1.  Create a C++ desktop project
2.  Import SFML and SFPhysics into your project.   
    The easiest way is with these nuget packages:  
    https://www.nuget.org/packages/SFPhysics/  
    https://www.nuget.org/packages/SFML_VS2019/  
3. include <SFML/Graphics.hpp>  and <SFPhysics.h> in your main file
4. Below is a "Hello Physics" example of a ball bouncing off a floor:
  
```
// HelloPhysics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

using namespace sf;
using namespace sfp;

const int WINDOWWIDTH = 800;
const int WINDOWHEIGHT = 600;

int main()
{
    PhysicsCircle circle;
    circle.setSize(Vector2f(25, 25));
    circle.setCenter(Vector2f(WINDOWWIDTH / 2, WINDOWHEIGHT / 2));

    PhysicsRectangle floor;
    floor.setSize(Vector2f(800, 20));
    floor.setCenter(Vector2f(400, 590));
    floor.getBody().setStatic(true);

    Vector2f gravity(0, 1.0);
    World world(gravity);
    world.AddPhysicsBody(circle.getBody());
    world.AddPhysicsBody(floor.getBody());

    RenderWindow window(VideoMode(WINDOWWIDTH, WINDOWHEIGHT),"Hello Physics");

    Clock clock;
    Time lastTime = clock.getElapsedTime();
    while (true) {
        Time currentTime = clock.getElapsedTime();
        unsigned long elapsedMs = (currentTime - lastTime).asMilliseconds();
        if (elapsedMs>0){ //update game
            lastTime = currentTime;
            world.UpdatePhysics(elapsedMs);
            window.clear();
            window.draw(circle.getShape());
            window.draw(floor.getShape());
            window.display();
        }
    }
}
```
