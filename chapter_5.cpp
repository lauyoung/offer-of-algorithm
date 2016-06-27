#include<iostream>
#include<stack>
#include <vector>
#include <deque>
#include<assert.h>
#include <string.h>
using namespace std;


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
int main()
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