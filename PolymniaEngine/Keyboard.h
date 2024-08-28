#pragma once
#include <Windows.h>

class Keyboard
{
public:
	void OnKeyDown(UINT_PTR wParam);
	void OnKeyUp(UINT_PTR wParam);
};

