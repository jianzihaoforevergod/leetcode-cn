﻿// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>

#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>
#include <sstream>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.Hi"
//#include "..\Common\TreeNode.Hi"
//#include "..\Common\ListNode.Hi"
using namespace std;


//////////////////////////////////////////////////////////////////////////
// 递归调用过程：查找当前 nums 数组中是否可以找到元素将背包填满（从后往前搜索）
// Param：start：起始搜索下标；curSum：当前的累加容量；C：背包容量
bool DFS(const vector<int>& nums, int start, int curSum, int C) 
{
	curSum += nums[start];
	if (curSum == C) return true;

	for (int i = start - 1; i >= 0; --i) 
	{
		if (curSum + nums[i] > C) continue;
		return DFS(nums, i, curSum, C);
	}
	return false;
}

bool canPartition(vector<int>& nums) 
{
	// 统计数组和
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
	}
	if (sum % 2 != 0) return false;

	// 如果排序后数组最后一个元素大于背包容量，此时无法分隔
	// 因为该元素无法放到两个子集中的任意一个
	sort(nums.begin(), nums.end());
	int C = sum / 2;
	if (nums.back() > C) return false;

	for (int i = nums.size() - 1; i >= 0; --i)
	{
		if (DFS(nums, i, 0, C)) return true;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////////
//bool canPartition(vector<int>& nums) 
//{
//	int sum = 0;
//	for (auto n : nums) 
//	{
//		sum += n;
//	}
//	if (sum % 2 != 0) return false;
//
//	int target = sum / 2;
//	vector<int> dp = vector<int>(target + 1, INT_MIN);
//	dp[0] = 0;
//	for (int i = 0; i < nums.size(); i++) 
//	{
//		int n = nums[i];
//		for (int j = target; j >= n; j--) 
//		{
//			dp[j] = max(dp[j], dp[j - n] + n); //使用了滚动数组
//			if (dp[j] < 0) 
//			{
//				dp[j] = INT_MIN;
//			}
//		}
//	}
//	return dp.back() == target;
//}



int main()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);

	auto f_time_cout = [&]()
	{
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << endl;
	};

	//////////////////////////////////////////////////////////////////////////
	vector<vector<int>> TESTS;
	//vector<int> K;
	vector<bool> ANSWERS;

	TESTS.push_back({ 21, 1, 1, 1 });
	ANSWERS.push_back(false);

	TESTS.push_back({ 1, 5, 11, 5 });
	ANSWERS.push_back(true);

	TESTS.push_back({ 1, 5, 10, 6 });
	ANSWERS.push_back(true);

	TESTS.push_back({ 3, 4, 5, 7, 11 });
	ANSWERS.push_back(true);
	 
	TESTS.push_back({ 3, 4, 5, 7, 13 });
	ANSWERS.push_back(true);

	TESTS.push_back({ 3, 4, 5, 12, 12 });
	ANSWERS.push_back(false);

	TESTS.push_back({ 1, 2, 3, 5 });
	ANSWERS.push_back(false);

	TESTS.push_back({ 3, 3, 3, 4, 5 });
	ANSWERS.push_back(true);

	TESTS.push_back({ 1, 2, 3, 5 });
	ANSWERS.push_back(false);

	TESTS.push_back({ 1, 2, 5 });
	ANSWERS.push_back(false);

	for (int i = 0; i < TESTS.size(); i++)
	{
		QueryPerformanceCounter(&nBeginTime);

		cout << endl << "/////////////////////////////" << endl;
		auto ans = canPartition(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;

		QueryPerformanceCounter(&nEndTime);
		f_time_cout();
	}
}


//////////////////////////////////////////////////////////////////////////
// TreeNode
//int main()
//{
//	vector<TreeNode *> N;
//	vector<int> K;
//	vector<bool> A;
//
//	N.push_back(StringToTreeNode("3,9,20,null,null,15,7"));
//	//K.push_back(3);
//	A.push_back(true);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,null,null,4,4"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	N.push_back(StringToTreeNode("1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5"));
//	//K.push_back(3);
//	A.push_back(false);
//
//	for (int i = 0; i < N.size(); i++)
//	{
//		cout << endl << "///////////////////////////////////////" << endl;
//		cout << N[i] << endl;
//		//DrawTreeNode(N[i]);
//
//		bool ans = isBalanced(N[i]);
//		cout << checkAnswer<bool>(ans, A[i]) << endl;
//		//DrawTreeNode(ans);
//
//	}
//}


//////////////////////////////////////////////////////////////////////////
// List Node
//int main()
//{
//	vector<ListNode *> lists;
//	ListNode *pHead = StringToListNode("[4,7,5,3]");
//	lists.push_back(pHead);
//	pHead = nullptr;
//
//	for (auto i : lists)
//	{
//		cout << i << endl;
//		pHead = sortList(i);
//		cout << pHead << endl;
//		cout << endl;
//	}
//}


