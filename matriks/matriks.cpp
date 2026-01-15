#include <iostream>
#include <vector>
using namespace std;

void inputMatriks(vector<vector<int>>& matriks, string nama) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Masukkan nilai " << nama << " baris " << i + 1 << " kolom " << j + 1 << ": ";
            cin >> matriks[i][j];
        }
    }
}

void printMatriks(vector<vector<int>> matriks, string nama) {
    cout << nama << ":" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void operasiMatriks(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>>& C, char op) {
    if (op == '+') {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                C[i][j] = A[i][j] + B[i][j];
    } 
    else if (op == '-') {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                C[i][j] = A[i][j] - B[i][j];
    } 
    else { // perkalian matriks
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                C[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> matriksA(3, vector<int>(3));
    vector<vector<int>> matriksB(3, vector<int>(3));
    vector<vector<int>> matriksC(3, vector<int>(3, 0));

    inputMatriks(matriksA, "Matriks 1");
    inputMatriks(matriksB, "Matriks 2");

    char op;
    bool valid = false;

    while (!valid) {
        cout << "Masukkan operator (+, -, *) : ";
        cin >> op;
        if (op == '+' || op == '-' || op == '*') valid = true;
        else cout << "Input tidak valid. Coba lagi!" << endl;
    }

    cout << "Operator yang dipilih: " << op << endl << endl;

    operasiMatriks(matriksA, matriksB, matriksC, op);

    printMatriks(matriksA, "Matriks 1");
    printMatriks(matriksB, "Matriks 2");
    printMatriks(matriksC, "Matriks Hasil");

    return 0;
}
