#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct DiscriminantStrategy
{
	virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
	double calculate_discriminant(double a, double b, double c) override {
		return pow(b, 2) - 4 * a * c;
	}
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
	double calculate_discriminant(double a, double b, double c) override {
		double ret = pow(b, 2) - 4 * a * c;
		if (ret < 0)
			return NAN;
		return ret;
	}
};

class QuadraticEquationSolver
{
	DiscriminantStrategy& strategy;
public:
	QuadraticEquationSolver(DiscriminantStrategy &strategy) : strategy(strategy) {}

	tuple<complex<double>, complex<double>> solve(double a, double b, double c)
	{
		complex<double> discriminant = complex<double>(strategy.calculate_discriminant(a, b, c));
		complex<double> res_1 = (-1 * b + sqrt(discriminant)) / (2 * a);
		complex<double> res_2 = (-1 * b - sqrt(discriminant)) / (2 * a);
		return tuple<complex<double>, complex<double>>{ res_1, res_2 };
	}
};

int main()
{
	OrdinaryDiscriminantStrategy strategy;
	QuadraticEquationSolver solver{ strategy };
	auto results = solver.solve(1, 10, 16);
	cout << get<0>(results) << " " << get<1>(results) << endl;
	return 0;
}