#include <iostream>
using namespace std;

void nhiphan(int n)
{
	if (n == 0)
	{
		return;
	}
	int res = n % 2;
	nhiphan(n / 2);
	cout << res;
}
int main()
{
	int n;
	cin >> n;
	nhiphan(n);
}
