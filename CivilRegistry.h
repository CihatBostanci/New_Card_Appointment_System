#ifndef _CivilRegistry_H  // to include only once
#define _CivilRegistry_H
#include<iostream>
#include <cstring>
#include <list>
#include <iterator>
#include "Citizen.h"
#include <cctype>
#include "Time.h"
using namespace std;

class CivilRegistry{
	list<Citizen> wApp;//Civil Registry attributes
	list<Citizen> wOutApp;
	
	public:
		CivilRegistry(){};//CivilRegistry Constructor 
		
		void insertCitizen(Citizen & c){// we need insert   Citizen argument respect to operator overloading functions. 
			
			if(c.getHasApp()==true){// we call if  return HasApp ->True then we understand it is with appointment list.
				if(wApp.empty()){//firsly if list is empty we add first node manually
						wApp.push_back(c);//insert func. for list operation 
				}
				else{// if list is not empty
					for(list<Citizen>::iterator it=wApp.begin();it!=wApp.end();it++){//with iterator func . 
						if(c.getAppTime()<it->getAppTime())// we could compare our object with in_objects and so that it is overload the >,<,== func.
						{
							wApp.push_front(c);//to arrange how can add the list 
							break;
						}
						else{
							wApp.push_back(c);// if operator overloading is not "<" the same function "==" with">" 
							break;
						}
					}
				}			
			}
			else{// if return HasApp->false then we understand it is without appointment list
			
				if(wOutApp.empty()){//firsly if list is empty we add first node manually
					wOutApp.push_back(c);//insert func. for list operation 
				}
				else{// if list is not empty
					for(list<Citizen>::iterator it=wOutApp.begin();it!=wOutApp.end();it++){//with iterator func . 
						if(c.getAppTime()<it->getAppTime())// we could compare our object with in_objects and so that it is overload the >,<,== func
						{
							wOutApp.push_front(c);
							break;
						}
						else{
							wOutApp.push_back(c);// if operator overloading is not "<" the same function "==" with">" 
							break;
						}
					}
				}
			}
		};
		void removerCitizen(int a){
		
			if(a==1)
				wApp.pop_front();// depend on a ,the same concept with insertion func. but at this point we pop_front every object 
			if(a==0)
			wOutApp.pop_front();//depend on a ,the same concept with insertion func. but at this point we pop_front every object
		
		
		}
		void print(){
				cout<<"Citizen with appointment:"<<endl;
				for(list<Citizen>::iterator it=wApp.begin();it!=wApp.end();it++){
					
						cout<<it->getName()<<endl;//to show wApp list element 	
						}	
				cout<<"Citizen without  appointment:"<<endl;
				for(list<Citizen>::iterator it=wOutApp.begin();it!=wOutApp.end();it++){
					
						cout<<it->getName()<<endl;//to show wOutApp list element 
						}					
			}
};



#endif
