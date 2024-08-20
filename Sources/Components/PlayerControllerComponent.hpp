#pragma once
#include "Pong.hpp"

#include "ControllerComponent.hpp"

class PONG_API PlayerControllerComponent : public ControllerComponent
{
	REFLECTED_CLASS(PlayerControllerComponent, ControllerComponent, PONG_API);

public:

	void OnAwake() override;
	void OnUpdate() override;
};
