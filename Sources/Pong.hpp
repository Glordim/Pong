#include <HodEngine/HodEngine.hpp>

#if defined(PONG_EXPORT)
	#define PONG_API HOD_EXPORT
#else
	#define PONG_API HOD_IMPORT
#endif

extern "C"
{
	PONG_API int Init();
	PONG_API int Clean();
}
