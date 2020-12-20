#include "Snake.h"

Snake::Snake(Location startLocation, int startSize)
{
	for (int i = 0; i < startSize; i++) {
		short colour = i % 2 == 0 ? Colours::FG_GREEN : Colours::FG_DARK_GREEN;
		if (i == 0)
			colour = Colours::FG_YELLOW;
		segments.emplace_back(
			Segment(
				Location{ startLocation.x - i, startLocation.y },
				colour
			)
		);
	}
}

Location Snake::GetHeadLocation() const
{
	return segments.front().GetLocation();
}

const bool Snake::IsCollidingWithSelf() const
{
	Location head = GetHeadLocation();
	for (auto segment = segments.begin() + 1; segment < segments.end(); segment++) {
		if (segment->GetLocation() == head) return true;
	}

	return false;
}

void Snake::Grow()
{
	segments.emplace_back(
		Segment(
			segments.back().GetLocation(),
			segments.size() % 2 == 0 ? Colours::FG_GREEN : Colours::FG_DARK_GREEN
		)
	);
}

void Snake::Move(Location direction)
{
	// Ensure snake can't back onto itself
	auto head = segments.begin();
	if ((head->GetLocation() + direction) == (head + 1)->GetLocation())
		return;

	// Move all the segments
	for (int i = segments.size() - 1; i > 0; i--) {
		segments[i].Follow(segments[i - 1]);
	}
	segments.front().Move(direction);
}

void Snake::Draw() const
{
	for (auto segment : segments) {
		segment.Draw();
	}
}

Snake::Segment::Segment(Location location, short colour) :
	location(location), colour(colour)
{
}

Location Snake::Segment::GetLocation() const
{
	return location;
}

void Snake::Segment::Move(Location direction)
{
	location.x += direction.x;
	location.y += direction.y;
}

void Snake::Segment::Follow(Segment& next)
{
	location = next.location;
}

void Snake::Segment::Draw() const
{
	Console::GetInstance().
		Draw(location.x, location.y, L'\u2588', colour);
}
