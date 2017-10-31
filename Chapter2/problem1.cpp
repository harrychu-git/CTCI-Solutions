/*  Write code to remove duplicates from an unsorted linked list.
    FOLLOW UP
    How would you solve this problem if a temporary buffer is not allowed?  */

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

void printLinkedList(node* n) {
    node* pointer = n;
    while(pointer != 0) {
        cout << pointer-> data << ' ';
        pointer = pointer -> next;
    }
    cout << endl;
}

// DOES NOT WORK WHEN REMOVING LAST NODE

void removeDuplicates(node* n) {
    if(n -> next == 0)
        return;
    node* pAhead = n;
    node* pBehind;
    while(pAhead -> next != 0) {
        pBehind = n;
        while(pBehind != pAhead -> next) {
            if(pBehind -> data == pAhead -> next -> data) {
                pAhead -> next = pAhead -> next -> next;
            }
            pBehind = pBehind -> next;
        }
        pAhead = pAhead -> next;
    }
}

int main() {
    node* LList = makeLinkedList(10);
    printLinkedList(LList);
    LList -> next -> data = 8;
    printLinkedList(LList);
    removeDuplicates(LList);
    printLinkedList(LList);
}
