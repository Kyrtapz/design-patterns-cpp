#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct ILogger {
	virtual void Log(const string& message) = 0;
};

class Logger : public ILogger {
	int messages_cnt = { 0 };
	// Constructors should be private/deleted or Boost DI should be used instead of directly calling 
public:
	void Log(const string& message) {
		cout << messages_cnt++ << " " << message << endl;
	}
};

class Data {
	shared_ptr<ILogger> log;
public:
	Data(const shared_ptr<ILogger>& l) : log(l) {
		log->Log("Creating a data object");
	}
};
int main(int argc, char* argv[])
{
	auto logger = make_shared<Logger>();
	Data d1(logger), d2(logger);
	return 0;

}
