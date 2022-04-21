#pragma once
#include <SFML/Graphics.hpp>
#include <functional>


using namespace std;

using namespace sf;

namespace sfp {
	class AABB;
	class CircleBounds;
	class BoundsCollisionResult;
	class Bounds
	{
	private:

	public:
		BoundsCollisionResult reverseCollsionObjects(BoundsCollisionResult result);
		virtual Vector2f getPosition() = 0;
		virtual void setPosition(Vector2f center);
		virtual void visualize(RenderWindow& window)=0;
		virtual BoundsCollisionResult collideWithAABB(AABB& other)=0;
		virtual BoundsCollisionResult collideWithCircle(CircleBounds& other)=0;
		virtual BoundsCollisionResult collideWith(Bounds& other)=0;
		function<void(Vector2f)> onMove;
	};
}


