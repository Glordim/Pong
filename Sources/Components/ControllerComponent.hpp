#pragma once
#include "Pong.hpp"

#include <HodEngine/Game/Component.hpp>
#include <HodEngine/Game/Components/Node2dComponent.hpp>
#include <HodEngine/Game/WeakComponent.hpp>

class PawnComponent;

class PONG_API ControllerComponent : public hod::game::Component
{
	REFLECTED_CLASS(ControllerComponent, hod::game::Component, PONG_API);

public:

	void Posses(std::shared_ptr<PawnComponent> pawn);
	void Unposses();

	std::shared_ptr<PawnComponent> GetPawn() const;

private:

	std::weak_ptr<PawnComponent>	_pawn;
};
