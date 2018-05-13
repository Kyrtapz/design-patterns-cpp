#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

template <typename T>
struct Node
{
	T value;
	Node *left{ nullptr }, *right{ nullptr }, *parent{ nullptr };

	Node(T value) : value(value) {}

	Node(T value, Node<T> *left, Node<T> *right) : value(value), left(left), right(right) {
		left->parent = right->parent = this;
	}

	// traverse the node and its children preorder
	// and put all the results into `result`
	void preorder_traversal(vector<Node<T>*>& result)
	{
		result.push_back(this);
		if (left)
			left->preorder_traversal(result);
		if (right)
			right->preorder_traversal(result);
	}
};

int main()
{
	Node<string> r{ "Right" }, ll{ "LLeft" }, lr{ "LRight" }, l1{ "Left", &ll, &lr };
	Node<string> root{ "Root",
		&l1,
		&r
		};

	vector<Node<string>*> v;
	root.preorder_traversal(v);

	for (auto& elem : v) {
		cout << elem->value << endl;
	}
	return 0;
}