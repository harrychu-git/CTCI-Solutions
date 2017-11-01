/*  You have two numbers represented by a linked list, where each node contains a single
    digit. The digits are stored in reverse order, such that the 1’s digit is at the head of
    the list. Write a function that adds the two numbers and returns the sum as a linked
    list.   */
    
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

node* addTwoNumbers(node* l1, node* l2) {
        node* dummyHead = new node(0);
        node* it1 = l1;
        node* it2 = l2;
        node* curr = dummyHead;
        int carry = 0;
        int value = 0;
        while(it1 != 0 || it2 != 0 || carry != 0) { //iterate through both lists until you reach the end
            value = 0;
            if(carry == 1) {
                value += carry;
                carry = 0;
            }
            if(it1 != 0){
                value += it1 -> data;
            }
            if(it2 != 0){
                value += it2 -> data;
            }
            //take sum of both nodes of list and determine if carry is needed
            
            if(value >= 10) {
                carry = 1;
                value = value % 10;
            }
            curr -> next = new node(value);
            curr = curr -> next;
            if(it1 != 0) {
                it1 = it1-> next;
            }
            if(it2 != 0) {
                it2 = it2 -> next;
            }
        }
        return dummyHead -> next;
    }
int main() {
    node* LList = makeLinkedList(3); //  (3 -> 1 -> 5) + (5 -> 9 -> 2) =  8 -> 0 -> 8
    node* LList2 = makeLinkedList(3);
    LList -> data = 3;
    LList -> next -> data = 1;
    LList -> next -> next -> data = 5;
    LList2 -> data = 5;
    LList2 -> next -> data = 9;
    LList2 -> next -> next -> data = 2;
    printLinkedList(LList);
    printLinkedList(LList2);
    printLinkedList(addTwoNumbers(LList, LList2));
}
