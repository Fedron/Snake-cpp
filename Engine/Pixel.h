#pragma once
#include <iostream>

#define COLOR_WHITE 7
#define COLOR_GREEN 10

struct Pixel
{
	wchar_t character = L' ';
	int color = COLOR_WHITE;

	void Set(wchar_t character, int color) {
		this->character = character;
		this->color = color;
	}
};

//namespace Color {
//	static const std::string Black = "30";
//	static const std::string Red = "31";
//	static const std::string Green = "32";
//	static const std::string Yellow = "33";
//	static const std::string Blue = "34";
//	static const std::string Magenta = "35";
//	static const std::string Cyan = "36";
//	static const std::string White = "37";
//}
