#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string nhi_phan = ""; 
    while (n)
    {
        int bit = n % 2;
        nhi_phan = char(bit + '0') + nhi_phan; 
        n /= 2;
    }
    cout << nhi_phan;
}
