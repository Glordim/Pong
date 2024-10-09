#pragma once
#include "../Pong.hpp"

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
	class Collider;
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

	void	OnTriggerEnter(const hod::physics::Collider& trigger, const hod::physics::Collider& visitor);
	void	OnTriggerExit(const hod::physics::Collider& trigger, const hod::physics::Collider& visitor);

	void	LaunchBall();

private:

	hod::Event<const hod::physics::Collision&>::Slot _onCollisionEnterSlot;
	hod::Event<const hod::physics::Collision&>::Slot _onCollisionExitSlot;

	hod::Event<const hod::physics::Collider&, const hod::physics::Collider&>::Slot _onTriggerEnterSlot;
	hod::Event<const hod::physics::Collider&, const hod::physics::Collider&>::Slot _onTriggerExitSlot;

	float _speed = 0.25f;
	hod::Vector2 _lastVelocity;
};
