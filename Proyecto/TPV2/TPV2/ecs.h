#pragma once
#ifndef ECS_H_
#define ECS_H_

using cmpId_type = int;
enum cmpId : cmpId_type {
	// ... (compoment ids)
	TRANSFORM_H = 0,
	DEACCELERATIONCOMPONENT_H = 1,
	IMAGE_H = 2,
	HEALTH_H = 3,
	FIGHTERCONTROL_H = 4,
	SHOWATOPPOSIDESIDE_H = 5,
	GUN_H = 6,
	DISABLEONEXIT_H = 7,
	FRAMEDIMAGE_H = 8,
	FOLLOW_H = 9,
	GENERATIONS_H = 10,
	// do not remove this
	_LAST_CMP_ID
};
constexpr cmpId_type maxComponentId = _LAST_CMP_ID;

using grpId_type = uint8_t;
enum grpId : grpId_type {
	_grp_ASTEROIDS = 0,
	_grp_BULLETS = 1,
	_LAST_GRP_ID
};
constexpr grpId_type maxGroupId = _LAST_GRP_ID;


#endif // !ECS_H_

