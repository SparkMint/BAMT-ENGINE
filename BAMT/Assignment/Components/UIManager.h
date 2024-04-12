#ifndef ASSIGNMENT_UI_MANAGER
#define ASSIGNMENT_UI_MANAGER

#include "Component.h"
#include "KeyboardMovement.h"
#include "ScoreSystem.h"
#include "TextRenderer.h"
#include "TimeSystem.h"
#include "WeaponSystem/PlayerWeapon.h"
#include "WeaponSystem/WeaponData.h"

class UIManager : public Component
{
	public:
		void Start() override;
		void Update(float* timeStep) override;

		ScoreSystem* scoreSystem = nullptr;
		TimeSystem* timeSystem = nullptr;
		PlayerWeapon* playerWeapon = nullptr;
		KeyboardMovement* playerMovement = nullptr;

		TextRenderer* scoreText = nullptr;
		TextRenderer* multiplierText = nullptr;
		TextRenderer* multiplierPowerupText = nullptr;
		TextRenderer* doubleSpeedText = nullptr;
		TextRenderer* timeExtendText = nullptr;
		TextRenderer* timeText = nullptr;
		TextRenderer* weaponText = nullptr;
		TextRenderer* gameOverText = nullptr;
		TextRenderer* restartPrompt = nullptr;

		void UpdateScoreUI(int score) const;
		void UpdateMultiplierUI(int multiplier) const;
		void UpdateMultiplierPowerupUI(bool active);
		void UpdateSpeedUI(bool active);
		void UpdateTimeExtendUI(bool active);
		void UpdateTimeUI(int time) const;
		void UpdateWeaponUI(WeaponData* data) const;

		void Stop() const;
		void Reset() const;
};
#endif
