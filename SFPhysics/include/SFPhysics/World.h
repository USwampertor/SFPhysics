#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "PhysicsBody.h"

// using namespace sf;
// using namespace std;

namespace sfp {
	class World
	{
	private:
		sf::Vector2f gravity;
		std::list<PhysicsBody*> objects; // becomes ptrs internally but never exposed
		bool ignoreMovement;
		std::list<PhysicsBody*> removalList;
		long unsigned deltaAccumulator = 0;
	public:
		World(sf::Vector2f gravity);

		void AddPhysicsBody(PhysicsBody& obj);
		void RemovePhysicsBody(PhysicsBody& obj);
		void UpdatePhysics(unsigned long deltaMilliseconds, unsigned long msPerTick = 0);
		void VisualizeAllBounds(sf::RenderWindow& window);
		void setIgnoreMovement(bool ignore = true);
		void ChangeGravity(const sf::Vector2f newValue);
	};
}


