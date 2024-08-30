#pragma once
#include <SFML/Graphics.hpp>

namespace sfp{
    class CenteredShape
    {
    public:
        virtual void setCenter(sf::Vector2f center)=0;
        virtual sf::Vector2f getCenter()=0;
        virtual void setSize(sf::Vector2f size) = 0;
        virtual sf::Vector2f getSize() = 0;
    };
}

