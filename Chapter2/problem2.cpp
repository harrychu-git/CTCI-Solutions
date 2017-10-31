/*  Implement an algorithm to find the nth to last element of a singly linked list. */

#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
    node(int i) {
        data = i;
        next = 0;
    }
};

node* makeLinkedList(int n) {
    // create a linked list of numbers from 0 to n-1
    node* dummy = new node(-1);
    node* current = dummy;
    for(int i = 0; i < n; i++) {
        node* n = new node(i);
        current -> next = n;
        current = current -> next;
    }
    return dummy -> next;
}

int findNthLast(node* head, int n) {
    node* back = head;
    node* front = head;
    for(int i = 0; i < n; i++) 
        front = front -> next;
    while(front != 0) {
        back = back -> next;
        front = front -> next;
    }
    return back -> data;
}

void printLinkedList(node* n) {
    node* pointer = n;
    while(pointer != 0) {
        cout << pointer-> data << ' ';
        pointer = pointer -> next;
    }
    cout << endl;
}

int main() {
    // given {0 1 2 3 4 5 6 7 8 9}, 2, return 8
    node* LList = makeLinkedList(10); 
    printLinkedList(LList);
    int i;
    while(1) {
        cout << "Give a number (-1 to break): ";
        cin >> i;
        if(i == -1)
            return 0;
        cout << findNthLast(LList, i) << endl;
    }
}
