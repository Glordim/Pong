#include "PlayerController.hpp"
#include "Paddle.hpp"

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
	std::shared_ptr<Paddle> paddle = std::static_pointer_cast<Paddle>(GetPawn());

	InputManager* inputManager = InputManager::GetInstance();

	Input::State upState = inputManager->GetInputState(InputId::KeyW);
	if (upState.IsPressed())
	{
		paddle->Move(upState._value);
	}
	else
	{
		Input::State downState = inputManager->GetInputState(InputId::KeyS);
		if (downState.IsPressed())
		{
			paddle->Move(-downState._value);
		}
		else
		{
			paddle->Move(0.0f);
		}
	}
}
