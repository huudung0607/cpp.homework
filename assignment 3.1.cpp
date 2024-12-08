#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int a[1000001];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (k == 1)
	{
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > 0)
			{
				cout << a[i] << " ";
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << 0 << endl;
		}
		cout << endl;
	}
	if (k == 2)
	{
		bool found = true;
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	if (k == 3)
	{
		int c = 0, l = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] % 2 == 0)
			{
				c++;
			}
			else
			{
				l++;
			}
		}
		if (c==l)
		{
			cout << 0 << endl;
		}
		else if (c > l)
		{
			cout << -1 << endl;
		}
		else if (c < l)
		{
			cout << 1 << endl;
		}
	}
	if (k ==4)
	{
		int dem = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i] > 0 && a[i + 1] > 0 || a[i] < 0 && a[i + 1] < 0)
			{
				if (abs(a[i]) < abs(a[i + 1]))
				{
					dem++;
				}
			}
		}
		cout << dem << endl;
	}
	if (k==5)
	{
		int first = -1;
		int last = -1;
		for (int i = 0; i < n; i++)
		{
			if (a[i] < 0)
			{
				first = i;
				break;
			}
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] < 0)
			{
				last = i;
				break;
			}
		}
		if (first <= last && first != - 1 && last != -1)
		{
			int sum = 0;
			for (int i = first + 1; i < last; i++)
			{
				sum += a[i];
			}
			cout << sum;
		}
	}
}
