#pragma once
#include <SFML/Graphics.hpp>
#include "Bounds.h"
#include <bitset>


namespace sfp {
	struct PhysicsBodyCollisionResult;
	class PhysicsBody 
	{
	protected:
		
		float restitution;
		float mass;
		bool isStatic;
		sf::Vector2f velocity;
		bool moved;
		std::bitset<16> layer;
		bool isTrigger;

	
	public:
		PhysicsBody();
		PhysicsBody(Bounds& bounds, bool isStatic = false,
			float restitution=1.0f,float mass=1.0f);
		void applyImpulse(sf::Vector2f impulse);
		void update(unsigned int deltaMillisconds);
		void setPosition(sf::Vector2f center);
		sf::Vector2f getPosition();
		virtual Bounds& getBounds()=0;
		void setBounds(Bounds& bounds);
		void visualizeBounds(sf::RenderWindow& window);
		sf::Vector2f getVelocity();
		virtual void setVelocity(sf::Vector2f v);
		float getRestitution();
		void setRestitution(float r);
		virtual float getMass();
		virtual void setMass(float m);
		bool getStatic();
		void setStatic(bool s);
		PhysicsBodyCollisionResult collideWith(PhysicsBody& other);
		void setMoved(bool moved = false);
		bool hasMoved();
		void setLayer(const unsigned int& position, const bool& active);
		const std::bitset<16>& getLayers();
		void setTrigger(const bool& shouldBe);
		const bool& checkTrigger();

		bool operator == (const PhysicsBody& other) {
			return this == &other;
		}

		bool operator != (const PhysicsBody& other) {
			return !(this->operator==(other));
		}
		
		std::function<void(PhysicsBodyCollisionResult&)> onCollision = [this](PhysicsBodyCollisionResult& other) {
			//nop
		};
		std::function<void(float deltaMS)> onUpdate = [this](float deltaMS) {
			//nop
		};
	};
}


