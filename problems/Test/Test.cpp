﻿// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <functional>

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
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.Hi"
using namespace std;

//////////////////////////////////////////////////////////////////////////
//int lengthOfLastWord(string s)
//{
//	reverse(s.begin(), s.end());
//	istringstream ss(s);
//	string word;
//	while (ss >> word)
//	{
//		return word.size();
//	}
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////
int lengthOfLastWord(string s)
{
	while (s.back() == ' ')
	{
		s.pop_back();
	}
	for (size_t i = s.size() - 1; i < s.size(); i--)
	{
		if (s[i] == ' ')
		{
			return s.size() - i - 1;
		}
	}
	return s.size();
}

//template<typename... Args>
//auto FunForward(Args... args)
//{
//	return calculate(args...);
//}


int main()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);

	auto f_time_begin = [&time, &nFreq, &nBeginTime, &nEndTime]()
	{
		cout << endl << "/////////////////////////////" << endl;
		QueryPerformanceCounter(&nBeginTime);
	};

	auto f_time_end = [&time, &nFreq, &nBeginTime, &nEndTime]()
	{
		QueryPerformanceCounter(&nEndTime);
		time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
		cout << "////////////////////////////////////////////////////////// time: " << time * 1000 << "ms" << endl;
	};

	//////////////////////////////////////////////////////////////////////////
	vector<string> TESTS;
	//vector<int> K;
	vector<int> ANSWERS;

	TESTS.push_back("Hello World");
	ANSWERS.push_back(5);

	TESTS.push_back("World");
	ANSWERS.push_back(5);

	TESTS.push_back("a ");
	ANSWERS.push_back(1);

	TESTS.push_back(" a");
	ANSWERS.push_back(1);

	for (int i = 0; i < TESTS.size(); i++)
	{
		f_time_begin();

		auto ans = lengthOfLastWord(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
		//sortArray(TESTS[i]);
		//cout << checkAnswer<vector<int>>(TESTS[i], ANSWERS[i]) << endl;

		f_time_end();
	}
}


//////////////////////////////////////////////////////////////////////////
// TreeNode
//	vector<TreeNode *> N;
//	N.push_back(StringToTreeNode("3,9,20,null,null,15,7"));


//////////////////////////////////////////////////////////////////////////
// List Node
//	ListNode *pHead = StringToListNode("[4,7,5,3]");


