#pragma once
#include <iostream>

using namespace std;


template<class K, class V>
struct BSTreeNode
{

	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;
	K _key;
	V _val;

	BSTreeNode(K key, V val)
		:_key(key)
		, _val(val)
		, _left(nullptr)
		, _right(nullptr)
	{}

};




template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:

	bool Insert(const K& key, const V& val)
	{
		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		Node* newNode = new Node(key, val);

		if (parent&&parent->_key > key)
		{
			parent->_left = newNode;
		}
		else if(parent && parent->_key < key)
		{
			parent->_right = newNode;
		}
		else
		{
			_root = newNode;
		}

		return true;
	}


	Node* Find(const K& key)
	{
		Node* cur = _root;

		while (cur)
		{
			if (cur->_key < key)
			{
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}


	bool Erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//只有一个孩子或者没有孩子
				if (cur->_left == nullptr)
				{
					//判断cur是parent的左孩子还是又右孩子
					if (parent == nullptr)
					{
						_root = cur->_right;
						return true;
					}

					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}

					delete cur;
					return true;
				}
				else if (cur->_right == nullptr)
				{
					//判断cur是parent的左孩子还是又右孩子
					if (parent == nullptr)
					{
						_root = cur->_left;
						return true;
					}

					if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}

					delete cur;
					return true;
				}

				else//有两个孩子，找左子树的最右边或者右子树的最左边
				{
					Node* rightMin = cur->_right;
					Node* rightP = cur;

					while (rightMin->_left)
					{
						rightMin = rightMin->_left;
						rightP = rightMin;
					}

					_root->_key = rightMin->_key;
					_root->_val = rightMin->_val;

					if (rightP->_right == rightMin)
					{
						if (rightMin->_left == nullptr)
							rightP->_right = rightMin->_right;
						else
							rightP->_right = rightMin->_left;
					}
					else
					{
						if (rightMin->_left == nullptr)
							rightP->_left = rightMin->_right;
						else
							rightP->_left = rightMin->_left;
					}

					delete rightMin;
					return true;

				}

			}
		}

		return false;
	}


	void InOrder()
	{
		_InOrder(_root);
	}


private:

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_key << " -> " << root->_val << endl;
		_InOrder(root->_right);

	}

	Node* _root = nullptr;
};


void TestBSTree()
{
	BSTree<string, string> dict;
	dict.Insert("insert", "插入");
	dict.Insert("erase", "删除");
	dict.Insert("left", "左边");
	dict.Insert("string", "字符串");

	dict.Erase("insert");
	dict.Erase("erase");
	dict.Erase("left");
	dict.Erase("string");

	dict.InOrder();
	cout << endl;

	//string str;
	//while (cin >> str)
	//{
	//	auto ret = dict.Find(str);
	//	if (ret)
	//	{
	//		cout << str << ":" << ret->_val << endl;
	//	}
	//	else
	//	{
	//		cout << "单词拼写错误" << endl;
	//	}
	//}

	string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
	// 统计水果出现的次
	BSTree<string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_val++;
		}
	}
	countTree.InOrder();
}

