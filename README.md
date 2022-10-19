# The Simple Fast Physics Library for SFML

![image](https://user-images.githubusercontent.com/4048613/166339619-9e51b359-07c4-461d-841e-e6493b1cd180.png)


This is a basic 2D collision library for SFML.  Its is quite fast and presents an API similar to SFML's API in that it is totally pointerless.  Simple games can be written with just stack allocation.

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
* Movement based collision optimization (can be disabled)

## LIMITATIONS
* Only supports Circular bounds and Axis-Aligned Bounding Boxes
* Only support simple hard bodies (no joints)
* Euler integrator can miss inter-frame collisions
* Code currently undocumented


## Documentation
System architecture: https://github.com/profK/SFPhysics/wiki

## EXAMPLES
https://github.com/profK/Breakout2  

## PLANNED EXTENSIONS
* Documentation
  
## RELEASE NOTES
Version 2.0.0 has been released.
Internally a number of changes have been made:
(1) The bounds of a PhysicsBody is now determined when the body is created and may not be changed, although the fields of the bounds
may be reset.  This eliminated issues with copying such that PhysicsShapes may now be copied freely and thus used (carefully) with stl collection types.
(2) Inheritance by field composition has been replaced with pure inheritance by sub classing.  The practical result of this is the the PhysicsBodies returned by the collision callback can be upcast to retreieve their PhysicsShape.
(3) In multiple places templated classed have been replaced by classname<T> (eg PhysicsShapeT).  The old name (eg PhysicsShape) now defines an abstract superclass that can be used like an "interface" in C# ort Java.  

The API has one major chnage, which is that PhysicsShapeList can now hold a mix of PhysicsShape instances (PhysicsCricle, PhysicsSprite) etc. The Create call to make a new shape on the list is now Create<T> where T can be any subclass of PhysicsShape.

Version 1.2.0 has been released.  It is feature complete and passses all the tests I have for it.  The largest addition is the
collision pruning based on motion.
There still may be bugs.  And documentation is still forthcoming.

Version 1.4.1 has been released.  Primary changes are:
1. bug fixes to solve getting multiple PhysicsBody.onCollision callbacks from the same collision
2. Added an any type field extraData to PhysicsBody to allow user to attach app specific data (only available on C++ 17 and higher)

## Getting Started
1.  Create a C++ desktop project
2.  Import SFML and SFPhysics into your project.   
    The easiest way is with these nuget packages:  
    https://www.nuget.org/packages/SFPhysics/  
    https://www.nuget.org/packages/SFML_VS2019/  
3. include <SFML/Graphics.hpp>  and <SFPhysics.h> in your main file
4. The physics simulation is controlled by a World object.  Use the PhysicsShape classes (PhysicsCircle, PhysicsRectangle, PhysicsConvexPolygon and PhysicsSprite) to create SFML drawable objects that participate in the physics simulation and add them to the world with World.AddPhysicsBody(). Obects that participate in collision but do not move or are moved manually by game logic can be set to effectively infinite mass by calling PhysicsShape.getBody().setStatic(true);
5. In your SFML render loop, "tick' the physics simulation by calling World.UpdatePhysics(elapsedMS) where elapsedMS is the miliseconds since the last physics update call.
6. Render your PhysicsShapes by using PhysicsShape.getShape() to retrieve an SFML drawable.  

Below is a "Hello Physics" example of a ball bouncing off a floor:
  
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
