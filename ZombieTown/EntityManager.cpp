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