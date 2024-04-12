#ifndef ASSIGNMENT_MOUSE_FOLLOW
#define ASSIGNMENT_MOUSE_FOLLOW
#include "Component.h"
#include "RigidBody.h"
#include "Input.h"

class MouseFollow : public Component
{
	RigidBody* _rb = nullptr;

	public:
		void Start() override;
		void Update(float* timeStep) override;
};

#endif
