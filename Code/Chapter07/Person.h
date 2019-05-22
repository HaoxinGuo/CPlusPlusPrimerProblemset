#ifndef PERSON_INCLUDED
#define PERSON_INCLUDED

#include<iostream>
#include<string>

class Person{
	friend std::istream &read(std::istream &is,Person &per);
	friend std::ostream &print(std::ostream &os, const Person &per);
	friend std::istream& operator >>(std::istream &is,Person &per);
	private:
		std::string strname;//name
		std::string straddress;//address
	public:
		Person() = default;
		Person(const std::string name,const std::string address):strname(name),straddress(address){};
		Person(std::istream &is){is>>*this;};
		std::string getname() const {return strname;};
		std::string getadress() const {return straddress;};
};

std::istream& operator >>(std::istream &is,Person &per){
	is>>per.strname>>per.straddress;
	return is;
}

#endif