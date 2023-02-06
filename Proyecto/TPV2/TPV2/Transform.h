#pragma once
#include "./src/utils/Vector2D.h"
#include "ecs.h"
using namespace ecs;
class Transform : public ecs::Component {
	public:
		Transform() {};
		virtual ~Transform() {};
		inline Vector2D& getPos() {
			return position_;
		}
		inline Vector2D& getVel() {
			return velocity_;
		}
	private:
		Vector2D position_;
		Vector2D velocity_;
		float width_;
		float height_;
		float rotation_;
};

