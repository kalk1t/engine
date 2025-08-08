#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


#include "platform.h"


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


int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nCmdShow) {

    if (!platform_init()) return EXIT_FAILURE;

    PlatformWindow win=platform_create_window(&(PlatformWindowDesc){
        .width = 900,
        .height = 900,
        .title = "My Engine Window"
	});

	double last_time = platform_get_time();
    while (!win.should_close) {


		platform_poll_events(&win);		// Update and render logic here

        double current_time = platform_get_time();
		double delta_time = current_time - last_time;
        last_time = current_time;

			//TODO : update_game_logic(delta_time);
			//TODO : render_game();

			// For demonstration, just print the delta time
			//platform_sleep(1.0/60.0 -delta_time); // Sleep to maintain 60 FPS
    }

    platform_cleanup();
	return EXIT_SUCCESS;
}