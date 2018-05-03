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

struct ContainsIntegers
{
	virtual ~ContainsIntegers() = default;
	virtual int* begin() = 0;
	virtual int* end() = 0;
};

struct SingleValue : ContainsIntegers
{
	int value{ 0 };

	SingleValue() = default;

	explicit SingleValue(const int value)
		: value{ value }
	{
	}

	int* begin() override {
		return &value;
	}

	int* end() override {
		return &value + 1;
	}
};

struct ManyValues : vector<int>, ContainsIntegers
{
	// It is bad to derive from std class
	int* begin() override { return &(*this)[0]; }
	int* end() override { cout << size() << endl;  return &(*this)[size()-1] + 1; } // VS crashed with out of range exception at (*this)[size()] 
	void add(const int value)
	{
		push_back(value);
	}
};

int sum(const vector<ContainsIntegers*> items)
{
	int sum = 0;
	for (auto& agg : items)
	{
		for (auto& item : *agg) {
			sum += item;
		}
	}
	return sum;
}

int main(int argc, char* argv[])
{
	SingleValue sv{ 1 };
	ManyValues mv;
	mv.add(2);
	mv.add(3);
	cout << sum({ &sv, &mv });
	return 0;
}
