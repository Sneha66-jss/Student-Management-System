#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
};

// Load students from file
vector<Student> loadStudents() {
    vector<Student> students;
    ifstream file("students.txt");

    Student s;
    while (file >> s.id >> s.name >> s.age >> s.course) {
        students.push_back(s);
    }

    file.close();
    return students;
}

// Save students to file
void saveStudents(vector<Student> students) {
    ofstream file("students.txt");

    for (Student s : students) {
        file << s.id << " "
             << s.name << " "
             << s.age << " "
             << s.course << endl;
    }

    file.close();
}

// Add Student
void addStudent() {
    vector<Student> students = loadStudents();

    Student s;

    cout << "\nEnter Student ID: ";
    cin >> s.id;

    for (Student st : students) {
        if (st.id == s.id) {
            cout << "Student ID already exists!\n";
            return;
        }
    }

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Age: ";
    cin >> s.age;

    cout << "Enter Course: ";
    cin >> s.course;

    students.push_back(s);

    saveStudents(students);

    cout << "\nStudent Added Successfully!\n";
}

// Display Students
void displayStudents() {
    vector<Student> students = loadStudents();

    if (students.empty()) {
        cout << "\nNo Student Records Found!\n";
        return;
    }

    cout << "\n------ Student Records ------\n";

    for (Student s : students) {
        cout << "ID      : " << s.id << endl;
        cout << "Name    : " << s.name << endl;
        cout << "Age     : " << s.age << endl;
        cout << "Course  : " << s.course << endl;
        cout << "-----------------------------\n";
    }
}

// Search Student
void searchStudent() {
    vector<Student> students = loadStudents();

    int id;

    cout << "\nEnter Student ID: ";
    cin >> id;

    for (Student s : students) {
        if (s.id == id) {
            cout << "\nStudent Found\n";
            cout << "ID: " << s.id << endl;
            cout << "Name: " << s.name << endl;
            cout << "Age: " << s.age << endl;
            cout << "Course: " << s.course << endl;
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

// Update Student
void updateStudent() {
    vector<Student> students = loadStudents();

    int id;

    cout << "\nEnter Student ID to Update: ";
    cin >> id;

    bool found = false;

    for (Student &s : students) {
        if (s.id == id) {
            found = true;

            cout << "Enter New Name: ";
            cin >> s.name;

            cout << "Enter New Age: ";
            cin >> s.age;

            cout << "Enter New Course: ";
            cin >> s.course;

            break;
        }
    }

    if (found) {
        saveStudents(students);
        cout << "\nStudent Updated Successfully!\n";
    } else {
        cout << "\nStudent Not Found!\n";
    }
}

// Delete Student
void deleteStudent() {
    vector<Student> students = loadStudents();

    int id;

    cout << "\nEnter Student ID to Delete: ";
    cin >> id;

    vector<Student> updated;
    bool found = false;

    for (Student s : students) {
        if (s.id == id)
            found = true;
        else
            updated.push_back(s);
    }

    if (found) {
        saveStudents(updated);
        cout << "\nStudent Deleted Successfully!\n";
    } else {
        cout << "\nStudent Not Found!\n";
    }
}

int main() {

    int choice;

    do {
        cout << "\n==============================\n";
        cout << " STUDENT MANAGEMENT SYSTEM\n";
        cout << "==============================\n";

        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}