#pragma once
#include <SFML/Graphics.hpp>
#include "PhysicsBodyT.h"
#include "CenteredShape.h"
#include "Bounds.h"
#include <functional>

namespace sfp {

	class PhysicsShape
	{
	public:

		virtual void setCenter(sf::Vector2f center) = 0;
		virtual void setSize(sf::Vector2f size) = 0;
		virtual sf::Vector2f getCenter() = 0;
		virtual sf::Vector2f getSize() = 0;
		std::function<void(PhysicsBodyCollisionResult&)> onCollision = [this]
		(PhysicsBodyCollisionResult& result) {
			this->collisionCallback(result);
		};
		std::function<void(unsigned int)> onUpdate = [this]
		(unsigned int deltaMS) {
			this->updateCallback(deltaMS);
		};
		virtual void collisionCallback(
			PhysicsBodyCollisionResult& result) = 0;
		virtual void updateCallback(unsigned int deltaMs) = 0;
	};
}



