/*  Implement an algorithm to delete a node in the middle of a single linked list, given
    only access to that node.
    EXAMPLE
    Input: the node ‘c’ from the linked list a->b->c->d->e
    Result: nothing is returned, but the new linked list looks like a->b->d->e  */
    
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


//  DELETING LAST NODE DOESNT WORK
void deleteNode(node* n) {
    if(n -> next == 0) {
        cout << "Deleting last node..." << endl;
        n = 0;
    }
    else {
        n -> data = n -> next -> data;
        n -> next = n -> next -> next;
    }
}

int main() {
    node* LList = makeLinkedList(10);
    printLinkedList(LList);
    
    deleteNode(LList -> next);
    printLinkedList(LList);
}