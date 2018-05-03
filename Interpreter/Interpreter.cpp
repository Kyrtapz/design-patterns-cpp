#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

struct ExpressionProcessor
{
	map<char, int> variables;

	// Not proud of that code...
	int calculate(const string& expression)
	{
		int l = 0;
		bool has_l = false;
		bool is_op_add = false;
		for (int i = 0; i < expression.size(); i++) {
			switch (expression[i]) {
				case '+': is_op_add = true; break;
				case '-': is_op_add = false; break;
				default: {
					int val;
					if (isdigit(expression[i])) {
						ostringstream nums;
						nums << expression[i];
						int j = i + 1;
						for (; j < expression.size(); j++)
						if (isdigit(expression[j]))
							nums << expression[j];
						else
							break;
						i = j - 1;
						val = stoi(nums.str());
					}
					else {
						if (variables.find(expression[i]) == variables.end())
							return 0;
						val = variables[expression[i]];
					}

					if (has_l) {
						if (is_op_add)
							l += val;
						else
							l -= val;
					}
					else {
						l = val;
						has_l = true;
					}
				} break;
			}
		}
		return l;
	}
};

int main()
{
	ExpressionProcessor e;
	e.variables['x'] = 3;
	cout << e.calculate("10-2-x") << endl; 
	return 0;
}