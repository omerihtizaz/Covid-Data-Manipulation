#include<string.h>
#include<iostream>
using namespace std;
struct co_node
{
public:
	int year, month, date;
	string country, countryname, region;
	int death, c_death, daily_confirmed, cum_comfirmed;
	int weight;
	co_node* next; co_node* last;
	int active_cases;
	int total;
	co_node()
	{
		year = month = date = death = c_death = daily_confirmed = cum_comfirmed =weight = total = active_cases = 0;
		next = last = NULL;
	}
	void operator = (const co_node &D )
	{
		total = D.total;
		year = D.year;
		month = D.month;
		date = D.date;
		country = D.country;
		countryname = D.countryname;
		region = D.region;
		weight = D.weight;
		death = D.death;
		c_death= D.c_death;
		daily_confirmed = D.daily_confirmed;
		cum_comfirmed = D.cum_comfirmed;
		next = D.next;
		last = D.last;
		active_cases = D.active_cases;
	}
	void set_active(int i )
	{
		active_cases = i;
	}
	int get_active()
	{
		return active_cases;
	}
	int get_weight()
	{
		return weight;
	}
	void set_weight(int s)
	{
		weight = s;
	}
	int get_death()
	{
		return death;
	}
	int get_c_death()
	{
		return c_death;
	}
	int get_comfirmed()
	{
		return daily_confirmed;
	}
	int get_cum_confirmed()
	{
		return cum_comfirmed;
	}
	string get_country()
	{
		return country;
	}
	string get_country_name()
	{
		return countryname;
	}
	string get_region()
	{
		return region;
	}
	void set_country(string c)
	{
		country = c;
	}
	void set_country_name(string c)
	{
		countryname = c;
	}
	void set_region(string s)
	{
		region = s;
	}
	void set_death(int a)
	{
		death = a;
	}
	void set_c_death(int a)
	{
		c_death = a;
	}
	void set_confirmed(int a)
	{
		daily_confirmed = a;
	}
	string get_date()
	{
		return to_string(year)+"-"+to_string(month)+"-"+to_string(date);
	}
	void set_c_comfirned(int a)
	{
		cum_comfirmed = a;
	}
	void set_year(int a)
	{
		year = a;
	}
	void set_month(int a)
	{
		month = a;
	}
	void set_date(int a)
	{
		date = a;
	}
	void set_date_all(int a, int b, int c)
	{
		year = a; month = b; date = c;
	}
	co_node& get()
	{
		return *this;
	}
	
};
void swap(co_node* a, co_node* b)
{
	co_node t = *a;
	*a = *b;
	*b = t;
}

void display(co_node* c)
	{
		if(c == NULL)
		{
			cout<<"No city exists"<<endl;
			return;
		}
		cout<<"Date = "<<c->year<<"-"<<c->month<<"-"<<c->date<<endl;
		cout<<"Country = "<<c->get_country()<<endl;
		cout<<"Country Name = "<<c->get_country_name()<<endl;
		cout<<"Region = "<<c->get_region()<<endl;
		cout<<"daily_confirmed Deaths = "<<c->get_death()<<endl;
		cout<<"Comulative Deaths = "<<c->get_c_death()<<endl;
		cout<<"daily_confirmed Cases = "<<c->get_comfirmed()<<endl;
		cout<<"Commulative Cases = "<<c->cum_comfirmed<<endl;
		cout<<"weight = "<<c->weight<<endl;
		cout<<"total = "<<c->total<<endl;
		cout<<"Active cases = "<<c->active_cases<<endl;
	}