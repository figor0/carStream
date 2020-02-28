#include <Geometry.h>

sRect::sRect() {}

sRect::sRect(int x, int y, int w, int h) { pos.x = x; pos.y = y; size.width = w; size.height = h; }

bool sRect::intersects(const sRect &other) {
	return !((other.pos.x + other.size.width <= pos.x) ||
			 (other.pos.y + other.size.height <= pos.y) ||
			 (other.pos.x >= pos.x + size.width) ||
			 (other.pos.y >= pos.y + size.height));
}

sSize::sSize() { width = 0; height = 0; }

sSize::sSize(int aW, int aH) { width = aW; height = aW; }

sPos::sPos() { x = 0; y = 0; }

sPos::sPos(int aX, int aY) { x = aX; y = aY; }
