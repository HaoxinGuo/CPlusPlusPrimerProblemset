#ifndef STRBLOB_H
#define STRBLOB_H


#include<iostream>
#include<string>
#include<memory>
#include<initializer_list>
#include<vector>
#include<stdexcept>
#include "StrBlobPtr.h"



using namespace std;
//��ǰ������Strblob�е�������������

class StrblobPtr;

class Strblob	
{
	friend class StrblobPtr;
public:
	typedef vector<string>::size_type size_type;	//����

	Strblob();	//���캯��

	Strblob(initializer_list<string> i1); //���ó�ʼ���б��캯��

	size_type size() const { return data->size(); };//����data����Ĵ�С

	bool empty() const { return data->empty(); };//���data�����Ƿ�Ϊ��

	void push_back(const string &s) { data->push_back(s); };//��data���������string����

	void pop_back();//ɾ��Ԫ��

	//Ԫ�ط���
	string& front();
	const string& front() const;//�����汾

	string& back();
	const string& back() const;//�����汾


	//�ṩ��StrblobPtr�Ľӿ�

	StrblobPtr begin();
	StrblobPtr end();

private:
	shared_ptr<std::vector<std::string>> data;
	//���data[i]���Ϸ����׳��쳣��
	void check(size_type i, const std::string &msg) const;
};




#endif // !STRBLOB_H


