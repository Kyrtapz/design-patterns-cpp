#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Command
{
	enum Action { deposit, withdraw } action;
	int amount{ 0 };
	bool success{ false };
};

struct Account
{
	int balance{ 0 };

	void process(Command& cmd)
	{
		switch (cmd.action) {
			case Command::Action::deposit: {
				cmd.success = false;
				if (cmd.amount > 0) {
					balance += cmd.amount;
					cmd.success = true;
				}
				break;
			}
			case Command::Action::withdraw: {
				cmd.success = false;
				if (cmd.amount <= balance) {
					balance -= cmd.amount;
					cmd.success = true;
				}
				break;
			}
		}
	}
};

int main()
{
	Account ac;
	Command deposit_100 = {};
	deposit_100.action = Command::Action::deposit;
	deposit_100.amount = 100;

	ac.process(deposit_100);
	cout << ac.balance << endl;
	return 0;
}