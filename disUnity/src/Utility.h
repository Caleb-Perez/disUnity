#pragma once

#define START_GAME(className) \
int main() { \
	className _game; \
	_game.Run(); \
} 

#ifdef DISUNITY_MS_COMPILER
	#ifdef DISUNITY_LIB
		#define DISUNITY_API __declspec(dllexport)
	#else
		#define DISUNITY_API __declspec(dllimport)
	#endif
#else 
	#define DISUNITY_API
#endif


#if DISUNITY_DEBUG == 2
	#define DISUNITY_ERROR(x) std::cout << x << std::endl;
	#define DISUNITY_LOG(x) std::cout << x << std::endl;
#elif DISUNITY_DEBUG == 1
	#define DISUNITY_ERROR(x) std::cout << x << std::endl;
	#define DISUNITY_LOG(x)
#else
	#define DISUNITY_ERROR(x)
	#define DISUNITY_LOG(x)
#endif