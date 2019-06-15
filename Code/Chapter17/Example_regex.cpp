#include<iostream>
#include<string>
#include<regex>
#include<set>
#include<fstream>
#include<random>

using namespace std;

void example1() {
	//* 零个或者多个匹配 + 表示一个或者多个匹配
	string pattren("[^c]ei");
	pattren = "[[:alpha:]]*" + pattren + "[[:alpha:]]*";
	regex r(pattren);
	smatch results;
	string test_str = "receipt freind theif receive";
	if (regex_search(test_str, results, r))
		cout << results.str() << endl;
}

void example2(){
	//匹配输入字符串的结尾位置。
	string pattren("[[:alpha:]]+\\.(cpp|cxx|cc)$");
	regex r(pattren, regex::icase);
	smatch results;
	string filename;
	while (cin >> filename) {
		if (regex_search(filename, results, r))
			cout << results.str() << endl;
	}
}

void example3() {
	string pattern = "[^c]ei";
	pattern = ("[[:alpha:]]*" + pattern + "[[:alpha:]]*");
	regex r(pattern,regex::icase);
	string test_str = "receipt freind theif receive";
	for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it;
		it != end_it; ++it)
		cout << it->str() << endl;
}

void example4() {
	default_random_engine e;
	for (size_t i = 0; i < 10; i++)
		cout << e() << " ";
	cout << endl;
}



//17.14
void func1() {
	try {
		regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
	}
	catch (regex_error e) {
		cout << e.what() << "\nvode:" << e.code() << endl;
	}
	try {
		regex t("[[:al:]]", regex::icase);
	}
	catch (regex_error t) {
		cout << t.what() << "\ncode" << t.code() << endl;
		}
}

//17.15

void func2() {
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern);
	smatch results;
	string input;
	while (1) {
		cout << "please enster string or q to quit:" << endl;
		cin >> input;
		if (input == "q")
			break;
		else
			if (regex_search(input, results, r))
				cout << results.str() << endl;
	}
}

//17.17
void func3() {
	string pattern = "[^c]ei";
	pattern = ("[[:alpha:]]*" + pattern + "[[:alpha:]]*");
	regex r(pattern, regex::icase);
	string test_str = "receipt freind theif receive";
	for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it;
		it != end_it; ++it)
		cout << it->str() << endl;
}

//17.18


void func4() {
	set<string> valid_string_set{ "albeit", "neighbor" };
	string pattern = "[^c]ei";
	pattern = ("[[:alpha:]]*" + pattern + "[[:alpha:]]*");
	regex r(pattern, regex::icase);
	string test_str = "receipt freind theif receive albeit neighbor";
	for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it;
		it != end_it; ++it)
		if(valid_string_set.count(it->str())==0)
			cout << it->str() << endl;
}

//17.20

void func5() {
	ifstream in("number.txt");

	if (!in) {
		cout << "NO File" << endl;
	}

	string pattren = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(pattren);
	string test_str; //= "(021)-321-1000";
	smatch results;
	while (getline(in, test_str)) {
		//for(sregex_iterator it(test_str.begin(),test_str.end(),r),end_it;it!=end_it,++it)
		if (regex_search(test_str, results, r))
			cout << results.str() << endl;
	}
}

//17.22
// \s* 表示零个或多个空格，只需要修改匹配模式（即phone）即可。
void func6() {
	ifstream in("numbersplit.txt");

	if (!in) {
		cout << "NO File" << endl;
	}

	string pattren = "(\\()?(\\d{3})(\\))?\\s*([-. ])?(\\d{3})\\s*([-. ]?)(\\d{4})\\s*";
	regex r(pattren);
	string test_str; //= "(021)-321-1000";
	smatch results;
	while (getline(in, test_str)) {
		//for(sregex_iterator it(test_str.begin(),test_str.end(),r),end_it;it!=end_it,++it)
		if (regex_search(test_str, results, r))
			cout << results.str() << endl;
	}
}

//17.23

void func7() {
	ifstream in("Zipcode.txt");

	if (!in) {
		cout << "NO File" << endl;
	}

	string pattern = "[0-9]{5}(-[0-9]{4})?"; 
	regex r(pattern);
	string test_str;
	smatch results;
	while (getline(in, test_str)) {
		if (regex_search(test_str, results, r))
			cout << results.str() << endl;
	}
}

//17.24
void func8() {

	ifstream in("numberName.txt");

	if (!in) {
		cout << "NO File" << endl;
	}

	string fmt = "$2.$5.$7";
	string pattren = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(pattren);
	string test_str; //= "(021)-321-1000";
	smatch results;
	while (getline(in, test_str)) {
		//for(sregex_iterator it(test_str.begin(),test_str.end(),r),end_it;it!=end_it,++it)
			cout << regex_replace(test_str, r, fmt) << endl;

	}
}


//17.25
void func9() {

	ifstream in("numberName.txt");

	if (!in) {
		cout << "NO File" << endl;
	}

	string fmt = "$2.$5.$7";
	string pattren = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(pattren);
	string test_str; //= "(021)-321-1000";
	smatch results;
	while (getline(in, test_str)) {
		//for(sregex_iterator it(test_str.begin(),test_str.end(),r),end_it;it!=end_it,++it)
		if (regex_search(test_str, results, r))
			cout << results.str() << endl;

	}
}

//17.26

void func10() {
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);	// 寻找模式所用的regex对象

	smatch result;
	string s;

	ifstream in("numberName.txt");

	if (!in) {
		cout << "NO File" << endl;
	}

	vector<vector<string>> person_numbers;

	while (getline(in, s))
	{
		vector<string> numbers;

		for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it)
		{
			numbers.push_back(it->str());
		}

		person_numbers.push_back(numbers);
	}

	for (const auto &numbers : person_numbers)
	{
		if (numbers.empty()) continue;

		if (numbers.size() > 1)
		{
			for (size_t i = 1; i < numbers.size(); ++i)
			{
				cout << numbers[i] << " ";
			}
		}
		else
		{
			cout << numbers[0];
		}

		cout << endl;
	}
}

//17.27
void func11() {
	ifstream in("Zipcode.txt");

	if (!in) {
		cout << "NO File" << endl;
	}

	string pattern = "([0-9]{5})-([0-9]{4})?";
	regex r(pattern);
	string test_str;
	string fmt = "$1-$2";
	smatch results;
	/*
		while (getline(in, test_str)) {
		if (regex_search(test_str, results, r))
			cout << results.str() << endl;
	}
	*/
	while (getline(in, test_str)) {
		cout << regex_replace(test_str, r, fmt) << endl;
	}
}
	



int main() {

	//Example1
	//example1();
	//cout << "--------------" << endl;
	//example2();
	//cout << "--------------" << endl;
	//example3();
	//func1();
	//func2();
	//func5();
	//cout << "--------------" << endl;
	//func6();
	//cout << "--------------" << endl;
	//func7();
	//cout << "--------------" << endl;
	//func8();
	//cout << "--------------" << endl;
	//func9();
	//cout << "--------------" << endl;
	//func10();
	//cout << "--------------" << endl;
	//func11();
	example4();
	char ch;
	cin >> ch;
	return 0;
}