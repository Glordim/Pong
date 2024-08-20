#pragma once
#include "Pong.hpp"

#include "PawnComponent.hpp"

namespace hod::game
{
	class Node2dComponent;
}

class PONG_API BarComponent : public PawnComponent
{
	REFLECTED_CLASS(BarComponent, PawnComponent, PONG_API);

public:

	void	OnAwake() override;

	void	Move(float value);

private:

	std::weak_ptr<hod::game::Node2dComponent> _node;

	float _speed = 3.0f;
};
