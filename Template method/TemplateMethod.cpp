#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct Creature
{
	int attack, health;

	Creature(int attack, int health) : attack(attack), health(health) {}
};

struct CardGame
{
	vector<Creature> creatures;

	CardGame(const vector<Creature> &creatures) : creatures(creatures) {}

	// return the index of the creature that won (is a live)
	// example:
	// - creature1 alive, creature2 dead, return creature1
	// - creature1 dead, creature2 alive, return creature2
	// - no clear winner: return -1
	int combat(int creature1, int creature2)
	{
		Creature &c1 = creatures[creature1], &c2 = creatures[creature2];
		hit(c1, c2);
		hit(c2, c1);

		if (c1.health <= 0 && c2.health <= 0)
			return -1;
		if (c1.health <= 0)
			return creature2;
		if (c2.health <= 0)
			return creature1;
		return -1;
	}

	virtual void hit(Creature& attacker, Creature& other) = 0;
};

struct TemporaryCardDamageGame : CardGame
{
	TemporaryCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}

	void hit(Creature &attacker, Creature &other) override {
		int h_prev = other.health;
		other.health -= attacker.attack;
		if (other.health > 0)
			other.health = h_prev;
	}
};

struct PermanentCardDamageGame : CardGame
{
	PermanentCardDamageGame(const vector<Creature> &creatures) : CardGame(creatures) {}

	void hit(Creature &attacker, Creature &other) override
	{
		other.health -= attacker.attack;
	}
};
int main()
{
	TemporaryCardDamageGame tcdg{ { { 2, 2 }, { 2, 2 } } };
	cout << tcdg.combat(0, 1) << endl;

	TemporaryCardDamageGame tcdg1{ { { 1, 2 }, { 1, 3 } } };
	tcdg1.combat(0, 1);
	cout << tcdg1.combat(0, 1) << endl;

	PermanentCardDamageGame pcdg{ { { 1, 2 }, { 1, 3 } } };
	pcdg.combat(0, 1);
	cout << pcdg.combat(0, 1) << endl;
	return 0;
}