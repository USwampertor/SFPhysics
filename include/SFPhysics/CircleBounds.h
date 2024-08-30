#pragma once
#include <SFML/Graphics.hpp>
#include "BoundsCollisionResult.h"
#include "Bounds.h"

// forward refernce

namespace sfp {
	class AABB;

	class CircleBounds: public Bounds
	{
	private:
		sf::Vector2f position;
		float radius;
		sf::CircleShape visual;
	public:
		CircleBounds();
		CircleBounds(sf::Vector2f position, float radius);
		bool intersectsWith(CircleBounds& other);
		BoundsCollisionResult collideWith(Bounds& other);
		BoundsCollisionResult collideWithAABB(AABB& other);
		BoundsCollisionResult collideWithCircle(CircleBounds &other);
		sf::Vector2f getPosition();
		void setPosition(sf::Vector2f center);
		void setRadius(float r);
		float getRadius();
		/// <summary>
		/// Uses the smaller of the extents as the radius
		/// </summary>
		/// <param name="extents"></param>
		virtual void setSize(sf::Vector2f extents) override;
		/// <summary>
		/// returns the radius in x and y
		/// </summary>
		/// <returns></returns>
		virtual sf::Vector2f getSize() override;
		void visualize(sf::RenderWindow& window);
	};
}


