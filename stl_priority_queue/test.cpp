#define _CRT_SECURE_NO_WARNINGS 1

#include "priority_queue.h"
#include<algorithm>

namespace Zq
{
	void test_priority1()
	{
		priority_queue<int> pq;
		pq.push(1);
		pq.push(21);
		pq.push(10);
		pq.push(4);
		pq.push(15);

		cout << pq.size()<<endl;

		while (!pq.empty())
		{
			cout << pq.top()<<" ";

			pq.pop();
		}
		cout << endl;

	}

	void test_priority2()
	{
		int a[] = { 10,30,40,55,65,45 };
		priority_queue<int, vector<int>, mygreater<int>> pq1(a, a + sizeof(a) / sizeof(int));
		while (!pq1.empty())
		{
			cout << pq1.top() << " ";

			pq1.pop();
		}
		cout << endl;
	}

}

//数组中第k个最大数
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		sort(nums.begin(), nums.end(), greater<int>());

		return nums[k - 1];
	}
};


int main()
{
	Zq::test_priority1();

	return 0;
}