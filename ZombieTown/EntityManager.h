#include "Raylib.h"
#include <vector>
#include "Entity.h"

struct EntityManager {
	std::vector<Entity> entities;
	void clear();
	size_t getCurrentPopulationInformation() const;
	void addEntity(const Entity& entity);
	void update(int bx, int by);
	void draw() const;
};