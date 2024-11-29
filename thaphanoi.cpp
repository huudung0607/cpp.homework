#include <iostream>

using namespace std;

void thaphanoi(int dia, char cot, char trunggian, char cotdich)
{
    if (dia == 1)
    {
        cout << "chuyen 1 dia tu " << cot << " toi " << cotdich << endl;
        return;
    }
    thaphanoi(dia - 1, cot, cotdich, trunggian);
    cout << "chuyen dia " << dia << " tu " << cot << " toi " << cotdich << endl;
    thaphanoi(dia - 1, trunggian, cot, cotdich);
}
int main()
{
    int n;
    cin >> n;
    thaphanoi(n, 'A', 'B', 'C');
}
