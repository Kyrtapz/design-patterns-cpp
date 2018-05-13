#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

class CombinationLock
{
	vector<int> combination;
public:
	string status{ "LOCKED" };

	CombinationLock(const vector<int> &combination) : combination(combination) {
	}

	void enter_digit(int digit)
	{
		static vector<int> entered_digits;

		if (entered_digits.size() < combination.size()) {
			entered_digits.push_back(digit);
		}

		std::stringstream result;
		std::copy(entered_digits.begin(), entered_digits.end(), std::ostream_iterator<int>(result, ""));;
		status = result.str();

		if (entered_digits.size() == combination.size()) {
			if (entered_digits == combination)
				status = "OPEN";
			else
				status = "ERROR";
			entered_digits.clear();
		}

	}
};

int main()
{
	CombinationLock lock({ 1, 2, 3 });
	cout << lock.status << endl;
	lock.enter_digit(1);
	cout << lock.status << endl;
	lock.enter_digit(2);
	cout << lock.status << endl;
	lock.enter_digit(3);
	cout << lock.status << endl;
	lock.enter_digit(3);
	cout << lock.status << endl;
	lock.enter_digit(3);
	cout << lock.status << endl;
	lock.enter_digit(3);
	cout << lock.status << endl;
	return 0;
}