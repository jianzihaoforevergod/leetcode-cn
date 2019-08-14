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
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;


//////////////////////////////////////////////////////////////////////////
string frequencySort(string s) 
{
	auto f_cmp = [](const pair<char, int> &a, const pair<char, int> &b){ return a.second > b.second; };
	auto f_sort = [f_cmp](map<char, int> &_m, vector<pair<char, int>> &_v)
	{
		for (auto i : _m) _v.push_back(i);
		sort(_v.begin(), _v.end(), f_cmp);
	};

	map<char, int> m;
	for (auto &c : s)m[c]++;
	vector<pair<char, int>> v;
	f_sort(m, v);
	string res;
	for (auto p : v) for (int i = 0; i < p.second; i++) res += p.first;
	return res;
}


int main()
{
	vector<string> TESTS;
	//vector<int> K;
	vector<string> ANSWERS;

	TESTS.push_back("tree");
	ANSWERS.push_back("eert");

	TESTS.push_back("cccaaa");
	ANSWERS.push_back("aaaccc");

	TESTS.push_back("Aabb");
	ANSWERS.push_back("bbAa");


	for (int i = 0; i < TESTS.size(); i++)
	{
		cout << endl << "/////////////////////////////" << endl;
		auto ans = frequencySort(TESTS[i]);
		cout << checkAnswer<decltype(ans)>(ans, ANSWERS[i]) << endl;
	}
}



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



//int main()
//{
//	vector<ListNode *> lists;
//	ListNode *pHead = nullptr;
//	StringToListNode(&pHead, "[4,7,5,3]");
//	lists.push_back(pHead);
//	pHead = nullptr;
//
//	for (auto p : lists)
//	{
//		PrintLinkList(p);
//		pHead = sortList(p);
//		PrintLinkList(pHead);
//		cout << endl;
//	}
//}


