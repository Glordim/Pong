#pragma once
#include "../Pong.hpp"

#include "Controller.hpp"

class PONG_API PlayerController : public Controller
{
	REFLECTED_CLASS(PlayerController, Controller, PONG_API);

public:

	void OnAwake() override;
	void OnUpdate() override;
};
