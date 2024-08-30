#pragma once
#include "CenteredShape.h"
#include <SFML/Graphics.hpp>

namespace sfp {
    class CenteredRectangle :
        public CenteredShape, public sf::RectangleShape
    {
    public:
        CenteredRectangle();
        CenteredRectangle(sf::Vector2f size);
        // Inherited via CenterPositionedShape
        virtual void setCenter(sf::Vector2f center) override;
        virtual sf::Vector2f getCenter() override;
        virtual void setSize(sf::Vector2f size) override;
        virtual sf::Vector2f getSize() override;
    };
}

