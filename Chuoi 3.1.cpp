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
using namespace std;
using ll = long long;

int main()
{
	string s;
	getline(cin, s);
	int c;
	cin >> c;
	cin.ignore();
	if (c == 1)
	{
		stringstream ss(s);
		string res = "", word;
		while (ss>>word)
		{
			if (!res.empty())
			{
				res += " ";
			}
			res += word;
		}
		cout << res << endl;
	}
	if (c== 2)
	{
		int cnt = 0;
		stringstream ss(s);
		string word;
		while (ss>>word)
		{
			cnt++;
		}
		cout << cnt << endl;
	}
	if (c == 3)
	{
		int maxstring = 0;
		stringstream ss(s);
		string res="",word;
		while (ss>>word)
		{
			if (word.length() > maxstring)
			{
				maxstring = word.length();
				res = word;
			}
		}
		if (maxstring == 0)
		{
			cout << "" << endl;
		}
		cout << res << endl;
	}
	if (c == 4)
	{
		stringstream ss(s);
		string res = "", word;
		while (ss>>word)
		{
			res += toupper(word[0]);
			for (int i = 1; i < word.size(); i++)
			{
				res += tolower(word[i]);
			}
			res += " ";
		}
		if (!res.empty())
		{
			res.pop_back();
		}
		cout << res;
	}
	if (c == 5)
	{
		string a, b;
		getline(cin, a);
		getline(cin, b);
		stringstream ss(s);
		string res = "", word;
		while (ss >> word)
		{
			if (word == a)
			{
				word = b;
			}
			if (!res.empty())
			{
				res += " ";
			}
			res += word;
		}
		cout << res << endl;
	}
}
