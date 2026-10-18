#include "raylib.h"
#include "EntityManager.h"
#include "Entity.h"

#include <vector>

void EntityManager::clear() {
	entities.clear();
}

void EntityManager::addEntity(const Entity& entity) {
	entities.push_back(entity);
}

void EntityManager::update(int bx, int by) {
	for (auto& entity : entities) {
		entity.Move(bx, by);
	}

	checkCollisions();
}

void EntityManager::draw() const {
	for (const auto& entity : entities) {
		Texture2D texture = entity.texture;
		DrawTextureV(texture, entity.position, WHITE);
	}
}

size_t EntityManager::getCurrentPopulationInformation() const {
	return entities.size();
}

void EntityManager::checkCollisions() {
	for (size_t i = 0; i < entities.size(); i++) {
		for (size_t j = i + 1; j < entities.size(); j++) {
			if (CheckCollisionCircles(entities[i].position, entities[i].radius, entities[j].position, entities[j].radius)) {
				if (!entities[i].isAlive && entities[j].isAlive) {
					entities[j].isAlive = false;
				}
				else if (entities[i].isAlive && !entities[j].isAlive) {
					entities[i].isAlive = false;
				}
			}
		}
	}
}

void EntityManager::giveRemaining() {
	int r = 0;
	for (int i = 0; i < entities.size(); i++) {
		if (entities[i].isAlive) {
			r++;
		}
	}
	DrawText(TextFormat("Remaining: %d", r), 10, 10, 20, BLACK);
}