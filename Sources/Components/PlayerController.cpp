#include "PlayerController.hpp"
#include "Bar.hpp"

#include <HodEngine/Game/Entity.hpp>
#include <HodEngine/Input/InputManager.hpp>

using namespace hod::input;

DESCRIBE_REFLECTED_CLASS(PlayerController, Controller)
{
}

void PlayerController::OnAwake()
{
	std::shared_ptr<Pawn> pawn = GetEntity()->GetComponent<Pawn>();
	if (pawn != nullptr)
	{
		Posses(pawn);
	}
}

void PlayerController::OnUpdate()
{
	InputManager* inputManager = InputManager::GetInstance();

	Input::State upState = inputManager->GetInputState(InputId::KeyW);
	if (upState.IsPressed())
	{
		std::shared_ptr<Bar> bar = std::static_pointer_cast<Bar>(GetPawn());
		bar->Move(upState._value);
	}

	Input::State downState = inputManager->GetInputState(InputId::KeyS);
	if (downState.IsPressed())
	{
		std::shared_ptr<Bar> bar = std::static_pointer_cast<Bar>(GetPawn());
		bar->Move(-downState._value);
	}
}
