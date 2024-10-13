#include <iostream>
#include <string>
using namespace std;
void XoaKiTu(string& s, int index) {
	int i;
	for ( i = index; i < s.length(); i++) {
		s[i] = s[i + 1];
	}
	s[i] = '\0';
}
string CorrectName(string& s) {
    while (s[0] == ' ') {
        XoaKiTu(s, 0);
    }
    int k = 0;
    char last = ' ';
    for (int i = 0; char c = s[i]; i++) {

        if (last == ' ') {
            if (c == ' ') continue;
            if (c >= 'a' && c <= 'z') c -= ' ';
        }
        else if (c <= 'Z' && c >= 'A') c += ' ';
        s[k++] = last = c;
        
    }
s[k] = '\0';
    return s;
}
int main() {
    string name; char c;
    int value = 0, i = 0;
    while (!value) {
        cout << "Nhap ho ten" << endl;
        getline(cin, name);
        for (i = 0; c = name[i]; i++) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' '))value = 1;
            else value = 0;
        }
		if (value) continue;
        cout << "nhap lai ho ten chi gom cac chu cai" << endl;
        getline(cin, name);
    };

    string Name = CorrectName(name);

    cout << Name;

    return 0;
}

