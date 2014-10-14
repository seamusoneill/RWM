#include "Blob.h"

Blob::Blob(){

}

Blob::~Blob(){

}

void Blob::Initialize(){

}

void Blob::Update(){

	m_position += m_velocity; //* timeSinceLastFrame (gametime)
}

//Getters and setters
b2Vec2 Blob::getPosition(){
	return m_position;
}

b2Vec2 Blob::getVelocity(){
	return m_velocity;
}

void Blob::setPosition(b2Vec2 p){
	m_position = p;
}

void Blob::setVelocity(b2Vec2 v){
	m_velocity = v;
}