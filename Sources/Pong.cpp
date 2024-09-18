#include "Pong.hpp"
#include <HodEngine/Game/ComponentFactory.hpp>

#include "Components/Ball.hpp"
#include "Components/Bar.hpp"
#include "Components/PlayerController.hpp"

/// @brief 
/// @return 
int Init()
{
	hod::game::ComponentFactory* componentFactory = hod::game::ComponentFactory::GetInstance();
	componentFactory->Register<Ball>();
	componentFactory->Register<Bar>();
	componentFactory->Register<PlayerController>();
	return 0;
}

/// @brief 
/// @return 
int Clean()
{
	hod::game::ComponentFactory* componentFactory = hod::game::ComponentFactory::GetInstance();
	componentFactory->Unregister<Ball>();
	componentFactory->Unregister<Bar>();
	componentFactory->Unregister<PlayerController>();
	return 0;
}
