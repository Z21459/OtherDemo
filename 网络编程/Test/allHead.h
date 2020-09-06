#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <mutex>
#include <algorithm>

using namespace std;

#define IntVector vector<int>
#define StringVector vector<string>
#define IntList list<int>
#define StringList list<string>
#define IntIntMap map<int,int>
#define StringStringMap map<string,string>
#define StringIntMap map<string,int>
#define IntStringMap map<int,string>
#define IntSet set<int>
#define StringSet set<string>

//宏定义成函数 
#define FOR_EACH(T, T1, T2) \
	for(T::iterator T2 = T1.begin();T2 != T1.end();T2++)

//基础函数 命名空间

		
