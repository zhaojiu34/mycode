#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    vector<vector<int> > ans;//�洢��������
    bool used[10];//�ж�ĳ�������Ƿ�ʹ�ù�
    int N;//���ָ���
    void dfs(vector<int> a, vector<int>& num)
    {
        if (a.size() == N) { ans.push_back(a); return; }//�������һ�����н�������
        for (int i = 0; i < N; i++)
        {            //if(mark[i] || i>0 && num[i] == num[i-1] && !mark[i-1]){

            if (!used[i] && !(i >= 1 && num[i] == num[i - 1] && !used[i - 1]))//��δʹ�ù�n�������ҵ�n����������ǰһ������ͬ���ų���ͬ�����ֱ��������ͬһ��λ�ã�
            {
                used[i] = true;
                a.push_back(num[i]);//��n�����ַ�������
                dfs(a, num);
                a.pop_back();
                used[i] = false;//����
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int>& num)
    {
        memset(used, false, sizeof used);
        N = num.size();
        sort(num.begin(), num.end());//Ϊ��������жϽ���������
        dfs(vector<int>(), num);//��ʼ����
        return ans;
    }
};

