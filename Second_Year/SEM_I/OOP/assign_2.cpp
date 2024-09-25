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

        // in >> s.name >> s.rollNumber >> s.className >> s.division >> s.dateOfBirth
        //    >> s.bloodGroup >> ws; // ws to consume whitespace before reading the address

        // // Read the rest of the line for the address and other details
        // getline(in, s.contactAddress, '\n'); // Read until the end of the line
        // in >> s.telephoneNumber >> s.drivingLicenseNo;

        in >> ws; // Consume any leading whitespace
        in >> s.name >> s.rollNumber >> s.className >> s.division
           >> s.dateOfBirth >> s.bloodGroup >> s.contactAddress 
           >> s.telephoneNumber >> s.drivingLicenseNo;


        return in;
    }

    inline void display() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No: " << drivingLicenseNo << endl;
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

    // Function to add a student
    void addStudent(const Student& s) {
        if (size < capacity) {
            students[size++] = new Student(s); // allocate new Student
        } else {
            cout << "Database is full, cannot add more students." << endl;
        }
    }

    // Function to display all students
    void displayAll() {
        for (int i = 0; i < size; ++i) {
            students[i]->display();
            cout << "-------------------------" << endl;
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
    StudentDatabase db(10); // Create a database with capacity for 10 students
    // (Name RollNumber Class Division DOB BloodGroup Address Telephone DL)

    // Omkar 74 15 A 2005/12/30 B+ 123-Patas-St 8485879999 DL12345
    // Riddesh 73 15 A 2005/04/15 B+ 123-Maple-St 1234567890 DL12345
    // Parth 66 15 C 2005/04/15 AB+ 123 Maple St 1234567890 DL12345
    cout << "Enter student details" << endl;
    cout << "Enter student info (Name RollNumber Class Division DOB BloodGroup Address Telephone DL): \n";

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
    cout << "All Students:" << endl;
    db.displayAll();

    // Count the number of students
    cout << "Total Students: " << StudentDatabase::countStudents(db) << endl;

    // Find a student by roll number
    cout << "Finding student with roll number 74: ";
    Student* foundStudent = db.findStudentByRollNumber(74);

    if (foundStudent)
        foundStudent->display();
    else
        cout << "Student not found." << endl;

    return 0;
}