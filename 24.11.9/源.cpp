#define _CRT_SECURE_NO_WARNINGS 1



	/**
	* Ë«Ö¸Õë
	*/
	string LCS(string str1, string str2) {
		int first = 0, second = 0;

		int maxLen = 0;
		string res;
		while (second < str1.size()) {
			string subStr = str1.substr(first, second - first + 1);
			if (str2.find(subStr) != string::npos) {
				if (subStr.size() > maxLen) {
					maxLen = subStr.size();
					res = subStr;
				}
				second++;
			}
			else {
				if (second == first) {
					second++;
					first++;
				}
				else if (first < second) {
					first++;
				}
			}
		}

		return res;
	}

