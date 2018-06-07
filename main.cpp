#include <iostream>
#include <vector>
#include <cstring>
#include "Citizen.h"
#include "CivilRegistry.h"
#include "Time.h"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;


int main(){
	vector<string> idNo;//we need to obtain to read input txt file so that after parsing, 
	vector<string> Name;//we divided by string input txt file besides that we must contain idNo's,Name's,Surname's,HasApp's etc. with vector string 
	vector<string> Surname;
	vector<string> hasApp;
	vector<string> appDate;
	vector<string> appSlot;
	vector<string> entryClock;
	
	ifstream inputfile;//open the data
	inputfile.open("input.txt");//open input.txt
	string line;
    string delimeter="\t";//set with tab  to get the names,surnames etc.

	getline(inputfile,line);
	
		while (getline(inputfile,line)){//read line by line
		
		size_t pos = 0;
		string token;
		string::size_type sz;
		
		pos = line.find(delimeter);
		token = line.substr(0, pos);
		idNo.push_back(token);//with using temporary string token we want to get idNo's
		line.erase(0, pos + delimeter.length());//erase token
		
		pos = line.find(delimeter);
		token = line.substr(0, pos);
		Name.push_back(token);///with using temporary string token we want to get Name's
		line.erase(0, pos + delimeter.length());//erase token
	
		pos = line.find(delimeter);
		token = line.substr(0, pos);
		Surname.push_back(token);//with using temporary string token we want to get Surname's
		line.erase(0, pos + delimeter.length());//erase token
		
		
		pos = line.find(delimeter);
		token = line.substr(0, pos);
		hasApp.push_back(token);//with using temporary token we want to get HasApp's
		line.erase(0, pos + delimeter.length());//erase token
		
		pos = line.find(delimeter);
		token = line.substr(0, pos);
		appDate.push_back(token);//with using temporary token we want to get AppDate's
		line.erase(0, pos + delimeter.length());//erase token
		
		pos = line.find(delimeter);
		token = line.substr(0, pos);
		appSlot.push_back(token);//with using temporary token we want to get AppSlot's
		line.erase(0, pos + delimeter.length());//erase token 		
		
		pos = line.find(delimeter);
		token = line.substr(0, pos);
		entryClock.push_back(token);//with using temporary token we want to get EntryClock's
		line.erase(0, pos + delimeter.length());//erase token
		
		
	}
    inputfile.close();//to close file

	
	int size = Name.size();//we need to know how many citizen size
	Citizen a[size];//we need  create with Citizen objects up to size.
	CivilRegistry b;//we need create civil registry object to sending Citizen's Objects ,we should insert,remove  with this.
	for (int i=0;i<idNo.size();i++){
		
																							
		Citizen new_citizen = Citizen(idNo[i],Name[i],Surname[i],hasApp[i],appSlot[i],appDate[i],entryClock[i]);//we should create a newCitizen constructor
		a[i] = new_citizen;//then we need contain this new-citizen object with a[i]citizens 																	
		
		b.insertCitizen(a[i]);//Now we have Citizen and we could insert our list with Civil Registry object
	
	}
		b.print();//As we can show our list objects to know the results.
	 
		//b.removerCitizen(1);// to test remover func. for wApp list
		//b.removerCitizen(0);//to test remover func. for wOutApp list
		//b.removerCitizen(1);// to test remover func. for wApp list
		//b.removerCitizen(0);//to test remover func. for wOutApp list
		//b.print();// As we could show and test  remover function to pop_front list elements.
   	
   return 0;
}
