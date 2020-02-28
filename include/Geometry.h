
struct sPos {
	sPos();
	sPos(int aX, int aY);
	int x;
	int y;
};
struct sSize
{
	sSize();
	sSize(int aW, int aH);
	int width;
	int height;
};
struct sRect
{
	sRect();
	sRect(int x, int y, int w, int h);
	sPos pos;
	sSize size;
	bool intersects(const sRect& other);
};

enum class eDirection {
	UP,
	LEFT,
	RIGHT,
	DOWN
};
