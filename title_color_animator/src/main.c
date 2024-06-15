




#include <Windows.h>

#include <dwmapi.h>


int r = 0;
int g = 0;
int b = 0;

int animation_rate = 5;

void animate();
void increment_colors();
void decrement_colors();

int WinMain(HINSTANCE instance, HINSTANCE previous_instance, LPSTR command_line, int command_show) {

	OutputDebugStringA("Application started");

	while (1) {

		HWND window_handle = GetForegroundWindow();

		COLORREF caption_color = RGB(r, g, b);

		DwmSetWindowAttribute(window_handle, DWMWA_CAPTION_COLOR, &caption_color, sizeof(caption_color));

		animate();

		Sleep(1);

	}

}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {

		case WM_DESTROY:
			PostQuitMessage(0);
			OutputDebugStringA("Finally quit!!");
			return 0;

		// setup a keyboard hook for closing the application
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void increment_colors() {
	if (r != 255 && g != 255 && b != 255) {
		r += animation_rate;
	}

	if (r == 255 && g != 255 && b != 255) {
		g += animation_rate;
	}

	if (r == 255 && g == 255 && b != 255) {
		b += animation_rate;
	}
}

void decrement_colors() {
	if (r != 0 && g != 0 && b != 0) {
		r -= animation_rate;
	}

	if (r == 0 && g != 0 && b != 0) {
		g -= animation_rate;
	}

	if (r == 0 && g == 0 && b != 0) {
		b -= animation_rate;
	}
}

int can_increment_color = 0;
int can_decrement_color = 0;

void animate() {

	Sleep(0.1);

	if (r == 0 && g == 0 && b == 0) {
		can_increment_color = 1;
		can_decrement_color = 0;
	}

	if (r == 255 && g == 255 && b == 255) {
		can_increment_color = 0;
		can_decrement_color = 1;
	}

	if (can_increment_color) {
		
		increment_colors();
		
	}

	if (can_decrement_color) {
		
		decrement_colors();
		
	}

}

