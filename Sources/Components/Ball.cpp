#include "Ball.hpp"
#include <HodEngine/Game/Entity.hpp>
#include <HodEngine/Game/Components/Node2dComponent.hpp>
#include <HodEngine/Game/Components/Physics/2d/Rigidbody2dComponent.hpp>
#include <HodEngine/Game/Components/Physics/2d/Collider2dComponent.hpp>
#include <HodEngine/Physics/Collision.hpp>
#include <HodEngine/Physics/Collision.hpp>
#include <HodEngine/Core/Output/OutputService.hpp>

using namespace hod;
using namespace hod::game;

DESCRIBE_REFLECTED_CLASS(Ball, Component)
{
	ADD_PROPERTY(Ball, _speed);
}

Ball::Ball()
: _onCollisionEnterSlot(std::bind(&Ball::OnCollisionEnter, this, std::placeholders::_1))
, _onCollisionExitSlot(std::bind(&Ball::OnCollisionExit, this, std::placeholders::_1))
{

}

void Ball::OnAwake()
{
	std::shared_ptr<Rigidbody2dComponent> rigidbody2d = GetEntity()->GetComponent<Rigidbody2dComponent>();
	rigidbody2d->GetOnCollisionEnterEvent() += _onCollisionEnterSlot;
	rigidbody2d->GetOnCollisionExitEvent() += _onCollisionExitSlot;

	LaunchBall();
}

void Ball::LaunchBall()
{
	float randomDirectionX = rand() % 2 == 0 ? -1.0f : 1.0f;
	float randomDirectionY = -1.0f + ((float)rand() / RAND_MAX) * (1.0f - -1.0f);

	std::shared_ptr<Rigidbody2dComponent> rigidbody2d = GetEntity()->GetComponent<Rigidbody2dComponent>();
    rigidbody2d->SetVelocity(Vector2::Normalize(Vector2(randomDirectionX, randomDirectionY)) * _speed);
}

void Ball::OnCollisionEnter(const hod::physics::Collision& collision)
{
	OUTPUT_MESSAGE("Enter {} / {}", (void*)&collision._colliderA, (void*)&collision._colliderB);
	/*
	// Ajouter un effet pour changer la direction de la balle en fonction du point d'impact
	//Vector2 hitPoint = collision. contacts[0].point;
	Vector2 paddleCenter = collision._colliderB.  bounds.center;

	// Calculer la différence entre l'impact et le centre de la raquette
	float difference = hitPoint.y - paddleCenter.y;
	*/
	// Appliquer la différence à la direction de la balle

	std::shared_ptr<Rigidbody2dComponent> rigidbody2d = GetEntity()->GetComponent<Rigidbody2dComponent>();
    //rigidbody2d->SetVelocity(Vector2::Normalize(rigidbody2d->GetVelocity()) * _speed);
}

void Ball::OnCollisionExit(const hod::physics::Collision& collision)
{
	OUTPUT_MESSAGE("Exit {} / {}", (void*)&collision._colliderA, (void*)&collision._colliderB);
}
