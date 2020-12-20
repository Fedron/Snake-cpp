#pragma once

struct Location {
	int x;
	int y;

	Location operator+(Location other) {
		x += other.x;
		y += other.y;

		return *this;
	}

	bool operator==(Location other) {
		return x == other.x && y == other.y;
	}

	bool operator!=(Location other) {
		return x != other.x && y != other.y;
	}
};