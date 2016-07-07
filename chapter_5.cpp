#include<iostream>
#include<stack>
#include <vector>
#include <deque>
#include<assert.h>
#include <string.h>
using namespace std;

//面试题29：数组中出现超过一半的数
bool IsArrayInvalid = true;
bool IsMoreThanHalf = true;

bool CheckArrayInvalid(int *arr, int length)
{
	if (arr == NULL || length <= 0)
		IsArrayInvalid = false;

	return IsArrayInvalid;
}
bool CheckMoreThanHalf(int *arr, int length, int num)
{
	int count = 0;
	for (int i = 0;i < length;++i)
	{
		if (arr[i] == num)
			count++;
	}

	if (count*2 <=length)
	{
		IsMoreThanHalf = false;
	}
	return IsMoreThanHalf;
}
int MoreThanHalfNum(int *arr, int length)
{
	if (!CheckArrayInvalid(arr,length))
		return -1;

	int result = arr[0];
	int times = 1;
	for (int i = 0;i < length;++i)
	{
		if (times == 0)
		{
			result = arr[i];
			times = 1;
		}
		else if (result == arr[i])
			times++;
		else
			times--;
	}

	if (!CheckMoreThanHalf(arr,length,result))
	{
		result = -1;
	}
	return result;
}
int test()
{
	int arr[] = {1,2,3,2,2,2,5,4,2};
	int ret = MoreThanHalfNum(arr, 9);
	if (ret == -1 && !IsMoreThanHalf)
	{
		cout << "not exist" << endl;
	}
	cout << ret<< endl;
	return 0;
}

//面试题30:最小的K个数,时间复杂度是O(N)
int Partition(int *arr, int len, int start, int end)
{
	if (arr == NULL || len <= 0 || start < 0 || end > len)
		return -1;

	int small = start-1;
	for (int index = start;index < end;++index)
	{
		if (arr[index]<arr[end])
		{
			++small;
			if (small != index)
				swap(arr[index], arr[small]);
		}
	}
	++small;
	swap(arr[small], arr[end]);

	return small;
}
void GetKLessNum(int *arr, int len, int *output, int k)
{
	if (arr == NULL || len <= 0 || k <= 0 || k > len)
		return;

	int start = 0;
	int end = len - 1;
	int index = Partition(arr, len, start, end);
	while (index != k - 1)
	{
		if (index <k - 1)
		{
			start = index + 1;
			index = Partition(arr, len, start, end);
		}
		else if (index >k - 1)
		{
			end = index - 1;
			index = Partition(arr, len, start, end);
		}
	}
	for (int i = 0;i < k;++i)
	{
		output[i] = arr[i];
	}
}

//扩展题：求一个数组的中位
int GetMiddlerNum(int *arr, int len)
{
	int k = len / 2 - 1;
	if (len % 2 == 1)
		k = len / 2;

	if (arr == NULL || len <= 0 || k <= 0 || k > len)
		return -1;

	int start = 0;
	int end = len - 1;
	int index = Partition(arr, len, start, end);
	while (index != k)
	{
		if (index <k)
		{
			start = index + 1;
			index = Partition(arr, len, start, end);
		}
		else if (index >k)
		{
			end = index - 1;
			index = Partition(arr, len, start, end);
		}
	}
	return arr[k];
}
void test18()
{
	int arr[] = { 3,2,5,1,6,4,8,9,7,0,1,1,1,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	

	cout << GetMiddlerNum(arr, len)<< endl;
	for (int i = 0;i < len;++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test19()
{
	int arr[] = { 0,2,5,1,6,4,8,9,7,3 };
	int brr[10];
	GetKLessNum(arr, 10, brr, 4);
	//cout << Partition(arr, 10, 0, 9) << endl;
	for (int i = 0;i < 10;++i)
	{
		//cout << arr[i] << " ";
		cout << brr[i] << " ";
	}
	cout << endl;
}
void main()
{
	test19();
}