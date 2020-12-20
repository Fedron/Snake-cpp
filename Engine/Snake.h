#pragma once
#include <vector>

#include "Console.h"
#include "Location.h"

class Snake
{
private:
	class Segment {
	public:
		Segment(Location location, short colour);
		Location GetLocation() const;
		void Move(Location direction);
		void Follow(Segment& next);
		void Draw() const;

	private:
		Location location;
		short colour;
	};

public:
	Snake(Location startLocation, int startSize);

	Location GetHeadLocation() const;
	const bool IsCollidingWithSelf() const;
	void Grow();
	void Move(Location direction);
	void Draw() const;

private:
	std::vector<Segment> segments;
};
