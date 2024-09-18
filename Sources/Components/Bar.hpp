#pragma once
#include "Pong.hpp"

#include "Pawn.hpp"

namespace hod::game
{
	class Node2dComponent;
}

class PONG_API Bar : public Pawn
{
	REFLECTED_CLASS(Bar, Pawn, PONG_API);

public:

	void	OnAwake() override;

	void	Move(float value);

private:

	std::weak_ptr<hod::game::Node2dComponent> _node;

	float _speed = 3.0f;
};
