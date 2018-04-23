#include <iostream>
#include <string>
#include <memory>

using namespace std;
#include <string>
using namespace std;

struct Renderer
{
	virtual string what_to_render_as() const = 0;
};

struct Shape
{
protected:
	const Renderer& renderer;
	Shape(const Renderer& renderer) : renderer{ renderer } {}
public:
	string name;
	string str() {
		return "Drawing " + name + " as " + renderer.what_to_render_as();
	}
};

struct Triangle : Shape
{
	Triangle(const Renderer& rr) : Shape(rr)
	{
		name = "Triangle";
	}
};

struct Square : Shape
{
	Square(const Renderer& rr) : Shape{ rr }
	{
		name = "Square";
	}
};

struct RasterRenderer : Renderer
{
	string what_to_render_as() const
	{
		return "pixels";
	}
};

struct VectorRenderer : Renderer
{
	string what_to_render_as() const
	{
		return "lines";
	}
};
// imagine e.g. VectorTriangle/RasterTriangle etc. here
int main(int argc, char* argv[])
{
	cout << Triangle{ RasterRenderer{} }.str() << endl;

	return 0;

}
