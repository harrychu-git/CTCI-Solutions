/*  Given an image represented by an NxN matrix, where each pixel in the image is 4
    bytes, write a method to rotate the image by 90 degrees. Can you do this in place?  */
    
//  use -std=c++11 flag when compiling
    
#include <iostream>
#include <vector>

using namespace std;

void rotate90(vector<vector<char> >& v) {
    int first = 0;
    int last = v.size()-1;
    while(first < last) {
        int count = 0;
        for(int i = first; i < last; i++) {
            int temp = v[first][first+count]; // column, row
            v[first][first+count] = v[last-count][first];
            v[last-count][first] = v[last][last-count];
            v[last][last-count] = v[first+count][last];
            v[first+count][last] = temp;
            count++;
        }
        first++;
        last--;
    }
}


void printImage(vector<vector<char> > v) {
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.at(i).size(); j++)
            cout << v.at(i).at(j) << ' ';
        cout << endl;
    }
}

int main() {
    vector<char> r1 = {'a','b','c','d'};    // m i e a
    vector<char> r2 = {'e','f','g','h'};    // n j f b
    vector<char> r3 = {'i','j','k','l'};    // o k g c
    vector<char> r4 = {'m','n','o','p'};    // p l h d
    vector<vector<char> > image;
    image.push_back(r1);
    image.push_back(r2);
    image.push_back(r3);
    image.push_back(r4);
    printImage(image);
    cout << "---------------" << endl << "Rotating..." << endl << "---------------" << endl;
    rotate90(image);
    printImage(image);
}
