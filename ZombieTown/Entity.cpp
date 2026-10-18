#include "Entity.h"
#include "Raylib.h"
#include <iostream>

using namespace std;

void Entity::Spawn(int bx, int by) {
	position = { 0,0 };
	new_position = { (float)GetRandomValue(0, bx), (float)GetRandomValue(0, by) };

};

void Entity::draw() const {
	DrawTextureV(texture, position, WHITE);
}

void Entity::takeDamage(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}

void Entity::Move(int bx, int by) {

	float distance = Entity::calculateDistance(position, new_position);
	Vector2 direction = Entity::calculateDirection(position, new_position);

	float step = speed * GetFrameTime();

	if (distance < 2.0f) {
		new_position = { (float)GetRandomValue(0, bx), (float)GetRandomValue(0, by) };
		distance = Entity::calculateDistance(position, new_position);
	}

	direction = Entity::calculateDirection(position, new_position);

	if (distance > step) {
		if (distance > 0) {
			direction.x /= distance;
			direction.y /= distance;
			position.x += direction.x * step;
			position.y += direction.y * step;
		}
	}
	else {
		position = new_position;
	}
}

float Entity::calculateDistance(Vector2 c_pos, Vector2 n_pos) const	{
	float dx = n_pos.x - c_pos.x;
	float dy = n_pos.y - c_pos.y;
	return sqrt((dx * dx) + (dy * dy));
}

Vector2 Entity::calculateDirection(Vector2 c_pos, Vector2 n_pos) const{
	return { n_pos.x - c_pos.x, n_pos.y - c_pos.y };
}