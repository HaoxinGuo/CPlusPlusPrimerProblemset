/*
Exercise10-15
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
#include<iterator>
#include<string>
#include"Sales_data.h"

using namespace std;


int main(){
	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter10\\data\\10-33.txt");
	if(!in){
		cout<<"No data"<<endl;
		return -1;
	}
	
	ofstream out1("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter10\\data\\10-33_1.txt");
	if(!out1){
		cout<<"打开文件失败"<<endl;
		return -1;
	}
	
	ofstream out2("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter10\\data\\10-33_2.txt");
	if(!out2){
		cout<<"打开文件失败"<<endl;
		return -1;
	}
	
	istream_iterator<int> in_ter(in),eof;
	vector<int> Vint;
	ostream_iterator<int> out_ter1(out1," ");
	ostream_iterator<int> out_ter2(out2,"\n");
	while(in_ter!=eof){
		if (*in_ter &1)
			*out_ter1++ = *in_ter;
		else
			*out_ter2++ = *in_ter;
		in_ter++;
	}
	
	
	return 0;
}