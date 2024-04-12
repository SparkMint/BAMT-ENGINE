#ifndef BAMT_RIGID_BODY
#define BAMT_RIGID_BODY

#include "../EngineSettings.h"
#include "../ECS/Scene.h"
#include "../ECS/Entity.h"
#include "../ECS/Component.h"
#include "Transform.h"

class RigidBody : public Component
{
	// Stored Current timestep.
	float _timeStep = 0;

	/// <summary>
	/// Simulates the next position this RigidBody will move to.
	/// </summary>
	Vector2 Simulate(const float* timeStep, Vector2 vel, Vector2 position);

	public:
		~RigidBody();

		/// <summary>
		/// Velocity of the RigidBody. Only alter this if you know what you are doing!
		/// </summary>
		Vector2 velocity;

		/// <summary>
		/// Pointer to this RigidBodies transform.
		/// </summary>
		Transform* transform = nullptr;

		/// <summary>
		/// List of all objects currently colliding with this object.
		/// </summary>
		std::vector<RigidBody*> collisionList;

		/// <summary>
		/// If active, no external forces can affect this RigidBody.
		/// </summary>
		bool isKinematic = false;

		bool isTrigger = false;

		/// <summary>
		/// Activates Debug Logging for this RigidBody.
		/// </summary>
		bool debugMode = false;

		/// <summary>
		/// Width of the collider of this object.
		/// </summary>
		float width = 1.0f;

		/// <summary>
		/// Width of the collider of this object.
		/// </summary>
		float height = 1.0f;

		/// <summary>
		/// How heavy this RigidBody is. Or how hard it is to move.
		/// </summary>
		float mass = 1.0f;

		/// <summary>
		/// Slows the RigidBody down.
		/// </summary>
		float drag = 1.0f;

		/// <summary>
		/// How bouncy should this object be?
		/// </summary>
		float bounciness = 1.0f;

		/// <summary>
		/// The maximum speed this RigidBody can move.
		/// </summary>
		float maxVelocity = 1.0f;

		/// <summary>
		/// Used by the physics engine to react to other colliders.
		/// </summary>
		void AddReactionForce(Vector2 direction, float force);

		/// <summary>
		/// Adds a force in a given direction.
		/// </summary>
		void AddForce(Vector2 direction, float force);

		void Start() override;
		void Update(float* timeStep) override;


};
#endif