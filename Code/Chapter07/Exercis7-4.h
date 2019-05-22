#ifndef PERSON_INCLUDED
#define PERSON_INCLUDED

#include<iostream>
#include<string>

class Person{
	private:
		string strname;//name
		string straddress;//address
	public:
		string getname() const {return strname;};
		string getadress() const {return straddress;};
#endif