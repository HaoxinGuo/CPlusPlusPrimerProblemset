#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

string make_pulral(size_t ctr,const string &word,const string &ending="s"){
	return (ctr>1)?word+ending:word;
}

int main(){
	cout<<"success�ĵ�����ʽ�ǣ�"<<make_pulral(1,"success","es")<<endl;
	cout<<"success�ĸ�����ʽ�ǣ�"<<make_pulral(2,"success","es")<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"failure�ĵ�����ʽ�ǣ�"<<make_pulral(1,"failure")<<endl;
	cout<<"failure�ĸ�����ʽ�ǣ�"<<make_pulral(2,"failure")<<endl;
	return 0;
}