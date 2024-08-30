#pragma once
#include <SFML/Graphics.hpp>
#include "CenteredShape.h"

namespace sfp {
	class CenteredConvexShape :
		public sf::ConvexShape, CenteredShape
	{
	public:
		// Inherited via CenteredShape
		virtual void setCenter(sf::Vector2f center) override;
		virtual sf::Vector2f getCenter() override;
		virtual void setSize(sf::Vector2f size) override;
		virtual sf::Vector2f getSize() override;
	};
 }


