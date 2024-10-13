#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;
int priority(string str) {
	if (str[0] == '*' || str[0] == '/') return 2;
	if (str[0] == '+' || str[0] == '-') return 1;
	if (str[0] == '(') return 0;
}
stack<string> s;
void toPostfix(string str, queue<string>& q) {
	string toanTu, toanHang;
	while (str.length() != 0) {
		if (str[0] >= 48 && str[0] <= 57)
		{
			toanHang.push_back(str[0]);
			str.erase(str.begin() + 0);
		}
		else {
			if (toanHang.length() != 0) {
				q.push(toanHang);
				toanHang.clear();
			}
			toanTu = str[0];
			//Stack rong va phan tu dau stack  = '(' thi them toan tu dang xet vao stack 
			if (s.empty() == true || toanTu == "(") {
				s.push(toanTu);
				str.erase(str.begin() + 0);

			}
			//toan tu dang xet  la ')' 
			else if (toanTu == ")")
			{
				if (s.top() != "(") {
					q.push(s.top());
					s.pop();

				}
				else {
					s.pop();
					str.erase(str.begin() + 0);
				}
			}
			// toan tu dang xet thuoc truong hop con lai
			else
			{
				if (s.top() == "(" || (priority(toanTu) > priority(s.top())))
				{
					s.push(toanTu);
					str.erase(str.begin() + 0);
				}
				else if (priority(toanTu) <= priority(s.top())) {
					q.push(s.top());
					s.pop();
				}
			}
		}
	}
	q.push(toanHang);
	while (s.empty() == false) {
		q.push(s.top());
		s.pop();
	}
}
void cal(queue<string>& qu) {
	//stack<string> v;
	while (qu.empty() == false) {
		string str = qu.front();
		if (str[0] >= 48 && str[0] <= 57) {
			s.push(qu.front());
		}
		else {

			int p1 = atoi(s.top().c_str()); s.pop();
			int p2 = atoi(s.top().c_str()); s.pop();
			int kq = 0;
			if (str == "+") kq = p1 + p2;
			else if (str == "-") kq = p2 - p1;
			else if (str == "*") kq = p2 * p1;
			else if (str == "/") kq = p2 / p1;
			s.push(to_string(kq));
		}
		qu.pop();
	}
	cout << s.top();
}
int main() {
	string expression;
	cout << "Enter an infix expression: ";
	getline(cin, expression);

	queue<string> postfix;
	toPostfix(expression, postfix);
	cout << "Postfix expression: ";
	while (!postfix.empty()) {
		cout << postfix.front() << " ";
		postfix.pop();
	}
	cout << endl;

	cout << "Result: ";
	cal(postfix);

	return 0;
}

