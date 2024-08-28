#include "Keyboard.h"
#include <iostream>
#include <basetsd.h>


void Keyboard::OnKeyDown(UINT_PTR wParam)
{
	switch (wParam)
	{
		case VK_LEFT:
			// Process the LEFT ARROW key. 
			break;

		case VK_RIGHT:
			// Process the RIGHT ARROW key. 
			break;

		case VK_UP:
			// Process the UP ARROW key. 
			break;

		case VK_DOWN:
			// Process the DOWN ARROW key. 
			break;

		case VK_HOME:
			// Process the HOME key. 
			break;

		case VK_END:
			// Process the END key. 
			break;

		case VK_INSERT:
			// Process the INS key. 
			break;

		case VK_DELETE:
			// Process the DEL key. 
			break;

		case VK_F2:
			// Process the F2 key. 
			break;

		default:
			// Process other non-character keystrokes. 
			break;
	}
}

void Keyboard::OnKeyUp(UINT_PTR wParam)
{
}
