#include <iostream>
using namespace std;
int buoc = 0;
int cotA = 0;
int cotB = 0;
int cotC = 0;
void thaphanoi(int n, char cot, char trunggian, char cotdich, int k)
{
	if (n == 0 || buoc == k)
	{
		return;
	}
	thaphanoi(n - 1, cot,cotdich,trunggian,k);
	if (buoc < k)
	{
		if (cot == 'A')
		{
			cotA--;
		}
		if (cot == 'B')
		{
			cotB--;
		}
		if (cot == 'C')
		{
			cotC--;
		}
		if (cotdich == 'A')
		{
			cotA++;
		}
		if (cotdich == 'B')
		{
			cotB++;
		}
		if (cotdich == 'C')
		{
			cotC++;
		}
		buoc++;
	}
	thaphanoi(n - 1, trunggian,cot,cotdich, k);
}
int main()
{
	int n, k;
	cin >> n >> k;
	cotA = n;
	cotB = 0;
	cotC = 0;
	buoc = 0;
	thaphanoi(n, 'A', 'B', 'C', k);
	cout << cotA << " " << cotC << " " << cotB << endl;

}
