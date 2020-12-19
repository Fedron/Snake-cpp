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
		void Follow(Segment& next);
		void Draw() const;

	private:
		Location location;
	};

public:
	Snake(Location startLocation, int startSize);

	void Draw() const;

private:
	std::vector<Segment> segments;
};
