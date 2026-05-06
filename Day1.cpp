#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int roll;
    string subjects[3];
    float marks[3];

public:
    void inputDetails() {
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Roll Number: ";
        cin >> roll;

        cout << "\nEnter 3 Subjects and Marks:\n";
        for (int i = 0; i < 3; i++) {
            cout << "Subject " << i + 1 << " Name: ";
            cin >> subjects[i];

            cout << "Marks in " << subjects[i] << ": ";
            cin >> marks[i];
        }
    }

    float getAverage() {
        float sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += marks[i];
        }
        return sum / 3;
    }

    char getGrade() {
        float avg = getAverage();

        if (avg >= 80) return 'A';
        else if (avg >= 60) return 'B';
        else if (avg >= 40) return 'C';
        else return 'F';
    }

    void displayResult() {
        cout << "\nName: " << name;
        cout << "\nAverage Marks: " << getAverage();
        cout << "\nGrade: " << getGrade() << endl;
    }

    float getAvgForTopper() {
        return getAverage();
    }
};

int main() {
    Student s1, s2;

    cout << "\n--- Enter Details for Student 1 ---\n";
    s1.inputDetails();

    cout << "\n--- Enter Details for Student 2 ---\n";
    s2.inputDetails();

    
    cout << "\n===== Results =====\n";

    cout << "\nStudent 1:";
    s1.displayResult();

    cout << "\nStudent 2:";
    s2.displayResult();

    cout << "\n===== Class Topper =====\n";
    if (s1.getAvgForTopper() > s2.getAvgForTopper()) {
        cout << "Topper is Student 1\n";
        s1.displayResult();
    } else {
        cout << "Topper is Student 2\n";
        s2.displayResult();
    }

    return 0;
}