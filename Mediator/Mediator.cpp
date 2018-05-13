#include <vector>
#include <iostream>
using namespace std;

struct IParticipant {
	virtual void add_to_val(int v) = 0;
};

struct Mediator
{
	vector<IParticipant*> participants;
	void broadcast(IParticipant* p, int val) {
		for (auto& pt : participants){
			if (pt != p)
				pt->add_to_val(val);
		}
	}
};

struct Participant : IParticipant
{
	int value{ 0 };
	Mediator& mediator;

	Participant(Mediator &mediator) : mediator(mediator)
	{
		mediator.participants.push_back(this);
	}
	void add_to_val(int v)
	{
		value += v;
	}
	void say(int value)
	{
		mediator.broadcast(this, value);
	}
};


int main()
{
	Mediator m;
	Participant p1{ m };
	Participant p2{ m };
	p1.say(3);
	cout << p1.value << " " << p2.value << endl;
	p2.say(2);
	cout << p1.value << " " << p2.value << endl;
	return 0;
}