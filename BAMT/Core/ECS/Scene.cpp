#include "Scene.h"
#include "../EngineSettings.h"


Scene::Scene() { }

Scene::~Scene()
{
	Debug::Log("Scene Destroyed.", this);

	for (const Entity* entity : entityList)
	{
		delete entity;
	}
}

void Scene::Start(){ }

void Scene::Update(float* timeStep)
{
	_timeStep = *timeStep / BAMT_PHYSICS_STEPS;
	for (int i = 0; i < BAMT_PHYSICS_STEPS; ++i)
	{
		DetectCollisions();
	}

	SortEntities();
	for (Entity* entity : entityList)
	{
		if (entity->active)
			entity->Update(timeStep);
	}
}

void Scene::Render(SDL_Renderer* renderer) const
{

	for (const Entity* entity : entityList)
	{
		if (entity->active)
			entity->Render(renderer);
	}
}

void Scene::SortEntities()
{
	std::sort(entityList.begin(), entityList.end(), [](const Entity* a, const Entity* b)
		{return a->renderLayer < b->renderLayer; });
}

void Scene::SortRigidBodies()
{
	std::sort(rigidBodiesList.begin(), rigidBodiesList.end(), [](const RigidBody* a, const RigidBody* b)
		{return a->transform->GetX() - a->width * 0.5f < b->transform->GetX() - b->width * 0.5f; });
}

void Scene::DetectCollisions()
{
	// Sort all RigidBodies by their minimum X values.
	SortRigidBodies();

	// This list is for that previously collided.
	std::vector<RigidBody*> activeInterval;
	activeInterval.reserve(rigidBodiesList.size());

	// Initialise a list of collisions we could find.
	std::vector<std::pair<RigidBody*, RigidBody*>> collisionPairs;
	collisionPairs.reserve(rigidBodiesList.size() * (rigidBodiesList.size() - 1) / 2);

	for (auto& rb : rigidBodiesList)
	{
		// Clear this RigidBodies collision list. As it will update here.
		rb->collisionList.clear();

		// Make sure the entity is active.
		if (!rb->entity->active || !rb->enabled) continue;

		for(int j = 0; j < activeInterval.size(); ++j)
		{
			// For some reason, this seems to work fine, but giving it my premade OverlapOnAxis function breaks it. so yeah...
			if (rb->transform->GetX() - rb->width * 0.5f > activeInterval[j]->transform->GetX() + activeInterval[j]->width * 0.5f)
			{
				// If the object isnt overlapping the X bounds of our current active interval. remove the active interval.
				activeInterval.erase(activeInterval.begin() + j);
				j--;
			}
			else
			{
				if (VectorMath::OverlapOnAxis(rb->transform->GetY(), rb->height, activeInterval[j]->transform->GetY(), activeInterval[j]->height))
				{
					collisionPairs.emplace_back(rb, activeInterval[j]);
				}
			}
		}
		// Add this object to our active interval list.
		activeInterval.emplace_back(rb);
	}

	// Go through each pair of RigidBodies and solve each collision.
	SolveRigidBodyCollisions(collisionPairs);
}

void Scene::SolveRigidBodyCollisions(const std::vector<std::pair<RigidBody*, RigidBody*>>& collisionPairs) const
{
	for (auto pair : collisionPairs)
	{
		// Add each object to their respective collision Lists.
		pair.first->collisionList.emplace_back(pair.second);
		pair.second->collisionList.emplace_back(pair.first);

		if (pair.first->isTrigger || pair.second->isTrigger) continue;

		// Get how much object one overlaps object two. We can use that to move them out the way of eachother.
		const float xOverlap = (pair.first->width + pair.second->width) * 0.5f - fabs(pair.first->transform->GetX() - pair.second->transform->GetX());
		const float yOverlap = (pair.first->height + pair.second->height) * 0.5f - fabs(pair.first->transform->GetY() - pair.second->transform->GetY());

		// Calculate which direction the pair collided on.
		// KEEP IN MIND THIS ONLY WORKS FOR BOX COLLIDERS!
		Vector2 collisionNormal;
		if (xOverlap < yOverlap)
		{
			collisionNormal = pair.first->transform->GetX() < pair.second->transform->GetX() ? Vector2{ 1, 0 } : Vector2{ -1, 0 };
		}
		else
		{
			collisionNormal = pair.first->transform->GetY() < pair.second->transform->GetY() ? Vector2{ 0, 1 } : Vector2{ 0, -1 };
		}

		// Move the object transform to try to get the object out of whatever its colliding with.
		const Vector2 displacement = { collisionNormal.x * xOverlap, collisionNormal.y * yOverlap };

		if (!pair.first->isKinematic)
		{
			pair.first->transform->Translate(-displacement.x, -displacement.y);
		}
		if (!pair.second->isKinematic)
		{
			pair.second->transform->Translate(displacement.x, displacement.y);
		}

		// Check if the objects are moving away from each other. If they are.
		// Dont add force. otherwise they will pull towards each other.
		Vector2 relativeVelocity = pair.second->velocity - pair.first->velocity;

		const float relativeVelocityInNormalDirection = VectorMath::Dot(collisionNormal, relativeVelocity);
		if (relativeVelocityInNormalDirection > 0) continue;

		// Use the object with the least amount of bounciness for calculating the impulse force.
		const float bounce = min(pair.first->bounciness, pair.second->bounciness);

		// Calculate the impulse force
		float impulseScalar = -(1 + bounce) * relativeVelocityInNormalDirection / (-pair.first->mass + -pair.second->mass) * 100;
		// Add the resulting forces to each object. Negate the second object so it goes in the other direction.

		pair.first->AddReactionForce(collisionNormal, impulseScalar);
		pair.second->AddReactionForce(collisionNormal, -impulseScalar);

		if (pair.first->debugMode || pair.second->debugMode)
		{
			Debug::Log("---------------------------------");
			Debug::Log("RIGIDBODY COLLISION DEBUG SUMMARY");
			Debug::Log("---------------------------------");
			Debug::Log("First object", pair.first);
			Debug::Log("Second object", pair.second);

			Debug::Log("Collision Normal: (" + std::to_string(collisionNormal.x) + ", " + std::to_string(collisionNormal.y) + ")");
			Debug::Log("Relative Velocity: (" + std::to_string(relativeVelocity.x) + ", " + std::to_string(relativeVelocity.y) + ")");
			Debug::Log("Bounce: " + std::to_string(bounce));
			Debug::Log("ImpulseScalar: " + std::to_string(impulseScalar));
			Debug::Log("Resulting Force: (" + std::to_string(collisionNormal.x * impulseScalar) + ", " + std::to_string(collisionNormal.y * impulseScalar) + ")");
			Debug::Log("---------------------------------");
		}
	}
}