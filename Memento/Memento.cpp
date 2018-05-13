#include <vector>
#include <iostream>
using namespace std;

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct Token
{
	int value;

	Token(int value) : value(value) {}
};

struct Memento
{
	vector<shared_ptr<Token>> tokens;
};

struct TokenMachine
{
	vector<shared_ptr<Token>> tokens;

	Memento add_token(int value)
	{
		return add_token(make_shared<Token>(value));
	}

	// adds the token to the set of tokens and returns the
	// snapshot of the entire system
	Memento add_token(const shared_ptr<Token>& token)
	{
		tokens.push_back(token);
		Memento m;
		for (const auto& t : tokens) {
			m.tokens.push_back(make_shared<Token>(*t));
		}
		return m;
	}

	// reverts the system to a state represented by the token
	void revert(const Memento& m)
	{
		tokens = m.tokens;
	}

	void print() {
		for (const auto& t : tokens) {
			cout << t->value << " ";
		}
		cout << endl;
	}
};

int main()
{
	TokenMachine tm;
	auto& m = tm.add_token(1);
	tm.add_token(2);
    tm.add_token(3);
	tm.print();
	tm.tokens.front()->value = 10;
	tm.print();
	tm.revert(m);
	tm.print();
	return 0;
}