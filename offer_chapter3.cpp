#include<iostream>
using namespace std;

//面试题11：数值的整数次方

//两种版本的求次方算法。
double powerwithunsignedexp(double base, unsigned int absexp)
{
	double result = 1.0;
	for (int i = 0;i < absexp;++i)
	{
		result *= base;
	}
	return result;
}

//版本二，递归算法
double powerwithunsignedexp_2(double base, unsigned int absexp)
{
	if (absexp == 0)
	{
		return 1;
	}
	if (absexp == 1)
	{
		return base;
	}

	double result = powerwithunsignedexp_2(base, absexp >> 1);
	result *= result;
	if (absexp & 0x1 == 1)
		result *= base;

	return result;
}
bool _equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2) < 0.0000001)
	{
		return true;
	}
	else
		return false;
}
double power(double base, int exp)
{
	if (exp == 0)
	{
		return 1.0;
	}
	if (_equal(base, 0.0) && exp < 0)
	{
		cout << "input invalid" << endl;
		return 0;
	}

	unsigned int absexp = (unsigned int)(exp);

	if (exp < 0)
	{
		absexp = (unsigned int)(-exp);
	}
	double result = powerwithunsignedexp(base, absexp);

	if (exp < 0)
		result = 1.0 / result;

	return result;

}
void test()
{
	cout << power(0.0, -1) << endl;
	cout << power(3.3, 3) << endl;
	cout << power(3.3, -3) << endl;
}


//面试题12：打印1到最大的n位数
//寻常写法
bool _Increment(char *str)
{
	bool IsOverFlow = false;
	int flag = 0;			//进位标志
	int length = strlen(str);

	for (int i = length - 1;i >= 0;--i)
	{
		int nsum = str[i] - '0' + flag;

		if (i == length-1)
			nsum++;

		if (nsum>=10)
		{
			if (i==0)
			{
				IsOverFlow = true;
			}
			else
			{
				nsum -= 10;
				flag = 1;
				str[i] = nsum + '0';
			}	
		}
		else
		{
			str[i] = nsum + '0';
			break;
		}

	}
	return IsOverFlow;
}

void PrintfNum(char* str)
{
	if (str == NULL)
		return;

	int length = strlen(str);
	bool flag = true;

	for (int i = 0;i < length;++i)
	{
		if (flag && str[i]!='0')
		{
			flag = false;
		}

		if (!flag)
		{
			printf("%c", str[i]);
		}
	}
}
void PrintMaxOfNum(int num)
{
	if (num <= 0)
		return;

	char* str = new char[num + 1];
	memset(str, '0', num + 1);
	str[num] = '\0';


	while (!_Increment(str))
	{
		PrintfNum(str);
	}

	delete []str;
}
//高级写法

void Print1ToNum_R(char *str,int length,int index)
{
	if (index == length-1)
	{
		PrintfNum(str);
		return;
	}


	for (int i = 0;i < 10;++i)
	{
		str[index + 1] = i + '0';
		Print1ToNum_R(str, length, index + 1);
	}
	cout << endl;
}
void Print1ToNum(int num)
{
	if (num <= 0)
		return;

	char *str = new char[num + 1];
	str[num] = '\0';

	for (int i = 0;i < 10;++i)
	{
		str[0] = i + '0';
		Print1ToNum_R(str, num, 0);
		
	}
}
void test1()
{
	//PrintMaxOfNum(3);
	Print1ToNum(3);
}
//面试题13：在O(1)时间内删除链表节点
struct ListNode
{
	ListNode(int value)
		:_value(value),
		_next(NULL)
	{}
	int _value;
	ListNode* _next;
};
class List
{
public:
	List()
		:_head(NULL),
		_size(0)
	{}
	~List()
	{
		ListNode* cur;
		while (_head)
		{
			cur = _head;
			_head = _head->_next;
			delete cur;
			cur->_next;
		}
	}
	void Insert(int data)
	{
		ListNode* NewNode = new ListNode(data);
		if (_head ==NULL)
		{
			_head = NewNode;
			++_size;
		}
		else
		{
			ListNode* cur = _head;
			
			while (cur->_next != NULL)
				cur = cur->_next;

			cur->_next = NewNode;
			++_size;
		}
	}
	void DeleteNodeOfList(ListNode* DeleteNode)
	{
		//存在情况，要删除的node不在链表中。
		//链表为空
		//只有一个node的删除，删除中间node，删除尾node

		if (_head == NULL || DeleteNode == NULL)
		{
			return;
		}

		//删除非尾节点
		if (DeleteNode->_next != NULL)
		{
			ListNode* flag = DeleteNode->_next;
			DeleteNode->_value = flag->_value;
			DeleteNode->_next = flag->_next;
			delete flag;
			flag = NULL;
		}
		//只有一个节点，删除头结点
		else if (DeleteNode == _head)
		{
			delete DeleteNode;
			DeleteNode = NULL;
			_head = NULL;
		}
		//链表有多个节点，删除尾节点
		else
		{
			ListNode* cur = _head;
			while (cur->_next != DeleteNode)
			{
				cur = cur->_next;
			}
			cur->_next = NULL;
			delete DeleteNode;
			DeleteNode = NULL;
		}
	}
	//void DeleteNodeOfList(ListNode* phead, ListNode* DeleteNode)
	//{
	//	//存在情况，要删除的node不在链表中。
	//	//链表为空
	//	//只有一个node的删除，删除中间node，删除尾node

	//	if (phead == NULL || DeleteNode == NULL)
	//	{
	//		return;
	//	}

	//	//删除非尾节点
	//	if (DeleteNode->_next != NULL)
	//	{
	//		ListNode* flag = DeleteNode->_next;
	//		DeleteNode->_value = flag->_value;
	//		DeleteNode->_next = flag->_next;
	//		delete flag;
	//		flag = NULL;
	//	}
	//	//只有一个节点，删除头结点
	//	else if (DeleteNode == phead)
	//	{
	//		delete DeleteNode;
	//		DeleteNode = NULL;
	//		phead = NULL;
	//	}
	//	//链表有多个节点，删除尾节点
	//	else
	//	{
	//		ListNode* cur = phead;
	//		while (cur->_next != DeleteNode)
	//		{
	//			cur = cur->_next;
	//		}
	//		cur->_next = NULL;
	//		delete DeleteNode;
	//		DeleteNode = NULL;
	//	}
	//}
	void Print()
	{
		ListNode* cur = _head;
		while (cur)
		{
			cout << cur->_value << "->";
			cur = cur->_next;
		}
		cout << "NULL" << endl;
	}
public:
	ListNode* _head;
	size_t _size;
};

//测试用例
void test13()
{
	List lt;
	lt.Insert(1);
	lt.Insert(2);
	lt.Insert(3);
	lt.Insert(4);
	lt.Insert(5);

	ListNode* deletenode = lt._head->_next;
	//删除头结点
	/*lt.DeleteNodeOfList(lt._head);
	lt.Print();*/

	//删除中间节点
	/*lt.DeleteNodeOfList(deletenode);
	lt.Print();*/

	//删除尾节点
	while (deletenode->_next !=NULL)
	{
		deletenode = deletenode->_next;
	}
	lt.DeleteNodeOfList(deletenode);
	lt.Print();
}

//面试题14：调整数组顺序使奇数位于偶数前面

void ReverOrder(int *arr, int length)
{
	if (arr == NULL || length <= 1)
		return;

	int left = 0;
	int right = length - 1;

	while (left<right)
	{
		while (left < right && (arr[left] & 0x01 == 1))
			left++;
		                                          
		//while (left < right && !(arr[right] & 0x01 == 1))
		while (left < right && (arr[right]%2 == 0))
			right--;

		swap(arr[left], arr[right]);
	}
}
//高级用法

void HighReverOrder(int *arr, int length,bool (*Func)(int))
{
	if (arr == NULL || length <= 1)
		return;

	int left = 0;
	int right = length - 1;

	while (left < right)
	{
		while (left < right && Func(arr[left]))
			left++;

		//while (left < right && !(arr[right] & 0x01 == 1))
		while (left < right && !(Func(arr[right])))
			right--;

		swap(arr[left], arr[right]);
	}
}
bool function(int data)
{
	return (data & 0x01 == 1);
}
void test2()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	//ReverOrder(arr, sizeof(arr)/sizeof(arr[0]));
	HighReverOrder(arr, sizeof(arr) / sizeof(arr[0]),function);
	for (int i = 0;i < sizeof(arr) / sizeof(arr[0]);++i)
	{
		cout << arr[i] << "-->";
	}
	cout << endl;
}


//面试题15：链表中倒数第K个节点
bool KIsOverFlow = false;

ListNode* FindKToTail(ListNode* head, int k)
{
	if (head == NULL || k <= 0)
		return NULL;


	ListNode* _front = head;
	ListNode* _behind = head;
	for (int i = 0;i < k - 1;++i)
	{
		if (_front->_next == NULL)
		{
			KIsOverFlow = true;
			return NULL;
		}
		_front = _front->_next;
		
	}

	while (_front->_next)
	{
		_front = _front->_next;
		_behind = _behind->_next;
	}

	return _behind;
}
void test3()
{
	List lt;
	lt.Insert(1);
	lt.Insert(2);
	lt.Insert(3);
	lt.Insert(4);
	lt.Insert(5);
	ListNode* ret = FindKToTail(lt._head, 6);

	if (KIsOverFlow)
	{
		cout << "k is invalid input" << endl;
	}
	if (ret)
	{
		cout <<"ret is "<< ret->_value << endl;
	}

}
//面试题16：单链表逆置
ListNode* Reverse(ListNode* head)
{
	if (head == NULL || head->_next == NULL)
		return NULL;

	ListNode* newNode = NULL;
	ListNode* prev = NULL;
	ListNode* cur = head;
	
	while (cur)
	{
		ListNode* Next = cur->_next;
		if (Next==NULL)
		{
			newNode = cur;
		}
		cur->_next = prev;
		prev = cur;
		cur = Next;
	}

	return newNode;
}
void test5()
{
	List lt;
	lt.Insert(1);
	lt.Insert(2);
	lt.Insert(3);
	lt.Insert(4);
	lt.Insert(5);
	ListNode* ret = Reverse(lt._head);
	while (ret)
	{
		cout << ret->_value << "->";
		ret = ret->_next;
	}
	cout << "NULL" << endl;

}

//扩展题：单链表逆置的递归写法
void Reverse_R(ListNode* prev, ListNode* head,ListNode*& newNode)
{
	//prev初始化NULL，head为头指针
	if (head == NULL)
	{
		newNode = prev;
		return;
	}
	Reverse_R(head, head->_next,newNode);
	head->_next = prev;
}
void test6()
{
	List lt;
	lt.Insert(1);
	lt.Insert(2);
	lt.Insert(3);
	lt.Insert(4);
	lt.Insert(5);
	ListNode* ret;
	Reverse_R(NULL,lt._head,ret);
	while (ret)
	{
		cout << ret->_value << "->";
		ret = ret->_next;
	}
	cout << "NULL" << endl;

}
//面试题17：合并两个排序链表
//递归写法
ListNode* Merge_R(ListNode* head1, ListNode* head2)
{
	if (head1 == NULL)
		return head2;

	if (head2 == NULL)
		return head1;

	ListNode* newNode = NULL;
	if (head1->_value < head2->_value)
	{
		newNode = head1;
		newNode->_next = Merge_R(head1->_next, head2);
	}
	else
	{
		newNode = head2;
		newNode->_next = Merge_R(head1, head2->_next);
	}
	return newNode;
}
//迭代写法
void Merge(ListNode* head1, ListNode* head2,ListNode*& newHead)
{
	if (head1 == NULL)
		newHead =head2;

	if (head2 == NULL)
		newHead= head1;

	ListNode* cur = newHead;
	while (head1 && head2)
	{
		if(head1->_value<head2->_value)
		{
			if (cur == NULL)
			{
				cur = head1;
				newHead = cur;
			}
			else
			{
				cur->_next = head1;
				cur = cur->_next;
			}
			head1 = head1->_next;
		} 
		else
		{
			if (cur == NULL)
			{
				cur = head2;
				newHead = cur;
			}
			else
			{
				cur->_next = head2;
				cur = cur->_next;
			}
			head2 = head2->_next;
		}
	}
	if (head1 == NULL)
		cur->_next = head2;

	if (head2 == NULL)
		cur->_next = head1;

}
void test7()
{
	List lt;
	lt.Insert(1);
	lt.Insert(3);
	lt.Insert(5);
	lt.Insert(7);
	lt.Insert(9);

	List lt2;
	lt2.Insert(2);
	lt2.Insert(4);
	lt2.Insert(6);
	lt2.Insert(8);
	lt2.Insert(10);

	ListNode* ret = NULL;
	Merge(lt._head, lt2._head,ret);

	while (ret)
	{
		cout << ret->_value << "->";
		ret = ret->_next;
	}
	cout << "NULL" << endl;

}
//面试题18:树的子结构
struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};
bool DoesTreeInclude(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot2 == NULL)
		return true;

	if (pRoot1 == NULL)
		return false;

	if (pRoot1->_value != pRoot2->_value)
		return false;

	return DoesTreeInclude(pRoot1->_left, pRoot2->_left) && \
		DoesTreeInclude(pRoot1->_right, pRoot2->_right);
}
bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool result = false;
	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		if (pRoot1->_value == pRoot2->_value)
			result = DoesTreeInclude(pRoot1, pRoot2);
		if (!result)
			result = HasSubTree(pRoot1->_left, pRoot2);
		if (!result)
			result = HasSubTree(pRoot1->_right, pRoot2);
	}
	return result;
}
