#include <iostream>
#include <string>
#include <memory>

using namespace std;
#include <string>
using namespace std;

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <string>
using namespace std;

struct Flower
{
	virtual string str() = 0;
};

struct Rose : Flower
{
	string str() override {
		return "A rose";
	}
};

struct RedFlower : Flower
{
	Flower& flower;
	RedFlower(Flower& flw) : flower{ flw } {

	}
	string str() override {
		string str = flower.str();
		if (str.find("red") != string::npos) return str;
		if (flower.str().find("that is") == std::string::npos)
			return str + " that is red";
		else
			return str + " and red";
	}
};

struct BlueFlower : Flower
{
	Flower& flower;
	BlueFlower(Flower& flw) : flower{ flw } {

	}
	string str() override {
		string str = flower.str();
		if (str.find("blue") != string::npos) return str;
		if (flower.str().find("that is") == std::string::npos)
			return str + " that is blue";
		else
			return str + " and blue";
	}
};

int main(int argc, char* argv[])
{
	Rose rose;
	BlueFlower blue_rose{ rose };
	RedFlower red_rose{ rose };
	RedFlower red_blue_rose{ blue_rose };
	cout << red_rose.str() << endl;
	cout << blue_rose.str() << endl;
	cout << red_blue_rose.str() << endl;
	return 0;
}
