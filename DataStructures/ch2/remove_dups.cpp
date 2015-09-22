#include "ctci_linked_list.h"

#include <iostream>
#include <set>

using std::cin; using std::cout; using std::endl;
using std::set;

void removeDups(Node* list) {
    Node* newList = list;
    set<int> list_numbers;

    //for (Node* n = list; n->next != nullptr; n = n->next) {
        //list_numbers.insert(n->data);
    //}

    while (list->next != nullptr) {
        cout << list->data << endl;
        if (!list_numbers.count(list->data)) {
            newList = new Node(list->data);
            list_numbers.insert(list->data);
        } else {
            newList->next = list->next->next;
        }
        newList = newList->next;
        list = list->next;
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

    removeDups(list);

    for (Node* n = list; n != nullptr; n = n->next) {
        cout << n->data << " ";
    }
    cout << endl;
}

void RemoveDups(Node* list);
