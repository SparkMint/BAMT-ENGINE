#ifndef ASSIGNMENT_PLAYER_ANIMATION_SYSTEM
#define ASSIGNMENT_PLAYER_ANIMATION_SYSTEM

#include "Component.h"
#include "Animator.h"

class PlayerAnimationSystem : public Component
{
	public:
		void Start() override;
		void Update(float* timeStep)override;

		Animator* animator = nullptr;
		RigidBody* rigidBody = nullptr;
		Animation* walkRightAnim = nullptr;
		Animation* walkLeftAnim = nullptr;
		Animation* idleRightAnim = nullptr;
		Animation* idleLeftAnim = nullptr;
};
#endif
