#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
    // write code here
    //ˮƽ��ת
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
            swap(mat[i][j], mat[n - i - 1][j]);
        }
    }
    // ���Խ��߷�ת
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    return mat;
}
