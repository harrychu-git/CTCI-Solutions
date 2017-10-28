/*  Write a method to replace all spaces in a string with ‘%20’.    */
#include <iostream>

using namespace std;

void replaceSpace(string& s) {
    string r = "";
    for(int i = 0; i < s.size(); i++) {
        if(s.at(i) == ' ') {
            r.push_back('%');
            r.push_back('2');
            r.push_back('0');
        }
        else
            r.push_back(s.at(i));
    }
    s = r;
}

int main() {
    cout << "Enter string: " << endl;
    string s;
    getline (cin,s);
    replaceSpace(s);
    cout << s << endl;
}