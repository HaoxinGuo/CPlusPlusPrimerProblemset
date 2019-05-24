#include<iostream>
#include<string>
#include<deque>
#include<stack>
#include<stdexcept>

using namespace std;

enum obj_type{LP,Rp,ADD,SUB,VAL};
struct obj {
	obj(obj_type type, double val = 0) { t = type, v = val; };
	double v;
	obj_type t;
};

inline void skipws(string &exp, size_t &p) {
	p = exp.find_first_not_of(" ", p);
}

inline void new_val(stack<obj> &so, double v) {
	if (so.empty() || so.top().t == LP) {//空栈或者左括号
		so.push(obj(VAL, v));
		cout << "push" << v << endl;
	}
	else if (so.top().t == ADD || so.top().t == SUB) {
		//之前是运算符
		obj_type type = so.top().t;
		so.pop();
		if (type == ADD)
			cout << "pop+" << endl;
		else
			cout << "pop-" << endl;
		//cout<<"pop"<<so.top().v<<endl;
		//执行加减法
		if (type == ADD)
			v += so.top().v;
		else
			v = so.top().v - v;
		so.pop();
		so.push(obj(VAL, v));
		//cout<<"push"<<v<<endl;
	}
	else
		throw invalid_argument("缺少运算符");
}

int main() {
	stack<obj> so;
	string exp;
	size_t p = 0, q;
	double v;
	cout << "请输入表达式：" << endl;
	getline(cin, exp);
	while (p < exp.size()) {
		skipws(exp, p);
		if (exp[p] == '(') {
			so.push(obj(LP));
			p++;
		}
		else if (exp[p] == '+' || exp[p] == '-') {
			if (so.empty() || so.top().t != VAL)
				//空栈或之前不是运算符
				throw invalid_argument("缺少运算符");
			if (exp[p] == '+')
				so.push(obj(ADD));
			else
				so.push(obj(SUB));
			p++;
			//cout<<"push"<<exp[p-1]<<endl;
		}
		else if (exp[p] == ')') {//右括号
			p++;
			if (so.empty())//之前无匹配的左括号
				throw invalid_argument("未匹配右括号");
			if (so.top().t == LP)//括号之间无内容
				throw invalid_argument("括号内无内容");
			if (so.top().t == VAL) {//正确：括号内正常运算，运算结果
				v = so.top().v;
				so.pop();
				if (so.empty() || so.top().t != LP)
					throw invalid_argument("未匹配右括号");
				so.pop();
				new_val(so, v);
			}
			else
				throw invalid_argument("缺少运算符");
		}
		else {
			v = stod(exp.substr(p), &q);
			p += q;
			new_val(so, v);
		}
	}

	if (so.size() != 1 || so.top().t != VAL)
		throw invalid_argument("非法表达式");
	cout << so.top().v << endl;
	
	return 0;
}