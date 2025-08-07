#include <windows.h>
#include <stdio.h>

#include "main_win_proc.h"

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"MyWindowClass";

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = NULL; // We fully handle background ourselves
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); //Set a default cursor

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Scripting",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        (GetSystemMetrics(SM_CXSCREEN) - 900) / 2,
        (GetSystemMetrics(SM_CYSCREEN) - 900) / 2,
        900,
        900,
        NULL, NULL, hInstance, NULL
    );

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}