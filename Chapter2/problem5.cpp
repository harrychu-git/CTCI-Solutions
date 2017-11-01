/*  Given a circular linked list, implement an algorithm which returns node at the beginning
    of the loop.
    DEFINITION
    Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an
    earlier node, so as to make a loop in the linked list.
    EXAMPLE
    input: A -> B -> C -> D -> E -> C [the same C as earlier]
    output: C   */
    
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

node* loopFinder(node* n) {
    node* slow = n;
    node* fast = n;
    do {
        slow = slow -> next;
        fast = fast -> next -> next;
    } while(slow != fast);
    slow = n;
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}

int main() {
    node* LList = makeLinkedList(5);
    printLinkedList(LList);
    cout << "Setting node " << LList -> next -> next -> next -> next -> data  << "'s next node to " << LList -> next -> next -> data << endl;
    LList -> next -> next -> next -> next -> next = LList -> next -> next;
    cout << "The start of the loop is at node: " << loopFinder(LList) -> data << endl;
    
}
