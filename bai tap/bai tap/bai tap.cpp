#include<iostream>
#include <fstream>
#include <sstream>
using namespace std;
//bai 1
void sort(int *A, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i+1; j < n ; j++) {
            if (A[i] > A[j ]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}
void sort2D(int a[][100], int m, int n) {
    //sap xep hang
    for (int i = 0; i < m; i++) {
        sort(a[i],n);
    }
    //sap xep cac cot
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if (a[i][j] > a[i + 1][j]) {
                int temp = a[i][j];
                a[i][j] = a[i + 1][j];
                a[i + 1][j] = temp;
            }
        }
    }
}
//bai 2
void sortFile(const string& text) {
    int a[1000];
    int size = 0; 

    
    ifstream inputFile(text);
    int num;
    while (inputFile >> num && size < 1000) {
        a[size++] = num;
    }
    inputFile.close();

    
    sort(a, size);

    
    ofstream outputFile(text);
    for (int i = 0; i < size; ++i) {
        outputFile << a[i] << " ";
    }
    outputFile.close();

    cout << "Cac so trong  " << text << " sau săp xep la " << endl;
}
int main() {
    int A[][100] = { {1, 2,3,4},
        {3, 4,8,9} };
    sort2D(A, 2, 4);
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < 4; i++)
            cout << A[j][i];

    string text;
    cout << "Nhập tên tập tin cần sắp xếp: ";
    cin >> text;

    sortFile(text);

    return 0;
}