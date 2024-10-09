#pragma once
#include "../Pong.hpp"

#include <HodEngine/Game/Component.hpp>
#include <HodEngine/Game/Components/Node2dComponent.hpp>
#include <HodEngine/Game/WeakComponent.hpp>

class Pawn;

class PONG_API Controller : public hod::game::Component
{
	REFLECTED_CLASS(Controller, hod::game::Component, PONG_API);

public:

	void Posses(std::shared_ptr<Pawn> pawn);
	void Unposses();

	std::shared_ptr<Pawn> GetPawn() const;

private:

	std::weak_ptr<Pawn>	_pawn;
};
