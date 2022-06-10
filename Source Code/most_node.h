#include<string.h>
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
class most_node
{
	public:
	string name;
	int most_death;
	int most_cum_cases;
	int all_cases;

	most_node()
	{
		all_cases = INT_MAX;
		most_death = -1;
		most_cum_cases = -1;
	}
	void set_name(string a)
	{
		name = a;
	}
	void set_all_cases(int a)
	{
		all_cases = a;
	}
	void set_val(int a, int b)
	{
		if(most_death<a)
		{
			most_death = a;
		}
		if(most_cum_cases<b)
		{
			most_cum_cases = b;
		}
	}
	
};
