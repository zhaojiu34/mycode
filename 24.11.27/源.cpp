#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    vector<vector<int> > ans;//存储答案用数组
    bool used[10];//判断某个数字是否被使用过
    int N;//数字个数
    void dfs(vector<int> a, vector<int>& num)
    {
        if (a.size() == N) { ans.push_back(a); return; }//若求出了一个排列将其存入答案
        for (int i = 0; i < N; i++)
        {            //if(mark[i] || i>0 && num[i] == num[i-1] && !mark[i-1]){

            if (!used[i] && !(i >= 1 && num[i] == num[i - 1] && !used[i - 1]))//若未使用过n号数字且第n号数字与其前一个不相同（排除相同的数字被多次填入同一个位置）
            {
                used[i] = true;
                a.push_back(num[i]);//将n号数字放入排列
                dfs(a, num);
                a.pop_back();
                used[i] = false;//回溯
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int>& num)
    {
        memset(used, false, sizeof used);
        N = num.size();
        sort(num.begin(), num.end());//为方便后序判断将数字排序
        dfs(vector<int>(), num);//开始搜索
        return ans;
    }
};

