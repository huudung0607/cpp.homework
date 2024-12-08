#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

#define ll long long;

double a[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	double x;
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (k == 1)
	{
		int dem = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == x)
			{
				dem++;
			}
		}
		cout << dem << endl;
	}
	if (k == 2)
	{
		bool found = false;
		for (int i = n - 1; i >= 0; i--)
		{
			if (a[i] == x)
			{
				cout << i << endl;
				found = true;
				break;
			}
		}
		if (!found)
		{
			cout << -1 << endl;
		}
	}
	if (k == 3)
	{
		int dis = 0;
		int max = INT_MIN;
		int index = -1;
		for (int i = 0; i < n; i++)
		{
			int dis = abs(a[i] - x);
			if (dis > max)
			{
				max = dis;
				index = a[i];
			}
		}
		cout << index << endl;
	}
	if (k == 4)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[i] > 0 && a[j] > 0 && a[i] > a[j])
				{
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
				else if (a[i] < 0 && a[j] < 0 && a[i] < a[j])
				{
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
	}
	if (k == 5)
	{
		for (int i = 0; i < n; i++)
		{
			bool found = false;
			for (int j = 0; j < n; j++)
			{
				if (abs(a[i] - (int)a[j]) == 0)
				{
					found = true;
				}
			}
			if (found)
			{
				cout << a[i] << " ";
			}
		}
	}
}
