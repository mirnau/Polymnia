#include "Window.h"
#include "resource.h"

Window::Window(uint32_t width, uint32_t height, const wchar_t* name) noexcept
    : 
    width(width), 
    height(height), 
    wndName(name),
    hwnd(nullptr),
    hInstance(GetModuleHandle(nullptr))
{
    WNDCLASSEX wc = { };

    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.lpszClassName = wndName;
    wc.hIcon = static_cast<HICON>(LoadImage(hInstance, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 32, 32, 0));
    wc.hIconSm = static_cast<HICON>(LoadImage(hInstance, MAKEINTRESOURCE(IDI_ICON1), IMAGE_ICON, 16, 16, 0));

    RegisterClassEx(&wc); 	// Register the window class.

    RECT wndRect{};
    wndRect.left = 100;
    wndRect.right = wndRect.left + width;
    wndRect.top = 100;
    wndRect.bottom = wndRect.top + height;

    AdjustWindowRect(&wndRect, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE);

    hwnd = CreateWindowEx(
        0,                           // Optional window styles.
        wndName,                     // Window class
        wndName,					 // Window text
        WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, wndRect.right - wndRect.left, wndRect.bottom - wndRect.top,

        nullptr,       // Parent window    
        nullptr,       // Menu
        hInstance,	   // Instance handle
        this		   // Additional application data
    );

    ShowWindow(hwnd, SW_SHOWDEFAULT);
};

Window::~Window()
{
    UnregisterClass(wndName, hInstance);
    DestroyWindow(hwnd);
}

// Messagepump
uint32_t Window::ProcessMessages()
{
    MSG msg {};

    while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) // (GetMessage(&msg, nullptr, 0, 0) != 0)//
    {
        if (msg.message == WM_QUIT) 
            return (int)msg.wParam;

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0; //Returns quit with no errors
}

//Behaviour of the window
LRESULT _stdcall Window::WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_QUIT:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT:
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        {
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
        }
        EndPaint(hwnd, &ps);
        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}