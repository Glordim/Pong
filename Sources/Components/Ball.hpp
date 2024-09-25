#pragma once
#include "Pong.hpp"

#include <HodEngine/Game/Component.hpp>
#include <HodEngine/Core/Event.hpp>
#include <HodEngine/Core/Math/Vector2.hpp>

namespace hod::game
{
	class Rigidbody2dComponent;
}

namespace hod::physics
{
	struct Collision;
}

class PONG_API Ball : public hod::game::Component
{
	REFLECTED_CLASS(Ball, hod::game::Component, PONG_API);

public:

			Ball();

	void	OnAwake() override;
	void	OnUpdate() override;

	void	OnCollisionEnter(const hod::physics::Collision& collision);
	void	OnCollisionExit(const hod::physics::Collision& collision);

	void	LaunchBall();

private:

	hod::Event<const hod::physics::Collision&>::Slot _onCollisionEnterSlot;
	hod::Event<const hod::physics::Collision&>::Slot _onCollisionExitSlot;

	float _speed = 0.25f;
	hod::Vector2 _lastVelocity;
};
