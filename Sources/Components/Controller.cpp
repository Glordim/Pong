#include "Controller.hpp"
#include "Pawn.hpp"

DESCRIBE_REFLECTED_CLASS(Controller, hod::game::Component)
{
}

void Controller::Posses(std::shared_ptr<Pawn> pawn)
{
	std::shared_ptr<Pawn> previousPawn = _pawn.lock();
	if (previousPawn != nullptr)
	{
		Unposses();
	}

	_pawn = pawn;
	pawn->SetController(std::static_pointer_cast<Controller>(shared_from_this()));
}

void Controller::Unposses()
{
	std::shared_ptr<Pawn> previousPawn = _pawn.lock();
	if (previousPawn != nullptr)
	{
		previousPawn->SetController(nullptr);
		_pawn.reset();
	}
}

std::shared_ptr<Pawn> Controller::GetPawn() const
{
	return _pawn.lock();
}
