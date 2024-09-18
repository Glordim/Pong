#include "Ball.hpp"
#include <HodEngine/Game/Entity.hpp>
#include <HodEngine/Game/Components/Node2dComponent.hpp>
#include <HodEngine/Game/Components/Physics/2d/Rigidbody2dComponent.hpp>
#include <HodEngine/Physics/Collision.hpp>
#include <HodEngine/Core/Output/OutputService.hpp>

using namespace hod;
using namespace hod::game;

DESCRIBE_REFLECTED_CLASS(Ball, Component)
{
	ADD_PROPERTY(Ball, _speed);
}

Ball::Ball()
: _onCollisionEnterSlot(std::bind(&Ball::OnCollisionEnter, this, std::placeholders::_1))
{

}

void Ball::OnAwake()
{
	std::shared_ptr<Rigidbody2dComponent> rigidbody2d = GetEntity()->GetComponent<Rigidbody2dComponent>();
	rigidbody2d->GetOnCollisionEnterEvent() += _onCollisionEnterSlot;

	new Ball();
}

void Ball::OnCollisionEnter(const hod::physics::Collision& collision)
{
	OUTPUT_MESSAGE("{} / {}", (void*)collision._colliderA, (void*)collision._colliderB);
}
