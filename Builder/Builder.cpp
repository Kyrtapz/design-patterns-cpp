#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Element
{
	string name, type;

public:
	Element(const string& name, const string& type) : name(name), type(type)
	{}

	friend std::ostream& operator<<(std::ostream& os, const Element& obj) {
		return os << obj.type << " " << obj.name << ";";
	}
};

class CodeBuilder {
	string name;
	std::vector<Element> elements;

public:
	CodeBuilder(string n) : name(n)
	{}

	CodeBuilder& add_field(string name, string type) {
		elements.emplace_back(Element{name, type});
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const CodeBuilder& gen) {
		os << "class " << gen.name << "\n{\n";
		for (const auto& elem : gen.elements) {
			os << "  " << elem << "\n";
		}
		os << "};";
		return os;
	}
};

int main(int argc, char* argv[])
{
	std::cout << CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
	return 0;
}

