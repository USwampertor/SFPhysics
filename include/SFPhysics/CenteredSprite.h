#pragma once
#include "CenteredShape.h"

namespace sfp {

    class CenteredSprite :
        public CenteredShape, public sf::Sprite
    {
    public:
        CenteredSprite();
        CenteredSprite(sf::Texture& tex);

        void setImage(sf::Texture& img);
        sf::Texture& getImage();

        // Inherited via CenteredShape
        virtual void setCenter(sf::Vector2f center) override;
        virtual sf::Vector2f getCenter() override;
        virtual void setSize(sf::Vector2f size) override;
        virtual sf::Vector2f getSize() override;

        
    };
}

