#include "Projectile.h"

Projectile::Projectile(){

}

Projectile::~Projectile(){

}

void Projectile::Initialize(){

}

void Projectile::Update(){

	m_position += m_velocity; //* timeSinceLastFrame (gametime)
}

//Getters and setters
b2Vec2 Projectile::getPosition(){
	return m_position;
}

b2Vec2 Projectile::getVelocity(){
	return m_velocity;
}

void Projectile::setPosition(b2Vec2 p){
	m_position = p;
}

void Projectile::setVelocity(b2Vec2 v){
	m_velocity = v;
}