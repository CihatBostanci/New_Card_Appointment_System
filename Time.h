#ifndef _Time_H           // to include only once
#define _Time_H
#include<iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>

using namespace std;

class Time{
		int day;//these are our attributes which told us in assignment
		int month;
		int year;
		int hour;
		int minute;
		
		public:
			Time(string date, string entry);// we need to create a Time constructor to set up date and entry time.
			Time getTime();//we can get time object for use by other class
			bool operator<(const Time &);// we need to compare our date time to set appointment sorting.
			bool operator>(const Time &);//we need to compare our date time to set appointment sorting.
		    bool operator==(const Time &);//we need to compare our date time to set appointment sorting.
};
Time::Time(string date, string entry){
				/*we should  give string arguments becouse of reading and parsing with string 
				then we need to convert this arguments and parsing again to integer arguments.
				As we could do whatever we want. But , primarily we compare the times.
				*/		
				//to keep appDate
				string line = date;
				string delimeter="-";
				
				size_t pos = 0;
				string token;
				string::size_type sz;
				
				pos = line.find(delimeter);
				token = line.substr(0, pos);
				day = atoi(token.c_str());
				line.erase(0, pos + delimeter.length());
				
				pos = line.find(delimeter);
				token = line.substr(0, pos);
				month = atoi(token.c_str());
				line.erase(0, pos + delimeter.length());
				
				pos = line.find(delimeter);
				token = line.substr(0, pos);
				year = atoi(token.c_str());
				line.erase(0, pos + delimeter.length());
				
				
				// to keep entry clock
				string line1 = entry;
				string delimeter1=".";
				
				size_t pos1 = 0;
				string token1;
				string::size_type sz1;
				
				pos1 = line1.find(delimeter1);
				token1 = line1.substr(0, pos1);
				hour = atoi(token1.c_str());
				line1.erase(0, pos1 + delimeter1.length());
				
				pos1 = line1.find(delimeter1);
				token1 = line1.substr(0, pos1);
				minute = atoi(token1.c_str());
				line1.erase(0, pos1 + delimeter1.length());						
				

}
Time Time::getTime(){
	string entry,date,nentry,pyear,spaceyear;
	entry=minute+"."+hour;
	nentry=entry+" ";
	date=day+"/"+month;			//this format is told us in assignment. So that I concatenate these strings to our wish.
	spaceyear="/"+year;
	pyear=date+spaceyear;
	cout<<hour<<"."<<minute<<" "<<day<<month<<year<<endl;
	return Time(nentry,pyear);


	
}
bool Time::operator<(const Time &indata){
/*We need to compare times such as greater or smaller date 
to sort our objects with fairly.
*/
	if(this->year < indata.year)
        return true;
    	else if(this->year == indata.year){
        	if(this->month < indata.month)
            return true;
        	else if(this->month == indata.month){
          	 if(this->day < indata.day)
                return true;
            	else if (this->day == indata.day){
               	 if(this->hour < indata.hour)
                    return true;
                	else if(this->hour == indata.hour){
                    	if(this->minute < indata.minute)
                        	return true;
                    	else return false;
                   	 }
               	 else return false;
               	 }
           	 else return false;
           	 }
       	 else return false;
    }	else return false;
}
bool Time::operator>(const Time &indata){
/*We need to compare times such as greater or smaller date 
to sort our objects with fairly.
*/
	if(this->year > indata.year)
        return true;
    else if(this->year == indata.year){
        if(this->month > indata.month)
            return true;
        else if(this->month == indata.month){
            if(this->day > indata.day)
                return true;
            else if (this->day == indata.day){
                if(this->hour > indata.hour)
                    return true;
                else if(this->hour == indata.hour){
                    if(this->minute > indata.minute)
                        return true;
                    else return false;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }else return false;
}
bool Time::operator==(const Time &indata){
/*We need to compare times such as greater or smaller date 
to sort our objects with fairly.
*/
if(this->year == indata.year)
        return true;
    else if(this->year == indata.year){
        if(this->month == indata.month)
            return true;
        else if(this->month == indata.month){
            if(this->day == indata.day)
                return true;
            else if (this->day == indata.day){
                if(this->hour == indata.hour)
                    return true;
                else if(this->hour == indata.hour){
                    if(this->minute == indata.minute)
                        return true;
                    else return false;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }else return false;
}

#endif
