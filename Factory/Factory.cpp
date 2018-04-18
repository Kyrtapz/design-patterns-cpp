#include <iostream>
#include <string>
using namespace std;

struct Person
{
	int id;
	string name;
	friend ostream& operator <<(ostream& os, const Person& p) {
		return os << "Name: " << p.name << " Id: " << p.id << endl;
	}
};

class PersonFactory
{
	int cnt = 0;

public:
	Person create_person(const string& name)
	{
		return{ cnt++, name };
	}
};


int main(int argc, char* argv[])
{
	PersonFactory fact;
	Person j = fact.create_person("John");
	Person b = fact.create_person("Barbara");
	cout << j << b << endl;
	return 0;
}


