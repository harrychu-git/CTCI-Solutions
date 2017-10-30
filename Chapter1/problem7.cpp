/*  Assume you have a method isSubstring which checks if one word is a substring of
    another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
    only one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).  */
    
#include <iostream>

using namespace std;

bool isRotation(string a, string b) {
    string c = b + b;
    if(c.find(a) == string::npos)
        return false;
    else
        return true;
}

int main() {
    string a, b;
    cout << "Type in string 1: ";
    cin >> a;
    cout << "Type in string 2: ";
    cin >> b;
    if(isRotation(a, b))
        cout << "Is rotation." << endl;
    else
        cout << "Not a rotation." << endl;
}