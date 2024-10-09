#pragma once
#include "../Pong.hpp"

#include "Pawn.hpp"

namespace hod::game
{
	class Node2dComponent;
	class Rigidbody2dComponent;
}

class PONG_API Paddle : public Pawn
{
	REFLECTED_CLASS(Paddle, Pawn, PONG_API);

public:

	void	OnAwake() override;

	void	Move(float value);

private:

	std::weak_ptr<hod::game::Node2dComponent> _node;
	std::weak_ptr<hod::game::Rigidbody2dComponent> _rigidbody;

	float _speed = 3.0f;
	float _limitY = 3.4f;
};
