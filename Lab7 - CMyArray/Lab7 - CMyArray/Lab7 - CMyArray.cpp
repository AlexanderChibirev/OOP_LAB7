// Lab7 - CMyArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyArray.h"
#include <array>
#include <vector>
using namespace std;

int main(void)
{
	//CMyArray<int> array = {20,1,2,4};
	//array.Resize(12);
	//vector<int> d = { 20,1,2,4,5 };
	//d.resize(0);
	//array.Resize(1);
	//array.Clear();
	//auto x = array[0];
	//d.clear();
	//auto xd = d[0];
//	CMyArray<string> array = { "dsad" };
	//array.Add("asdasd");
	//array.Add("asdasd");
//	array.Add("asdasd");
	CMyArray<int> array /*= { 20 }*/;
	array.Add(34);
	array.Add(14);
	auto xd = array[0];
	xd = array[1];
	//array.Add(24);
	//array.Add(234);
	//array.Add(1234);
	// = array[3];
	return 0;
}