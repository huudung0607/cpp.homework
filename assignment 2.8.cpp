#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	if (k == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (n % i == 0)
			{
				cout << i << " ";
			}
		}
	}
	else if (k == 2)
	{
		for (int i = n; i >= 1; i--) {
			if (n % i == 0)
			{
				cout << i << " ";
			}
		}
	}
	else if (k == 3)
	{
		for (int i = 1; i <= n; i += 2) {
			if (2016 % i == 0)
			{
				cout << i << " ";
			}
		}
	}
	else if (k == 4)
	{
		if ((int)sqrt(n) * (int)sqrt(n) == n)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
	}
	else if (k == 5)
	{
		bool nguyento = true;
		if (n == 1)
		{
			nguyento = false;
		}
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				nguyento = false;
				break;
			}
		}
		if (nguyento == true)
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
	}
}
