#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

#include <sstream>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct Sentence
{
	struct WordToken
	{
		bool capitalize;
		string text;
	};

	vector<WordToken> words;

	Sentence(const string& text)
	{
		stringstream ss(text);
		string buf;
		while (ss >> buf)
			words.push_back({ false, buf });
	}

	WordToken& operator[](size_t index)
	{
		// unsafe
		return words[index];
	}

	string str() const
	{
		ostringstream oss;
		for (int i = 0; i < words.size(); i++) {
			WordToken w = words[i];
			if (w.capitalize)
				transform(w.text.begin(), w.text.end(), w.text.begin(), ::toupper);
			oss << w.text;
			if (i < words.size() - 1) oss << " ";
		}
		return oss.str();
	}
};

int main()
{
	Sentence s{ "Hello world" };
	s[0].capitalize = true;
	cout << s.str() << endl;
	return 0;
}