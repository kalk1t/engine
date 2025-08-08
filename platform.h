#pragma once	

static LONGLONG qpc_frequency;

typedef struct {
	int width, height;
	const char* title;
}PlatformWindowDesc;

typedef struct {
	void* handle;		//opaque, backend-specific window handle
	bool should_close;	// set true when user request close
}PlatformWindow;

bool platform_init(void) {
	QueryPerformanceFrequency((LARGE_INTEGER*)&qpc_frequency);
	return true;
}

PlatformWindow platform_create_window(const PlatformWindowDesc* desc) {
	WNDCLASSA wc = { 0 };
	wc.lpfnWndProc = DefWindowProcA;
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpszClassName = "MyEngineWindowClass";
	RegisterClassA(&wc);

	HWND hwnd = CreateWindowA(
		wc.lpszClassName, desc->title,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		desc->width, desc->height, NULL, NULL, wc.hInstance, NULL);

	ShowWindow(hwnd, SW_SHOW);

	PlatformWindow win = { .handle = hwnd, .should_close = false };

	return win;
}

void platform_poll_events(PlatformWindow* win) {
		MSG msg;
	while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
		if (msg.message == WM_QUIT) {
			win->should_close = true;
			return;
		}
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
}

double platform_get_time(void) {
	LONGLONG time;
	QueryPerformanceCounter((LARGE_INTEGER*)&time);
	return (double)time / qpc_frequency;
}

void platform_cleanup(void) {
	// No specific cleanup needed for this simple platform abstraction
}


/*Input*/
bool   platform_key_down(int key) {
	return (GetAsyncKeyState(key) & 0x8000) != 0;
}

void platform_cursor_pos(double * x, double* y) {
	POINT p;
	GetCursorPos(&p);
	*x = (double)p.x;
	*y = (double)p.y;
}


/* FILE I/O */
bool platform_read_file(const char* path, void** out_data, size_t* out_size) {
	FILE* f = fopen(path, "rb");
	if (!f) return false;
	fseek(f, 0, SEEK_END);
	long sz = ftell(f);
	rewind(f);
	void* buf = malloc(sz);
	if (!buf) { fclose(f); return false; }
	if (fread(buf, 1, sz, f) != (size_t)sz) {
		free(buf);
		fclose(f);
		return false;
	}
	fclose(f);
	*out_data = buf;
	*out_size = (size_t)sz;
	return true;
}


void platform_free_file(void* data) {
	free(data);
}