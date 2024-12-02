#include <iostream>
#include <math.h>

using namespace std;

int count_digit(int n)
{
	int count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return count;
}

int reverse_num(int n)
{
	int temp = 0;
	while (n)
	{
		int last_num = n % 10;
		temp = temp * 10 + last_num;
		n /= 10;
	}
	return temp;
}

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	int count = count_digit(n);
	int temp2 = reverse_num(n);
	while (temp2)
	{
		int last_num = temp2 % 10;
		int res = last_num * pow(2, count - 1);
		sum += res;
		temp2 /= 10;
		count = count - 1;
	}
	cout << sum << endl;
}
