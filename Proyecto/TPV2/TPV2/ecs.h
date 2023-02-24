#pragma once
#ifndef ECS_H_
#define ECS_H_

using cmpId_type = int;
enum cmpId : cmpId_type {
	// ... (compoment ids)
	TRANSFORM_H = 0,
	DEACCELERATIONCOMPONENT_H = 1,
	IMAGE_H = 2,
	HEALTH_H =3,
	FIGHTERCONTROL_H=4,
	SHOWATOPPOSIDESIDCE_H=5,
	// do not remove this
	_LAST_CMP_ID
};
constexpr cmpId_type maxComponentId = _LAST_CMP_ID;

#endif // !ECS_H_

