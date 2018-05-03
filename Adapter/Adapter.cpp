#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Square
{
	int side{ 0 };


	explicit Square(const int side)
		: side(side)
	{
	}
};

struct Rectangle
{
	virtual int width() const = 0;
	virtual int height() const = 0;

	int area() const
	{
		return width() * height();
	}
};

struct SquareToRectangleAdapter : Rectangle
{
	Square sq;
	SquareToRectangleAdapter(const Square& square) : sq(square)
	{ }
	int width() const {
		return sq.side;
	}
	int height() const {
		return sq.side;
	}
};

int main(int argc, char* argv[])
{
	Square sq(2);
	auto rectangle = SquareToRectangleAdapter(sq);
	cout << "The square area is: " << rectangle.area() << endl; 

	return 0;

}
