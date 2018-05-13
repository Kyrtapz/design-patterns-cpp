#include <iostream>
#include <vector>
using namespace std;


// Most part was copied from the course answer, i was confused on what was the task
struct IRat
{
	virtual void rat_enters(IRat* sender) = 0;
	virtual void rat_dies(IRat* sender) = 0;
};

struct Game
{
	vector<IRat*> rats;
	virtual void fire_rat_enters(IRat* sender)
	{
		for (auto& rat : rats) rat->rat_enters(sender);
	}
	virtual void fire_rat_dies(IRat* sender)
	{
		for (auto& rat : rats) rat->rat_dies(sender);
	}
};

struct Rat : IRat
{
	Game& game;
	int attack{ 1 };

	Rat(Game &game) : game(game)
	{
		attack += game.rats.size();
		game.rats.push_back(this);
		game.fire_rat_enters(this);
	}

	~Rat() { game.fire_rat_dies(this); }

	void rat_enters(IRat *sender) override {
		if (sender != this) {
			++attack;
		}
	}

	void rat_dies(IRat *sender) override {
		--attack;
	}
};


int main()
{
	Game g;
	Rat r1{ g };
	cout << "R1 " << r1.attack << endl;
	Rat r2{ g };
	cout << "R1 " << r1.attack << " R2 " << r2.attack << endl;
	{
		Rat r3{ g };
		cout << "[After R3 joined] R1 " << r1.attack << " R2 " << r2.attack << endl;
	}
	cout << "[After R3 died]   R1 " << r1.attack << " R2 " << r2.attack << endl;
	return 0;
}