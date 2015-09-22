//CTCI implementation of a linked list used for CH2 of Data Structures
#include "ctci_linked_list.h"

class Node;

void Node::appendToTail(int d) {
    Node* end = new Node(d);
    Node* n = this;
    while (n->next != nullptr) {
        n = n->next;
    }
    n->next = end;
}
