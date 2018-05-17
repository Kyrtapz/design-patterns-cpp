#include <string>
#include <sstream>
#include <iostream>
using namespace std;

struct Value;
struct AdditionExpression;
struct MultiplicationExpression;

struct ExpressionVisitor
{
	virtual void accept(Value& v) = 0;
	virtual void accept(AdditionExpression& v) = 0;
	virtual void accept(MultiplicationExpression& v) = 0;
};

struct Expression
{
	virtual void visit(ExpressionVisitor& ev) = 0;
};

struct Value : Expression
{
	int value;

	Value(int value) : value(value) {}

	void visit(ExpressionVisitor& ev) {
		ev.accept(*this);
	}
};

struct AdditionExpression : Expression
{
	Expression &lhs, &rhs;

	AdditionExpression(Expression &lhs, Expression &rhs) : lhs(lhs), rhs(rhs) {}

	void visit(ExpressionVisitor& ev) {
		ev.accept(*this);
	}
};

struct MultiplicationExpression : Expression
{
	Expression &lhs, &rhs;

	MultiplicationExpression(Expression &lhs, Expression &rhs)
		: lhs(lhs), rhs(rhs) {}

	void visit(ExpressionVisitor& ev) {
		ev.accept(*this);
	}
};

struct ExpressionPrinter : ExpressionVisitor
{
	ostringstream oss;

	virtual void accept(Value& v) {
		oss << v.value;
	}

	virtual void accept(AdditionExpression& v) {
		oss << "(";
		v.lhs.visit(*this);
		oss << "+";
		v.rhs.visit(*this);
		oss << ")";
	}
	virtual void accept(MultiplicationExpression& v) {
		v.lhs.visit(*this);
		oss << "*";
		v.rhs.visit(*this);
	}
	string str() const { return oss.str();  }
};

int main()
{
	Value a{ 1 }, b{ 2 }, c{ 3 };
	AdditionExpression add{ a, b };
	MultiplicationExpression mul{ c, add };
	ExpressionPrinter ep;
	ep.accept(mul);
	std::cout << ep.str() << endl;
	return 0;
}