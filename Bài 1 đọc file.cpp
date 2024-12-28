#include <iostream>
#include <fstream>
using namespace std;
int arr[10001];
void docFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file !" << endl;
        return;
    }
    int n = 0;
    while (file >> arr[n]) {
        n++;
    }
    file.close();
    cout << "Day so : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nSo luong : " << n << endl;
}
void tachchanle(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file!" << endl;
        return;
    }
    ofstream evenFile("even.txt"), oddFile("odd.txt");
    int num;
    while (file >> num) {
        if (num % 2 == 0) {
            evenFile << num << " ";
        }
        else {
            oddFile << num << " ";
        }
    }
    file.close();
    evenFile.close();
    oddFile.close();
    cout << "Tach so le tu 'even.txt' và 'odd.txt'." << endl;
}
int main() {
    ofstream file("arrInteger.txt");
    file << "1 2 3 4 5 6 7 8 9 10";
    file.close();
    docFile("arrInteger.txt");
    tachchanle("arrInteger.txt");
    return 0;
}
