#pragma once
#include "Pong.hpp"

#include <HodEngine/Game/Component.hpp>
#include <HodEngine/Core/Event.hpp>

namespace hod::game
{
	class Rigidbody2dComponent;
}

namespace hod::physics
{
	class Collision;
}

class PONG_API Ball : public hod::game::Component
{
	REFLECTED_CLASS(Ball, hod::game::Component, PONG_API);

public:

			Ball();

	void	OnAwake() override;

	void	OnCollisionEnter(const hod::physics::Collision& collision);

private:

	hod::Event<const hod::physics::Collision&>::Slot _onCollisionEnterSlot;

	float _speed = 3.0f;
};
