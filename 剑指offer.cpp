#include<iostream>
#include<stack>
#include<assert.h>
#include<vector>
using namespace std;


//二维数组中的查找
//#include <iostream>
//#include <vector>
//using namespace std;
//#define M 100
//#define N 100
//
//#include <cassert>
//
//bool Find(int array[][N],int row,int col, int key) 
//{
//	assert(row > 0 && col > 0);
//
//	int i = 0,j = col-1;
//	while (i <row && j>=0)
//	{
//		if (array[i][j] == key)
//		{
//			return true;
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
//	return false;
//}
//
//int main()
//{
//	int array[M][N];
//
//	int m, n,key;
//	cin >> m;
//	cin >> n;
//
//	for (int i = 0;i < m;++i)
//		for (int j = 0;j < n;++j)
//		{
//			cin >> array[i][j];
//		}
//	cin >> key;
//	cout << Find(array,m,n,key)<<endl;
//	return 0;
//}


//题目描述世界上有10种人，一种懂二进制，一种不懂。
//那么你知道两个int32整数m和n的二进制表达，有多少个位(bit)不同么？
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

//从尾到头打印链表
//#include <iostream>
//#include<vector>
//#include<stack>
//using namespace std;
//
//
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//		val(x), next(NULL) {
//		
//	}
//	
//};
//***************从尾到头打印链表***************************
//vector<int> printListFromTailToHead(struct ListNode* head) {
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
//vector<int> printListFromTailToHead(struct ListNode* head)
//{
//	vector<int> ret;
//
//	if (NULL != head)
//	{
//		if (NULL != head->next)
//		{
//			printListFromTailToHead(head->next);
//		}
//		ret.push_back(head->val);
//	}
//	return ret;
//}
//#include<iostream>
//#include<string.h>
//#include <assert.h>
//using namespace std;
//
//请实现一个函数，将一个字符串中的空格替换成“ % 20”。例如，当
//字符串为We Are Happy.则经过替换之后的字符串为We % 20Are % 20Happy。
//void replaceSpace(char str[], int Length) {
//
//	assert(str != NULL || Length > 0);
//
//	int num=0;
//	int length = 0;
//	int i = 0;
//	while ('\0' !=str[i])
//	{
//		++length;
//		if (str[i] ==' ')
//		{
//			num++;
//		}
//		i++;
//	}
//	int NewLength = 2 * num + length;
//	int PrevofArray = length;
//	while (PrevofArray>=0 && NewLength >PrevofArray)
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
//int main()
//{
//	char str[22] = "we are happy.";
//	cout <<str<< endl;
//
//	int length = sizeof(str);
//	cout << length << endl;
//	replaceSpace(str,22);
//	cout << str << endl;
//	return 0;
//}

//腾讯2016春招 生成格雷码
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



//Definition for binary tree
// struct TreeNode 
// {
//	 int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
//
// //重建二叉树--版本1
// struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in)
// {
//	 if (pre.size() == 0)
//		 return NULL;
//	 
//	 TreeNode* root = new TreeNode(pre[0]);
//
//	 vector<int> LeftPre, RightPre, LeftIn, RightIn;
//	 bool flag = false;
//	 for (int i = 0;i < pre.size();++i)
//	 {
//		 if (in[i] == pre[0])
//		 {
//			 flag = true;
//			 continue;
//		 }
//		 if (flag == false)
//		 {
//			 LeftPre.push_back(pre[i+1]);
//			 LeftIn.push_back(in[i]);
//		 }
//		 else
//		 {
//			 RightPre.push_back(pre[i]);
//			 RightIn.push_back(in[i]);
//		 }
//	 }
//	 root->left = reConstructBinaryTree(LeftPre, LeftIn);
//	 root->right = reConstructBinaryTree(RightPre, RightIn);
//	 return root;
// }
//
//
//
////重建二叉树--版本2
//struct TreeNode* ConstructBTree(vector<int>::iterator PreBegin, \
//	vector<int>::iterator PreEnd, \
//	vector<int>::iterator InBegin, \
//	vector<int>::iterator InEnd)
//{
//	int rootval = PreBegin[0];
//	TreeNode* root = new TreeNode(rootval);
//
//	if (PreBegin == PreEnd)
//	{
//		if (InBegin == InEnd && *PreBegin == *InBegin)
//		{
//			return root;
//		}
//		else
//		{
//			return NULL;
//		}
//	}
//	//在中序遍历中寻找根节点的值
//	vector<int>::iterator PointIn = InBegin;
//	while (PointIn != InEnd && *PointIn != rootval)
//		++PointIn;
//
//	if (PointIn == InEnd&&*PointIn != rootval)
//		return NULL;
//
//	int gap = PointIn - InBegin;
//	vector<int>::iterator LeftPreEnd = PreBegin + gap;
//
//	if (gap > 0)
//	{
//		root->left = ConstructBTree(PreBegin,LeftPreEnd,InBegin,PointIn-1);
//	}
//	if (gap < PreBegin - PreEnd)
//	{
//		root->right= ConstructBTree(LeftPreEnd+1,PreEnd, PointIn+1,InEnd);
//	}
//	return root;
//}
//	
//struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in)
//{
//	if (pre.size() == 0 || in.size() == 0)
//		return NULL;
//	return ConstructBTree(pre.begin(), pre.end() - 1, in.begin(), in.end() - 1);
//}
//
//int main()
//{
//	vector<int> pre;
//	pre.push_back(1);
//	pre.push_back(2);
//	pre.push_back(4);
//	pre.push_back(7);
//	pre.push_back(3);
//	pre.push_back(5);
//	pre.push_back(6);
//	pre.push_back(8);
//
//	vector<int> in;
//	in.push_back(4);
//	in.push_back(7);
//	in.push_back(2);
//	in.push_back(1);
//	in.push_back(5);
//	in.push_back(3);
//	in.push_back(8);
//	in.push_back(6);
//
//	struct TreeNode*ret;
//	ret= reConstructBinaryTree(pre,in);
//	return 0;
//}

//面试题七：用两个栈来实现一个队列，完成队列的Push和Pop操作。
//队列中的元素为int类型。

//#include<iostream>
//#include<stack>
//using namespace std;
//
//class Solution
//{
//public:
//	void push(int node)
//	{
//		stack1.push(node);
//	}
//
//	int pop()
//	{
//		if (stack2.size() < 0)
//		{
//			while (!stack1.empty())
//			{
//				int node = stack1.top();
//				stack1.pop();
//				stack2.push(node);
//			}
//			if (stack2.size() == 0)
//			{
//				cout << "queue is empty" << endl;
//			}
//			int ret = stack2.top();
//			stack2.pop();
//			return ret;
//		}
//	}
//		
//private:
//	stack<int> stack1;
//	stack<int> stack2;
//};

//面试题9：斐波那契数列
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

//int rectCover(int number)
//{
//	int count = 0;
//
//	if (number == 0 || number == 1)
//		return 1;
//
//	int curr = 1;
//	int next = 1;
//
//	for (int i = 2;i <=number;++i)
//	{
//		count = curr + next;
//		curr = next;
//		next = count;
//	}
//
//	return count;
//}

//面试题10：二进制中1的个数
//int NumOf1(int num)
//{
//	int i = 0;
//	int j;
//	int count = 0;
//	while (i < 32)
//	{
//		j =1<< i;
//		if (j&num)
//		{
//			count++;
//		}
//		++i;
//	}
//	return count;
//}

//int BitCount(unsigned int n)
//{
//	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
//	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
//	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
//	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
//	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
//
//	return n;
//}


//面试题8：旋转数组的最小值

//顺序查找
int find(vector<int> arr, int left, int right)
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
int BinarySearchMin(vector<int> arr)
{

	int len = arr.size();
	int left = 0;
	int right = len - 1;
	int mid = left;
	while (left <= right)
	{
		//当只有两个数时，前面的那个数就是非递增数组的最大值，
		//后面的数就是旋转后的最小值。

		if (right - left == 1)
		{
			mid = right;
			break;
		}
		mid = left + (right - left) / 2;

		//特殊情况的处理
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
int main()
{
	vector<int> arr;
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
	arr.push_back(1);
	arr.push_back(2);
	/*int brr[] = { 1,1,1,0,1 };
	int crr[] = { 1,1,1,1,1,0 };
	int drr[] = { 1,1,1,1,1,1 };*/
	cout << BinarySearchMin(arr) << endl;
	/*cout << BinarySearchMin(brr) << endl;
	cout << BinarySearchMin(crr) << endl;
	cout << BinarySearchMin(drr) << endl;*/
	return 0;
}