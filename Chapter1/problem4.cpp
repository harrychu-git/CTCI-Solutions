/*  Write a method to decide if two strings are anagrams or not.    */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isAnagram(string a, string b) {
    if(a.size() != b.size())
        return false;
    int dict[256] = {0};
    for(int i = 0; i < a.size(); i++) {
        dict[a.at(i)]++;
    }
    for(int i = 0; i < b.size(); i++) {
        dict[b.at(i)]--;
    }
    for(int i = 0; i < 256; i++) {
        if(dict[i] != 0)
            return false;
    }
    return true;
    
}

int main() {
    string a;
    string b;
    cout << "String A: ";
    cin >> a;
    cout << "String B: ";
    cin >> b;
    if(isAnagram(a, b))
        cout << "ANAGRAM" << endl;
    else
        cout << "NOT ANAGRAM" << endl;
}