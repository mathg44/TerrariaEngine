#pragma once

#ifdef ENG_PLATFORM_WINDOWS
	#ifdef ENG_BUILD_DLL
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif	
#else
	#error Engine only support Windows
#endif

// Bit Macro
#define BIT(x) (1 << x)