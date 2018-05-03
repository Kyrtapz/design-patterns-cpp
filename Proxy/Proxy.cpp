// open closed principle

// open for extension, closed for modification

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

#include <sstream>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

using namespace std;

#include <string>
using namespace std;

class Person
{
	friend class ResponsiblePerson;
	int age;
public:
	Person(int age) : age(age) {}

	int get_age() const { return age; }
	void set_age(int age) { this->age = age; }

	string drink() const { return "drinking"; }
	string drive() const { return "driving"; }
	string drink_and_drive() const { return "driving while drunk"; }
};

class ResponsiblePerson
{
	bool drunk;
	Person person;
public:
	ResponsiblePerson(int age) : person(age) {
	}
	ResponsiblePerson(Person p) : person(p) {
	}
	int get_age() const { return person.get_age(); }
	void set_age(int age) { person.set_age(age); }

	int operator()() {
		return get_age();
	}
	int operator=(int age) {
		set_age(age);
		return get_age();
	}
	string drink() const {
		if (get_age() < 18)
			return "too young";
		else
			return person.drink();

	}
	string drive() const {
		if (get_age() < 16)
			return "too young";
		else
			return person.drive();
	}
	string drink_and_drive() const { return "dead"; }
};



int main()
{
	Person a{ 2 };
	ResponsiblePerson b{ 18 };
	cout << a.drink() << endl << b.drink_and_drive() << endl;
	return 0;
}