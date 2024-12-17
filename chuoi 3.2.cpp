#include <iostream>
#include <set>	
#include <map>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <iomanip>
#include <string>
#include <sstream>
#include <climits>

using namespace std;
using ll = long long;
string temp[10001];
int res[10001];
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		temp[dem++] = s;
	}
	string max_s = "";
	int max_num = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (temp[i] == temp[j])
			{
				cnt++;
			}
		}
		if (cnt > max_num || cnt == max_num && temp[i] > max_s)
		{
			max_num = cnt;
			max_s = temp[i];
		}
	}
	cout << max_s << " " << max_num << endl;
}
