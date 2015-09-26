#include "ctci_linked_list.h"

#include <iostream>
#include <set>

using std::cin; using std::cout; using std::endl;
using std::set;

void removeDups(Node*& list) {
    set<int> seen;

    Node* result = new Node(list->data);

    for (Node* n = list->next; n != nullptr; n = n->next) {
        if (!seen.count(n->data)) {
            result->appendToTail(n->data);
            seen.insert(n->data);
        } 
    }


    list = result;
}

void removeDupsNoBuffer(Node*& list) {
    for (Node* current = list; current->next != nullptr; current = current->next) {
        for (Node* runner = current; runner->next != nullptr;) {
            if (current->data == runner->next->data) {
                runner->next = runner->next->next;
            } else {
                runner = runner->next;
            }
        }
    }
    
}

int main() {
    int list_length;
    cin >> list_length;

    Node* list;
    for (int i = 0; i != list_length; ++i) {
        int temp;
        cin >> temp;

        if (i == 0) {
            list = new Node(temp);
        } else {
            list->appendToTail(temp);
        }
    }

    //removeDups(list);

    //for (Node* n = list; n != nullptr; n = n->next) {
        //cout << n->data << " ";
    //}

    removeDupsNoBuffer(list);

    for (Node* n = list; n != nullptr; n = n->next) {
        cout << n->data << " ";
    }

    cout << endl;
}

void RemoveDups(Node* list);
