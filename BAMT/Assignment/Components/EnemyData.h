#ifndef ASSIGNMENT_ENEMY_DATA
#define ASSIGNMENT_ENEMY_DATA

#include "WeaponSystem/WeaponData.h"

//					    MSPEED | MASS   | DRAG  | BOUNCINESS
#define WEIGHT_DEFAULT { 10    , 1      , 1     , 1      }
#define WEIGHT_RANGER  { 10    , 1      , 5     , .2f    }
#define WEIGHT_ZOMBIE  { 10    , 2      , 5     , .2f    }
#define WEIGHT_TANK    { 10    , 10     , 5     , .2f    }

//					   WIDTH   | HEIGHT  | SPEED | HEALTH | WEAPON            | ENEMY WEIGHT
#define ENEMY_ZOMBIE { .18f * 4, .24f * 4, 30    , 2      , WEAPON_DATA_ZOMBIE, WEIGHT_ZOMBIE}   
#define ENEMY_RANGER { .25f * 4, .33f * 4, 10    , 4      , WEAPON_DATA_RANGER, WEIGHT_RANGER }
#define ENEMY_TANK   { .30f * 4, .42f * 4, 5     , 7      , WEAPON_DATA_TANK  , WEIGHT_TANK }


struct EnemyWeightData
{
	float maxSpeed = 10;

	float mass = 1;

	float drag = 1;

	float bounciness = 1;
};

struct EnemyData
{
	float width = .5f;

	float height = .5f;

	float speed = 1;

	int health = 1;

	WeaponData weapon = WEAPON_DATA_NONE;

	EnemyWeightData weightData = WEIGHT_DEFAULT;
};
#endif