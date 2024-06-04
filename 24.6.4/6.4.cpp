#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <stack>


using namespace std;

//只出现过一次的数字
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int cnt1 = 0;
            for (int x : nums) {
                cnt1 += x >> i & 1;
            }
            ans |= cnt1 % 3 << i;
        }
        return ans;
    }
};


//找出两个只出现一次的数字
class solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int sum = 0;
        for (const int& e : nums)
        {
            sum ^= e;
        }

        int l = (sum == INT_MIN ? sum : sum & (-sum));

        int sum1 = 0, sum2 = 0;
        for (const int& e : nums)
        {
            if (e & l)
                sum1 ^= e;
            else
                sum2 ^= e;
        }

        vector<int> vv = { sum1,sum2 };
        return vv;
    }
}; 

//最小栈
class MinStack {
public:
    MinStack()
    {}

    void push(int val) {
        if (minst.empty())
        {
            st.push(val);
            minst.push(val);
        }
        else if (val <= minst.top())
        {
            st.push(val);
            minst.push(val);
        }
        else
        {
            st.push(val);
        }

    }

    void pop() {
        if (st.top() == minst.top())
        {
            st.pop();
            minst.pop();
        }

        else {
            st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minst.top();
    }

    stack<int> st;
    stack<int> minst;
};

//栈的压入，弹出
bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
{
    // write code here
    stack<int> s;
    auto pushit = pushV.begin();
    auto popit = popV.begin();

    while (pushit != pushV.end())
    {
        s.push(*pushit);

        while (!s.empty() && s.top() == (*popit))
        {
            s.pop();
            popit++;
        }

        pushit++;
    }

    return s.empty();
}
};
