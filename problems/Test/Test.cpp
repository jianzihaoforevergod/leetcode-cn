﻿// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;


//int lowerBound(vector<int> &nums, int num, int low, int high)
//{
//	if (low >= high) return low;
//	int mid = low + (high - low) / 2;
//	if (nums[mid] < num) return lowerBound(nums, num, mid + 1, high);
//	else return lowerBound(nums, num, low, mid);
//}

//int lowerBound(vector<int> &nums, int num, int low, int high)
//{
//	while (low < high)
//	{
//		int mid = low + (high - low) / 2;
//		if (nums[mid] < num) low = mid + 1;
//		else high = mid;
//	}
//	return low;
//}


int findMin(vector<int>& nums)
{
	int low = 0;
	int high = nums.size() - 1;
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] == nums[high]) high--;
		else if (nums[mid] > nums[high]) low = mid + 1;
		//else if (nums[mid] < nums[0]) high = mid;
		else high = mid;
	}
	return (low < nums.size()) ? nums[low] : nums[0];
}

int main()
{
	vector<string> str;
	str.push_back("[2,2,2,0,1]");
	str.push_back("[3,1,3,3]");
	str.push_back("[4,5,0,1,2]");
	str.push_back("[2,3,1]");
	str.push_back("[2,1]");
	str.push_back("[1,2]");
	str.push_back("[1]");

	for (auto s : str)
	{
		cout << endl << "/////////////////////////////" << endl;
		vector<int> nums = StringToVectorInt(s);
		printVectorInt(nums);
		cout << "Find Min = " << findMin(nums) << endl;
	}
}
