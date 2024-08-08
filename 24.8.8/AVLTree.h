#pragma once

#include<iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _bf(0)
	{}

	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf;   // �ڵ��ƽ������
};


// AVL: ���������� + ƽ�����ӵ�����
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:

	AVLTree()
		: _pRoot(nullptr)
	{}


	AVLTree(const AVLTree<T>& t)
	{
		_pRoot = Copy(t._pRoot);
	}

	AVLTree operator=(AVLTree<T> t)
	{
		swap(_pRoot, t._pRoot);
		return *this;
	}

	~AVLTree()
	{
		Destroy(_pRoot);
		_pRoot = nullptr;
	}

	// ��AVL���в���ֵΪdata�Ľڵ�
	bool Insert(const T& data)
	{
		if (_pRoot == nullptr)
		{
			_pRoot = new Node(data);
			return true;
		}

		Node* cur = _pRoot;
		Node* parent = nullptr;

		while (cur)
		{
			if (cur->_data < data)
			{
				parent = cur;
				cur = cur->_pRight;
			}
			else if (cur->_data > data)
			{
				parent = cur;
				cur = cur->_pLeft;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(data);
		cur->_pParent = parent;
		
		//�����½ڵ�
		if (parent->_data < data)
			parent->_pRight = cur;
		else
			parent->_pLeft = cur;

		//����ƽ������
		while (parent)
		{
			if (parent->_pLeft == cur)
				parent->_bf--;
			else
				parent->_bf++;

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//�������ϵ���
				cur = parent;
				parent = cur->_pParent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//����
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)//�ҵ���
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)//����˫��
				{
					RotateRL(parent);
				}
				else
				{
				RotateLR(parent);//����˫��
				}

				break;

			}
		}

		return true;
	}
	
	size_t Size()
	{
		return _Size(_pRoot);
	}

	size_t Height()
	{
		return _Height(_pRoot);
	}

	void InOrder()
	{
		_InOrder(_pRoot);
		cout << endl;
	}

	bool IsBalanceTree()
	{
		return _IsBalanceTree(_pRoot);
	}

private:
	bool _IsBalanceTree(Node* root)
	{
		if (root == nullptr)
			return true;

		int lefHeight = _Height(root->_pLeft);
		int rightHeight = _Height(root->_pRight);

		int diff = rightHeight - lefHeight;

		if (diff != root->_bf || (diff > 1 || diff < -1))
		{
			return false;
		}

		return _IsBalanceTree(root->_pLeft) && _IsBalanceTree(root->_pRight);
	}

	void Destroy(Node* root)
	{
		if (root == nullptr)
			return;

		Destroy(root->_pLeft);
		Destroy(root->_pRight);

		delete root;
	}


	Node* Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;

		Node* r = new Node(root);
		root->_pLeft = new Node(root->_pLeft);
		root->_pRight = new Node(root->_pRight);

		return r;
	}


	void _InOrder(Node* pRoot)
	{
		if (pRoot == nullptr)
		{
			return;
		}

		_InOrder(pRoot->_pLeft);
		cout << pRoot->_data << " ";
		_InOrder(pRoot->_pRight);
	}


	size_t _Size(Node* pRoot)
	{
		if (pRoot == nullptr)
			return 0;

		return _Size(pRoot->_pLeft) + _Size(_pRoot->_pRight) + 1;
	}


	size_t _Height(Node* pRoot)
	{
		if (pRoot == __nullptr)
			return 0;

		int rightHeight = _Height(pRoot->_pRight);
		int leftHeight = _Height(pRoot->_pLeft);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}


	// �ҵ���
	void RotateR(Node* pParent)
	{
		Node* subL = pParent->_pLeft;
		Node* subLR = subL->_pRight;

		Node* pp = pParent->_pParent;

		//���Ľڵ�ָ��
		pParent->_pLeft = subLR;
		subL->_pRight = pParent;

		//���ڸ��׽ڵ�
		subL->_pParent = pp;
		pParent->_pParent = subL;
		if(subLR)
			subLR->_pParent = pParent;

		if (pp == nullptr)
		{
			_pRoot = subL;
			subL->_pParent = nullptr;
		}
		else
		{
			if (pp->_pLeft == pParent)
			{
				pp->_pLeft = subL;
			}
			else
			{
				pp->_pRight = subL;
			}
			subL->_pParent = pp;
		}

		//����ƽ������
		pParent->_bf = 0;
		subL->_bf = 0;
	}

	// ����
	void RotateL(Node* pParent)
	{
		Node* subR = pParent->_pRight;
		Node* subRL = subR->_pLeft;

		Node* pp = pParent->_pParent;

		//���ڸ��׺��ӽ��ָ��
		pParent->_pRight = subRL;
		subR->_pLeft = pParent;

		//���ڸ��׽ڵ�ָ��
		subR->_pParent = pp;

		if(subRL)
			subRL->_pParent = pParent;

		pParent->_pParent = subR;

		if (pp == nullptr)
		{
			_pRoot = subR;
			subR->_pParent = nullptr;
		}
		else
		{
			if (pp->_pLeft == pParent)
			{
				pp->_pLeft = subR;
			}
			else
			{
				pp->_pRight = subR;
			}
			subR->_pParent = pp;
		}

		//����ƽ������
		pParent->_bf = 0;
		subR->_bf = 0;
	}


	// ����˫��
	void RotateRL(Node* pParent)
	{
		Node* subR = pParent->_pRight;
		Node* subRL = subR->_pLeft;
		int bf = subRL->_bf;

		RotateR(pParent->_pRight);
		RotateL(pParent);
		
		if (bf == 0)
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			pParent->_bf = 0;
		}
		else if(bf == -1)
		{
			subRL->_bf = 0;
			subR->_bf = 1;
			pParent->_bf = 0;
		}
		else
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			pParent->_bf = -1;
		}
	}


	// ����˫��
	void RotateLR(Node* pParent)
	{
		Node* subL = pParent->_pLeft;
		Node* subLR = subL->_pRight;
		int bf = subLR->_bf;

		RotateL(pParent->_pLeft);
		RotateR(pParent);
		

		if (bf == 0)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			pParent->_bf = 0;
		}
		else if (bf == -1)
		{
			subLR->_bf = 0;
			subL->_bf = 0;
			pParent->_bf = 1;
		}
		else
		{
			subLR->_bf = 0;
			subL->_bf = -1;
			pParent->_bf = 0;
		}
	}

private:
	Node* _pRoot;
};
