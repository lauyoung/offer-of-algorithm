
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

//������3����ά�����еĲ���
//#include <iostream>
//#include <vector>
//using namespace std;
//#define M 100
//#define N 100
//
//#include <cassert>
//
//bool Find(int array[][N], int row, int col, int key)
//{
//	assert(row > 0 && col > 0);
//
//	bool found = false;
//	int i = 0, j = col - 1;
//	while (i <row && j >= 0)
//	{
//		if (array[i][j] == key)
//		{
//			found = true;
//			break;
//		}
//		else if (array[i][j] > key)
//		{
//			j--;
//		}
//		else
//		{
//			i++;
//		}
//
//	}
//	return found;
//}
//
////��������������4x4�����飬����Ҫ���ҵ����ݣ�����1(����)����0(������)
////4 4
////1  2  8  9
////2  4  9  12
////4  7  10 13
////6  8  11 15
//int main()
//{
//	int array[M][N];
//
//	int m, n, key;
//	cin >> m;
//	cin >> n;
//
//	for (int i = 0;i < m;++i)
//		for (int j = 0;j < n;++j)
//		{
//			cin >> array[i][j];
//		}
//	cin >> key;
//	cout << Find(array, m, n, key) << endl;
//	return 0;
//}

//�������ģ���ʵ��һ����������һ���ַ����еĿո��滻�ɡ� % 20�������磬��
//�ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe % 20Are % 20Happy��
//void replaceSpace(char *str, int Length)
//{
//
//	assert(str != NULL || Length > 0);
//
//	int num = 0;
//	int length = 0;
//	int i = 0;
//	while ('\0' != str[i])
//	{
//		++length;
//		if (str[i] == ' ')
//		{
//			num++;
//		}
//		i++;
//	}
//	int NewLength = 2 * num + length;
//	int PrevofArray = length;
//	while (PrevofArray >= 0 && NewLength > PrevofArray)
//	{
//		if (str[PrevofArray] == ' ')
//		{
//			str[NewLength--] = '0';
//			str[NewLength--] = '2';
//			str[NewLength--] = '%';
//		}
//		else
//		{
//			str[NewLength--] = str[PrevofArray];
//		}
//		--PrevofArray;
//	}
//}
//const int MAX = 100;
////����������
////���������1���޿ո�2��һ���ո�3������ո�
//int main()
//{
//	//�޿ո�
//	char str3[MAX] = "iamabadboy";
//	cout << str3 << endl;
//
//	replaceSpace(str3, strlen(str3));
//	cout << str3 << endl;
//
//
//	char str[MAX] = "we are happy.";
//	cout << str << endl;
//
//	replaceSpace(str, strlen(str));
//	cout << str << endl;
//
//	//һ���ո�
//	char str1[MAX] = " ";
//	cout << str1 << endl;
//
//	replaceSpace(str1, strlen(str1));
//	cout << str1<< endl;
//
//	//����ո����
//	char str2[MAX] = "     ";
//	cout << str2 << endl;
//
//	replaceSpace(str2, strlen(str2));
//	cout << str2 << endl;
//	return 0;
//}


//�������壺��β��ͷ��ӡ����
#include <iostream>
#include<vector>
#include<stack>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {

	}
};
void addTail(ListNode *&head, int value)
{
	ListNode* NewHead = new ListNode(value);
	NewHead->next = NULL;

	if (head == NULL)
	{
		head = NewHead;
	}
	else
	{
		ListNode *cur = head;
		while (cur->next !=NULL)
			cur = cur->next;

		cur->next = NewHead;
	}
}
//***************��β��ͷ��ӡ����***************************
//vector<int> printListFromTailToHead(ListNode* head)
//{
//	stack<int> vestack;
//	vector<int> ret;
//
//	while (head != NULL)
//	{
//		vestack.push(head->val);
//		head = head->next;
//	}
//	while (!vestack.empty())
//	{
//		int val = vestack.top();
//		ret.push_back(val);
//		vestack.pop();
//	}
//	return ret;
//}
void printListFromTailToHead(ListNode*& head)
{

	if (NULL != head)
	{
		if (NULL != head->next)
		{
			printListFromTailToHead(head->next);
		}
		cout << head->val << " ";
	}
}
int test()
{

	ListNode* head = NULL;
	addTail(head, 1);
	addTail(head, 2);
	addTail(head, 3);
	addTail(head, 4);
	addTail(head, 5);
	printListFromTailToHead(head);

	cout << endl;
	return 0;
}

//������6���ؽ�������
 struct TreeNode 
 {
	 int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 //�ؽ�������--�汾1
 //struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in)
 //{
	// if (pre.size() == 0)
	//	 return NULL;
	// 
	// TreeNode* root = new TreeNode(pre[0]);

	// vector<int> LeftPre, RightPre, LeftIn, RightIn;
	// bool flag = false;
	// for (int i = 0;i < pre.size();++i)
	// {
	//	 if (in[i] == pre[0])
	//	 {
	//		 flag = true;
	//		 continue;
	//	 }
	//	 if (flag == false)
	//	 {
	//		 LeftPre.push_back(pre[i+1]);
	//		 LeftIn.push_back(in[i]);
	//	 }
	//	 else
	//	 {
	//		 RightPre.push_back(pre[i]);
	//		 RightIn.push_back(in[i]);
	//	 }
	// }
	// root->left = reConstructBinaryTree(LeftPre, LeftIn);
	// root->right = reConstructBinaryTree(RightPre, RightIn);
	// return root;
 //}



//�ؽ�������--�汾2
struct TreeNode* ConstructBTree(vector<int>::iterator PreBegin, \
	vector<int>::iterator PreEnd, \
	vector<int>::iterator InBegin, \
	vector<int>::iterator InEnd)
{
	int rootval = PreBegin[0];
	TreeNode* root = new TreeNode(rootval);
	root->left = root->right = NULL;

	if (PreBegin == PreEnd)
	{
		if (InBegin == InEnd && *PreBegin == *InBegin)
		{
			return root;
		}
		else
		{
			cout << "input error1" << endl;
			return NULL;
		}
	}
	//�����������Ѱ�Ҹ��ڵ��ֵ
	vector<int>::iterator PointIn = InBegin;
	while (PointIn != InEnd && *PointIn != rootval)
		++PointIn;

	if (PointIn == InEnd&&*PointIn != rootval)
	{
		cout << "input error2" << endl;
		return NULL;
	}

	int gap = PointIn - InBegin;
	vector<int>::iterator LeftPreEnd = PreBegin + gap;

	if (gap > 0)
	{
		root->left = ConstructBTree(PreBegin+1,LeftPreEnd,InBegin,PointIn-1);
	}
	if (gap < PreEnd - PreBegin)
	{
		root->right= ConstructBTree(LeftPreEnd+1,PreEnd, PointIn+1,InEnd);
	}
	return root;
}
	
struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in)
{
	if (pre.size() == 0 || in.size() == 0)
		return NULL;
	return ConstructBTree(pre.begin(), pre.end() - 1, in.begin(), in.end() - 1);
}

int test2()
{
	vector<int> pre;
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(4);
	pre.push_back(7);
	pre.push_back(3);
	pre.push_back(5);
	pre.push_back(6);
	pre.push_back(8);

	vector<int> in;
	in.push_back(4);
	in.push_back(7);
	in.push_back(2);
	in.push_back(1);
	in.push_back(5);
	in.push_back(3);
	in.push_back(8);
	in.push_back(6);

	struct TreeNode*ret;
	ret= reConstructBinaryTree(pre,in);
	return 0;
}
//�������ߣ�������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������
//�����е�Ԫ��Ϊint���͡�

#include<iostream>
#include<stack>
using namespace std;

class MyQueue
{
public:
	void push(int node)
	{
		stack1.push(node);
	}

	int pop()
	{
		if (stack2.size() <= 0)
		{
			while (!stack1.empty())
			{
				int node = stack1.top();
				stack1.pop();
				stack2.push(node);
			}
			if (stack2.size() == 0)
			{
				cout << "queue is empty" << endl;
			}
			int ret = stack2.top();
			stack2.pop();
			return ret;
		}
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
//�����������鿴������Ԫ���Ƿ�Ϊ��һ�ν�ȥ�ġ�
int test3()
{
	MyQueue qu;
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	qu.push(5);

	int ret = qu.pop();
	cout << ret << endl;
	return 0;
}
//������8����ת�������Сֵ

//˳�����
int find(int *arr, int left, int right)
{
	int ret = arr[left];
	for (int i = left;i < right;++i)
	{
		if (arr[i] < ret)
		{
			ret = arr[i];
		}
	}
	return ret;
}
int BinarySearchMin(int *arr,int length)
{

	int len = length;
	int left = 0;
	int right = len - 1;
	int mid = left;
	while (left <= right)
	{
		//��ֻ��������ʱ��ǰ����Ǹ������Ƿǵ�����������ֵ��
		//�������������ת�����Сֵ��

		if (right - left == 1)
		{
			mid = right;
			break;
		}
		mid = left + (right - left) / 2;

		//��������Ĵ���
		if (arr[left] == arr[mid] && arr[right] == arr[mid])
		{
			return find(arr, left, right);
		}

		if (arr[mid] >= arr[left])
		{
			left = mid;
		}
		else if (arr[mid] <= arr[right])
		{
			right = mid;
		}
	}
	return arr[mid];
}
//�������������������������ʱ���������������drr�����ô�ͳ�ķ�����������
int test4()
{
	int arr[] = { 3,4,6,7,8,1,2 };
	int brr[] = { 1,1,1,0,1 };
	int crr[] = { 1,1,1,1,1,0 };
	int drr[] = { 1,1,1,1,1,1 };
	int err[] = { 1};
	cout << BinarySearchMin(arr,7) << endl;
	cout << BinarySearchMin(brr,5) << endl;
	cout << BinarySearchMin(crr,6) << endl;
	cout << BinarySearchMin(drr, 6) << endl;
	cout << BinarySearchMin(err, 1) << endl;
	return 0;
}

//��Ŀ������������10���ˣ�һ�ֶ������ƣ�һ�ֲ�����
//��ô��֪������int32����m��n�Ķ����Ʊ��ж��ٸ�λ(bit)��ͬô��
//
//#include <iostream>
//using namespace std;
//
//int countBitDiff(int m, int n) {
//	int num = m^n;
//	int i = 0;
//	int count=0;
//	while (i<32)
//	{
//		int tmp=1 << i;
//		if (tmp&num)
//		{
//			count++;
//		}
//		++i;
//	}
//	return count;
//}
//int main()
//{
//	int num1, num2;
//	cin >> num1 >> num2;
//	cout << countBitDiff(num1, num2)<<endl;
//	return 0;
//}


//#include<iostream>
//#include<string.h>
//#include <assert.h>
//using namespace std;
//


//��Ѷ2016���� ���ɸ�����
//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<string> getGray(int n)
//{
//	vector<string> arr(int(pow(2,n)));
//
//	if (n == 1)
//	{
//		arr[0] = "0";
//		arr[1] = "1";
//		return arr;
//	}
//
//	vector<string> last = getGray(n - 1);
//
//	for (int i = 0; i < last.size();++i)
//	{
//		arr[i] = "0" + last[i];
//		arr[arr.size() - i - 1] = "1" + last[i];
//	}
//	
//	return arr;
//}
//int main()
//{
//	int num;
//	cin >> num;
//	vector<string> array;
//	array=getGray(num);
//
//	return 0;
//}






//������9��쳲���������
//int Fibonacci(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	return Fibonacci(n - 1) + Fibonacci(n - 2);
//}
//int Fibonacci(int n) 
//{
//	int arr[2] = { 0,1 };
//	if (n <= 2)
//	{
//		return arr[n];    
//	}
//	int curr = arr[0];
//	int next = arr[1];
//	int ret = 0;
//	for (int i = 2;i < n;++i)
//	{
//		ret = curr + next;
//		curr = next;
//		next = ret;
//	}
//	return ret;
//}


//������10����������1�ĸ���

//����ȱ�ݵĴ���
//int NumOf1(int num)
//{
//	int i = 0;
//	int j;
//	int count = 0;
//	while (i < 32)
//	{
//		j = 1 << i;
//		if (j&num)
//		{
//			count++;
//		}
//		++i;
//	}
//	return count;
//}

int Numof1(int num)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (flag&num)
			count++;
		flag = flag << 1;
	}
	return count;
}
//����n&(n-1)���Խ����������һ��1��0.
int NumOf1(int num)
{
	int count = 0;
	while (num)
	{
		num = num&(num - 1);
		++count;
	}
	return count;
}
//����ķ���
int BitCount(int n)
{
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);

	return n;
}
int main()
{
	cout << BitCount(-1) << endl;
	cout << NumOf1(-1) << endl;
	return 0;
}

