#ifndef _Citizen_H           //to include only once
#define _Citizen_H
#include "Time.h"
#include<iostream>
#include <cstring>

using namespace std;

class Citizen{
	char *idNo;//these are our attributes which told us in assignment
	char *Name;
	char *surName;
	bool hasApp;
	Time *appTime;
	char *appSlot; 
	public:
		Citizen(){};
		char * getName()const;// we need to show name by name our objects so this getter func. is necessary
		void setName(string name);
		bool getHasApp(){
			// to arrange citizen who has with an appoinment or without appointment 
				if(hasApp ==true)
				return  true;
				else
				return false;
			
		
		}
		Citizen(string id,string name,string surname,string hasapp,string appslot,string date,string entry){
		// to set id's,Name's etc and convert them whatever we want to use.
			idNo = new char[sizeof(id)];
			strncpy(idNo, id.c_str(), sizeof(idNo));
				
			Name = new char[sizeof(name)];
			strncpy(Name, name.c_str(), sizeof(Name));
			
			
			surName = new char[sizeof(surname)];
			strncpy(surName, surname.c_str(), sizeof(surName));
		
			appSlot = new char[sizeof(appslot)];
			strncpy(appSlot, appslot.c_str(), sizeof(appSlot));
			
			if(hasapp == "TRUE"){
				hasApp = true;
			}
			else if(hasapp =="FALSE"){
				hasApp = false;
			}
			
			//add time infos entryclock and appDate
			appTime = new Time(date,entry);
		};	
		Time & getAppTime();
		~Citizen();
};
Time  & Citizen::getAppTime(){
	return *appTime;// with  get app Time, we are flexible compare to time features of Citizen entry Clock
}

char  * Citizen::getName()const {
	return Name;// to get Citizen's Name
}

Citizen::~Citizen(){
// we use dynamic array so that for the memory leak  we have to use destructor 
	delete[]idNo;
	delete[] Name;
	delete[] surName;
	delete[] appSlot;
	
}

#endif
