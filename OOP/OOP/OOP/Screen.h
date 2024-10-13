#pragma once

#include <Windows.h>
#include <iostream>

class Screen {
	HANDLE _handle;
public:
	Screen() {
		_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	template<class T>
	Screen& operator<<(const T& value) { std::cout << value; return *this; }

	Screen& SetCursor(int x, int y) {
		COORD coord = { x, y };
		SetConsoleCursorPosition(_handle, coord);
		return *this;
	}
	Screen& ShowCursor(bool visible) {
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100; // 100%
		info.bVisible = visible;
		SetConsoleCursorInfo(_handle, &info);
		return *this;
	}
	Screen& SetColor(int text, int background = 0) {
		SetConsoleTextAttribute(_handle, (background << 4) | text);
		return *this;
	}
	Screen& ResetColor() { return SetColor(7); }

	void Wait(int ms) { Sleep(ms); }
};