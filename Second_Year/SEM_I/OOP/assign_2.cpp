// ======================================================================
// Name        : assign_2.cpp
// Author      : Omkar Sonawane
// Description : This program implements constructors, destructor, static
//               member functions, friend class, this pointer, inline 
//               code and dynamic memory allocation operators-new and 
//               delete as well as exception handling
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    int rollNumber;
    string className;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;

public:
    Student() : rollNumber(0), division('A') {}

    // Parameterized constructor
    Student(string n, int r, string c, char d, string dob, string bg, string ca, string tn, string dl) {
        name = n;
        rollNumber = r;
        className = c;
        division = d;
        dateOfBirth = dob;
        bloodGroup = bg;
        contactAddress = ca;
        telephoneNumber = tn;
        drivingLicenseNo = dl;        
    }

    // Copy constructor
    Student(const Student& s) {
        name = s.name;
        rollNumber = s.rollNumber;
        className = s.className;
        division = s.division;
        dateOfBirth = s.dateOfBirth;
        bloodGroup = s.bloodGroup;
        contactAddress = s.contactAddress;
        telephoneNumber = s.telephoneNumber;
        drivingLicenseNo = s.drivingLicenseNo;
    }

    friend istream& operator>>(istream& in, Student& s) {
        cout << "\nStudent details: ";

        in >> ws; // Consume any leading whitespace
        in >> s.name >> s.rollNumber >> s.className >> s.division
           >> s.dateOfBirth >> s.bloodGroup >> s.contactAddress 
           >> s.telephoneNumber >> s.drivingLicenseNo;


        return in;
    }

    string formatWithPadding(const string& str, int width) {
        return str + string(width > str.length() ? width - str.length() : 0, ' ');
    }

    inline void display() {
        cout << formatWithPadding(to_string(rollNumber), 5)
             << formatWithPadding(name, 10)
             << formatWithPadding(className, 7)
             << formatWithPadding(to_string(division), 5)
             << formatWithPadding(dateOfBirth, 12)
             << formatWithPadding(bloodGroup, 4)
             << formatWithPadding(contactAddress, 14)
             << formatWithPadding(telephoneNumber, 12)
             << drivingLicenseNo << endl;
    }

    int getRollNumber() const { return rollNumber; }

    // Destructor
    ~Student() {}
};

class StudentDatabase {
    // Pointer to an array of pointers to Student objects
    Student** students;
    int capacity;
    int size;

public:
    StudentDatabase(int cap) : capacity(cap), size(0) {
        students = new Student*[capacity]; // Allocate memory for students
    }

    // Destructor to free allocated memory
    ~StudentDatabase() {
        for (int i = 0; i < size; ++i) {
            delete students[i];
        }
        delete[] students; 
    }

    void addStudent(const Student& s) {
        if (size < capacity) {
            students[size++] = new Student(s);
        } else {
            cout << "Database is full, cannot add more students." << endl;
        }
    }

    // Function to display all students
    void displayAll() {
        cout << "Rol  Name      Class  Div  DOB         "
             << "BG  Address       TelePhone   License No" << endl
             << string(79, '-') << endl;

        for (int i = 0; i < size; ++i) {
            students[i]->display();
        }
    }

    // Static member function to count students
    static int countStudents(StudentDatabase& db) {
        return db.size;
    }

    // Function to find a student by roll number
    Student* findStudentByRollNumber(int rollNumber) {
        for (int i = 0; i < size; ++i) {
            if (students[i]->getRollNumber() == rollNumber) {
                return students[i];
            }
        }
        return nullptr;
    }
};

int main() {
    StudentDatabase db(10); 

    // (Name RollNumber Class Division DOB BloodGroup Address Telephone DL)
    cout << "Enter student details" << endl;
    cout << "Format (Name RollNo Class Division DOB BloodG Address Telephone DL): \n";

    while (true) {
        Student student;
        char choice;
        cin >> student;
        db.addStudent(student);

        cout << "\nDo you want to add students (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') continue;
        else break;
    }
    
    // Display all students
    cout << "\nAll Students:" << endl;
    db.displayAll();

    // Count the number of students
    cout << "\nTotal Students: " << StudentDatabase::countStudents(db) << endl;

    // Find a student by roll number
    cout << "\nFinding student with roll number 74: \n\n";
    Student* foundStudent = db.findStudentByRollNumber(74);

    if (foundStudent)
        foundStudent->display();
    else
        cout << "Student not found." << endl;

    return 0;
}


// Omkar 74 CO_SE A 2005/12/30 B+ Padvi 8485879999 MH42-13345
// Riddesh 73 CO_SE A 2005/10/20 AB+ Bhor 888500890 MH42-92345
// Parth 66 CO_SE C 2005/04/15 B+ Chandrapur 9994567890 MH42-22345
// Nihar 23 CO_FE A 2004/02/01 A+ Gujrat 8827374664 GJ23-98444