#include "Pawn.hpp"

DESCRIBE_REFLECTED_CLASS(Pawn, hod::game::Component)
{
}

std::shared_ptr<Controller> Pawn::GetController() const
{
	return _controller.lock();
}

void Pawn::SetController(std::shared_ptr<Controller> controller)
{
	_controller = controller;
}
