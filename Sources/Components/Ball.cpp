#include "Ball.hpp"
#include <HodEngine/Game/World.hpp>
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
, _onTriggerEnterSlot(std::bind(&Ball::OnTriggerEnter, this, std::placeholders::_1, std::placeholders::_2))
, _onTriggerExitSlot(std::bind(&Ball::OnTriggerExit, this, std::placeholders::_1, std::placeholders::_2))
{

}

void Ball::OnAwake()
{
	std::shared_ptr<Rigidbody2dComponent> rigidbody2d = GetEntity()->GetComponent<Rigidbody2dComponent>();
	rigidbody2d->GetOnCollisionEnterEvent() += _onCollisionEnterSlot;
	rigidbody2d->GetOnCollisionExitEvent() += _onCollisionExitSlot;
	rigidbody2d->GetOnTriggerEnterEvent() += _onTriggerEnterSlot;
	rigidbody2d->GetOnTriggerExitEvent() += _onTriggerExitSlot;

	LaunchBall();
}

void Ball::LaunchBall()
{
	float randomDirectionX = rand() % 2 == 0 ? -1.0f : 1.0f;
	float randomDirectionY = -1.0f + ((float)rand() / (float)RAND_MAX) * (1.0f - -1.0f);

	Vector2 newVelocity = Vector2::Normalize(Vector2(randomDirectionX, randomDirectionY)) * _speed;

	std::shared_ptr<Rigidbody2dComponent> rigidbody2d = GetEntity()->GetComponent<Rigidbody2dComponent>();
    rigidbody2d->SetVelocity(newVelocity);
	_lastVelocity = newVelocity;
}

void Ball::OnUpdate()
{
	std::shared_ptr<Node2dComponent> node2d = GetEntity()->GetComponent<Node2dComponent>();
	Vector2 position = node2d->GetWorldMatrix().GetTranslation();

	//World::GetInstance()->DrawDebugLine(position, position + Vector2::Normalize(_lastVelocity) * 0.3f, Color(1.0f, 1.0f, 1.0f, 1.0f));
}

void Ball::OnCollisionEnter(const hod::physics::Collision& collision)
{
	//OUTPUT_MESSAGE("Enter {} / {}", (void*)&collision._colliderA, (void*)&collision._colliderB);
	/*
	// Ajouter un effet pour changer la direction de la balle en fonction du point d'impact
	//Vector2 hitPoint = collision. contacts[0].point;
	Vector2 paddleCenter = collision._colliderB.  bounds.center;

	// Calculer la différence entre l'impact et le centre de la raquette
	float difference = hitPoint.y - paddleCenter.y;
	*/
	// Appliquer la différence à la direction de la balle

	Vector2 newVelocity = Vector2::Normalize(Vector2::Reflect(_lastVelocity, collision._normal)) * _speed;

	std::shared_ptr<Node2dComponent> node2d = GetEntity()->GetComponent<Node2dComponent>();
	Vector2 position = node2d->GetWorldMatrix().GetTranslation();

	//World::GetInstance()->DrawDebugLine(position, position - Vector2::Normalize(_lastVelocity), Color(1.0f, 0.0f, 0.0f, 1.0f), 3.0f);
	//World::GetInstance()->DrawDebugLine(position, position + Vector2::Normalize(collision._normal), Color(0.0f, 0.0f, 1.0f, 1.0f), 3.0f);
	//World::GetInstance()->DrawDebugLine(position, position + Vector2::Normalize(newVelocity), Color(0.0f, 1.0f, 0.0f, 1.0f), 3.0f);

	std::shared_ptr<Rigidbody2dComponent> rigidbody2d = GetEntity()->GetComponent<Rigidbody2dComponent>();
    rigidbody2d->SetVelocity(newVelocity);
	_lastVelocity = newVelocity;

	OUTPUT_MESSAGE("Normal : {} / {}", collision._normal.GetX(), collision._normal.GetY());
	OUTPUT_MESSAGE("Last : {} / {}", _lastVelocity.GetX(), _lastVelocity.GetY());
	OUTPUT_MESSAGE("New : {} / {}", newVelocity.GetX(), newVelocity.GetY());
}

void Ball::OnCollisionExit(const hod::physics::Collision& collision)
{
	//OUTPUT_MESSAGE("Exit {} / {}", (void*)&collision._colliderA, (void*)&collision._colliderB);
}

void Ball::OnTriggerEnter(const hod::physics::Collider& trigger, const hod::physics::Collider& visitor)
{
	OUTPUT_MESSAGE("Trigger Enter");
}

void Ball::OnTriggerExit(const hod::physics::Collider& trigger, const hod::physics::Collider& visitor)
{
	OUTPUT_MESSAGE("Trigger Exit");
}
