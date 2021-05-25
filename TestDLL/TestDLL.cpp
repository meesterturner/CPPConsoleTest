#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>

#include "TestDLL.h"

int isLower(int a, int b)
{
	if (a < b)
		return a;

	return b;
}