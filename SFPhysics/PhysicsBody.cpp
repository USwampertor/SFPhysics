#include "pch.h"
#include "PhysicsBody.h"
#include <iostream>
#include <stdexcept>
#include "PhysicsBodyCollisionResult.h"
#include <limits>


using namespace sfp;

sfp::PhysicsBody::PhysicsBody()
	: restitution(1.0),
		mass(1.0),
		isStatic(false),
		velocity(sf::Vector2f(0,0)),
		layer("0000000000000000"),
		isTrigger(false)
{
}



void sfp::PhysicsBody::setPosition(sf::Vector2f center)
{
	if (getBounds().getPosition() != center) {
		getBounds().setPosition(center);
		moved = true;
	}
}

sf::Vector2f sfp::PhysicsBody::getPosition()
{
	return getBounds().getPosition();
}





void sfp::PhysicsBody::visualizeBounds(sf::RenderWindow& window)
{
	getBounds().visualize(window);
}

sf::Vector2f sfp::PhysicsBody::getVelocity()
{
	return velocity;
}

void sfp::PhysicsBody::setVelocity(sf::Vector2f v)
{
	if (!isStatic) {
		velocity = v;
	}
}

float sfp::PhysicsBody::getRestitution()
{
	return restitution;
}

void sfp::PhysicsBody::setRestitution(float r)
{
	restitution = r;
}

float sfp::PhysicsBody::getMass()
{
	if (!isStatic) {
		return mass;
	}
	else {
		return std::numeric_limits<float>::infinity();
	}
	
}

void sfp::PhysicsBody::setMass(float m)
{
	mass = m;
}

bool sfp::PhysicsBody::getStatic()
{
	return isStatic;
}

void sfp::PhysicsBody::setStatic(bool s)
{
	isStatic = s;
}

void sfp::PhysicsBody::update(unsigned int deltaMilliseconds)
{
	//cout << "in update ms=" << deltaMilliseconds << endl;
	moved = false;
	if (!isStatic) {
		sf::Vector2f pos = getBounds().getPosition();
		pos += (velocity * (float)deltaMilliseconds);
		//pos += velocity * 10.0f;
		setPosition(pos);
	}
	if (onUpdate) onUpdate(deltaMilliseconds);
}

void sfp::PhysicsBody::applyImpulse(sf::Vector2f impulse)
{
	if (!isStatic) {
		velocity += impulse;
	}
}

PhysicsBodyCollisionResult sfp::PhysicsBody::collideWith(
	PhysicsBody& other)
{
	PhysicsBodyCollisionResult collision(*this,other,
		this->getBounds().collideWith(other.getBounds()));
	return collision;
}

void sfp::PhysicsBody::setMoved(bool moved)
{
	this->moved = moved;
}

bool sfp::PhysicsBody::hasMoved()
{
	return moved;
}

void sfp::PhysicsBody::setLayer(const unsigned int& position, const bool& active)
{
	layer.set(position, active ? 1 : 0);
}

const std::bitset<16>& sfp::PhysicsBody::getLayers()
{
	return layer;
}


void sfp::PhysicsBody::setTrigger(const bool& shouldBe)
{
	isTrigger = shouldBe;
}

const bool& sfp::PhysicsBody::checkTrigger()
{
	return isTrigger;
}



