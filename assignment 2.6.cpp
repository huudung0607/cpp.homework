#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	if (k == 1)
	{
		cout <<fixed << setprecision(2)<< (double)n * (n  + 1) / 2;
	}
	else if (k == 2)
	{
		double sum = 0.0;
		for (int i = 1.0; i <= n; i++)
		{
			sum += i / (i + 1.0);
		}
		cout << fixed << setprecision(2) << sum;
	}
	else if (k == 3)
	{
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (n % i == 0)
			{
				sum += i;
			}
		}
		cout << fixed << setprecision(2) << (double)sum;
	}
	else if (k == 4)
	{
		double sum = 0.0;
		for (int i = 1; i <= n; i++) {
			sum += pow(2, i) / (i + 1);
		}
		sum++;
		cout << fixed << setprecision(2) << sum;
	}
	else if (k == 5)
	{
		double sum = 0.0;
		for (int i = 1.0; i <= n; i++)
		{
			if (i % 2 == 0)
			{
				sum += (i - 1.0) * i / (2.0 * i - 1.0);
			}
			else
			{
				sum -= (i - 1.0) * i/ (2.0 * i - 1.0);
			}
		}
		cout << fixed << setprecision(2) << sum;
	}
}
