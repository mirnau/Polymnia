#include "AppWindow.h"
#include <tchar.h>

AppWindow::~AppWindow()
{
	UnregisterClass(szWindowClass, hInstance);
}

LRESULT CALLBACK AppWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
 	//GWLP_USERDATA contains ptr to window
	AppWindow* pThis = reinterpret_cast<AppWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

	if (pThis)
	{
		return pThis->HandleMessage(message, wParam, lParam);
	}
	
	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT AppWindow::HandleMessage(UINT message, WPARAM wParam, LPARAM lParam) noexcept
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, Windows desktop!");

	switch (message)
	{
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
			{
				keyboard.OnKeyDown(wParam, message);
			}
			break;

		case WM_KEYUP:
		case WM_SYSKEYUP:
			{
				keyboard.OnKeyUp(wParam);
			}
			break;

		case WM_CHAR:
			{

			}
		break;

		case WM_PAINT:
			{
				hdc = BeginPaint(hWnd, &ps);

				// Here your application is laid out.
				// For this introduction, we just print out "Hello, Windows desktop!"
				// in the top left corner.
				TextOut(hdc,
					5, 5,
					greeting, _tcslen(greeting));
				// End application specific layout section.

				EndPaint(hWnd, &ps);
			}
			break;

		case WM_DESTROY:
			{
				PostQuitMessage(0);
			}
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
			break;
	}

	return 0;
}

int AppWindow::Init()
{
	WNDCLASSEX wcex{};

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = AppWindow::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

	//Creating the Window

	hWnd = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,			// WS_EX_OVERLAPPEDWINDOW : An optional extended window style.
		szWindowClass,					// szWindowClass: the name of the application
		szTitle,						// szTitle: the text that appears in the title bar
		WS_OVERLAPPEDWINDOW, 			// WS_OVERLAPPEDWINDOW: the type of window to create
		CW_USEDEFAULT,					// Init x-position	
		CW_USEDEFAULT, 					// Init y-position
		500,							// Width
		100, 							// Height
		NULL, 							// NULL: the parent of this window
		NULL, 							// NULL: this application does not have a menu bar
		hInstance,						// hInstance: the first parameter from WinMain
		NULL							// NULL: not used in this application
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindowEx failed!"),
			_T("Windows Desktop Guided Tour"),
			NULL);

		return 1;
	}

	// Store the instance ptr in user data
	SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return Run();
}

int AppWindow::Run() 
{
	MSG msg {};

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int) msg.wParam;
}