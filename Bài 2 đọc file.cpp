#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Student {
    long id;
    string name;
    string group;
    double gpa;
};
void taoFileStudent() {
    ofstream file("student.txt");
    file << "5\n";
    file << "201,Huynh Huu Dung,CNTT24,9.0\n";
    file << "202,Nguyen Hoang Anh Duy,CTK44,9.0\n";
    file << "203,Nguyen Thanh Dung,CTK44,9.0\n";
    file << "204,Phan Quoc Dung,CTK44,8.5\n";
    file << "205,Ly Khanh Duy,CTK44,8.5\n";
    file.close();
    cout << "Da tao 'student.txt'." << endl;
}
void docFileStudent(Student students[], int& n) {
    ifstream file("student.txt");
    if (!file.is_open()) {
        cout << "Cannot open file !" << endl;
        return;
    }
    file >> n;
    file.ignore();
    for (int i = 0; i < n; i++) {
        file >> students[i].id;
        file.ignore();
        getline(file, students[i].name, ',');
        getline(file, students[i].group, ',');
        file >> students[i].gpa;
        file.ignore();
    }
    file.close();
}
void xuatStudents(const Student students[], int n) {
    cout << "DSSV :\n";
    for (int i = 0; i < n; i++) {
        cout << "ID: " << students[i].id
            << ", Ho ten: " << students[i].name
            << ", Lop: " << students[i].group
            << ", GPA: " << students[i].gpa << endl;
    }
}
void themStudents(Student students[], int& n) {
    Student newStudent;
    cout << "ID: ";
    cin >> newStudent.id;
    cin.ignore();
    cout << "Ho ten: ";
    getline(cin, newStudent.name);
    cout << "Lop: ";
    getline(cin, newStudent.group);
    cout << "GPA: ";
    cin >> newStudent.gpa;
    students[n++] = newStudent;
    ofstream file("student.txt", ios::app);
    file << newStudent.id << "," << newStudent.name << ","
        << newStudent.group << "," << newStudent.gpa << "\n";
    file.close();
    cout << "Da them sv moi." << endl;
}
void filterStudents(const Student students[], int n) {
    ofstream file("result.txt");
    file << "Ma so sinh vien\tHo ten\tDiem trung binh\n";
    for (int i = 0; i < n; i++) {
        if (students[i].gpa >= 8.0) {
            file << students[i].id << "\t" << students[i].name
                << "\t" << students[i].gpa << "\n";
        }
    }
    file.close();
    cout << "GPA >= 8.0 vao 'result.txt'." << endl;
}
int main() {
    taoFileStudent();
    Student students[100];
    int n = 0;
    docFileStudent(students, n);
    xuatStudents(students, n);
    themStudents(students, n);
    filterStudents(students, n);
    return 0;
}
