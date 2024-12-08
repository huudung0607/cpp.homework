#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

#define ll long long;
int mark[100001];
int a[1000001];
int b[1000001];
int res[100001];
int duong[1000001];
int am[1000001];
int zero[10000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	if (k == 1)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			res[cnt++] = a[i];
		}
		for (int i = 0; i < m; i++)
		{
			res[cnt++] = b[i];
		}
		for (int i = 0; i < cnt; i++)
		{
			for (int j = i + 1; j < cnt; j++)
			{
				if (res[i] > res[j])
				{
					int temp = res[i];
					res[i] = res[j];
					res[j] = temp;
				}
			}
			cout << res[i] << " ";
		}
	}
	if (k == 2)
	{
		int cnt1 = 0;
		int cnt2 = 0;
		int cnt3 = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > 0)
			{
				duong[cnt1++] = a[i];
			}
			if (a[i] <0)
			{
				am[cnt2++] = a[i];
			}
			if (a[i] == 0)
			{
				zero[cnt3++] = a[i];
			}
		}
		for (int i = 0; i < cnt1; i++)
		{
			cout << duong[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < cnt2; i++)
		{
			cout << am[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < cnt3; i++)
		{
			cout << zero[i] << " ";
		}
	}
	if (k == 3)
	{
		int min_val = INT_MAX;
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			bool bcheck = false;
			for (int j = 0; j < m; j++)
			{
				if (a[i] == b[j])
				{
					bcheck = true;
					break;
				}
			}
			if (!bcheck && a[i] < min_val)
			{
				min_val = a[i];
				flag = true;
			}
		}
		if (flag)
		{
			cout << min_val << endl;
		}
		else
		{
			cout << "INF" << endl;
		}
	}
}
