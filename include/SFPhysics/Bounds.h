#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
#include <any>


// using namespace std;

// using namespace sf;

namespace sfp {
	class AABB;
	class CircleBounds;
	class BoundsCollisionResult;
	class Bounds
	{
	private:

	public:
		BoundsCollisionResult reverseCollsionObjects(BoundsCollisionResult result);
		virtual sf::Vector2f getPosition() = 0;
		virtual void setPosition(sf::Vector2f center);
		virtual void setSize(sf::Vector2f rectSize)=0;
		virtual sf::Vector2f getSize() = 0;
		virtual void visualize(sf::RenderWindow& window)=0;
		virtual BoundsCollisionResult collideWithAABB(AABB& other)=0;
		virtual BoundsCollisionResult collideWithCircle(CircleBounds& other)=0;
		virtual BoundsCollisionResult collideWith(Bounds& other)=0;
		std::function<void(sf::Vector2f)> onMove;
	};
}


