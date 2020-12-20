#pragma once
#include <vector>

#include "Console.h"
#include "Location.h"

class Snake
{
private:
	class Segment {
	public:
		Segment(Location location);
		Location GetLocation() const;
		void Move(Location direction);
		void Follow(Segment& next);
		void Draw() const;

	private:
		Location location;
	};

public:
	Snake(Location startLocation, int startSize);

	void Move(Location direction);
	void Draw() const;

private:
	std::vector<Segment> segments;
};
