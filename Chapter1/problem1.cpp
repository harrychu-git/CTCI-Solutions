#include <iostream>

using namespace std;

/*  Problem 1.
    Implement an algorithm to determine if a string has all unique characters.
    What if you can not use additional data structures? */


// Using an additional data structure. O(N) runtime
bool allUniqueChars(string s) { 
    int dict[256] = {0};
    for(int i = 0; i < s.size(); i++) {
        if(dict[s.at(i)] > 0)
            return false;
        else 
            dict[s.at(i)]++;
    }
    return true;
}

// Using no additional data structures. O(N^2) runtime
bool allUniqueChars2(string s) {
    for(int i = 0; i < s.size()-1; i++) {
        for(int j = i+1; j < s.size(); j++) {
            if(s[i] == s[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    while(1) {
        string in;
        cout << "Enter a string: ";
        cin >> in;
        if(allUniqueChars(in))
            cout << "Unique" << endl;
        else
            cout << "Not unique" << endl;
        if(in == "end")
            return 0;
    }
    
    return 0;
}