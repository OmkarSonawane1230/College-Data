#include <iostream>
using namespace std;

class Matrix {
    int mat[3][3];
public:
    void getMat() {
        cout << "Enter values: " << endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> mat[i][j];
            }
        }
    }

    Matrix operator+(Matrix &mat2) {
        Matrix result;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.mat[i][j] = mat[i][j] + mat2.mat[i][j];
            }
        }

        return result;
    }

    Matrix operator*(Matrix &mat2) {
        Matrix result;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.mat[i][j] = 0;           // initialize with zero for correct output
                for (int k = 0; k < 3; ++k) {
                    result.mat[i][j] += mat[i][k] * mat2.mat[k][j];
                }
            }
        }

        return result;
    }

    void display() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix A;
    Matrix B;

    A.getMat();
    B.getMat();
    
    Matrix C = A + B;
    Matrix D = A * B;

    cout << "Mat A: " << endl;
    A.display();
    cout << "Mat B: " << endl;
    B.display();

    cout << "Mat C: (addition) " << endl;
    C.display();

    cout << "Mat D: (multiplication) " << endl;
    D.display();

    return 0;
}