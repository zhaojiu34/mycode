#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (k == 0 || k > input.size()) {
            return res;
        }
        //vector���Դ���sort������������
        sort(input.begin(), input.end());
        //����������ǰkС����
        return vector<int>({ input.begin(),input.begin() + k });
    }
};
