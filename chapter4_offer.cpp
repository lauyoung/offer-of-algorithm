#include<iostream>
#include<stack>
#include <deque>
#include<assert.h>
using namespace std;

struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};

//������19���������ľ���--�ݹ�ʵ��
void MirrorBinary_R(BinaryTreeNode* Node)
{
	if (Node == NULL)
		return;

	if (Node->_left == NULL && Node->_right == NULL)
		return;

	BinaryTreeNode* temp = Node->_left;
	Node->_left = Node->_right;
	Node->_right = temp;

	if (Node->_left)
	{
		MirrorBinary_R(Node->_left);
	}
	if (Node->_right)
	{
		MirrorBinary_R(Node->_right);
	}
}

//��ѭ��ʵ������Ĵ���
//˼·���ڵ�ȫѹ��ջ����Ȼ������ȡ����������Ϊ��break�����򽻻����ң�ջΪ��
void _MyPush(BinaryTreeNode* Node, stack<BinaryTreeNode*> &st)
{
	if (Node == NULL)
		return;

	st.push(Node);
	_MyPush(Node->_left,st);
	_MyPush(Node->_right,st);
}
void MirrorBinary(BinaryTreeNode* Node)
{
	if (Node == NULL)
		return;

	if (Node->_left == NULL && Node->_right == NULL)
		return;

	stack<BinaryTreeNode*> st;
	_MyPush(Node, st);

	while (st.size() > 0)
	{
		Node = st.top();
		swap(Node->_left, Node->_right);
		st.pop();
	}
}

//������20��˳ʱ���ӡ����
void PrintNumber(int num)
{
	cout << num << " ";
}
void PrintMatrix(int arr[][4], int col, int row, int start)
{
	int endx = row - 1 - start;
	int endy = col - 1 - start;

	//�������Ҵ�ӡ
	for (int i = start;i <= endx;++i)
	{
		PrintNumber(arr[start][i]);
	}

	//�������´�ӡ
	if (start<endy)
	{
		for (int i = start + 1;i <= endy;++i)
		{
			PrintNumber(arr[i][endx]);
		}
	}

	//���������ӡ
	if (start < endx && start < endy)
	{
		for (int i = endx - 1;i >= start;--i)
		{
			PrintNumber(arr[endy][i]);
		}
	}

	//�������ϴ�ӡ
	if (start < endy - 1 && start<endx)
	{
		for (int i = endy - 1;i >= start+1;--i)
		{
			PrintNumber(arr[i][start]);
		}
	}
}
void PrintMatrixInCircle(int arr[][4], int col, int row)
{
	if (arr == NULL || col <= 0 || row <= 0)
		return;

	int start = 0;
	while (col > start * 2 && row > start * 2)
	{
		PrintMatrix(arr, col, row, start);
		start++;
	}
}

void test11()
{
	int arr[][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	PrintMatrixInCircle(arr, 4, 4);
}
//������21������min������ջ
template<class T>
class  StackWithMin
{
public:
	void _MyPush(const T& value)
	{
		_data.push(value);
		if (_min.size() <= 0 || _min.top() > value)
		{
			_min.push(value);
		}
		else
		{
			_min.push(_min.top());
		}
	}
	void _Mypop()
	{
		assert(_data.size() >= 0 && _min.size() >= 0);

		_data.pop();
		_min.pop();
	}
	const T& min() const
	{
		assert(_data.size() >= 0 && _min.size() >= 0);
		return _min.top();
	}
public:
	stack<T> _data;
	stack<T> _min;
};
void test12()
{
	StackWithMin<int> swm;
	swm._MyPush(3);
	swm._MyPush(4);
	swm._MyPush(2);
	swm._MyPush(1);
	swm._MyPush(0);
	swm._MyPush(5);
	int ret = swm.min();
	cout <<ret<< endl;
}
//������22��ջ��ѹ�룬��������
bool IsPopOrder(const int *pPush, const int* pPop, int length)
{
	bool flag = false;

	if (pPush!=NULL &&pPop!=NULL && length>0)
	{
		const int* pPushNext = pPush;
		const int* pPopNext = pPop;
		stack<int> st;

		while (pPopNext - pPop < length)
		{
			while (st.empty() || *pPopNext != st.top())
			{
				if (pPushNext - pPush == length)
					break;

				st.push(*pPushNext);
				++pPushNext;
			}

			if (st.top() != *pPopNext)
				break;

			st.pop();
			pPopNext++;
		}

		if (st.empty() && pPopNext - pPop == length)
			flag = true;
	}

	return flag;
}
void test14()
{
	int arr[] = {1,2,3,4,5};
	int arr2[] = { 4,3,5,1,2 };
	cout << IsPopOrder(arr, arr2, 5) << endl;
}
//������23����α���������
void PrintTreeFromTop(BinaryTreeNode* _root)
{
	if (!_root)
		return;
	deque<BinaryTreeNode*> de;
	de.push_back(_root);

	while (de.size())
	{
		BinaryTreeNode* Node = de.front();
		de.pop_front();

		cout <<Node->_value<< " ";

		if (Node->_left)
		{
			de.push_back(Node->_left);
		}
		if (Node->_right)
		{
			de.push_back(Node->_right);
		}
	}
}
int main()
{
	test14();
	return 0;
}