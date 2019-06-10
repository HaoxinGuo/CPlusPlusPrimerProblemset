#pragma once
#include<iostream>
#include<string>

using namespace std;

class Quote
{
	//friend double print_total(ostream &os, const Quote &item, size_t n);
public:
	Quote();//Ĭ�Ϲ��캯��
	Quote(const string &book, double sales_price) :bookNo(book), price(sales_price) {
		cout << "Quote(const string &book, double sales_price)" << endl;
	};//���캯��
	Quote(const Quote&);		//��������
	Quote(Quote&&);				//�ƶ����캯��
	Quote& operator=(const Quote&);			//������ֵ����
	Quote& operator=(Quote && );	//�ƶ���ֵ����
	string isbn() const { return bookNo; };
	virtual double net_price(size_t) const;//����۸�
	virtual void debug();//��ʾ����
	virtual ~Quote();
private:
	string bookNo;
protected:
	double price = 0.0;
};
