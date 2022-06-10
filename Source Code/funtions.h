#include<string.h>
#include<iostream>
using namespace std;


int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return -1; 
} 
void c_out_pdf()
{
	fstream obj("a.txt");
	string str;
	int i = 0;
	while(obj)
	{
		i++;
		getline(obj, str);
		cout<<str<<endl;
	}
	if(i == 0)
	cout<<"Please place Project.pdf in the same directory"<<endl;
}
void swap(int *a, int *b)
{
	int t = *a;
		*a = *b;
		*b = t;
}
int ym = 2020;
int mm = 1;
int mmax = 4;
int daym = 8;
int daymax = 16;
int gy(string str)
	{
		int num= 0;
		int i = 0;
		while(i<4)
		{
			num*= 10;
			num+=(str[i]-48);
			i++;
		}
		return num;
		
	}
int gm(string str, int &i)
	{
		int num = 0;
		while(str[i]!='-')
		{
			num*= 10;
			num+=(str[i]-48);
			i++;
		}
		i++;
		return num;
		
	}
int gd(string str, int i)
	{
		int num = 0;
		while(str[i]!='\0')
		{
			num*= 10;
			num+=(str[i]-48);
			i++;
		}
		return num;
	}
bool check_m(string a)
{
	int i = 5;
	int year = gy(a);
	int month = gm(a, i);
	int day = gm(a, i); 
	if(year= ym)
	{
		if(month >= mm)
		{
			if(day >= daym)
			return true;
		}
	}
	return false;
}
bool check_max(string a)
{
	int i = 5;
	int year = gy(a);
	int month = gm(a, i);
	int day = gm(a, i); 
	
	if(year= ym)
	{
		if(month <= mmax)
		{
			if(day <= daymax)
			return true;
		}
	}
	return false;
}
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value%213;
}
	int convert_year(int year)
	{
		return (int)year*365;
	}
	long convert_month(int month)
	{
		if(month == 1||month == 3||month == 5||month == 7||month == 8|| month == 10 || month == 12)
		return (long)month *31;
		else if(month == 2)
		return (long)month *29;
		else return (long)month*30;

	}
	
	int substract(string d1, string d2)
	{
		if(d1 == d2)
		return 0;
		int i=5;
		int v1 = convert_year(gy(d1)) + convert_month(gm(d1,i))+ gd(d1, i);
		i = 5;
		int v2 = (convert_year(gy(d2)) + convert_month(gm(d2,i))+ gd(d2, i));
		return v1 - v2;
			
	}

