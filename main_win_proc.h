#pragma once

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    switch (uMsg) {

    case WM_CREATE:
    {

        return 0;
    }

    case WM_COMMAND:
    {

        return 0;
    }

    case WM_PAINT:
    {

        return 0;
    }

    case WM_DESTROY:
    {


        PostQuitMessage(0);
        return 0;
    }



    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
	return 0;
}
