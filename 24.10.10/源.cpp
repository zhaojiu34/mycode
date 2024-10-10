#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     * �������������ͼ
     * @param xianxu int����vector �������
     * @param zhongxu int����vector �������
     * @return int����vector
     */
    vector solve(vector& xianxu, vector& zhongxu) {
        // write code here
        vector res = viewRight(xianxu, zhongxu, 0, zhongxu.size() - 1, 0);
        return res;
    }
    /**
     * �ʼ���뷨�ǣ��ع�������+�������
     * ����ϸһ�뷢�ֲ���, �ⷨ���£�
     *   ʹ�õݹ��ҵ���������������ͼ������������������ͼ��ӵ�����У�
     *   ֮��ʹ����ͬ������������ʱ����������ֵ�������������
     *
     * ��Ҫע��������Ѱ���������ĸ��ڵ㣬����ǰ������������֪xianxu[0]��Ȼ�Ǹ��ڵ㣬
     * ��ô֮������������ڵ����Ѱ���أ��������ĸ��ڵ�index = ��ʱ�ĸ��ڵ�index+���������Ľڵ����,
     * �����Կ�����ǰ�����ҵ��������ĸ��ڵ��ˡ�
     *
     * �������LC199 Binary Tree Right Side View����
     *
     *
     */
    vector viewRight(vector& xianxu, vector& zhongxu, int start, int end, int ridx)
    {
        if (start > end) return vector();
        int root = xianxu[ridx];
        vector res;
        res.push_back(root);
        int idx = find(
            zhongxu.begin() + start, zhongxu.begin() + end, root) - zhongxu.begin();
        vector left;
        if (idx > start)
            left = viewRight(xianxu, zhongxu, start, idx - 1, ridx + 1);
        vector right;
        if (idx < end)
            right = viewRight(xianxu, zhongxu, idx + 1, end, ridx + idx - start + 1);
        int i = 0;
        while (i < right.size())
        {
            res.push_back(right[i]);
            i++;
        }
        while (i < left.size())
        {
            res.push_back(left[i]);
            i++;
        }
        return res;
    }
};