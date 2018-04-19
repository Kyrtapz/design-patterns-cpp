#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct Point
{
	int x{ 0 }, y{ 0 };

	Point(){}

	Point(const int x, const int y) : x{ x }, y{ y } {}
	Point(const Point& other) : x{ other.x }, y{ other.y } {}

	friend ostream& operator<<(ostream& os, const Point& p)
	{
		return os << "X: " << p.x << ", Y: " << p.y;
	}
};

struct Line
{
	Point *start, *end;

	Line(Point* const start, Point* const end)
		: start(start), end(end)
	{
	}

	~Line()
	{
		delete start;
		delete end;
	}

	Line(const Line& other)
	{
		start = new Point{ *other.start };
		end = new Point{ *other.end };
	}

	friend ostream& operator<<(ostream& os, const Line& l)
	{
		return os << "Start (" << *l.start << ") End(" << *l.end << ")\n";
	}
};

struct LineFactory
{
	static unique_ptr<Line> new_zero_line(const Point& end) {
		static Line proto = Line{ new Point{ 0, 0 }, new Point{ 0, 0 } };
		return new_line(end, proto);
	}
private:
	static unique_ptr<Line> new_line(const Point& end, const Line& prototype) {
		auto ret = make_unique<Line>(prototype);
		ret->end->x = end.x;
		ret->end->y = end.y;
		return ret;
	}
};


int main(int argc, char* argv[])
{
	auto line1 = LineFactory::new_zero_line(Point{ 1, 1 });
	auto line2 = LineFactory::new_zero_line(Point{ 2, 2 });
	cout << *line1 << *line2;
	return 0;

}

