#include "pch.h"
#include "CenteredSprite.h"

using namespace sfp;

sfp::CenteredSprite::CenteredSprite(): sf::Sprite()
{
}

CenteredSprite::CenteredSprite(sf::Texture& tex) :
  sf::Sprite(tex)
{
}

void sfp::CenteredSprite::setImage(sf::Texture& img)
{
  sf::Vector2f center = getCenter();
  sf::Sprite::setTexture(img);
    setCenter(center);
}

sf::Texture& sfp::CenteredSprite::getImage()
{
    return getImage();
}


void CenteredSprite::setCenter(sf::Vector2f center)
{
  sf::Vector2f sz = getSize();
    setPosition(sf::Vector2f(center.x - (sz.x / 2), center.y - (sz.y / 2)));
}

sf::Vector2f CenteredSprite::getCenter()
{
  sf::Vector2f szvect = getSize();
    sf::Vector2f pos = getPosition();
    return sf::Vector2f(pos + (szvect / 2.0f));
}

void sfp::CenteredSprite::setSize(sf::Vector2f size)
{
  sf::IntRect imageSize = getTextureRect();
  sf::Vector2f scale =
    sf::Vector2f(size.x/imageSize.width,size.y/imageSize.height);
  sf::Sprite::setScale(scale);
}

sf::Vector2f sfp::CenteredSprite::getSize()
{
  sf::IntRect imageSize = getTextureRect();
  sf::Vector2f scale = getScale();
    return sf::Vector2f(imageSize.width*scale.x,
        imageSize.height*scale.y);
}


