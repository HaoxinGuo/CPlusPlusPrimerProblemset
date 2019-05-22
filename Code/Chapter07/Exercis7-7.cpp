#include"Sales_data.h"
using namespace std;

int main() {
	Sales_data data1;
	Sales_data data2("978-7-121-15353-2");
	Sales_data data3("978-7-121-15353-2",10,128,109);
	Sales_data data4(cin);
	//cout << "\b 请输入交易记录：" << endl;
	cout << data1<<"\n"<<data2<<"\n"<<data3<<"\n"<<data4<<endl;
	/*Sales_data total;
	if (read1(cin, total)) 
	{
		Sales_data trans;
		while (read1(cin, trans)) {
			if (total.isbn() == trans.isbn())
				total = add1(total, trans);
			else {
				print1(cout, total);
				cout << endl;
				total = trans;
			}
		}
		print1(cout, total);
		cout << endl;
	}
	else 
	{
		cout << "No data" << endl;
		return -1;
	}
	*/
	return 0;
}