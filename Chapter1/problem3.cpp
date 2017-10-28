/*  Design an algorithm and write code to remove the duplicate characters in a string
    without using any additional buffer. NOTE: One or two additional variables are fine.
    An extra copy of the array is not.  */
    
#include <iostream>

using namespace std;

string removeDuplicates(string s) {
    string r = "";
    for(int i = 0; i < s.size(); i++) {
        bool isDup = false;
        for(int j = 0; j < i; j++) {
            if(s[j] == s[i])
                isDup = true;
        }
        if(!isDup)
            r.push_back(s[i]);
    }
    return r;
}

int main() {
    cout << removeDuplicates("ABCDE") << endl; // "ABCDE"
    cout << removeDuplicates("AABBC") << endl; // "ABC"
    cout << removeDuplicates("A") << endl;      // "A"
    cout << removeDuplicates("AAAAA") << endl;  // "A"
}