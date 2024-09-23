#include "Paddle.hpp"
#include <HodEngine/Game/Entity.hpp>
#include <HodEngine/Game/Components/Node2dComponent.hpp>
#include <HodEngine/Game/Components/Physics/2d/Rigidbody2dComponent.hpp>

using namespace hod;
using namespace hod::game;

DESCRIBE_REFLECTED_CLASS(Paddle, Pawn)
{
	ADD_PROPERTY(Paddle, _speed);
	ADD_PROPERTY(Paddle, _limitY);
}

void Paddle::OnAwake()
{
	_node = GetEntity()->GetComponent<hod::game::Node2dComponent>();
	_rigidbody = GetEntity()->GetComponent<hod::game::Rigidbody2dComponent>();
}

void Paddle::Move(float value)
{
	if (value > 0.0f && _node.lock()->GetPosition().GetY() >= _limitY)
	{
		value = 0.0f;
	}
	else if (value < 0.0f && _node.lock()->GetPosition().GetY() <= -_limitY)
	{
		value = 0.0f;
	}
	_rigidbody.lock()->SetVelocity(Vector2(0.0f, value * _speed));
}
