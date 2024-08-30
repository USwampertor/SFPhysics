#pragma once
#include "pch.h"
#include "CenteredShape.h"

namespace sfp {
    class CenteredCircle :
        public CenteredShape, public sf::CircleShape
    {
    public:
        CenteredCircle();
        virtual void setCenter(sf::Vector2f center) override;
        virtual sf::Vector2f getCenter() override;
        virtual void setSize(sf::Vector2f sz) override;
        virtual sf::Vector2f getSize() override;
    };
}

