#ifndef CTCI_LINKED_LIST_HPP
#define CTCI_LINKED_LIST_HPP
//CTCI implementation of a linked list used for CH2 of Data Structures

class Node {
    public:
        Node(int d): data(d) {};
        void appendToTail(int d);

        Node* next = nullptr;
        int data;
};

#endif
