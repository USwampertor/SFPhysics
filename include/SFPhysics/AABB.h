#pragma once
#include <SFML/Graphics.hpp>
#include "Bounds.h"
#include "BoundsCollisionResult.h"




namespace sfp {
	class CircleBounds;

	class AABB: public Bounds
	{
	private:
		sf::Vector2f min;
		sf::Vector2f max;
		sf::RectangleShape visual;
	public:
		AABB();
		AABB(sf::Vector2f min, sf::Vector2f max);
		bool intersectsWith(AABB other);
		BoundsCollisionResult collideWith(Bounds& other);
		BoundsCollisionResult collideWithAABB(AABB &other);
		BoundsCollisionResult collideWithCircle(CircleBounds& other);
		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f center);
		virtual void setSize(sf::Vector2f extents) override;
		virtual sf::Vector2f getSize() override;
		void visualize(sf::RenderWindow& window);

	};
}


