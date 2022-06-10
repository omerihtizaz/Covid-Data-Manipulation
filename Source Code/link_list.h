#include"p6.h"
#include"most_node.h"
#include"p3.h"
#include"co_node.h"
#include"alpha.h"
#include"funtions.h"
#include <stdlib.h>
#include <vector>
#include <set>
#include<iterator>
#include<algorithm>
#include<string.h>
#include<iostream>
#include <bits/stdc++.h> 
#define _tot_ 213
#define _max 97
using namespace std;
static fstream alpha__("result.txt");//to record the interface
template<class T>
void swap(T* a, T* b)
{
	T t = *a;
	*a = *b;
	*b = t;
}
struct p5
{
	int val;
	string date;
};
struct p4
{
	int i;
	p5* alpha;
};
int convert_string_to_int(string str)
{
	int i = 0;
	int result = 0;
	while(i<str.length())
	{
		result+= (int)str[i];
		i++;
	}
	return result;
}
co_node* n;
class link_list
{
private:
	co_node** head;
	int counter;
	int i;
	most_node* array_;
	p3* hp3;
	int p3_c;
	
	int get_city_date_index(string city_name, string date)
	{
		int i = binarySearch(0,212, city_name);
		if(i == -1)
			cout<<"No"<<endl;
		co_node* temp = head[i];
		int j = 0;
		while(temp)
		{
			if(temp->get_date() == date)
			{
				return j;
			}
			j++;
			temp = temp->next;
		}
		return -1;

	}
	bool is_empty()
	{
		if(head[0] == NULL)
			return true;
		return false;
	}
	co_node* get_node_city(string city_name, int &j)
	{
		j = binarySearch(0, 212, city_name);
		if(j == -1)
		{
			return NULL;
		}
		else return head[j];
	}
	co_node* get_c_d(co_node*temp, string date)
	{
		while(temp)
		{
			if(temp->get_date() == date)
			{
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}
	co_node* get_node_city_date(string city_name, string date)
	{
		int i;
		co_node* temp =get_node_city(city_name, i);
		return get_c_d(temp, date);
	}
	most_node* get_name_most(string a)
	{
		
		int i = 0;
		while(array_[i].name!=a)
		{
			i++;
		}
		return &array_[i];

	}
	void pigeonholeSort_b(most_node arr[], int n) 
	{ 
		int min = arr[0].all_cases, max = arr[0].all_cases; 
		for (int i = 1; i < n; i++) 
		{ 
			if (arr[i].all_cases < min) 
				min = arr[i].all_cases; 
			if (arr[i].all_cases > max) 
				max = arr[i].all_cases; 
		} 
		int range = max - min + 1;
		vector<most_node> holes[range]; 
		for (int i = 0; i < n; i++) 
			holes[arr[i].all_cases-min].push_back(arr[i]); 
		int index = 0;  
		for (int i = 0; i < range; i++) 
		{ 
		vector<most_node>::iterator it; 
		for (it = holes[i].begin(); it != holes[i].end(); ++it) 
				arr[index++]  = *it; 
		} 
	} 
	p3& return_which(int nun)
	{
		return hp3[nun];
	}
	void pigeonholeSort_a(alpha arr[], int n) 
	{ 
		int min = arr[0].val, max = arr[0].val; 
		for (int i = 1; i < n; i++) 
		{ 
			if (arr[i].val < min) 
				min = arr[i].val; 
			if (arr[i].val > max) 
				max = arr[i].val; 
		} 
		int range = max - min + 1;
		vector<alpha> holes[range]; 
		for (int i = 0; i < n; i++) 
			holes[arr[i].val-min].push_back(arr[i]); 
		int index = 0;  
		for (int i = 0; i < range; i++) 
		{ 
		vector<alpha>::iterator it; 
		for (it = holes[i].begin(); it != holes[i].end(); ++it) 
				arr[index++]  = *it; 
		} 
	} 
	void heapify(p6 arr[], int n, int i) 
	{ 
		int largest = i; 
		int l = 2*i + 1; 
		int r = 2*i + 2; 
	
		if (l < n && arr[l].val > arr[largest].val) 
			largest = l; 
		if (r < n && arr[r].val > arr[largest].val) 
			largest = r; 
		if (largest != i) 
		{ 
			swap(arr[i], arr[largest]); 
			heapify(arr, n, largest); 
		} 
	} 
	void heapSort(p6 arr[], int n) 
	{ 
		for (int i = n / 2 - 1; i >= 0; i--) 
			heapify(arr, n, i); 
		for (int i=n-1; i>0; i--) 
		{ 
			swap(arr[0], arr[i]); 
			heapify(arr, i, 0); 
		} 
	}
	void display_total()
	{
		int i = 0;
		while(i<_tot_)
		{
			cout<<head[i]->countryname << "   "<<head[i]->total<<endl;
			i++;
		}
	}
	void Display()
	{
		co_node *temp;
		for (int i = 0; i < 213; i++)
		{
			temp = head[i];
			while(temp)
			{
				display(temp);
				temp= temp->next;
			}
		}
	}
	void add_p3(p3 node)
	{
		hp3[p3_c] = node;
		//d(hp3[p3_c]);
		p3_c++;
	}
	void d(p3 node)
	{
		cout<<"Starts on: "<<node.start<<endl;
		cout<<"Counter: "<<node.counter<<endl;
		cout<<"Value: "<<node.val<<endl;
		cout<<"Ends on: "<<node.end<<endl;
	}
	void display_p3()
	{
		int al = 0;
		while(al<p3_c)
		{
			d(hp3[al]);
			al++;
		}
	}
	int GetCeilIndex(p5 arr[], vector<int>& T, int l, int r,  int key) 
	{ 
		while (r - l > 1) { 
			int m = l + (r - l) / 2; 
			if (arr[T[m]].val >= key) 
				r = m; 
			else
				l = m; 
		} 
	
		return r; 
	} 
	double return_val(co_node* temp, char c, bool option)
	{
		if(c == 'c')
		{
				p4 mn = get_c(temp, 3);
				int n = mn.i;
				vector<int> tailIndices(n, 0); 
				vector<int> prevIndices(n, -1);
				int len = 1; 
				for (int i = 1; i < n; i++) { 
					if (mn.alpha[i].val < mn.alpha[tailIndices[0]].val) { 
						tailIndices[0] = i; 
					} 
					else if (mn.alpha[i].val > mn.alpha[tailIndices[len - 1]].val) { 
						prevIndices[i] = tailIndices[len - 1]; 
						tailIndices[len++] = i; 
					} 
					else { 
						int pos = GetCeilIndex(mn.alpha, tailIndices, -1, 
											len - 1, mn.alpha[i].val); 
			
						prevIndices[i] = tailIndices[pos - 1]; 
						tailIndices[pos] = i; 
					} 
				} 
				
				cout << "For the country the longest increase of spread of COVID is as follows: " << endl; 
				if (len>10)
				len-=4;
				for (int i = tailIndices[len - 1]; i >= 0; i = prevIndices[i]) 
				{
					if(option)
					{
						alpha__ << mn.alpha[i].val << " "<<mn.alpha[i].date<<endl; 
					}
					cout << mn.alpha[i].val << " "<<mn.alpha[i].date<<endl; 
				}
				
				cout << endl; 
			if(option)
			{
				alpha__<<"The length over the spread of days continued for: ";
				alpha__<< len<<endl;		
			}
				cout<<"The length over the spread of days continued for: ";
				cout<< len<<endl;			
		}
		else
		{
				p4 mn = get_c(temp, 4);
				int n = mn.i;
				vector<p5> LDS[n];
				LDS[0].push_back(mn.alpha[0]);
				for (int i = 1; i < n; i++)
				{
					for (int j = 0; j < i; j++)
					{
						if (mn.alpha[j].val > mn.alpha[i].val && LDS[j].size() > LDS[i].size())
							LDS[i] = LDS[j];
					}
					LDS[i].push_back(mn.alpha[i]);
				}
				int j = 0;
				for (int i = 0; i < n; i++)
					if (LDS[j].size() < LDS[i].size())
						j = i;
					int k = 0;
				p5 l;
				if(option)
				{
					alpha__<<"The Longest daily death tally decrease for the mentioned country is as follows: "<<endl;
				}
				cout<<"The Longest daily death tally decrease for the mentioned country is as follows: "<<endl;
				for (p5 i : LDS[j])
				{
					if(k == 0)
					{
						if(option)
						{
							alpha__ <<"Starting date=  "<<i.date<<endl;
							alpha__ << i.val <<endl;
						}
						cout <<"Starting date=  "<<i.date<<endl;
						cout << i.val <<endl;
					}
					else
					{
						if(option)
						{
							alpha__ << i.val <<endl;
						}
						cout << i.val <<endl;
					}
					l = i;
					k++;
				}
				if(option)
				{
					alpha__<<"Ending date for the death tally decrease is: "<<l.date<<endl;
					alpha__<<"Length over the decearse is: "<<k<<endl;
				}
				cout<<"Ending date for the death tally decrease is: "<<l.date<<endl;
				cout<<"Length over the decearse is: "<<k<<endl;
		}
		
		 
	}	
	string get_ni(int i)
	{
		return head[i]->countryname;
	}
	void find_sequence(string s, string e, string name)
	{
		int val=0;
		int i =0;
		co_node *temp = get_node_city_date(name, s);
		if(temp == NULL)
		{
			get_name_most(name)->set_all_cases(val);
		}
		else
		{
			while(temp->get_date()!=e)
			{
				val+=temp->daily_confirmed;
				temp = temp->next;
				i++;
			}
			val+=temp->daily_confirmed;
			get_name_most(name)->set_all_cases(val);
		}
	}
	p4& get_c(co_node *temp, int part)
	{
		
		p4* node = new p4;
		int i= 0;
		if(part == 4)
		{
			node->alpha = new p5[temp->total];
			while(temp)
			{
				node->alpha[i].val = temp->death;
				node->alpha[i].date = temp->get_date();
				temp = temp->next;
				i++;
			}
			node->i = i;
			return *node;	
		}
		else if(part == 6 || part == 3)
		{
			node->alpha = new p5[temp->total];
			while(temp)
			{
				node->alpha[i].val = temp->daily_confirmed;
				node->alpha[i].date = temp->get_date();
				temp = temp->next;
				i++;
			}
			node->i = i;
			return *node;
		}
	}
	void get_d_i(string name, int i)
	{
		int k= 0;
		co_node* temp = get_node_city(name,k);
		while(temp)
		{
			if(temp->daily_confirmed == i)
			{
				cout<<temp->get_date();
			}
			temp = temp->next;
		}
	}
	void LCS(p5 A[], p5 B[], int n, int m, int k, string c1, string c2, bool option) 
	{ 
		
		bool f = false;
		string n1, n2, m1, m2;
		int dp[n + 1][m + 1]; 
		for(int i = 0; i <= n ;i++) 
			for(int j = 0; j <= m ;j++) 
				dp[i][j] = 0; 
		int prev_i , prev_j;
		for (int i = n - 1 ; i >= 0; i--) 
		{ 
			for (int j = m - 1 ; j >= 0; j--) 
			{ 
				int a = A[i].val - B[j].val;
				if(a<0)
					a = a * (-1);
				if (a<k) 
				{
					
					dp[i][j] = dp[i + 1][j + 1] + 1; 
					if(!f)
					{
					n1 = A[i].date;
					m1 = B[j].date;
						f = true;
					}
					prev_i = i;
					prev_j = j;
				}
			} 
		} 
		
		
		int maxm = 0; 
		
		for( int c = 0 ; c < n ;c ++) 
		{ 
			for(int d = 0; d < m; d++) 
			{ 
				maxm = max(maxm, dp[c][d]); 
			
			} 
		} 
		if(option)
		{
		alpha__<<"Similarity ("<<c1<<","<<c2<<") = " <<maxm;
		alpha__<<endl<<"("<<c1<<"["<<get_city_date_index(c1, A[prev_i].date)<<":"<<get_city_date_index(c1,n1)<<"] = "<<c2<<"["<<get_city_date_index(c2, B[prev_j].date)<<":"<<get_city_date_index(c2, m1)<<"])"<<endl;			
		}
		cout<<"Similarity ("<<c1<<","<<c2<<") = " <<maxm;
		cout<<endl<<"("<<c1<<"["<<get_city_date_index(c1, A[prev_i].date)<<":"<<get_city_date_index(c1,n1)<<"] = "<<c2<<"["<<get_city_date_index(c2, B[prev_j].date)<<":"<<get_city_date_index(c2, m1)<<"])"<<endl;
		
	} 
	void return_value(int k, bool option)
	{
		p6 a[_tot_];
		int i = 0;
		while(i<_tot_)
		{
			a[i].name = head[i]->countryname; 
			if(head[i]->countryname == "undefined")
			{
				a[i].amount = INT_MAX;
				a[i].val =-1;
			}
			else
			{
				a[i].val = head[i]->last->active_cases;
				a[i].amount = head[i]->weight;
			}
			i++;
		}
		heapSort(a,213);
		int amount = 0, counter = 0;
		if(option)
		{
			alpha__<<"The countries which can be facilitated with aid under the given amount i.e, "<<k<<endl;
		}
		cout<<"The countries which can be facilitated with aid under the given amount i.e, "<<k<<endl;
		while(i>=0)
		{
			amount+= a[i].amount;
			if(amount<=k)
			{
				if(a[i].name !="undefined")
				{
					counter++;
					if(option)
					{
						alpha__<<counter<<") "<<a[i].name<<" "<<a[i].amount<<"."<<endl;
					}
					cout<<counter<<") "<<a[i].name<<" "<<a[i].amount<<"."<<endl;
				}
			}
			else
			{
				amount-=a[i].amount;
			}
			
			i--;
		}
		if(option)
		{
			alpha__<<"Total countries are: "<<counter<<endl;
		}
		cout<<"Total countries are: "<<counter<<endl;
	}
public:
	string* search(string result[],string str, int &n)
	{
		co_node* temp;
		int i = 0, j = 0, counter_n = 0,count_y = 0, k = 0;
		int result_i = 0;
		while(i<_tot_)
		{
			temp = head[i];
			while(j<temp->countryname.length()|| j>k||k>j)
			{
				if(str[k] != temp->countryname[j])
				{
					counter_n++;
				}
				k++,j++;
			}
			if(counter_n>2)
			{
				if (temp->countryname.find(str) !=string::npos)
				{
					result[result_i] = temp->countryname;
					result_i++;
					n++;
				}
				else if(count_y >3 )
				{
					result[result_i] = temp->countryname;
					result_i++;
					n++;
				}
			}
			else if(counter_n<3)
			{
				
				result[result_i] = temp->countryname;
				result_i++;
				n++;
			}
			counter_n = 0, j = 0, k = 0;
			i++;
		}
	}
	int binarySearch(int l, int r, string x) 
	{ 
		if (r >= l) { 
			int mid = l + (r - l) / 2; 
			if (head[mid]->get().countryname == x) 
				return mid; 
			if (head[mid]->get().countryname > x) 
				return binarySearch( l, mid - 1, x); 
			return binarySearch( mid + 1, r, x); 
		} 
		return -1; 
	}
	link_list()
	{
		array_ = new most_node[_tot_];
		i = 0;
		p3_c = 0;
		counter = 0;
		head = new co_node* [_tot_];
		hp3 = new p3[_max];
		
	}
	void part_a(string date, bool option)
	{
		clock_t start, end; 
		start = clock(); 
		alpha ap[_tot_];
		int b = 0;
		co_node* temp;
		while(b<_tot_)
		{
			temp = get_node_city_date(head[b]->countryname, date);
			if(!temp)
			{
				ap[b].val = 0;
			}
			else
			{
				ap[b].val = temp->daily_confirmed;
			}
			ap[b].name = head[b]->countryname;
			b++;
		}
		pigeonholeSort_a(ap,_tot_);
		int i =_tot_-1;
		while(i>=_tot_-20)
		{
			if(option)
				alpha__<<"For date: "<<date<<endl<<ap[i].name<<" = "<<ap[i].val<<endl;
			cout<<ap[i].name<<" = "<<ap[i].val<<endl;
			i--;
		}
		end = clock();
		 double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
		 if(option)
		 {
			 alpha__ << "Time taken by part(a) is : " << fixed  
				<< time_taken << setprecision(5); 
			alpha__ << " sec " << endl; 
		 }
		cout << "Time taken by part(a) is : " << fixed  
			<< time_taken << setprecision(5); 
		cout << " sec " << endl; 
	}
	void part_b(string s, string e, bool option)
	{
		clock_t start, end; 
		start = clock(); 
		for (int i = 0; i< _tot_; i++)
		{
			find_sequence(s,e,head[i]->get().countryname);
		}
		pigeonholeSort_b(array_,_tot_);
		end = clock();
		int val = array_[_tot_-1].all_cases;
		int i = _tot_-1;
		while(val==array_[i].all_cases)
		{
			if(option)
			{
				alpha__<<"For Start date: "<<s<<"\t End Date"<<e<<endl<<array_[i].name<<" = "<<array_[i].all_cases<<endl;
			}
			cout<<array_[i].name<<" "<<array_[i].all_cases<<endl;
			i--;
		}
		
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
		if(option)
		{
				alpha__ << "Time taken by part B is : " << fixed  
				<< time_taken << setprecision(5); 
			alpha__ << " sec " << endl;
		}
			cout << "Time taken by part B is : " << fixed  
				<< time_taken << setprecision(5); 
			cout << " sec " << endl;
	}
	void part_c_d(string n, char part, bool option)
	{
		clock_t start, end; 
		start = clock(); 
		int k;
		co_node* temp = get_node_city(n,k);
		if(option)
		{
			alpha__<<"Country: "<<temp->countryname<<endl;
		}
		cout<<"Country: "<<temp->countryname<<endl;
	
		return_val(temp, part, option);
		end = clock();
		
		double time_taken = (double(end - start) / double(CLOCKS_PER_SEC));
		if(option)
		{
			if(part == 'c')
			{
				alpha__ << "Time taken by part_c is : " << fixed
				<< time_taken << setprecision(5); 
					alpha__ << " secs " << endl;
			}
			else alpha__ << "Time taken by part_d is : " << fixed 
					<< time_taken << setprecision(5); 
					alpha__ << " secs " << endl;
		} 
		if(part == 'c')
		{
				alpha__ << "Time taken by part_c is : " << fixed
				<< time_taken << setprecision(5); 
					alpha__ << " secs " << endl;
		}
		else cout << "Time taken by part_d is : " << fixed 
			<< time_taken << setprecision(5); 
		cout << " secs " << endl;
	}
	void part_f(string m, string n, int k, bool option)
	{
		clock_t start, end; 
		start = clock(); 
		int i=0;
		p4 node = get_c(get_node_city(m, i), 6);
		i=0;
		p4 node1 = get_c(get_node_city(n, i),6);
		
  	 	LCS(node.alpha,node1.alpha, node.i, node1.i, k, m, n, option);
	   end = clock();
		double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)); 
		if(option)
		{
			alpha__ << "Time taken by part_f is : " << fixed  
			<< time_taken << setprecision(5); 
		alpha__ << " secs " << endl;
		}
			cout << "Time taken by part_f is : " << fixed  
			<< time_taken << setprecision(5); 
		cout << " secs " << endl;
	
	}
	void join_node(co_node &c, string &current, string &now)
	{
		if(is_empty())
		{
			head[counter] = new co_node;
			head[counter]->get() = c;
			head[counter]->get().next = NULL;
			head[counter]->get().total+=1;
			n = head[counter];
		}
		else if(current==now)
		{
			co_node* temp = head[counter];
		
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = new co_node;
			temp->next->get() = c;
			temp->next->next = NULL;
			temp = temp->next;
			n = temp;
			head[counter]->get().total+=1;
		}
		else if(current!=now)
		{
			head[counter]->last = n;
			counter++;

			head[counter] = new co_node;
			co_node* temp = head[counter];
			temp->get() = c;
			temp->next = NULL;
			temp = temp->next;
			current = now;
			head[counter]->get().total+=1;
		}
		head[counter]->last = n;
		array_[counter].set_name(c.countryname);
		array_[counter].set_val(c.c_death, c.cum_comfirmed);
		i++;
	}
	co_node* get_head(int i)
	{
		return head[i];
	}
	co_node* get_no_ci(string city_name, int &j)
	{
		for (int i = 0 ; i<_tot_; i++)
		{
			if(head[i]->get().countryname == city_name)
			{
				
				return &head[i]->get();
			}
		}
		return NULL;
	}
	void part_e(int value, bool option)
	{
		clock_t start, end; 
		start = clock(); 
		return_value(value, option);
		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
		if(option)
		 {
			 alpha__ << "Time taken by part(e) is : " << fixed  
				<< time_taken << setprecision(5); 
			alpha__ << " sec " << endl; 
		 }
		cout << "Time taken by part(e) is : " << fixed  
			<< time_taken << setprecision(5); 
		cout << " sec " << endl; 
	}
};
link_list all;
void file_reading()
	{
		int counter = 0, tell;
		clock_t start, end; 
		start = clock(); 
		fstream obj("WHO-COVID-19.csv");
		if(!obj.is_open())
		{
			cout<<"File not opened.\n Terminating program."<<endl;
			return;
		}
		string str;
		char check;
		getline(obj, str);
		int i =0;
		string current;
		string now = "-";
		while(obj)
		{
			if(i == 9042)
				break;
			co_node node;
			getline(obj, str, '-');
			node.set_year(stoi(str));
			getline(obj, str, '-');
			node.set_month(stoi(str));
			getline(obj, str, ',');
			node.set_date(stoi(str));
			getline(obj, str, ',');
			node.set_country(str);
			obj>>check;
			if(check -0  == 34)
			{
				getline(obj, str, '"');
				if(i==0)
				{
					current = str;
				}
				else 
				{
					now = str;
				}
				node.set_country_name(str);
				obj>>check;
			}
			else
			{
				tell = obj.tellp();
				obj.seekp(tell-1);
				getline(obj, str, ',');
				if(i==0)
				{
					current = str;
				}
				else 
				{
					now = str;
				}
				node.set_country_name(str);	
			}
			
			getline(obj, str, ',');
			node.set_region(str);
			getline(obj, str, ',');
			node.set_death(stoi(str));
			getline(obj, str, ',');
			int c_death = stoi(str);
			node.set_c_death(c_death);
			getline(obj, str, ',');
			node.set_confirmed(stoi(str));
			getline(obj, str);
			int c_comfirmed = stoi(str);
			node.cum_comfirmed = c_comfirmed;
			node.set_active(c_comfirmed - c_death);
			node.next = NULL;
			all.join_node(node, current, now);
			i++;
			str.clear();
		}		
		obj.close();
		obj.clear();
		obj.open("CountryWeight.csv");
		getline(obj, str);
		string str1;
		string c;
		int it= 0;
		while(obj)
		{
			obj>>check;
			if(check -0 == 34)
			{
				getline(obj, str, '"');
				
				obj>>check;
			}
			else
			{
				tell = obj.tellp();
				obj.seekp(tell-1);
				getline(obj, str, ',');
				
			}
			if(c == str)
			{
				break;
			}
			getline(obj, str1);
			if(all.get_head(it)->countryname == str)
			{
				all.get_head(it)->weight = stoi(str1);
				i++;
			}
			else
			{
				all.get_no_ci(str, i)->weight = stoi(str1);
			}
			c = str;
		}
		end = clock();
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
		cout << "Time taken by fileading is : " << fixed  
			<< time_taken << setprecision(5); 
		cout << " sec " << endl; 
	}