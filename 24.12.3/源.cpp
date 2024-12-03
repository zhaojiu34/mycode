#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <string>

using namespace std;


static int ans[10000] = { 0 }, maxdeep = 0;

void dfs(int* xianxu, int xianxuLen, int* zhongxu, int zhongxuLen, int deep)
{
    if (xianxuLen < 1 || zhongxuLen < 1) return;
    int indx = 0;
    maxdeep = deep > maxdeep ? deep : maxdeep;
    ans[deep] = xianxu[0];
    if (xianxuLen == 1 || zhongxuLen == 1) return;
    for (; indx < zhongxuLen; indx++)
    {
        if (zhongxu[indx] == xianxu[0]) break;
    }
    dfs(xianxu + 1, indx, zhongxu, indx, deep + 1);
    dfs(xianxu + indx + 1, xianxuLen - 1 - indx, zhongxu + indx + 1, zhongxuLen - 1 - indx, deep + 1);

}


int* solve(int* xianxu, int xianxuLen, int* zhongxu, int zhongxuLen, int* returnSize) {
    // write code here
    dfs(xianxu, xianxuLen, zhongxu, zhongxuLen, 0);
    *returnSize = maxdeep + 1;
    return ans;
}
