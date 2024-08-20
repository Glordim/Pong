#pragma once
#include "Pong.hpp"

#include <HodEngine/Game/Component.hpp>

class ControllerComponent;

class PONG_API PawnComponent : public hod::game::Component
{
	REFLECTED_CLASS(PawnComponent, hod::game::Component, PONG_API);

	friend class ControllerComponent;

public:

	std::shared_ptr<ControllerComponent> GetController() const;

private:

	void SetController(std::shared_ptr<ControllerComponent> controller);

private:

	std::weak_ptr<ControllerComponent> _controller;
};
