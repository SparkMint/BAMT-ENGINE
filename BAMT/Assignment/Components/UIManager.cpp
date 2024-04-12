#include "UIManager.h"

void UIManager::Start()
{
	constexpr float width = BAMT_REFERENCE_RESOLUTION_WIDTH / BAMT_WORLD_SCALE;
	constexpr float height = BAMT_REFERENCE_RESOLUTION_HEIGHT / BAMT_WORLD_SCALE;

	auto* gameOverEnt = entity->scene->AddEntity();
	gameOverText = gameOverEnt->AddComponent<TextRenderer>();
	gameOverText->SetFont("Comfortaa.ttf");
	gameOverText->SetText("TIME OVER");
	gameOverText->colour = BAMT_COLOUR_RED;
	gameOverText->width = gameOverText->height = 2;
	gameOverEnt->transform->SetPosition(width / 3 - 2, height / 2);
	gameOverEnt->renderLayer = 1;
	gameOverText->enabled = false;

	auto* restartPromptEnt = entity->scene->AddEntity();
	restartPrompt = restartPromptEnt->AddComponent<TextRenderer>();
	restartPrompt->SetFont("Comfortaa.ttf");
	restartPrompt->SetText("Press R to Restart!");
	restartPrompt->colour = BAMT_COLOUR_WHITE;
	restartPrompt->width = restartPrompt->height = 1;
	restartPromptEnt->transform->SetPosition(width / 3 - 1, height / 2 + 3);
	restartPromptEnt->renderLayer = 1;
	restartPrompt->enabled = false;

	auto* weaponTextEnt = entity->scene->AddEntity();
	weaponText = weaponTextEnt->AddComponent<TextRenderer>();
	weaponText->SetFont("Comfortaa.ttf");
	weaponText->colour = BAMT_COLOUR_RED;
	weaponText->width = weaponText->height = .8f;
	weaponTextEnt->transform->SetPosition(17, .5f);
	weaponTextEnt->renderLayer = 5;

	auto* scoreTextEnt = entity->scene->AddEntity();
	scoreText = scoreTextEnt->AddComponent<TextRenderer>();
	scoreText->width = scoreText->height = .8f;
	scoreText->colour = BAMT_COLOUR_YELLOW;
	scoreText->SetFont("Comfortaa.ttf");
	scoreText->SetText("Score: 0");
	scoreTextEnt->transform->SetPosition(2, .5f);
	scoreTextEnt->renderLayer = 5;

	auto* multiplierTextEnt = entity->scene->AddEntity();
	multiplierText = multiplierTextEnt->AddComponent<TextRenderer>();
	multiplierText->width = multiplierText->height = .8f;
	multiplierText->SetFont("Comfortaa-Bold.ttf");
	multiplierText->SetText("X1");
	multiplierTextEnt->transform->SetPosition(.5f, .5f);
	multiplierTextEnt->renderLayer = 5;

	auto* doubleMultiplierEnt = entity->scene->AddEntity();
	multiplierPowerupText = doubleMultiplierEnt->AddComponent<TextRenderer>();
	multiplierPowerupText->width = multiplierPowerupText->height = .7f;
	multiplierPowerupText->SetFont("Comfortaa-Bold.ttf");
	multiplierPowerupText->SetText("DOUBLE MULTIPLIER!");
	multiplierPowerupText->colour = BAMT_COLOUR_YELLOW;
	doubleMultiplierEnt->transform->SetPosition(.5f, height - .5f);
	doubleMultiplierEnt->renderLayer = 5;

	auto* timeExtendEnt = entity->scene->AddEntity();
	timeExtendText = timeExtendEnt->AddComponent<TextRenderer>();
	timeExtendText->width = timeExtendText->height = .7f;
	timeExtendText->SetFont("Comfortaa-Bold.ttf");
	timeExtendText->SetText("TIME EXTENDED!");
	timeExtendText->colour = BAMT_COLOUR_GREEN;
	timeExtendEnt->transform->SetPosition(width - 8, height - .5f);
	timeExtendEnt->renderLayer = 5;

	auto* doubleSpeedEnt = entity->scene->AddEntity();
	doubleSpeedText = doubleSpeedEnt->AddComponent<TextRenderer>();
	doubleSpeedText->width = doubleSpeedText->height = .7f;
	doubleSpeedText->SetFont("Comfortaa-Bold.ttf");
	doubleSpeedText->SetText("DOUBLE SPEED!");
	doubleSpeedText->colour = BAMT_COLOUR_BLUE;
	doubleSpeedEnt->transform->SetPosition(width - 16, height - .5f);
	doubleSpeedEnt->renderLayer = 5;

	auto* timeTextEnt = entity->scene->AddEntity();
	timeText = timeTextEnt->AddComponent<TextRenderer>();
	timeText->SetFont("Comfortaa.ttf");
	timeText->SetText("Time Remaining: 00");
	timeText->width = timeText->height = .8f;
	timeText->colour = BAMT_COLOUR_GREEN;
	timeTextEnt->transform->SetPosition(width / 2 - 4, .5f);
	timeTextEnt->renderLayer = 5;
}

void UIManager::Update(float* timeStep)
{
	if (scoreSystem != nullptr)
	{
		UpdateScoreUI(scoreSystem->score);

		int multiplier = scoreSystem->scoreMultiplier;
		if (scoreSystem->doubleMultiplier) multiplier *= 2;
		UpdateMultiplierUI(multiplier);

		UpdateMultiplierPowerupUI(scoreSystem->doubleMultiplier);
	}

	if(timeSystem != nullptr)
	{
		UpdateTimeUI((int)timeSystem->currentTimeSeconds);
		UpdateTimeExtendUI(timeSystem->timeExtended);
	}

	if(playerWeapon != nullptr)
	{
		UpdateWeaponUI(playerWeapon->weaponData);
	}

	if(playerMovement != nullptr)
	{
		UpdateSpeedUI(playerMovement->currentMovementSpeed == playerMovement->powerupMovementSpeed);
	}
}

void UIManager::UpdateScoreUI(int score) const
{
	if (scoreText == nullptr) return;
	std::string scoreString = "Score: " + std::to_string(score);
	scoreText->SetText(scoreString.c_str());
}

void UIManager::UpdateMultiplierUI(int multiplier) const
{
	if (multiplierText == nullptr) return;
	const std::string multiplierString = "X" + std::to_string(multiplier);

	switch(multiplier)
	{
		case 1:
			multiplierText->colour = BAMT_COLOUR_WHITE;
			multiplierText->width = multiplierText->height = .6f;
			break;
		case 2:
			multiplierText->colour = BAMT_COLOUR_GREEN;
			multiplierText->width = multiplierText->height = .7f;
			break;
		case 4:
			multiplierText->colour = BAMT_COLOUR_YELLOW;
			multiplierText->width = multiplierText->height = .75f;
			break;
		case 8:
			multiplierText->colour = BAMT_COLOUR_RED;
			multiplierText->width = multiplierText->height = .8f;
			break;
		case 16:
			multiplierText->colour = BAMT_COLOUR_CYAN;
			multiplierText->width = multiplierText->height = .9f;
			break;
	}

	multiplierText->SetText(multiplierString.c_str());
}

void UIManager::UpdateMultiplierPowerupUI(bool active)
{
	multiplierPowerupText->enabled = active;
}

void UIManager::UpdateSpeedUI(bool active)
{
	doubleSpeedText->enabled = active;
}

void UIManager::UpdateTimeExtendUI(bool active)
{
	timeExtendText->enabled = active;
}

void UIManager::UpdateTimeUI(int time) const
{
	if (timeText == nullptr) return;
	std::string timeString = "Time Remaining: " + std::to_string(time);
	timeText->SetText(timeString.c_str());
}

void UIManager::UpdateWeaponUI(WeaponData* data) const
{
	if (weaponText == nullptr) return;
	std::string weaponString = "Weapon: " + data->weaponName;
	weaponText->SetText(weaponString.c_str());
}

void UIManager::Stop() const
{
	gameOverText->enabled = true;
	restartPrompt->enabled = true;
}

void UIManager::Reset() const
{
	UpdateScoreUI(0);
	gameOverText->enabled = false;
	restartPrompt->enabled = false;
}
