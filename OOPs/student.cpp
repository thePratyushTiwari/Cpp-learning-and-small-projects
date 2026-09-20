#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
    string name;
    int rollno;
    float cgpa;
    
    Student(){
        cout << "Enter your name: ";
        getline(cin >> ws, this->name);
        cout << "Enter your roll no.: ";
        cin >> this->rollno;
        cout << "Enter your CGPA: ";
        cin >> this->cgpa;
    }

    void getStudentProfile() {
        cout << "Name: " << name << "\nRoll No.: " << rollno << "\nCGPA: " << cgpa << '\n';
    }

    void getPercentage() {
        cout << "Percentage: " << cgpa*9.5 << "%\n";
    }

    void changeDetails() {
        cout << "Enter your name: ";
        getline(cin >> ws, this->name);
        cout << "Enter your roll no.: ";
        cin >> this->rollno;
        cout << "Enter your CGPA: ";
        cin >> this->cgpa;
    }
    
};

int main()
{
    Student std1;
    int ask;
    while(true) {
        cout << "-----------------------------------\n";
        cout << "1. Get Student Info\n2. Check Percentage\n3. Change Student Details\n0. Exit\nInput: ";
        cin >> ask;
        cout << "-----------------------------------\n";
        if(ask == 0) break;
        else if(ask == 1) {
            std1.getStudentProfile();
        } else if( ask == 2 ) {
            std1.getPercentage();
        } else if( ask == 3 ) {
            std1.changeDetails();
        } else{
            cout << "Invalid Input\n";
        }
        cout << "-----------------------------------\n\n";
    }
    return 0;
}
