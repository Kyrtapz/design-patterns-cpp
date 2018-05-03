#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Creature;
struct Game
{
	vector<Creature*> creatures;
};

struct StatQuery
{
	enum Statistic { attack, defense } statistic;
	int result;
};

struct Creature
{
protected:
	Game& game;
	int base_attack, base_defense;

public:
	Creature(Game &game, int base_attack, int base_defense) : game(game), base_attack(base_attack),
		base_defense(base_defense) {}
	virtual int get_attack() = 0;
	virtual int get_defense() = 0;
	virtual void query(Creature* src, StatQuery& sq) = 0;
};

class Goblin : public Creature
{
public:
	Goblin(Game &game, int base_attack, int base_defense) : Creature(game, base_attack, base_defense) {}

	Goblin(Game &game) : Creature(game, 1, 1) {
	}

	int get_stat(StatQuery::Statistic stat) {
		StatQuery q{ stat, 0 };
		for (auto c : game.creatures)
			c->query(this, q);
		return q.result;
	}
	int get_attack() override {
		return get_stat(StatQuery::Statistic::attack);
	}

	int get_defense() override {
		return get_stat(StatQuery::Statistic::defense);
	}

	void query(Creature* src, StatQuery& sq) {
		if (src == this)
		{
			switch (sq.statistic)
			{
			case StatQuery::attack:
				sq.result += base_attack;
				break;
			case StatQuery::defense:
				sq.result += base_defense;
				break;
			}
		}
		else
		{
			if (sq.statistic == StatQuery::defense)
			{
				sq.result++;
			}
		}
	}
};

class GoblinKing : public Goblin
{
public:
	GoblinKing(Game &game) : Goblin(game, 3, 3) {

	}

	int get_stat(StatQuery::Statistic stat) {
		StatQuery q{ stat, 0 };
		for (auto c : game.creatures)
			c->query(this, q);
		return q.result;
	}
	int get_attack() override {
		return get_stat(StatQuery::Statistic::attack);
	}

	int get_defense() override {
		return get_stat(StatQuery::Statistic::defense);
	}

	void query(Creature* src, StatQuery& sq) {
		if (src != this && sq.statistic == StatQuery::attack) {
			sq.result++;
		}
		else Goblin::query(src, sq);
	}
};


int main()
{
	Game game;
	Goblin g1(game);
	game.creatures.push_back(&g1);
	cout << g1.get_defense() << endl;
	Goblin g2(game);
	game.creatures.push_back(&g2);
	cout << g1.get_defense();
	return 0;
}