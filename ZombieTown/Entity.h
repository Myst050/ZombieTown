#pragma once

#include "raylib.h"

struct Entity {
	Vector2 position;
	Texture2D texture;
	bool isAlive;
	bool isZombie;
	int health;
	int speed;
	Vector2 new_position;
	float radius = 15.0f;

	void Move(int bx, int by);
	void Spawn(int bx, int by);

	float calculateDistance(Vector2 c_pos, Vector2 n_pos) const;
	Vector2 calculateDirection(Vector2 c_pos, Vector2 n_pos) const;

	void draw() const;
	void takeDamage(int damage);
};