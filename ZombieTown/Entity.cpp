#include "Entity.h"
#include "Raylib.h"
#include <iostream>

using namespace std;

void Entity::draw() {
	DrawTextureV(texture, position, WHITE);
}

void Entity::takeDamage(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}

void Entity::Move(int bx, int by) {
	int relx = GetRandomValue(0, bx);
	int rely = GetRandomValue(0, by);

	Vector2 current_pos = position;
	Vector2 new_pos = { (float)relx, (float)rely };

	float distance = Entity::calculateDistance(current_pos, new_pos);
	Vector2 direction = Entity::calculateDirection(current_pos, new_pos);

	float step = speed * GetFrameTime();

	if (distance > 0) {
		direction.x /= distance;
		direction.y /= distance;
		position.x += direction.x * step;
		position.y += direction.y * step;
	}
	else {
		position = new_pos;
	}

	std::cout << "Current Position: (" << current_pos.x << ", " << current_pos.y << ")" << std::endl;

}

float Entity::calculateDistance(Vector2 c_pos, Vector2 n_pos) {
	float dx = n_pos.x - c_pos.x;
	float dy = n_pos.y - c_pos.y;
	return sqrt((dx * dx) + (dy * dy));
}

Vector2 Entity::calculateDirection(Vector2 c_pos, Vector2 n_pos) {
	return { n_pos.x - c_pos.x, n_pos.y - c_pos.y };
}