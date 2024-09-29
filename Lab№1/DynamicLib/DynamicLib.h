#ifndef DYNAMIC_FUNCTIONS_H
#define DYNAMIC_FUNCTIONS_H

#if defined(DYNAMICLIB_EXPORTS)
#define LIBSPEC extern "C" __declspec(dllexport)
#else
#define LIBSPEC extern "C"__declspec(dllimport)
#endif

namespace func {
	LIBSPEC void BubbleSort(int* a, int n);
}
#endif