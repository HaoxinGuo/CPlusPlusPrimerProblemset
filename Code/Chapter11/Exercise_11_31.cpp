#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include<iterator>

using namespace std;

void remove_author(multimap<string,string> &books,const string &author){
	auto pos = books.equal_range(author);
	if(pos.first==pos.second)
		cout<<"没有"<<author<<"这个作者"<<endl;
	else
		books.erase(pos.first,pos.second);
}

void print_books(multimap<string,string> &books){
	cout<<"当前书目包括："<<endl;
	for(auto &book:books)
		cout<< book.first<< "《" <<book.second<<"》"<<endl;
	cout<<endl;
}

int main()
{
	multimap<string,string> books;

	books.insert({"barth,john","ABCD"});
	books.insert({"barth,john","ABCDEFG"});
	books.insert({"basg","gagagasgasg"});
	books.insert({"basg","gagag"});

	print_books(books);

	remove_author(books,"barth,john");

	print_books(books);

	return 0;
}
