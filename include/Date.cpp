#include "Date.hpp"
#include <sstream>
#include <string>
Date::Date()
{
	m_year=1000;
	m_month=1;
	m_day=1;
	m_hour=0;
	m_minute=0;
}
Date::Date(int t_year, int t_month, int t_day, int t_hour, int t_minute)
{
	m_year=t_year;
	m_month=t_month;
	m_day=t_day;
	m_hour=t_hour;
	m_minute=t_minute;
}
Date::Date(std::string dateString)
{
	std::string temp;
	temp=dateString.substr(0,3);
	m_year=atoi(temp.c_str());
	temp=dateString.substr(5,6);
	m_month=atoi(temp.c_str());
	temp=dateString.substr(8,9);
	m_day=atoi(temp.c_str());
	temp=dateString.substr(11,12);
	m_hour=atoi(temp.c_str());
	temp=dateString.substr(14,15);
	m_minute=atoi(temp.c_str());
}
int Date::getYear(void) const
{
	return m_year;
}
void Date::setYear(const int t_year)
{
	m_year=t_year;
}
int Date::getMonth(void) const
{
	return m_month;
}
void Date::setMonth(const int t_month)
{
	m_month=t_month;
}
int Date::getDay(void) const
{
	return m_day;
}
void Date::setDay(const int t_day)
{
	m_day=t_day;
}
int Date::getHour(void) const
{
	return m_hour;
}
void Date::setHour(const int t_hour)
{
	m_hour=t_hour;
}
int Date::getMinute(void) const
{
	return m_month;
}
void Date::setMinute(const int t_minute)
{
	m_minute=t_minute;
}
bool Date::isValid(const Date t_date)
{
	int flag=0;
	if(t_date.m_year%4==0&&t_date.m_year%100!=0||t_date.m_year%400==0) 
		flag=1;
	else; 	 
	if(t_date.m_year>=1000&&t_date.m_year<=9999);
	else return false;
	if(t_date.m_hour>=0&&t_date.m_hour<=24);
	else return false;
	if(t_date.m_minute>=0&&t_date.m_minute<=60);
	else return false;
	if(t_date.m_month==1||t_date.m_month==3||t_date.m_month==5||t_date.m_month==7||t_date.m_month==8||t_date.m_month==10||t_date.m_month==12)
	{
		if(t_date.m_day>=1&&t_date.m_day<=31);
		else return false;
	}
	else if(t_date.m_month==4||t_date.m_month==6||t_date.m_month==9||t_date.m_month==11)
	{
		if(t_date.m_day>=1&&t_date.m_day<=30);
		else return false;
	}
	else
	{
		if(flag=0)
		{
			if(t_date.m_day>=1&&t_date.m_day<=28);
			else return false;
		}
		else
		{
			if(t_date.m_day>=1&&t_date.m_day<=29);
			else return false;
		}
	}
	return true;
}
Date Date::stringToDate(const std::string t_dateString)
{
	for(int i=0;i<t_dateString.size();i++) 
 	{   
  		if ((t_dateString.at(i)>'9') || (t_dateString.at(i)<'0') );
  		else
  		{
  			if(i==4||i==7||i==10||i==13);
  			else return Date(0,0,0,0,0);
		}
    }  
	std::string temp=t_dateString;
	temp=t_dateString.substr(0,3);
	int year=atoi(temp.c_str());
	temp=t_dateString.substr(5,6);
	int month=atoi(temp.c_str());
	temp=t_dateString.substr(8,9);
	int day=atoi(temp.c_str());
	temp=t_dateString.substr(11,12);
	int hour=atoi(temp.c_str());
	temp=t_dateString.substr(14,15);
	int minute=atoi(temp.c_str());
	Date temp2(year,month,day,hour,minute);
	if(isValid(temp2)) return temp2;
	else return Date(0,0,0,0,0);
}
std::string Date::dateToString(Date t_date)
{
	if(isValid(t_date));
	else return "0000-00-00/00:00";
	std::stringstream ss;
    std::string str,temp;
    ss<<t_date.m_year;
    ss>>str;
    temp=str;
    temp+="-";
    ss<<t_date.m_month;
    ss>>str;
    if(t_date.getMonth()>=10) temp+=str;
    else
    {
    	temp+="0";
    	temp+=str;
	}
	temp+="-";
    ss<<t_date.m_day;
    ss>>str;
    if(t_date.getDay()>=10) temp+=str;
    else
    {
    	temp+="0";
    	temp+=str;
	}
	temp+="/";
	ss<<t_date.m_hour;
    ss>>str;
    if(t_date.getHour()>=10) temp+=str;
    else
    {
    	temp+="0";
    	temp+=str;
	}
	temp+=":";
	ss<<t_date.m_minute;
    ss>>str;
    if(t_date.getMinute()>=10) temp+=str;
    else
    {
    	temp+="0";
    	temp+=str;
	}
	return temp;
}
Date &Date::operator=(const Date &t_date)
{
	this->m_year=t_date.getYear();
	this->m_month=t_date.getMonth();
	this->m_day=t_date.getDay();
	this->m_hour=t_date.getHour();
	this->m_minute=t_date.getMinute();
	return *this;
}
bool Date::operator==(const Date &t_date) const
{
	if((this->m_year==t_date.m_year)&&(this->m_month==t_date.m_month)&&(this->m_day==t_date.m_day)&&(this->m_hour==t_date.m_hour)&&(this->m_minute==t_date.m_minute))
		return true;
	else
		return false;
}
bool Date::operator>(const Date &t_date) const
{
	if(this->m_year>t_date.m_year) return true;
	else if(this->m_year<t_date.m_year) return false;
	else
	{
		if(this->m_month>t_date.m_month) return true;
		else if(this->m_month<t_date.m_month) return false;
		else
		{
			if(this->m_day>t_date.m_day) return true;
			else if(this->m_day<t_date.m_day) return false;
			else
			{
				if(this->m_hour>t_date.m_hour) return true;
				else if(this->m_hour<t_date.m_hour) return false;
				else
				{
					if(this->m_minute>t_date.m_minute) return true;
					else return false;
				}
			}
		}
	}
}
bool Date::operator<(const Date &t_date) const
{
	if(this->m_year<t_date.m_year) return true;
	else if(this->m_year>t_date.m_year) return false;
	else
	{
		if(this->m_month<t_date.m_month) return true;
		else if(this->m_month>t_date.m_month) return false;
		else
		{
			if(this->m_day<t_date.m_day) return true;
			else if(this->m_day>t_date.m_day) return false;
			else
			{
				if(this->m_hour<t_date.m_hour) return true;
				else if(this->m_hour>t_date.m_hour) return false;
				else
				{
					if(this->m_minute<t_date.m_minute) return true;
					else return false;
				}
			}
		}
	}
}
bool Date::operator>=(const Date &t_date) const
{
	if(this->m_year>t_date.m_year) return true;
	else if(this->m_year<t_date.m_year) return false;
	else
	{
		if(this->m_month>t_date.m_month) return true;
		else if(this->m_month<t_date.m_month) return false;
		else
		{
			if(this->m_day>t_date.m_day) return true;
			else if(this->m_day<t_date.m_day) return false;
			else
			{
				if(this->m_hour>t_date.m_hour) return true;
				else if(this->m_hour<t_date.m_hour) return false;
				else
				{
					if(this->m_minute>=t_date.m_minute) return true;
					else return false;
				}
			}
		}
	}
}
bool Date::operator<=(const Date &t_date) const
{
	if(this->m_year<t_date.m_year) return true;
	else if(this->m_year>t_date.m_year) return false;
	else
	{
		if(this->m_month<t_date.m_month) return true;
		else if(this->m_month>t_date.m_month) return false;
		else
		{
			if(this->m_day<t_date.m_day) return true;
			else if(this->m_day>t_date.m_day) return false;
			else
			{
				if(this->m_hour<t_date.m_hour) return true;
				else if(this->m_hour>t_date.m_hour) return false;
				else
				{
					if(this->m_minute<=t_date.m_minute) return true;
					else return false;
				}
			}
		}
	}
}
