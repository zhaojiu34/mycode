#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string×Ö·û´® the string
     * @param s2 string×Ö·û´® the string
     * @return string×Ö·û´®
     */
    string LCS(string s1, string s2) {
        // write code here
        int l1 = s1.size(), l2 = s2.size();
        vector<string> res(l2 + 1, "");
        for (int i = 1; i <= l1; i++) {
            string pre = "";
            for (int j = 1; j <= l2; j++) {
                string tem = res[j];
                if (s1[i - 1] == s2[j - 1]) {
                    res[j] = pre + s1[i - 1];
                }
                else {
                    res[j] = (res[j].size() > res[j - 1].size() ? res[j] : res[j - 1]);
                }
                pre = tem;
            }
        }

        if (res[l2] == "")
            return res[l2] = "-1";
        return res[l2];
    }
};
