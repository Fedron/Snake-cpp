#include "Snake.h"

Snake::Snake(Location startLocation, int startSize)
{
	for (int i = 0; i < startSize; i++) {
		segments.emplace_back(
			Location{ startLocation.x - i, startLocation.y }
		);
	}
}

void Snake::Draw() const
{
	for (auto segment : segments) {
		segment.Draw();
	}
}

Snake::Segment::Segment(Location location) :
	location(location)
{
}

void Snake::Segment::Follow(Segment& next)
{
}

void Snake::Segment::Draw() const
{
	Console::GetInstance().
		Draw(location.x, location.y, L'\u25a0', Colours::FG_WHITE);
}
