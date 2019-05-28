// 练习12.7

#include<iostream>
#include<vector>
#include<memory>

using namespace std;

shared_ptr<vector<int>> new_vector(void) {
	return make_shared<vector<int>>();
}

void read_ints(shared_ptr<vector<int>> pv) {
	int v;
	while (cin >> v)
		pv->push_back(v);
}


void print_ints(shared_ptr<vector<int>> pv) {
	for (auto &a : *pv)
		cout << a << " ";
	cout << endl;
}


int main()
{
	shared_ptr<vector<int>> pv = new_vector();

	if (!pv) {
		cout << "内存不足" << endl;
		return -1;
	}

	read_ints(pv);

	print_ints(pv);

	return 0;
}
