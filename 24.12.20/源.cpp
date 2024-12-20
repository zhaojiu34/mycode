#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    void recursion(vector<vector<int>>& res, vector<int>& num, int index) {
        if (index == num.size() - 1)
            res.push_back(num);                        //@1
        else {
            for (int i = index; i < num.size(); i++) {       //@2
                swap(num[i], num[index]);                //@3
                recursion(res, num, index + 1);        //@4
                swap(num[i], num[index]);                //@5
            }
        }
    }
    vector<vector<int> > permute(vector<int>& num) {
        sort(num.begin(), num.end());
        vector<vector<int>> res;

        recursion(res, num, 0);
        return res;
    }
};