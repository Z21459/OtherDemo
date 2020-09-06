#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <mutex>
#include <map>
using namespace std;

class Stock
{
public:
	Stock() {}
	~Stock()
	{

	}
};

class StockFactory
{
public:
	shared_ptr<Stock> get(const string &key);

private:
	mutable mutex _mutex;
	std::map<string, shared_ptr<Stock> >_stock;
};
