#include<iostream>
#include<string.h>
#include<fstream>
#include"link_list.h"
#include <stdio.h>  
using namespace std;
#define screen_clear cout << "\033[2J\033[1;1H";
void options(bool option)
{
	if(option)
	{
		alpha__<<"On a given day, to find the top 20 countries with the most confirmed cases please enter 1"<<endl;
		alpha__<<"To find the country(s) with the highest new cases between two given dates please enter 2"<<endl;
		alpha__<<"To find the starting and ending days of the longest spread period for a given country please enter 3"<<endl;
		alpha__<<"To find the longest daily death toll decrease period for a given country please enter 4"<<endl;
		alpha__<<"If you wish to compare the response of any two countries against this virus please enter 6"<<endl;
	}
	cout<<"On a given day, to find the top 20 countries with the most confirmed cases please enter 1"<<endl;
	cout<<"To find the country(s) with the highest new cases between two given dates please enter 2"<<endl;
	cout<<"To find the starting and ending days of the longest spread period for a given country please enter 3"<<endl;
	cout<<"To find the longest daily death toll decrease period for a given country please enter 4"<<endl;
	cout<<"If you wish to compare the response of any two countries against this virus please enter 6"<<endl;
}
int main()
{
	file_reading();	
	string o;
	int selection;
	int selection_2;
	bool file_read = false;
	while(1)
	{
		cout<<"There are 2 options on how to see your answers.\n\t1.) To see on the terminal.\n\t2.) To be written on a file by the name of *result.txt* as well as on the terminal"<<endl;
		cout<<"Please enter 1 for option#1 and 2 for option#2: ";cin>>selection_2;
		if(selection_2 == 2)
		{
			file_read = true;
			break;
		}
		else if(selection_2 == 1)
			break;
		screen_clear
	}		
	if(file_read)
	{
		alpha__<<"Do you want to see your options or do you want to see the pdf here?\n Press Y/y for options and N/n for pdf[Y/N]. If not both, enter any other key"<<endl;
	}
		cout<<"Do you want to see your options or do you want to see the pdf here?\n Press Y/y for options and N/n for pdf[Y/N]. If not both, enter any other key"<<endl;
		cin>> o;
	if(file_read)
		alpha__<<o<<endl;
	if(o == "Y"|| o == "y")
	{
		options(file_read);
	}
	else if(o == "N"|| o == "n")
	{
		screen_clear
		system("pdftotext Project.pdf a.txt");
		alpha__<<"PDF Displayed on terminal!!!!!"<<endl;
		c_out_pdf();
	}
	else
	{
		screen_clear
	}
	
	while(1)
	{
		if(file_read)
			alpha__<<"Please enter a Queury Number: ";
		cout<<"Please enter a Queury Number: ";
			cin>>selection;
			if(file_read)
			alpha__<<selection<<endl;
		if(selection<7 && selection >0)
		{
			break;
		}
	}
	bool f = false;
	screen_clear
	char option, option_1;
	while(1)
	{
		if(f)
		{	
			while(1)
			{
				if(file_read)
					alpha__<<"Please enter a Queury Number: ";
				cout<<"Please enter a Queury Number: ";
					cin>>selection;
				if(file_read)
					alpha__<<selection<<endl;
				if(selection<7 && selection >-1)
				{
					break;
				}
			}
		}
		if(selection == 1)
		{	
			screen_clear
			
			string date;
			cout<<"Please enter the date in the following pattren. YY-MM-DD"<<"eg,. 13th November, 2000 is == 2000-11-13 and 13th May 2000 == 2000-5-13"<<endl;
			cout<<"Please enter date: ";
			cin.sync();
			cin>>date;
			cout<<endl;
			if(file_read)
			{
				alpha__<<"Please enter the date in the following pattren. YY-MM-DD"<<"eg,. 13th November, 2000 is == 2000-11-13 and 13th May 2000 == 2000-5-13"<<endl;
				alpha__<<"Please enter date: ";
				alpha__<<date<<endl;
			}
			all.part_a(date, file_read);
		}
		else if(selection == 2)
		{	screen_clear
			string date,date1;
			cout<<"Please enter the date in the following pattren. YY-MM-DD"<<endl<<" eg,. 13th November, 2000 is == 2000-11-13 and 13th May 2000 == 2000-5-13"<<endl;
			cout<<"Please enter the starting date: ";
			cin.sync();
			cin>>date;
			if(file_read)
			{
				alpha__<<"Please enter the date in the following pattren. YY-MM-DD"<<"eg,. 13th November, 2000 is == 2000-11-13 and 13th May 2000 == 2000-5-13"<<endl;
				alpha__<<"Please enter date: ";
				alpha__<<date<<endl;
			}
			cin.sync();
			cout<<"Please enter the ending date: ";
			cin>>date1;
			cout<<endl;
			if(file_read)
			{
				alpha__<<"Please enter the ending date: ";
				alpha__<<date1<<endl;
			}
			all.part_b(date, date1, file_read);
		}
		else if(selection == 3)
		{	screen_clear
			cin.sync();
			char str[100]; 
			cout<<"Please enter the name of the country"<<endl;
			scanf(" %[^\n]%*c", str);
			if(file_read)
				{
					alpha__<<"Please enter the name of the country: ";
					alpha__<<str<<endl;
				}
			bool f = false;
			while(all.binarySearch(0,_tot_-1,(string)str ) == -1)
			{
				f = true;
				cout<<"The country you have input, is not on the list. We will display the closes matching countries on the list for you"<<endl;
				cout<<"If you find your country, please enter the number assigned to it"<<endl;
				if(file_read)
				{
					alpha__<<"The country you have input, is not on the list. We will display the closes matching countries on the list for you"<<endl;
				alpha__<<"If you find your country, please enter the number assigned to it"<<endl;
				}
				int m = 0;
				string a[10];
				all.search(a,(string )str, m);
				if(m == 0)
				{
					cout<<"There is no country which matches with any single country in the list, Please enter your countryname again: ";
					scanf(" %[^\n]%*c", str);
					if(file_read)
					{
						alpha__<<"There is no country which matches with any single country in the list, Please enter your countryname again: ";
						alpha__<<str<<endl;
					}
				}
				else
				{
					int k = m-1;
					while(k>=0)
					{
						if(file_read)
						{
							alpha__<<a[k]<<" -> "<<k<<endl;
						}
						cout<<a[k]<<" -> "<<k<<endl;k--;
					}
					cout<<"If you see your name on the list provided, please enter the number. Enter -1 if you want to renter country name: ";
					int num;
					cin>>num;
					if(file_read)
					{
						alpha__<<"If you see your name on the list provided, please enter the number. Enter -1 if you want to renter country name: ";
						alpha__<<num<<endl;
					}
					while(num >= m)
					{
						cout<<"Please enter a valid number: ";
						cin>>num;
						if(file_read)
						{
							alpha__<<"Please enter a valid number: ";
							alpha__<<num<<endl;
						}
					}
					if(num>-1 && num<m)
					{
						all.part_c_d(a[num], 'c', file_read);
						break;
					}
					else if(num == -1)
					{
						cout<<"Please enter the name of the country: ";
					
						scanf(" %[^\n]%*c", str);
						if(file_read)
						{
							alpha__<<"Please enter the name of the country: ";		
							alpha__<<str<<endl;
						}
					}					
				}
			
			}
			if(!f)
			all.part_c_d(string(str), 'c', file_read);
		}
		else if(selection == 4)
		{	screen_clear
			cin.sync();
			char str[100]; 
			cout<<"Please enter the name of the country"<<endl;
			scanf(" %[^\n]%*c", str); bool f = false;
			if(file_read)
				{
					alpha__<<"Please enter the name of the country: ";
					alpha__<<str<<endl;
				}
			while(all.binarySearch(0,_tot_-1,(string)str ) == -1)
			{
				cout<<"The country you have input, is not on the list. We will display the closes matching countries on the list for you"<<endl;
				cout<<"If you find your country, please enter the number assigned to it"<<endl;
				if(file_read)
				{
					alpha__<<"The country you have input, is not on the list. We will display the closes matching countries on the list for you"<<endl;
				alpha__<<"If you find your country, please enter the number assigned to it"<<endl;
				}
				int m = 0;
				string a[10];
				all.search(a,(string )str, m);
				if(m == 0)
				{
					cout<<"There is no country which matches with any single country in the list, Please enter your countryname again: ";
					scanf(" %[^\n]%*c", str);
					if(file_read)
					{
						alpha__<<"There is no country which matches with any single country in the list, Please enter your countryname again: ";
						alpha__<<str<<endl;
					}
				}
				else
				{
					int k = m-1;
					while(k>=0)
					{
						if(file_read)
						{
							alpha__<<a[k]<<" -> "<<k<<endl;
						}
						cout<<a[k]<<" -> "<<k<<endl;k--;
					}
					cout<<"If you see your name on the list provided, please enter the number. Enter -1 if you want to renter country name: ";
					int num;
					cin>>num;
					if(file_read)
					{
						alpha__<<"If you see your name on the list provided, please enter the number. Enter -1 if you want to renter country name: ";
						alpha__<<num<<endl;
					}
					while(num >= m)
					{
						cout<<"Please enter a valid number: ";
						cin>>num;
						if(file_read)
						{
							alpha__<<"Please enter a valid number: ";
							alpha__<<num<<endl;
						}
					}
					if(num>-1 && num<m)
					{
						all.part_c_d(a[num], 'd', file_read);
						break;
					}
					else if(num == -1)
					{
						cout<<"Please enter the name of the country: ";
						scanf(" %[^\n]%*c", str);
						if(file_read)
						{
							alpha__<<"Please enter the name of the country: ";		
							alpha__<<str<<endl;
						}
					}					
				}
				f = true;
			}
			if(!f)
			all.part_c_d(string(str), 'd', file_read);
		}
		else if(selection == 5)
		{
			screen_clear
			cout<<"Do you want to enter your own budget or go with 300?[Y/N]: ";
			char a;
			cin>>a;
			if(file_read)
			{
				alpha__<<"Do you want to enter your own budget or go with 300?[Y/N]: ";
				alpha__<<a<<endl;
			}
			int budget;
			if(a == 'Y'|| a == 'y')
			{
				cout<<"Please enter your budget: ";

				cin>>budget;
				if(file_read)
				{
					alpha__<<"Please enter your budget: ";alpha__<<budget<<endl;
				}
			}
			else budget = 300;
			all.part_e(budget, file_read);
		}
		else if(selection == 6)
		{
			screen_clear
				cout<<"We wish to compare the response of any two countries against this virus. To do this, we must"<<endl;
				cout<<"compare how similar the change of their daily active cases is. The similarity is measured by"<<endl;
				cout<<"the longest number of days their daily active cases share similar values. However, since it is"<<endl;
				cout<<"extremely unlikely that two countries have the exact same values for a sequence of days, we"<<endl;
				cout<<"define a compare threshold K such that any two countries are said to have similar daily"<<endl;
				cout<<"active cases on a given day if their active cases differ <= K."<<endl;cin.sync();
				if(file_read)
				{
					alpha__<<"We wish to compare the response of any two countries against this virus. To do this, we must"<<endl;
					alpha__<<"compare how similar the change of their daily active cases is. The similarity is measured by"<<endl;
					alpha__<<"the longest number of days their daily active cases share similar values. However, since it is"<<endl;
					alpha__<<"extremely unlikely that two countries have the exact same values for a sequence of days, we"<<endl;
					alpha__<<"define a compare threshold K such that any two countries are said to have similar daily"<<endl;
					alpha__<<"active cases on a given day if their active cases differ <= K."<<endl;
				}
			int k;
			cin.sync();
			cout<<"Please enter the name of the first country"<<endl;
			cin.sync();
			char n1[100]; 
			scanf(" %[^\n]%*c", n1); 
			if(file_read)
			{
				alpha__<<"Please enter the name of the first country"<<endl;
				alpha__<<n1<<endl;
			}
			while(all.binarySearch(0,_tot_-1,(string)n1 ) == -1)
			{
				cout<<"The country you have input, is not on the list. We will display the closes matching countries on the list for you"<<endl;
				cout<<"If you find your country, please re-enter with the proper name"<<endl;
				if(file_read)
				{
					alpha__<<"The country you have input, is not on the list. We will display the closes matching countries on the list for you"<<endl;
					alpha__<<"If you find your country, please re-enter with the proper name"<<endl;
				}
				int m = 0;
				string a[10];
				all.search(a,(string )n1, m);
				int k = m-1;
					while(k>=0)
					{
						if(file_read)
							alpha__<<a[k]<<" -> "<<k<<endl;
						cout<<a[k]<<" -> "<<k<<endl;k--;
					}
					if(m == 0)
					cout<<"There is no country which matches with any single country in the list, Please enter your countryname again: ";
					cout<<"Please enter the name: ";scanf(" %[^\n]%*c", n1);
					if(file_read)
					{
							alpha__<<"There is no country which matches with any single country in the list, Please enter your countryname again: ";
					alpha__<<"Please enter the name: ";alpha__<<n1<<endl;
					}
			}
				screen_clear
			
			cout<<"Please enter the name of the second country"<<endl;
			char n2[100]; 
			scanf(" %[^\n]%*c", n2); 
			if(file_read)
			{
				alpha__<<"Please enter the name of the second country"<<endl;
				alpha__<<n2<<endl;
			}
			while(all.binarySearch(0,_tot_-1,(string)n2 ) == -1)
			{
				
				cout<<"The country you have input, is not on the list. We will display the closes matching countries on the list for you"<<endl;
				cout<<"If you find your country, please re-enter with the proper name"<<endl;
				if(file_read)
				{
					alpha__<<"The country you have input, is not on the list. We will display the closes matching countries on the list for you"<<endl;
					alpha__<<"If you find your country, please re-enter with the proper name"<<endl;
				}
				int m = 0;
				string a[10];
				all.search(a,(string )n2, m);
				int k = m-1;
					while(k>=0)
					{
						if(file_read)
							alpha__<<a[k]<<" -> "<<k<<endl;
						cout<<a[k]<<endl;
						k--;
					}
					if(m == 0)
						cout<<"There is no country which matches with any single country in the list, Please enter your countryname again: ";
					cout<<"Please enter the name: ";scanf(" %[^\n]%*c", n2);	
					if(file_read)
					{
							alpha__<<"There is no country which matches with any single country in the list, Please enter your countryname again: ";
					alpha__<<"Please enter the name: ";alpha__<<n2<<endl;
					}
			}
			cin.sync();
				screen_clear
			cout<<"Please enter the value of K"<<endl;
			cin.sync();
			cin>>k;
				screen_clear
			cout<<"For country "<<(string)n1<<" and for country  "<<(string)n2<<endl;
			cout<<"For k = "<<k<<endl; 
			if(file_read)
			{
				alpha__<<"Please enter the value of K: ";alpha__<<k<<endl;
				alpha__<<"For country "<<(string)n1<<" and for country  "<<(string)n2<<endl;
				alpha__<<"For k = "<<k<<endl; 
			}
			all.part_f(string(n1), string(n2), k, file_read);
		}
		
			f = true;
	
		while(1)
		{
			cout<<"Do you want to make another querey? [Y/N]"<<endl;
			cin>> option;
			if(file_read)
			{
				alpha__<<"Do you want to make another querey? [Y/N]"<<endl;
				alpha__<< option;
			}
			if(option != 'Y'|| option !='y'|| option!='N'|| option!='n')
			break;
		}
			
		
			if(option == 'Y'|| option == 'y')
			{
				while(1)
				{
					cout<<"Do you want to see the options again?[Y/N]"<<endl;
					cin>> option_1;
					if(file_read)
					{
						alpha__<<"Do you want to see the options again?[Y/N]"<<endl;
						alpha__<< option_1;
					}
					if(option_1 != 'Y'|| option_1 !='y' || option_1!='N'|| option_1!='n')
					break;
				}
				if(option_1 == 'Y'|| option_1 == 'y')
				{
					options(file_read);
				}
			}
			else 
			{
				screen_clear
				if(file_read)
				{
					alpha__<<"Exiting...."<<endl;
				}
				cout<<"Exiting...."<<endl;
				break;
			}
	}
	
	return 0; 
} 