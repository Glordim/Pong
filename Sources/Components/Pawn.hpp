#pragma once
#include "../Pong.hpp"

#include <HodEngine/Game/Component.hpp>

class Controller;

class PONG_API Pawn : public hod::game::Component
{
	REFLECTED_CLASS(Pawn, hod::game::Component, PONG_API);

	friend class Controller;

public:

	std::shared_ptr<Controller> GetController() const;

private:

	void SetController(std::shared_ptr<Controller> controller);

private:

	std::weak_ptr<Controller> _controller;
};
