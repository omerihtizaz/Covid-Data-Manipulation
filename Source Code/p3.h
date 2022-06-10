#include<string.h>
#include<iostream>
using namespace std;

#include <stdlib.h>
#include <bits/stdc++.h> 
struct p3
{
	string start;
	string end;
	int val;
	int counter;
	int max;
	p3()
	{
		max = INT_MAX;
	}
	void operator = (const p3 &d )
	{
		max = d.max;
		start = d.start;
		end = d.end;
		counter = d.counter;
		val= d.val;
	}
	void clear()
	{
		start = "";
		end = "";
		val = counter = max = 0;
	}
};