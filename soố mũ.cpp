#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double my_pow(double x, double n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return x;
	}
	if (n < 0)
	{
		double res = x * my_pow(x, -n - 1);
		return 1 / res;
	}
	return exp(n * log(fabs(x))) * (x < 0 && ((long long)n % 2 == 1) ? -1 : 1);
}
int main()
{
	double x, n;
	cin >> x >> n;
	cout <<fixed << setprecision(2) <<my_pow(x, n) << endl;
}
